try {
    if (!(Test-Path -Path ".\.venv")) {
        Write-PrefixedMessage "Installing Virtual Environment..."
        python -m venv .venv
        Write-PrefixedMessage "Virtual Environment installation complete!"
    }
    else {
        Write-PrefixedMessage "Virtual Environment is already set up."
    }
}
catch {
    Write-Error $_
}

Write-PrefixedMessage "Activating virtual environment..."
& '.venv\Scripts\activate'
