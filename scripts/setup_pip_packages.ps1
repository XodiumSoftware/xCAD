param (
    [string]$prefix
)

Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Activating virtual environment..."
& '.venv\Scripts\activate'

Write-Host -NoNewline "$prefix " -ForegroundColor Red; Write-Host "Installing pip packages..."
pip install -r requirements.txt
