param (
    [string]$prefix
)

try {
    if (!(Test-Path -Path "C:\msys64")) {
        Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Installing MSYS2..."
        Invoke-WebRequest -Uri "https://repo.msys2.org/distrib/x86_64/msys2-x86_64-latest.exe" -OutFile "msys2-x86_64-latest.exe"
        Start-Process -FilePath "msys2-x86_64-latest.exe" -ArgumentList "/S" -Wait
        Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "MSYS2 installation complete!"
    } else {
        Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "MSYS2 is already installed."
    }

    Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Checking if mingw-w64-ucrt-x86_64-gcc is installed..."
    if ($LASTEXITCODE -ne 0) {
        Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Installing mingw-w64-ucrt-x86_64-gcc..."
        & 'C:\msys64\msys2_shell.cmd' -mingw64 -no-start -defterm -here -c "pacman -S mingw-w64-ucrt-x86_64-gcc"
        Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "mingw-w64-ucrt-x86_64-gcc installation complete!"
    } else {
        Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "mingw-w64-ucrt-x86_64-gcc is already installed."
    }
} catch {
    Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "An error occurred while setting up MSYS2 and mingw-w64-ucrt-x86_64-gcc." -ForegroundColor Red
}
