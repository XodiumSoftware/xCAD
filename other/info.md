# Important:

- Files named `__init__.py` are a special type of file that tells python that a specfic directory is a module. These files are required for accessing all python modules from anywhere.

# Setup c/c++ compiler:

1. Navigate to: https://code.visualstudio.com/docs/cpp/config-mingw and follow its instruction.
   1.1 **ATTENTION!** when the tutorial says to use the following cmd: pacman -S mingw-w64-ucrt-x86_64-gcc instead use: pacman -S mingw-w64-x86_64-gcc (so without the ucrt).

# To automatically update all the pip packages:

1. pip list --outdated --format=columns | Select-String -Pattern "(?<!^\-e)^\S+" | ForEach-Object { $_.Matches.Value } | ForEach-Object { pip install --upgrade $_ }

# My VSC profile:

1. https://vscode.dev/profileprofile/github/95a1af1b0d85808ab9250cce92e4d903

# Bandit run:

1. cd C:\Python311\Scripts
2. python -m bandit {absolute_file_path}

# Delete (local)branches:

1. git branch -d --remote {remote_branch_name}
   or
2. git branch -d {local_branch_name}

Note: if the branch is not merged, use -D instead of -d. This will delete the branch regardless of its merge status.
