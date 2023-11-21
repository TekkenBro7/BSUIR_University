import numpy


def y_diff_1(x, y):
    return x**2


left_border_1 = -3
right_border_1 = 3
y0_1 = 1


def y_diff_2(x, y):
    return 2 * y


left_border_2 = -1
right_border_2 = 1
y0_2 = 1


def y_diff_3(x, y):
    return numpy.tan(x)


left_border_3 = -1
right_border_3 = 1
y0_3 = 0


def y_diff_4(x, y):
    return 7


left_border_4 = -2
right_border_4 = 2
y0_4 = 0
