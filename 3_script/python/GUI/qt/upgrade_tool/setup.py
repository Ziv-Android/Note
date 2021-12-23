#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from pip._internal.req import parse_requirements
from setuptools import setup, find_packages

setup(
    name="vz-upgrade-tool",
    version="0.0.1",
    description="云平台批量升级工具",
    long_description=open("README.md").read(),
    author="ziv",
    license="",
    packages=find_packages(exclude=("tests", "doc", "etc")),
    install_requires=[str(ir.req) for ir in parse_requirements("requirements.txt", session=False)],
)
