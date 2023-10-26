from setuptools import find_packages, setup

setup(
    name="AutoFrameCad",
    version="0.0.1",
    long_description=open("README.md").read(),
    long_description_content_type="text/markdown",
    license=open("LICENSE.md").read(),
    url="https://github.com/Illyrius666/AutoFrameCad",
    project_urls={"Bug Tracker": "https://github.com/Illyrius666/AutoFrameCad/issues"},
    install_requires=["pyside6", "pyqtdarktheme", "setuptools", "types-setuptools"],
    packages=find_packages(),
    python_requires=">=3.12.0",
    package_data={
        "*": ["*.py", "*.pyi"],
    },
    zip_safe=False,
)
