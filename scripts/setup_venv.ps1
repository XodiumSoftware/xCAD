param (
    [string]$prefix
)

try {
    if (!(Test-Path -Path ".\.venv")) {
        Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Installing Virtual Environment..."
        python -m venv .venv
        Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Virtual Environment installation complete!"
    } else {
        Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Virtual Environment is already set up."
    }
} catch {
    Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "An error occurred while setting up the Virtual Environment." -ForegroundColor Red;
}

Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Activating virtual environment..."
& '.venv\Scripts\activate'