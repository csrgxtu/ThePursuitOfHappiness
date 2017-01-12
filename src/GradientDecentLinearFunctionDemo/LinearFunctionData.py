#!/usr/bin/env python
# coding=utf-8
#
# Author: Archer
# File: LinearFunctionData.py
# Desc: generate linear function sample data
# Date: 12/Jan/2017
import numpy as np

def linearFunc(theta, x):
    return theta * x

for x in list(np.linspace(0, 50, 1000000)):
    print str(x) + ',' + str(linearFunc(2, x))
