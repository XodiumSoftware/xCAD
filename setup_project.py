import subprocess


# TODO: remove.
def run_command(command: str) -> int:
    """Run a command and return the exit code."""
    process = subprocess.Popen(command, shell=True)
    process.communicate()
    return process.returncode


def setup_venv():
    """Run the setup_venv.bat script."""
    return run_command(".\\scripts\\setup_venv.bat")


def setup_msys2():
    """Run the setup_msys2.bat script."""
    return run_command(".\\scripts\\setup_msys2.bat")


if __name__ == "__main__":
    import os

    os.chdir(os.path.dirname(os.path.abspath(__file__)))

    if setup_venv() != 0:
        print("An error occurred during virtual environment setup.")
    elif setup_msys2() != 0:
        print("An error occurred during MSYS2 setup.")
    else:
        print("Setup complete!")
