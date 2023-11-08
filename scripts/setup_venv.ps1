param (
    [string]$prefix
)

if (!(Test-Path -Path ".\.venv")) {
    Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Installing Virtual Environment..."
    python -m venv .venv
    Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Virtual Environment installation complete!"
} else {
    Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Virtual Environment is already set up."
}
