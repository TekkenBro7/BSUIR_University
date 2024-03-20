#include <iostream>

int main()
{
    __int8 A[8] = { 5, 9, 3, 14, 6, 10, 3, 8 };
    __int8 B[8] = { 3, 14, 11, 16, 12, 18, 5, 11 };
    __int8 C[8] = { 15, 11, 16, 21, 22, 25, 19, 24 };
    __int16 D[8] = { 10, 4, 7, 8, 10, 4, 11, 12 };
    __int16 F[8];

    __asm {
		// a + b * c - d
		
		movsd xmm0, [A] // запись значений в регистры
		movsd xmm1, [B]
		movsd xmm2, [C]
		movlpd xmm3, [D] 


		movhpd xmm3, [D + 8] // Расширение значений int8 до int16 (до 2 байт)


		pmovsxbw xmm0, xmm0 // Расширение значений int8 до int16 (до 2 байт)
		pmovsxbw xmm1, xmm1
		pmovsxbw xmm2, xmm2

		pmullw xmm1, xmm2
		
		paddd xmm0, xmm1
		
		psubd xmm0, xmm3

		movdqu[F], xmm0
    }

    std::cout << "Results of calculation F[i]: \n";
    for (int i = 0; i < 8; i++) {
        std::cout << "F[" << i << "] = " << F[i] << '\n';
    }
    return 0;
}