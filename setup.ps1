$prefix = "(Setup):"

trap {
    Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "An error occurred during setup." -ForegroundColor Red
    exit
}

$scripts = @('setup_msvc.ps1','setup_python.ps1', 'setup_venv.ps1', 'setup_pip_packages.ps1', 'setup_pytests.ps1')

foreach ($script in $scripts) {
    Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Running $script..." -ForegroundColor Cyan
    & ".\scripts\$script" -prefix $prefix
}

Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Setup complete!" -ForegroundColor Green
Pause
Clear-Host
