import numpy

m = 1.5
a = 0.9


def f(x, y):
    dY = numpy.zeros(y.shape)
    dY[0] = a * (1 - y[0] ** 2) / ((1 + m) * x**2 + y[0] ** 2 + 1)
    return dY


left = 0
right = 1
