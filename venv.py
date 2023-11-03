import subprocess

from src.constants import PIP_PACKAGES


class VENVSetup:
    """Setup virtual environment and install pip packages"""

    def __init__(self) -> None:
        """Setup virtual environment and install pip packages"""
        self.setup_venv()

    def setup_venv(self) -> None:
        """Setup virtual environment and install pip packages"""
        subprocess.check_call(["python", "-m", "venv", ".venv"])
        for package in PIP_PACKAGES:
            if package == "StenLib":
                subprocess.check_call(
                    [
                        ".venv\\Scripts\\python",
                        "-m",
                        "pip",
                        "install",
                        "--index-url",
                        "https://test.pypi.org/simple/",
                        "--upgrade",
                        package,
                    ]
                )
            else:
                subprocess.check_call(
                    [
                        ".venv\\Scripts\\python",
                        "-m",
                        "pip",
                        "install",
                        "--no-python-version-warning",
                        "--upgrade",
                        package,
                    ]
                )
        subprocess.check_call(
            [".venv\\Scripts\\python", "-m", "pip", "install", "--upgrade", "pip"]
        )
