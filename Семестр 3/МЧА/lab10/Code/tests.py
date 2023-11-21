import numpy


def f_1(x, y):
    dY = numpy.zeros(y.shape)
    dY[0] = x**2 + y + 4
    return dY


left_1 = 0
right_1 = 1


def f_2(x, y):
    dY = numpy.zeros(y.shape)
    dY[0] = numpy.tan(x) + y
    return dY


left_2 = 0
right_2 = 1
