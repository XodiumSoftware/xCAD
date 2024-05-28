"""This module contains the setup configuration for Dardania."""

from pathlib import Path

from setuptools import find_packages, setup

setup(
    name="Dardania",
    version="1.0.0",
    url="https://github.com/IllyrianEngineering/Dardania",
    license=Path("LICENSE.md").read_text(),
    description="CAD addon/plug-in to automize frameworks.",
    long_description=Path("README.md").read_text(),
    long_description_content_type="text/markdown",
    author="IllyrianEngineering",
    author_email="info@illyrian-engineering.com",
    packages=find_packages(),
    install_requires=Path("requirements.txt").read_text().splitlines(),
    python_requires=">=3.12",
    package_data={"*": ["*.py", "py.typed"]},
    data_files=[
        (
            "",
            [
                "CODE_OF_CONDUCT.md",
                "CONTRIBUTING.md",
                "LICENSE.md",
                "README.md",
                "requirements.txt",
            ],
        ),
    ],
    zip_safe=False,
    project_urls={
        "Source Code": "https://github.com/IllyrianEngineering/Dardania",
        "Bug Tracker": "https://github.com/IllyrianEngineering/Dardania/issues",
        "Documentation": "https://wiki.IllyrianEngineering.com/",
        "Funding": "https://buymeacoffee.com/illyrius",
    },
)
