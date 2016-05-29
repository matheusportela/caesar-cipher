from distutils.core import setup, Extension

setup(
    name='pycaesar', version='1.0',
    ext_modules=[Extension('pycaesar', sources=['pycaesar.c', 'caesar.c'])],
    headers=['caesar.h']
)
