Write-PrefixedMessage "Updating pip..."
try {
    python -m pip install --upgrade pip --quiet
    Write-PrefixedMessage "Pip updated successfully!"
}
catch {
    Write-PrefixedMessage "An error occurred while updating pip." -color Red
}

Write-PrefixedMessage "Installing pip packages..."
try {
    pip install -r requirements.txt --quiet
    Write-PrefixedMessage "Pip packages installed successfully!"
}
catch {
    Write-PrefixedMessage "An error occurred while installing pip packages." -color Red
}
