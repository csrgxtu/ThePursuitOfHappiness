#!/usr/bin/env python
# coding=utf-8
#
# Author: Archer
# File: GradientDescentLinearFunction.py
# Desc: 使用梯度下降法计算线性回归的参数
# Date: 12/Jan/2017
import sys

def originalFunc(theta, x):
    return theta * x

def costFunc(samples, theta):
    errorSum = 0.0
    for sample in samples:
        errorSum = errorSum + (originalFunc(theta, sample[0]) - sample[1]) * (originalFunc(theta, sample[0]) - sample[1])

    return errorSum / (2 * len(samples))

def pde(costFunc, samples, theta, delta):
    return (costFunc(samples, theta + delta) - costFunc(samples, theta)) / delta

def loadSamples():
    samples = []
    with open('./sample.data') as F:
        for line in F:
            samples.append([float(x) for x in line.strip().split(',')])

    return samples

samples = loadSamples()

theta = 16
alpha = 0.05
delta = 0.0001
tor = 0.0000001
epoch = 10000
for e in range(epoch):
    cost = abs(costFunc(samples, theta))
    if cost <= tor:
        print 'epoch:', e, 'theta:', theta, 'tol:', cost
        sys.exit(0)
    else:
        print 'epoch:', e, 'theta:', theta, 'tol:', cost

    theta = theta - alpha * pde(costFunc, samples, theta, delta)
