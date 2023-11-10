Write-PrefixedMessage "Updating pip..."
try {
    python -m pip install --upgrade pip --quiet
    Write-PrefixedMessage "Pip updated successfully!"
}
catch {
    Write-Error $_
}

Write-PrefixedMessage "Installing pip packages..."
try {
    pip install -r requirements.txt --quiet
    Write-PrefixedMessage "Pip packages installed successfully!"
}
catch {
    Write-Error $_
}