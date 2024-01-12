from setuptools import find_packages, setup

setup(
    name='AutoFrameCAD',
    version='0.0.4',
    long_description=open('README.md').read(),
    long_description_content_type='text/markdown',
    license=open('LICENSE.md').read(),
    url='https://github.com/Structura-Engineering/AutoFrameCad',
    project_urls={
        'Bug Tracker': 'https://github.com/Structura-Engineering/AutoFrameCad/issues'
    },
    install_requires=open('requirements.txt').read().splitlines(),
    packages=find_packages(),
    python_requires='==3.12.1',
    package_data={'*': ['*.py']},
    data_files=[('', ['LICENSE.md', 'README.md', 'requirements.txt'])],
    zip_safe=False,
)
