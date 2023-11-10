function Write-PrefixedMessage {
    param (
        [string]$message,
        [ConsoleColor]$color = [ConsoleColor]::White
    )

    Write-Host -NoNewline "(Setup): " -ForegroundColor Red; Write-Host $message -ForegroundColor $color
}

trap {
    Write-PrefixedMessage "An error occurred during setup." -color Red
    exit
}

$scripts = @("setup_msvc.ps1", 'setup_python.ps1', "setup_venv.ps1", "setup_pip_packages.ps1", "setup_pytests.ps1")

foreach ($script in $scripts) {
    Write-PrefixedMessage "Running $script..." -color Cyan
    & ".\scripts\$script"
}

Write-PrefixedMessage "Setup complete!" -color Green
Pause
Clear-Host
