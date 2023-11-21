import math
import sympy
import numpy

epsilon = 0.000001
z = sympy.symbols("z")
# integral = 1.6893633


def intMiddleRectangle(f, l, r, n):
    h = (r - l) / n
    x = l + h / 2
    s = 0.0
    while x < r:
        s += f.subs(z, x) * h
        x += h
    return s


def integralTrapezoid(f, l, r, n):
    h = (r - l) / n
    x = l + h / 2
    s = 0.0
    while x < r:
        s += ((f.subs(z, x - h / 2) + f.subs(z, x + h / 2)) / 2) * h
        x += h
    return s


def integralSimpson(f, l, r, n):
    h = (r - l) / n
    x = l + h / 2
    s = 0.0
    while x < r:
        fa = f.subs(z, x - h / 2)
        fm = f.subs(z, x)
        fb = f.subs(z, x + h / 2)
        s += (fa + 4 * fm + fb) * h / 6
        x += h
    return s


def integralRandSegments(method, f, l, r, epsilon=0.000001):
    left_coeff, right_coeff = 1 / 3, 1 / 2
    h_prev = r - l
    ans_prev = method(f, l, r, 1)
    while True:
        h_new = h_prev * (left_coeff + (right_coeff - left_coeff) * numpy.random.rand())
        n = math.floor((r - l) / h_new)
        m = l + h_new * n
        ans_new = method(f, l, m, n) + method(f, m, r, 1)
        if abs(ans_new - ans_prev) < epsilon:
            print("\nЧисло итераций:", n)
            return ans_new
        ans_prev = ans_new
        h_prev = h_new


def integralMiddleRectangleViaEstimation(f, l, r, epsinon=0.000001, m2deLR=0):
    if m2deLR > 0.0:
        M2 = m2deLR
        h = (24 * epsinon / (r - l) / M2) ** (1 / 2)
        n = numpy.ceil((r - l) / h)
        return intMiddleRectangle(f, l, r, n)
    else:
        return integralRandSegments(intMiddleRectangle, f, l, r)


def integralTrapezoidViaEstimation(f, l, r, epsinon=0.000001, m2deLR=0):
    if m2deLR > 0.0:
        M2 = m2deLR
        h = (12 * epsinon / (r - l) / M2) ** (1 / 2)
        n = numpy.ceil((r - l) / h)
        return integralTrapezoid(f, l, r, n)
    else:
        return integralRandSegments(integralTrapezoid, f, l, r)


def integralSimpsonViaEstimation(f, l, r, epsinon=0.000001, m4deLR=0):
    if m4deLR > 0.0:
        M4 = m4deLR
        h = (180 * epsinon / (r - l) / M4) ** (1 / 4)
        n = numpy.ceil((r - l) / h)
        return integralSimpson(f, l, r, n)
    else:
        return integralRandSegments(integralSimpson, f, l, r)
