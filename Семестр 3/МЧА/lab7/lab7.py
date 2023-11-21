import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import *


def inputf(func, left_border, right_border, dots_count):
    x, y = [], []
    for i in range(dots_count):
        x.append(left_border + (right_border - left_border) * i / (dots_count - 1))
        y.append(func(x[i]))
    return x, y, func


def sweep_method(A, b):
    A = A.copy()
    b = b.copy()
    n = len(A)

    if len(A) > 1:
        A[0][1] /= A[0][0]
    for i in range(1, n - 1):
        A[i][i + 1] /= -(A[i][i] + A[i][i - 1] * A[i - 1][i])

    b[0] /= A[0][0]
    for i in range(1, n):
        b[i] = (b[i] - A[i][i - 1] * b[i - 1]) / (A[i][i] + A[i][i - 1] * A[i - 1][i])

    x = np.zeros(n)
    x[n - 1] = b[n - 1]
    for i in range(n - 2, -1, -1):
        x[i] = b[i] + A[i][i + 1] * x[i + 1]
    return x


def syst_spline(x, y):
    n = len(x) - 1
    h = []
    for i in range(0, n):
        h += [x[i + 1] - x[i]]

    A = np.zeros((n - 1, n - 1))

    for i in range(0, n - 2):
        A[i + 1][i] = h[i]
        A[i][i + 1] = h[i]

    for i in range(0, n - 1):
        A[i][i] = 2 * (h[i] + h[i + 1])

    F = []
    for i in range(1, n):
        F += [3 * ((y[i + 1] - y[i]) / h[i] - (y[i] - y[i - 1]) / h[i - 1])]

    c = sweep_method(A, F)
    c = [0.0] + list(c) + [0.0]
    return c, h


def syst_spline2(x, y):
    n = len(x) - 1
    h = []
    for i in range(0, n):
        h += [x[i + 1] - x[i]]

    A = np.zeros((n - 1, n - 1))

    for i in range(0, n - 2):
        A[i + 1][i] = h[i]
        A[i][i + 1] = h[i]

    for i in range(0, n - 1):
        A[i][i] = 2 * (h[i] + h[i + 1])

    F = []
    for i in range(1, n):
        F += [3 * ((y[i + 1] - y[i]) / h[i] - (y[i] - y[i - 1]) / h[i - 1])]

    c = sweep_method(A, F)
    c = [0.0] + list(c) + [0.0]
    return c, h


def evaluate(xdot, x, y, h, c):
    for i in range(1, len(x)):
        if x[i - 1] <= xdot <= x[i]:
            val = 0
            val += y[i]
            b = (y[i] - y[i - 1]) / h[i - 1] + (2 * c[i] + c[i - 1]) * h[i - 1] / 3
            val += b * (xdot - x[i])
            val += c[i] * ((xdot - x[i]) ** 2)
            d = (c[i] - c[i - 1]) / (3 * h[i - 1])
            val += d * ((xdot - x[i]) ** 3)
            return val
    return None


def output(x, y, h, c):
    for i in range(1, len(x)):
        b = (y[i] - y[i - 1]) / h[i - 1] + (2 * c[i] + c[i - 1]) * h[i - 1] / 3
        d = (c[i] - c[i - 1]) / (3 * h[i - 1])
        print(
            f"Промежуток {x[i - 1]} --- {x[i]}",
        )
        print(np.poly1d([d, c[i], b, y[i]]))
    return evaluate, output


def test(func, xdot, left_border, right_border, dots_count):
    """

    :param func: function
    :param xdot: value in this dot
    :param left_border: left border
    :param right_border: right border
    :param dots_count: number of dots
    :return:
    """
    x, y, f = inputf(func, left_border, right_border, dots_count)

    plt.plot(x, y, "om")
    x_plot = np.linspace(min(x), max(x), 100)
    y_plot = [f(xdot) for xdot in x_plot]
    plt.plot(x_plot, y_plot)

    spline_koef, h = syst_spline(x, y)
    y_plot = [evaluate(xdot, x, y, h, spline_koef) for xdot in x_plot]
    plt.plot(x_plot, y_plot)

    output(x, y, h, spline_koef)

    print(f"Считаеем значение в точке {xdot}...")
    print(f"f({xdot}) =", f(xdot))
    print(f"Кубический сплайн в точке {xdot} =", evaluate(xdot, x, y, h, spline_koef))
    print(f"Разница значений =", abs(f(xdot) - evaluate(xdot, x, y, h, spline_koef)))

    plt.show()


def main():
    test(np.sqrt, 2, 0, 4, 6)


main()
