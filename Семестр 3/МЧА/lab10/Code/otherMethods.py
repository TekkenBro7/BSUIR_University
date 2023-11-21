import numpy
from adamsMethod import pickStep, adams
from matplotlib import pyplot


def evaluate(h, left, right, f, eps):
    T, Y_exact = pickStep(left, right + h, f, step=h)
    adams_res = adams(T, h, f)
    difference = numpy.abs(adams_res - Y_exact)
    while max(difference) > eps:
        h /= 2
        T, Y_exact = pickStep(left, right + h, f, step=h)
        adams_res = adams(T, h, f)
        difference = numpy.abs(adams_res - Y_exact)

    return h, T, adams_res, Y_exact, difference


def solve(f, left, right, h=2, eps=0.001):
    h, T, Y_Adams3, Y_exact, error = evaluate(h, left, right, f, eps)
    print("Шаг:", h)
    print(f"Погрешность: {max(error)}\n")
    for it in range(0, len(T), 13):
        print(
            f"Точка {T[it]:.3f}: \n\tТочное значение - {Y_exact[it]:.3f},"
            f""
            f" Метод Адамса - {Y_Adams3[it]:.3f}\n\tРазница:{error[it]}"
        )

    pyplot.title("Green - exact; Blue - Adams")
    pyplot.plot(T, Y_exact, "g--")
    pyplot.plot(T, Y_Adams3, "b")
    pyplot.show()
    return
