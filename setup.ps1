function Write-PrefixMsg {
    param (
        [string]$message,
        [ConsoleColor]$color = [ConsoleColor]::White
    )

    Write-Host -NoNewline "(Setup): " -ForegroundColor Magenta; Write-Host $message -ForegroundColor $color
}

function Write-Error {
    param($Err)
    $ErrorMessage = $Err.Exception.Message
    Write-PrefixMsg "An error occurred: $ErrorMessage" -color Red
}

function Get-UserConfirmation {
    param (
        [Parameter(Mandatory = $true)]
        [string]$message
    )
    Write-PrefixMsg ($message + " [Y/N]") -color Gray
    $userInput = Read-Host
    while ($userInput -ne 'Y' -and $userInput -ne 'N') {
        Write-PrefixMsg "Invalid input. Please enter 'Y' for Yes or 'N' for No." -color Yellow
        $userInput = Read-Host
    }
    return $userInput
}


trap {
    Write-PrefixMsg "An error occurred during setup." -color Red
    exit
}

$scripts = @(
    "setup_msvc.ps1",
    "setup_python.ps1",
    "setup_venv.ps1",
    "setup_pip_packages.ps1",
    "setup_unittests.ps1",
    "run_unittests.ps1"
)

do {
    Write-PrefixMsg "Please select a script to run:" -color Cyan
    Write-PrefixMsg "[A]: Run All Scripts" -color Green
    for ($i = 0; $i -lt $scripts.Length; $i++) {
        $scriptNameWithoutExtension = [System.IO.Path]::GetFileNameWithoutExtension($scripts[$i])
        Write-PrefixMsg "[$($i+1)]: $scriptNameWithoutExtension"
    }
    Write-PrefixMsg "[0]: Exit" -color Red
    $inputOptions = "A,1-" + $scripts.Length + ",0"
    Write-PrefixMsg "Enter your choice [$inputOptions]:" -color Gray
    $choice = Read-Host
    while ($choice -ne 'A' -and $choice -ne '0' -and -not ($choice -gt 0 -and $choice -le $scripts.Length)) {
        Write-PrefixMsg "Invalid input. Please enter 'A' (All), a number from '1-$($scripts.Length)' (Script no.), or '0' (Exit)." -color Yellow
        $choice = Read-Host
    }
    if ($choice -eq 'A') {
        foreach ($script in $scripts) {
            Write-PrefixMsg "Running $script..." -color Cyan
            & ".\scripts\$script"
        }
    }
    elseif ($choice -gt 0 -and $choice -le $scripts.Length) {
        $script = $scripts[$choice - 1]
        Write-PrefixMsg "Running $script..." -color Cyan
        & ".\scripts\$script"
    }
} while ($choice -ne 0)

Write-PrefixMsg "Setup complete!" -color Green
Pause
Clear-Host
