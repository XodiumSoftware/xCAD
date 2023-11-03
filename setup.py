from setuptools import find_packages, setup

from src.constants import PIP_PACKAGES


class PackageSetup:
    """Setup package"""

    def __init__(self) -> None:
        """Setup package"""
        self.setup_package()

    def read_file(self, filename: str) -> str:
        """Read file"""
        with open(filename) as f:
            return f.read()

    def setup_package(self) -> None:
        """Setup package"""
        long_description: str = self.read_file("README.md")
        license: str = self.read_file("LICENSE.md")

        setup(
            name="AutoFrameCad",
            version="0.0.1",
            long_description=long_description,
            long_description_content_type="text/markdown",
            license=license,
            url="https://github.com/Illyrius666/AutoFrameCad",
            project_urls={
                "Bug Tracker": "https://github.com/Illyrius666/AutoFrameCad/issues"
            },
            install_requires=PIP_PACKAGES,
            packages=find_packages(),
            python_requires=">=3.12.0",
            package_data={
                "*": ["*.py", "*.pyi"],
            },
            zip_safe=False,
        )


if __name__ == "__main__":
    PackageSetup()
