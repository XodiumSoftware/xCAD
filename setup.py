# from Cython.Build import cythonize  # type: ignore
from setuptools import find_packages, setup

setup(
    name='AutoFrameCAD',
    version='0.0.78',
    url='https://github.com/Structura-Engineering/AutoFrameCad',
    license=open('LICENSE.md').read(),
    long_description=open('README.md').read(),
    long_description_content_type='text/markdown',
    author='Structura Engineering',
    author_email='info@structura-engineering.com',
    packages=find_packages(),
    install_requires=open('requirements.txt').read().splitlines(),
    python_requires='==3.12.2',
    package_data={'*': ['*.py']},
    data_files=[('', ['LICENSE.md', 'README.md', 'requirements.txt'])],
    # ext_modules=cythonize(['*.pyx']),  # type: ignore
    zip_safe=False,
    project_urls={
        'Bug Tracker': 'https://github.com/Structura-Engineering/AutoFrameCad/issues'
    },
)
