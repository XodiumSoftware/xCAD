try {
    Write-PrefixedMessage "Generating unit test files..."
    python .\scripts\unittest_generator.py
    Write-PrefixedMessage "Unittest generation complete!"
}
catch {
    Write-Error $_
}
