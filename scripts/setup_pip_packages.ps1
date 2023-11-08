param (
    [string]$prefix
)

Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Activating virtual environment..."
& '.venv\Scripts\activate'

Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Installing pip packages..."
try {
    pip install -r requirements.txt --quiet
    Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Pip packages installed successfully!"
} catch {
    Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "An error occurred while installing pip packages." -ForegroundColor Red;
}
