param (
    [string]$prefix
)

try {
    $vsInstallerPath = Get-Command vs_installer.exe -ErrorAction SilentlyContinue
    if ($null -eq $vsInstallerPath) {
        Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Visual Studio Installer is not installed. Downloading the latest Visual Studio Installer..."
        Invoke-WebRequest -Uri "https://aka.ms/vs/17/release/vs_buildtools.exe" -OutFile "vs_installer.exe"
        Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Visual Studio Installer download complete!"
        Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Running Visual Studio Installer with command-line parameters to install the 'Desktop development with C++' workload..."
        Start-Process -FilePath "vs_installer.exe" -ArgumentList "--add Microsoft.VisualStudio.Workload.VCTools --includeRecommended" -Wait
        Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Visual Studio Installer ran successfully!"
        Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Setting environment variables to use the MSVC compiler from the command line..."
        $env:PATH = "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build;" + $env:PATH
        cmd.exe /c "vcvarsall.bat x64 & set" |
        ForEach-Object {
            if ($_ -match "^(.*?)=(.*)$") {
                Set-Content "env:\$($matches[1])" $matches[2]
            }
        }
        Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Environment variables set successfully!"
        Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Cleaning up Visual Studio Installer executable..."
        Remove-Item -Path "vs_installer.exe"
        Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Visual Studio Installer executable cleaned up successfully!"
    } else {
        Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Visual Studio Installer is already installed."
    }
} catch {
    Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "An error occurred while downloading and running Visual Studio Installer." -ForegroundColor Red
}
