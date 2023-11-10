try {
    $pythonPath = Get-Command python -ErrorAction SilentlyContinue
    if ($null -eq $pythonPath) {
        Write-PrefixMsg "Python is not installed. Installing Python..."
        Invoke-WebRequest -Uri "https://www.python.org/ftp/python/3.12.0/python-3.12.0-amd64.exe" -OutFile "python-installer.exe"
        Start-Process -FilePath "python-installer.exe" -ArgumentList "/quiet InstallAllUsers=1 PrependPath=1 Include_test=0" -Wait
        Remove-Item -Path "python-installer.exe"
        Write-PrefixMsg "Python installation complete!"
    }
    else {
        Write-PrefixMsg "Python is already installed."
    }
}
catch {
    Write-Error $_
}