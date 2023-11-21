#include <iostream>
#include <string>

using namespace std;

int main()
{
    int ArabianNumber;
    std::cin >> ArabianNumber;
    int massArabian[] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
    string RomanNumbers[] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
    int i = sizeof(massArabian) / sizeof(int) - 1;
    while (ArabianNumber > 0)
    {
        int forvivod = ArabianNumber / massArabian[i];
        ArabianNumber = ArabianNumber % massArabian[i];
        while (forvivod-- != 0)                              // Типо повтореня (3 - III)
        {
            cout << RomanNumbers[i];
        }
        i--;
    }

    return 0;
}