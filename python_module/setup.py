#!/usr/bin/env python3

from distutils.core import setup, Extension

module1 = Extension(
    'spam',
    sources=['spammodule.c']
)

setup (
    name='Spam',
    version='1.0',
    description='My first C extension for python.',
    ext_modules=[module1]
)
