try {
    Write-PrefixMsg "Generating unit test files..."
    python .\scripts\generators\unittest_generator.py
    Write-PrefixMsg "Unittest generation complete!"
}
catch {
    Write-Error $_
}
