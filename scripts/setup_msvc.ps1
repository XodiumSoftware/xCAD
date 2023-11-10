try {
    $vsInstallationPath = "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools"

    if (!(Test-Path -Path $vsInstallationPath)) {
        Write-PrefixedMessage "Visual Studio is not installed. Downloading the latest Visual Studio Installer..."
        Invoke-WebRequest -Uri "https://aka.ms/vs/17/release/vs_buildtools.exe" -OutFile "vs_installer.exe"
    }
    else {
        Write-PrefixedMessage "Visual Studio is already installed."
        Write-PrefixedMessage "Do you want to re-install? [Y/N]"
        $userInput = Read-Host
        while ($userInput -ne 'Y' -and $userInput -ne 'N') {
            Write-PrefixedMessage "Invalid input. Please enter 'Y' for Yes or 'N' for No."
            $userInput = Read-Host
        }
        if ($userInput -ne 'Y') {
            Write-PrefixedMessage "Skipping the installation as per user request."
            return
        }
        else {
            Write-PrefixedMessage "Re-installing Visual Studio..."
            Invoke-WebRequest -Uri "https://aka.ms/vs/17/release/vs_buildtools.exe" -OutFile "vs_installer.exe"
        }
    }

    Write-PrefixedMessage "Running Visual Studio Installer with command-line parameters to install the 'Desktop development with C++' workload..."
    Start-Process -FilePath "vs_installer.exe" -ArgumentList "--add Microsoft.VisualStudio.Workload.VCTools --includeRecommended --quiet" -Wait
    Write-PrefixedMessage "Visual Studio Installer ran successfully!"
    
    $batFile = Join-Path -Path $vsInstallationPath -ChildPath "VC\Auxiliary\Build\vcvarsall.bat"
    
    if ((Test-Path -Path $vsInstallationPath) -and (Test-Path -Path $batFile)) {
        Write-PrefixedMessage "Setting environment variables to use the MSVC compiler from the command line..."
        $env:PATH = "$vsInstallationPath\VC\Auxiliary\Build;" + $env:PATH
        cmd.exe /c "vcvarsall.bat x64 & set" |
        ForEach-Object {
            if ($_ -match "^(.*?)=(.*)$") {
                Set-Content "env:\$($matches[1])" $matches[2]
            }
        }
        Write-PrefixedMessage "Environment variables set successfully!"
    }
    else {
        Write-PrefixedMessage "The MSVC path or the vcvarsall.bat file does not exist." -color Red
    }

    Write-PrefixedMessage "Updating compilerPath in c_cpp_properties.json..."
    $jsonPath = Join-Path -Path (Split-Path $PSScriptRoot -Parent) -ChildPath ".vscode/c_cpp_properties.json"
    $json = Get-Content -Path $jsonPath | ConvertFrom-Json -Depth 5
    $msvcPath = Get-ChildItem -Path "$vsInstallationPath\VC\Tools\MSVC" | Sort-Object -Property Name -Descending | Select-Object -First 1
    $json.configurations[0].compilerPath = "$msvcPath\bin\Hostx64\x64\cl.exe"
    $json | ConvertTo-Json | Set-Content -Path $jsonPath
    Write-PrefixedMessage "Updated compilerPath in c_cpp_properties.json successfully!"
    
    Write-PrefixedMessage "Cleaning up Visual Studio Installer executable..."
    Remove-Item -Path "vs_installer.exe"
    Write-PrefixedMessage "Visual Studio Installer executable cleaned up successfully!"
}
catch {
    Write-PrefixedMessage "An error occurred while downloading and running Visual Studio Installer: $($_.Exception.Message)" -color Red
}
