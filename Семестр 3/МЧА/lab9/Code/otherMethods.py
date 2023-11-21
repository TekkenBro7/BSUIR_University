import matplotlib.pyplot as plt
from eulerMethods import *
from rungeKuttMethod import rungeKutt


def getValueAtPoint(method, x, y0, y_diff, eps):
    n = 1
    old_dots, new_dots = method(x, n, y0, y_diff), method(x, 2 * n, y0, y_diff)
    while max(abs(new_dots[2 * i] - old_dots[i]) for i in range(n + 1)) > eps:
        n *= 2
        old_dots, new_dots = method(x, n, y0, y_diff), method(x, 2 * n, y0, y_diff)
    return new_dots[-1], 2 * n


def createYDots(method, xdots, y0, y_diff, eps):
    ydots = []
    maxn = 0
    midn = []
    for x in xdots:
        y, n = getValueAtPoint(method, x, y0, y_diff, eps)
        ydots.append(y)
        maxn = max(maxn, n)
        midn += [n]
    midn = sum(midn) / len(xdots)
    return ydots, midn, maxn


def solve(y_diff, y0, left_border, right_border, plotdots=10**3, eps=10**-3):
    print("Число точек: ", plotdots)
    print("Точность:  ", eps)
    x_dots = [
        left_border + (right_border - left_border) / plotdots * i
        for i in range(plotdots + 1)
    ]

    ydots, midn, maxn = createYDots(euler, x_dots, y0, y_diff, eps)
    print("Метод Эйлера:")
    for i in range(1, 10, 3):
        print(f"x[{i}]: {x_dots[i * 100]}\n" f"y[{i}]: {ydots[i * 100]}\n")
    print(f"Максимальное количество отрезков (n): {maxn}")
    print(f"Среднее количество отрезков (n): {midn}\n")
    plt.plot(x_dots, ydots, "y")

    ydots, midn, maxn = createYDots(modifiedEuler, x_dots, y0, y_diff, eps)
    print("Модифицированный метод Эйлера:")
    for i in range(1, 10, 3):
        print(f"x[{i}] = {x_dots[i * 100]}\n" f"y[{i}] = {ydots[i * 100]}\n")
    print(f"Максимальное количество отрезков (n): {maxn}")
    print(f"Среднее количество отрезков (n): {midn}\n")
    plt.plot(x_dots, ydots, "b--")

    ydots, midn, maxn = createYDots(rungeKutt, x_dots, y0, y_diff, eps)
    print("Метод Рунге-Кутта: ")
    for i in range(1, 10, 3):
        print(f"x[{i}] = {x_dots[i * 100]}\n" f"y[{i}] = {ydots[i * 100]}\n")
    print(f"Максимальное количество отрезков (n): {maxn}")
    print(f"Среднее количество отрезков (n): {midn}\n")
    plt.plot(x_dots, ydots, "r:")

    plt.show()
    return
