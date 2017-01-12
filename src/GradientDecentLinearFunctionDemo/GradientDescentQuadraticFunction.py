#!/usr/bin/env python
# coding=utf-8
#
# Author: Archer
# File: GradientDescentLinearFunction.py
# Desc: 使用梯度下降法计算线性回归的参数
# Date: 12/Jan/2017

def loadSamples():
    samples = []
    with open('./sample.data') as F:
        for line in F:
            samples.append([float(x) for x in line.strip().split(',')])

            return samples

            samples = loadSamples()

def originalFunc(theta, x):
    return theta * x * x

def costFunc(theta):
    errorSum = 0.0
    for sample in samples:
        errorSum = errorSum + abs(originalFunc(theta, sample[0]) - sample[1])

    return errorSum / (2 * len(samples))

def pde(theta, delta):
    return (costFunc(samples, theta + delta) - costFunc(samples, theta)) / delta


theta = 16
alpha = 0.1
delta = 0.0001
tor = 0.0000001
epoch = 10000
cost = 0.0
for e in range(epoch):
    cost = costFunc(theta)
    if cost <= tor:
        print 'epoch:', e, 'theta:', theta, 'tol:', cost, 'pde:', pde(theta, delta)
        sys.exit(0)
    else:
        print 'epoch:', e, 'theta:', theta, 'tol:', cost, 'pde:', pde(theta, delta)

    theta = theta - alpha * abs(pde(theta, delta))
