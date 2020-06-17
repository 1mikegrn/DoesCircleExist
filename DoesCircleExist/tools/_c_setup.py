"""
to build C files, pass:

python _c_setup.py build_ext --inplace clean --all

this file is only used for testing purposes
"""
import glob
from setuptools import setup, Extension, find_packages
from os import path

here = path.abspath(path.dirname(__file__))
files = [path.split(x)[1] for x in glob.glob(path.join(here, '**.c'))]

extensions = [Extension(
    path.splitext(x)[0], [x]
) for x in files]

setup(
    ext_modules = extensions,
)