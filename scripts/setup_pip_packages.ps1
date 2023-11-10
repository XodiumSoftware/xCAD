Write-PrefixMsg "Updating pip..."
try {
    python -m pip install --upgrade pip --quiet
    Write-PrefixMsg "Pip updated successfully!"
}
catch {
    Write-Error $_
}

Write-PrefixMsg "Installing pip packages..."
try {
    pip install -r requirements.txt --quiet
    Write-PrefixMsg "Pip packages installed successfully!"
}
catch {
    Write-Error $_
}