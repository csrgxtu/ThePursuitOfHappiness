#!/usr/bin/env python
# coding=utf-8
#
# Author: Archer
# File: GradientDescentLinearRegression.py
# Desc: use gradient descent do linear reguression optimization
# Date: 12/Jan/2017
import numpy as np
import random
import sklearn
from sklearn.datasets.samples_generator import make_regression
import pylab
from scipy import stats

# h(theta) = theta * x
def gradient_descent(alpha, x, y, ep=0.0001, max_iter=10000):
    converged = False
    iter = 0
    # m = x.shape[0] # number of samples
    m = len(x)

    # initial theta
    # t0 = np.random.random(x.shape[1])
    t0 = 18.0

    # total error, J(theta)
    J = sum([(t0*x[i]**2 - y[i])**2 for i in range(m)])
    print 'Init', 'theta:', t0, 'cost:', J

    # Iterate Loop
    while not converged:
        # for each training sample, compute the gradient (d/d_theta j(theta))
        grad0 = 1.0/m * sum([(t0*x[i]**2 - y[i]) for i in range(m)])

        # update the theta_temp
        temp0 = t0 - alpha * grad0

        # update theta
        t0 = temp0

        # mean squared error
        e = sum( [(t0*x[i]**2 - y[i])**2 for i in range(m)] )

        if abs(J-e) <= ep:
            print 'Converged, iterations: ', iter, '!!!'
            converged = True

        J = e   # update error
        iter += 1  # update iter

        print 'Epoch:', iter, 'theta', t0, 'cost:', e

        if iter == max_iter:
            print 'Max interactions exceeded!'
            converged = True

    return t0

if __name__ == '__main__':

    # f(x) = 2 + 2x
    X = []
    Y = []
    for x in list(np.linspace(25, 25, 10000)):
        X.append(x)
        Y.append(2.7 * x ** 2)

    alpha = 0.01 # learning rate
    ep = 0.00000001 # convergence criteria

    # call gredient decent, and get intercept(=theta0) and slope(=theta1)
    theta0 = gradient_descent(alpha, X, Y, ep, max_iter=10000)
    print ('theta0 = %s') %(theta0)
    #
    # # check with scipy linear regression
    # slope, intercept, r_value, p_value, slope_std_error = stats.linregress(x[:,0], y)
    # print ('intercept = %s slope = %s') %(intercept, slope)
    #
    # # plot
    # for i in range(x.shape[0]):
    #     y_predict = theta0 + theta1*x
    #
    # pylab.plot(x,y,'o')
    # pylab.plot(x,y_predict,'k-')
    # pylab.show()
    # print "Done!"
