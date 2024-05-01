"""This module contains the setup configuration for AutoFrameCAD."""

from pathlib import Path

from setuptools import find_packages, setup

setup(
    name="AutoFrameCAD",
    version="0.0.81",
    url="https://github.com/Structura-Engineering/AutoFrameCAD",
    license=Path("LICENSE.md").read_text(),
    description="CAD addon/plug-in to automize frameworks.",
    long_description=Path("README.md").read_text(),
    long_description_content_type="text/markdown",
    author="Structura Engineering",
    author_email="info@structura-engineering.com",
    packages=find_packages(),
    install_requires=Path("requirements.txt").read_text().splitlines(),
    python_requires=">=3.12",
    package_data={"*": ["*.py", "py.typed"]},
    data_files=[
        (
            "",
            [
                "CHANGELOG.md",
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
        "Source Code": "https://github.com/Structura-Engineering/AutoFrameCAD",
        "Bug Tracker": "https://github.com/Structura-Engineering/AutoFrameCAD/issues",
        "Documentation": "https://wiki.structura-engineering.com/AutoFrameCAD",
        "Funding": "https://buymeacoffee.com/illyrius",
    },
)
