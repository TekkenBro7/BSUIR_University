import sympy
from diif import deriviativeFirst, deriviativeSecond, deriviativeSecond2
from int import (
    integralMiddleRectangleViaEstimation,
    integralTrapezoidViaEstimation,
    integralSimpsonViaEstimation,
)


def solve(f, left_border, right_border, middle_dot, int_precised):
    z = sympy.symbols("z")
    f1 = sympy.diff(f, z)
    f2 = sympy.diff(f1, z)
    f3 = sympy.diff(f2, z)
    f4 = sympy.diff(f3, z)

    def delta(new_diff, known_number=f1.subs(z, middle_dot).evalf()):
        return abs(new_diff - known_number)

    print(f"\nЗначение производной первого порядка: {f1.subs(z, middle_dot).evalf()}")
    d1 = deriviativeFirst(f, middle_dot, f2, f3)
    print(
        f"Значение производной первого порядка, полученное численными методами: {d1.evalf()}"
        f"\nОтклонение: {delta(d1.evalf())}"
    )

    print(f"\nЗначение производной второго порядка: {f2.subs(z, middle_dot).evalf()}")
    d2 = deriviativeSecond(f, middle_dot, f4).evalf()
    print(
        f"Значение производной второго порядка, полученное численными методами: {d2}"
        f"\nОтклонение: {delta(d2, f2.subs(z, middle_dot).evalf())}"
    )
    d2 = deriviativeSecond2(f, middle_dot, f2, f4).evalf()
    print(
        f"Значение производной второго порядка, полученное численными методами(2-й способ): {d2}"
        f"\nОтклонение: {delta(d2, f2.subs(z, middle_dot).evalf())}"
    )

    print(f"\nОжидаемое значение интеграла: {int_precised}")
    int_rect = integralMiddleRectangleViaEstimation(f, left_border, right_border)
    print(
        f"Метод прямоугольников: {int_rect}\nОтклонение: {delta(int_rect, int_precised)}"
    )
    int_trap = integralTrapezoidViaEstimation(f, left_border, right_border)
    print(f"Метод трапеций: {int_trap}\nОтклонение: {delta(int_trap, int_precised)}")
    int_simp = integralSimpsonViaEstimation(f, left_border, right_border)
    print(f"Метод Симпсона: {int_simp}\nОтклонение: {delta(int_simp, int_precised)}")
    return
