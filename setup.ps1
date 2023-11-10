function Write-PrefixedMessage {
    param (
        [string]$message,
        [ConsoleColor]$color = [ConsoleColor]::White
    )

    Write-Host -NoNewline "(Setup): " -ForegroundColor Magenta; Write-Host $message -ForegroundColor $color
}

function Write-Error {
    param($Err)
    $ErrorMessage = $Err.Exception.Message
    Write-PrefixedMessage "An error occurred: $ErrorMessage" -color Red
}

trap {
    Write-PrefixedMessage "An error occurred during setup." -color Red
    exit
}

$scripts = @(
    # "setup_msvc.ps1",
    # "setup_python.ps1",
    # "setup_venv.ps1",
    # "setup_pip_packages.ps1",
    "setup_unittests.ps1"
)

foreach ($script in $scripts) {
    Write-PrefixedMessage "Running $script..." -color Cyan
    & ".\scripts\$script"
}

Write-PrefixedMessage "Setup complete!" -color Green
Pause
Clear-Host
