from distutils.core import setup, Extension

main = Extension(
    'facto',
    sources=['fast_factorial.c']
)

setup (
    name='facto',
    version='1.0',
    description='Fast factorial: python with C!',
    ext_modules=[main]
)
