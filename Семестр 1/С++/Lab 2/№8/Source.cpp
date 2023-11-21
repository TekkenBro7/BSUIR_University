#include <iostream>
#include <cmath>

int main() {
    setlocale(LC_ALL, "ru");
    long double a, b, c, x, D, t1{}, t2{}, x1, x2, x3, x4, Q, p, q, A, B, Kef, t, pi = 3.14159265359;
    int variant;
    std::cout << "Выберите уравнение: " << '\n';
    std::cout << "ax^4 + bx^2 + c = 0 (1)" << '\n';
    std::cout << "ax^4 + bx^3 + cx^2 + bx + a = 0 (2)" << '\n';
    std::cout << "x^3 + px + q= 0 (3)" << '\n';
    std::cin >> variant;
    switch (variant) {
    case(1): {
        std::cout << "ax^4 + bx^2 + c = 0" << '\n';
        std::cout << "a, b, c: ";
        std::cin >> a >> b >> c;
        D = b * b - 4 * a * c;
        if (D < 0) {
            std::cout << "Нет корней" << '\n';
            break;
        }
        else
            if (a == 0 && b == 0 && c == 0)
            {
                std::cout << "X = R";
                break;
            }
            else if (a == b && b == 0 && c != 0) {
                std::cout << "Нет корней";
                break;
            }
            else if (a == 0 && b > 0 && c >= b) {
                std::cout << "Нет вещественных корней";
                break;
            }
            else if (a == 0 && b < 0 && c <= b) {
                std::cout << "Нет вещественных корней";
                break;
            }
            else if (a == 0 && b < 0 && c != 0) {
                x1 = sqrt(-c / b);
                x2 = -sqrt(-c / b);
                std::cout << "x1 = " << x1 << " " << "x2 = " << x2;
                break;
            }

        t1 = (-b + sqrt(D)) / (2 * a);
        t2 = (-b - sqrt(D)) / (2 * a);
        if (t1 > 0) {
            x = sqrt(t1);
            std::cout << "x1 = " << x << '\n';
            x = -sqrt(t1);
            std::cout << "x2 = " << x << '\n';
            return 0;
        }
        else if (t1 == 0) {
            std::cout << "x1 = " << 0 << " ";
        }
        if (t2 > 0) {
            x = sqrt(t2);
            std::cout << "x1 = " << x << " ";
            x = -sqrt(t2);
            std::cout << "x2 = " << x << " ";
            return 0;
        }
        else if (t2 == 0) {
            std::cout << "x1 = " << 0 << " ";
        }
        else if (t1 < 0 && t2 < 0)
            std::cout << "Нет решений";
        else 
            std::cout << "Нет решений";
        break;
    }
    case(2): {
        std::cout << "ax^4 + bx^3 + cx^2 + bx + a = 0" << '\n';
        std::cout << "a, b, c: ";
        std::cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
        {
            std::cout << "X = R ";
            break;
        }
        D = b * b - 4 * a * (-2 * a + c);
        if (D == 0)
        {
            t = -b / (2 * a);
        }
        else
            if (D < 0)
            {
                std::cout << "Нет корней";

            }
            else if (a == 0) {
                std::cout << "x = " << 0;
                D = c * c - 4 * b * b;
                if (D < 0) {
                    break;
                }
                else if (D == 0) {
                    x = -b / (2 * a);
                    std::cout << "x = " << x;
                    break;
                }
                else {
                    x1 = -b + sqrt(D) / (2 * a);
                    x2 = -b - sqrt(D) / (2 * a);
                    std::cout << "x1 =  " << x1 << "x2 = " << x2;
                }
                break;
            }
            else
                if (D > 0)
                {
                    t1 = (-b + sqrt(D)) / (2 * a);
                    t2 = (-b - sqrt(D)) / (2 * a);
                }
        if (t1 * t1 - 4 < 0 && t2 * t2 - 4 < 0)
        {
            std::cout << "Нет корней";
        }
        else
            if (t1 * t1 - 4 < 0)
            {
                x2 = (t2 + sqrt(t2 * t2 - 4)) / 2;
                x4 = (t2 - sqrt(t2 * t2 - 4)) / 2;
                std::cout << "Корни уравнения:" << '\n';
                std::cout << "x2 = " << x2 << " x4 = " << x4;
            }
            else
                if (t2 * t2 - 4 < 0)
                {
                    x1 = (t1 + sqrt(t1 * t1 - 4)) / 2;
                    x3 = (t1 - sqrt(t1 * t1 - 4)) / 2;
                    std::cout << "Корни уравнения:" << '\n';
                    std::cout << "x: " << x1 << " x: " << x3 << '\n';
                }
                else
                {
                    x1 = (t1 + sqrt(t1 * t1 - 4)) / 2;
                    x2 = (t2 + sqrt(t2 * t2 - 4)) / 2;
                    x3 = (t1 - sqrt(t1 * t1 - 4)) / 2;
                    x4 = (t2 - sqrt(t2 * t2 - 4)) / 2;

                    if (x1 != 0)
                    {
                        std::cout << "Корни уравнения:" << '\n';
                        std::cout << "x1 = " << x1 << '\n';
                    }
                    if (x2 != 0)
                    {
                        std::cout << "Корни уравнения:" << '\n';
                        std::cout << "x2 = " << x2 << '\n';
                    }
                    if (x3 != 0 and x3 != x1)
                    {
                        std::cout << "Корни уравнения:" << '\n';
                        std::cout << "x3 = " << x3 << '\n';
                    }
                    if (x4 != 0 and x4 != x2)
                    {
                        std::cout << "Корни уравнения:" << '\n';
                        std::cout << "x4 = " << x4 << '\n';
                    }

                }
        break;
    }
    case(3): {
        std::cout << "x^3 + px + q= 0" << '\n';
        std::cout << "p, q: ";
        std::cin >> p >> q;
        Q = powl(p / 3, 3) + powl(q / 2, 2);

        if (Q > 0)
        {
            A = cbrtl(-q / 2 + sqrt(Q));
            B = cbrtl(-q / 2 - sqrt(Q));
            x1 = A + B;
            std::cout << "Корни уравнения:" << '\n';
            std::cout << "x1 = " << x1 << '\n';
            return 0;
        }
        else
            if (Q == 0)
            {
                A = cbrtl(-q / 2 + sqrtl(Q));

                x1 = 2 * A;
                x2 = A;
                std::cout << "Корни уравнения:" << '\n';
                std::cout << "x1 = " << x1 << " x2 = " << x2 << '\n';
            }
            else
                if (Q < 0)
                {
                    Kef = acosl(-q / 2.0 * powl(3.0 / -p, 3.0 / 2.0));
                    x1 = 2.0 * sqrtl(-p / 3.0) * cosl(Kef / 3);
                    x2 = 2.0 * sqrtl(-p / 3.0) * cosl(Kef / 3.0 + (2.0 * pi / 3.0));
                    x3 = 2.0 * sqrtl(-p / 3.0) * cosl(Kef / 3.0 - (2.0 * pi / 3.0));
                    std::cout << "Корни уравнения:";
                    std::cout << "x1 = " << x1 << " x2 = " << x2 << " x3 = " << x3 << '\n';
                    break;
                }
    }
    default:
    {
        std::cout << "Ошибка";
        return 0;
    }
    }
    return 0;
}