import numpy as np
import matplotlib.pyplot as plt
from numpy.core.multiarray import dot


def input():
    x = [0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
    p = [0.0, 0.41, 0.79, 1.13, 1.46, 1.76, 2.04, 2.3, 2.55, 2.79, 3.01]
    k = 11
    m = 2.53
    y = [(p[i] + ((-1) ** k) * m) for i in range(len(x))]
    dots = list(zip(x, y))
    return dots


# Многочлен Лагранжа
def Lagrange(dots):
    n = len(dots)  # Число точек
    (x, y) = map(list, zip(*dots))  # Списки X и Y отдельно
    polynom = np.poly1d([0])  # polynom = 0
    for i in range(n):
        p = np.poly1d([1])  # p = 1
        for j in range(n):
            if j != i:  # пропускаем j-ое
                p *= np.poly1d([1, -x[j]]) / (x[i] - x[j])  # p *= (X-Xj)/(Xi-Xj)
        polynom += y[i] * p  # polynom += P*Yi
    return polynom


# Разделенные разности
def DividedDifferences(x):
    n = len(x)
    diffs = [[None for j in range(n - i)] for i in range(n)]

    for i in range(n):
        diffs[i][0] = y[i]

    for j in range(1, n):
        for i in range(n - j):
            diffs[i][j] = (diffs[i + 1][j - 1] - diffs[i][j - 1]) / (x[i + j] - x[i])

    return diffs


# Многочлен Ньютона
def Newton(dots):
    n = len(dots)  # Число точек
    (x, y) = map(list, zip(*dots))  # Списки X и Y отдельно

    diffs = DividedDifferences(x)  # Разделенные разности
    polynom = np.poly1d([0])  # polynom = 0
    for i in range(n):
        p = np.poly1d([1])  # p = 1
        for j in range(i):
            p *= np.poly1d([1, -x[j]])  # p *= (X - Xj)
        polynom += p * diffs[0][i]  # polynom += p * fn(x0,..,xi)

    return polynom


# МНК при m == n
def Simple(dots):
    n = len(dots)
    (x, y) = map(list, zip(*dots))
    A = []
    for i in range(n):
        A.append([])
        for j in range(n):
            A[i].append(x[i] ** j)
    polynom = np.poly1d(np.linalg.solve(A, y)[::-1])
    return polynom


# Аппроксимация методом наименьших квадратов
def Squares(dots, m=None):
    n = len(dots) - 1
    if m is None:
        m = n
    assert 0 <= m <= n
    if m == n:
        return Simple(dots)

    (x, y) = map(list, zip(*dots))

    b = []
    for k in range(m + 1):
        s = 0
        for i in range(n + 1):
            s += y[i] * (x[i] ** (m - k))
        b.append(s)

    A = []
    for k in range(m + 1):
        A.append([])

        for j in range(m + 1):
            s = 0
            for i in range(n + 1):
                s += x[i] ** (2 * m - k - j)
            A[k].append(s)

    polynom = np.poly1d(np.linalg.solve(A, b))
    return polynom


# Общая погрешность
def get_error(method, dots):
    func = method(dots) - Squares(dots, 10)
    der = np.polyder(func)

    max_error = 0.0
    for root in np.roots(der):
        if x[0] <= root <= x[-1]:
            max_error = max(max_error, abs(np.polyval(func, root)))

    return max_error


dots = input()
(x, y) = map(list, zip(*dots))
print("(x,y) =", dots, "\n")

lagrange = Lagrange(dots)
print("Полином Лагранжа =")
print(lagrange, "\n")

newton = Newton(dots)
print("Полином Ньютона =")
print(newton, "\n")

squares = Squares(dots)
print("Полином МНК =")
print(squares, "\n")

xdot = 0.47
width = 25

print(f"Полином Лагранжа ({xdot}) =".ljust(width), lagrange(xd      ot))
print(f"Полином Ньютона ({xdot}) =".ljust(width), newton(xdot))
print(f"Молином МНК ({xdot}) =".ljust(width), squares(xdot))
# print(f"Молином МНК ({xdot}) =", "{:.4f}".format(squares(xdot)))

print("|Лагранж - Ньютон| =".ljust(width), abs(lagrange(xdot) - newton(xdot)))
print("|Лагранж - МНК| =".ljust(width), abs(lagrange(xdot) - squares(xdot)))
print("|Ньютон - МНК| =".ljust(width), abs(newton(xdot) - squares(xdot)))

print("Погрешность Лагранж: ".ljust(width), get_error(Lagrange, dots))
print("Погрешность Ньютон: ".ljust(width), get_error(Newton, dots))
# print(f"Inaccuracy({xdot}) = ", Inaccuracy(x, xdot))


plotdots = 10**4
plt.plot(x, y, "og", linewidth=5)

xplot = np.linspace(min(x), max(x), plotdots)

yplot = [squares(xdot) for xdot in xplot]
plt.plot(xplot, yplot, "r", linewidth=4)  # Красный

yplot = [lagrange(xdot) for xdot in xplot]
plt.plot(xplot, yplot, "b--", linewidth=4)  # Пунктир голубой

yplot = [newton(xdot) for xdot in xplot]
plt.plot(xplot, yplot, "m:", linewidth=4)  # Фиолетовый точками


plt.show()
