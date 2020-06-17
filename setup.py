from setuptools import setup, Extension, find_packages
from os import path
import glob

here = path.abspath(path.dirname(__file__))
files = [path.split(x)[1] for x in glob.glob(path.join(here, '**.c'))]

extensions = [Extension(
    path.splitext(x)[0], [x]
) for x in files]

with open(path.join(here, 'README.md'), encoding='utf-8') as f:
    long_description = f.read()

setup(
    name='DoesCircleExist',
    version='0.0.1',
    description='Solving a google coding challenge with C extensions',
    long_description=long_description,
    author='Michael Green',
    author_email='1mikegrn@gmail.com',
    license='GPL-3.0',

    classifiers=[
        'Development Status :: 3 - Beta',
        'Intended Audience :: STEM research',
        'License :: OSI Approved :: GPL-3.0 License',
    ],

    packages=find_packages(),

    include_package_data=True,

    python_requires='>=3.6',

    ext_modules = extensions,

)