#include <iostream>
#include "conio.h"

int main()
{
    __int8 A[8] = { 5, 9, 3, 14, 6, 10, 3, 8 };
    __int8 B[8] = { 3, 14, 11, 16, 12, 18, 5, 11 };
    __int8 C[8] = { 15, 11, 16, 21, 22, 25, 19, 24 };
    __int16 D[8] = { 10, 4, 7, 8, 10, 4, 11, 12 };
    __int16 F[8];

    __asm {
        movq mm0, [A]
        movq mm1, [B]
        movq mm2, [C]
        movq mm3, [D]

        punpcklbw mm4, mm0; Распаковать нижние 4 байта в mm4
        punpckhbw mm5, mm0; Распаковать верхние 4 байта в mm5

        pxor mm0, mm0; Очищаем регистры

        punpcklbw mm6, mm1; Распаковать нижние 4 байта в mm6
        punpckhbw mm7, mm1; Распаковать верхние 4 байта в mm7

        pxor mm1, mm1

        punpcklbw mm0, mm2; Распаковать нижние 4 байта в mm0
        punpckhbw mm1, mm2; Распаковать верхние 4 байта в mm1

        pxor mm2, mm2; Очищаем регистры

        movq mm2, [D + 8]; Записываем в mm2 вторую половину D

        psrlw mm0, 8; Смещаем на 8 чтобы потом умножение работало корректно
        psrlw mm1, 8;
        psrlw mm4, 8
            psrlw mm6, 8
            psrlw mm5, 8
            psrlw mm7, 8

            paddsw mm4, mm6
            pxor mm6, mm6
            movq mm6, mm4

            pmullw mm4, mm0; Умножаем верхнюю часть первой половины чисел
            pmulhw mm6, mm0

            paddsw mm6, mm4

            paddsw mm6, mm3  // ласт сложение
            movq[F], mm6 // Добавляем первые 4 числа в результат


            paddsw mm5, mm7
            pxor mm7, mm7
            movq mm7, mm5

            pmullw mm7, mm1
            pmulhw mm5, mm1

            paddsw mm7, mm5

            paddsw mm7, mm2     // ласт сложение

            movq[F + 8], mm7 // Добавляем последние 4 числа в результат
    }

    std::cout << "Results of calculation F[i]: \n";
    for (int i = 0; i < 8; ++i) {
        std::cout << "F[" << i << "] = " << F[i] << '\n';
    }
    return 0;
}