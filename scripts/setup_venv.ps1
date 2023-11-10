try {
    if (!(Test-Path -Path ".\.venv")) {
        Write-PrefixMsg "Installing Virtual Environment..."
        python -m venv .venv
        Write-PrefixMsg "Virtual Environment installation complete!"
    }
    else {
        Write-PrefixMsg "Virtual Environment is already set up."
    }
}
catch {
    Write-Error $_
}

Write-PrefixMsg "Activating virtual environment..."
& '.venv\Scripts\activate'
