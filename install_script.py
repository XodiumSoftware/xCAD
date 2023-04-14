import importlib
import subprocess

LIBRARY_NAME = "PyQt6"

try:
    importlib.import_module(LIBRARY_NAME)
    print(f"{LIBRARY_NAME} is installed")

    # Check if there is a newer version available
    result = subprocess.run(
        [
            "pip",
            "install",
            f"{LIBRARY_NAME}==version_check",
            "--upgrade",
            "--no-cache-dir",
            "-q",
        ],
        capture_output=True,
    )

    # If an upgrade is available, install it
    if "Successfully installed" in result.stdout.decode("utf-8"):
        print(f"{LIBRARY_NAME} has been upgraded to the latest version.")

except ImportError:
    print(f"{LIBRARY_NAME} is not installed.")
    install = input(f"Do you want to install {LIBRARY_NAME}? (y/n): ")
    if install.lower() == "y":
        subprocess.check_call(["pip", "install", f"{LIBRARY_NAME}"])
        print(f"{LIBRARY_NAME} has been installed.")
    else:
        print(f"{LIBRARY_NAME} was not installed.")
