import numpy
from scipy import integrate


def pickStep(left, right, f, step):
    T = numpy.arange(left, right, step)
    Y = rungekutta(T, f)
    return (T, Y)


def rungekutta(T, f):
    Y0 = numpy.array([0])
    r = (
        integrate.ode(f)
        .set_integrator("dopri5", atol=0.0001)
        .set_initial_value(Y0, T[0])
    )  # выражение интеграла (метод рунге-кутта)
    Y = numpy.zeros((len(T), len(Y0)))
    Y[0] = Y0
    for it in range(1, len(T)):
        Y[it] = r.integrate(T[it])  # подстановка
        # if not r.successful():
        #    raise RuntimeError("Нельзя интегрировать")
    return Y[:, 0]


def adams(T, h, f):
    Y0 = numpy.array([0])
    Y = numpy.zeros((len(T) + 2, 1))
    result = numpy.zeros((len(T), 1))

    extra_y = rungekutta([T[0], T[0] - h, T[0] + h], f)
    Y[0] = extra_y[1]
    Y[1] = Y0

    for it in range(2, len(T) + 1):
        Y[it] = Y[it - 1] + h * (
            1.5 * f(T[it - 1], Y[it - 1]) - 0.5 * f(T[it - 2], Y[it - 2])
        )
    for it in range(0, len(T)):
        result[it] = Y[it + 1]
    return result[:, 0]
