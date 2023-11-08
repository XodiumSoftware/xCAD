$prefix = "(Setup):"

Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Running setup_msys2.bat..." -ForegroundColor Cyan
.\scripts\setup_msys2.ps1 -prefix $prefix
if ($LASTEXITCODE -ne 0) {
    Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "An error occurred during MSYS2 setup." -ForegroundColor Cyan
    exit
}

Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Running setup_python.bat..." -ForegroundColor Cyan
.\scripts\setup_python.ps1 -prefix $prefix
if ($LASTEXITCODE -ne 0) {
    Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "An error occurred during Python setup." -ForegroundColor Cyan
    exit
}

Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Running setup_venv.bat..." -ForegroundColor Cyan
.\scripts\setup_venv.ps1 -prefix $prefix
if ($LASTEXITCODE -ne 0) {
    Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "An error occurred during virtual environment setup." -ForegroundColor Cyan
    exit
}

Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Running setup_pip_packages.bat..." -ForegroundColor Cyan
.\scripts\setup_pip_packages.ps1 -prefix $prefix
if ($LASTEXITCODE -ne 0) {
    Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "An error occurred during pip package setup." -ForegroundColor Cyan
    exit
}

Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Setup complete!" -ForegroundColor Green
pause
Clear-Host
