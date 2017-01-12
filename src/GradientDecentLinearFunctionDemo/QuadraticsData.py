#!/usr/bin/env python
# coding=utf-8
#
# Author: Archer
# File: QuadraticsData.py
# Desc: generate x^2 function sample data
# Date: 12/Jan/2017
import numpy as np

def quadraticFunc(theta, x):
    return theta * x * x

for x in list(np.linspace(0, 50, 1000000)):
    print str(x) + ',' + str(quadraticFunc(0.5, x))
