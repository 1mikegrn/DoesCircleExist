# from distutils.core import 
from setuptools import find_packages, setup, Extension
from os import path

here = path.abspath(path.dirname(__file__))

extensions = [
    Extension(
        'pycees.tools.DoesCircleExist', 
        [path.join('pycees', 'tools', 'DoesCircleExist.c')]
    ),

    Extension(
        'pycees.tools.quickSort',
        [path.join('pycees', 'tools', 'quickSort.c')]
    )
]

with open(path.join(here, 'README.md'), encoding='utf-8') as f:
    long_description = f.read()

setup(
    name='pycees',
    version='0.0.1',
    description='playing around with C extensions',
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