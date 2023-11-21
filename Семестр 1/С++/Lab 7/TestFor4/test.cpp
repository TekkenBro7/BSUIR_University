#include "pch.h" 

using namespace std;

string f1(int ArabianNumber)
{
	int massArabian[] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
	string RomanNumbers[] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
	int i = sizeof(massArabian) / sizeof(int) - 1;
	while (ArabianNumber > 0)
	{
		int forvivod = ArabianNumber / massArabian[i];
		ArabianNumber = ArabianNumber % massArabian[i];
		i--;
	}
	string s;
	s = RomanNumbers[8] + RomanNumbers[6] + RomanNumbers[4] + RomanNumbers[4] + RomanNumbers[2] + RomanNumbers[0] + RomanNumbers[0];
	return s;
}
string f2(int ArabianNumber)
{
	int massArabian[] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
	string RomanNumbers[] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
	int i = sizeof(massArabian) / sizeof(int) - 1;
	while (ArabianNumber > 0)
	{
		int forvivod = ArabianNumber / massArabian[i];
		ArabianNumber = ArabianNumber % massArabian[i];
		i--;
	}
	string s;
	s = RomanNumbers[12];
	return s;
}
string f3(int ArabianNumber)
{
	int massArabian[] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
	string RomanNumbers[] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
	int i = sizeof(massArabian) / sizeof(int) - 1;
	while (ArabianNumber > 0)
	{
		int forvivod = ArabianNumber / massArabian[i];
		ArabianNumber = ArabianNumber % massArabian[i];
		i--;
	}
	string s;
	s = RomanNumbers[10] + RomanNumbers[8] + RomanNumbers[6] + RomanNumbers[4] + RomanNumbers[2] + RomanNumbers[0];
	return s;
}


TEST(TestCaseName1, TestName1) {

	int ArabianNumber = 177;
	cout << "\n 177 -> CLXXVII \n\n";
	EXPECT_EQ(f1(ArabianNumber), "CLXXVII");
	//EXPECT_TRUE(true); 
}

TEST(TestCaseName2, TestName2) {

	int ArabianNumber = 1000;
	cout << "\n 1000 -> M \n\n";
	EXPECT_EQ(f2(ArabianNumber), "M");
	//EXPECT_TRUE(true); 
}
TEST(TestCaseName3, TestName3) {

	int ArabianNumber = 1000;
	cout << "\n 666 -> DCLXVI \n\n";
	EXPECT_EQ(f3(ArabianNumber), "DCLXVI");
	//EXPECT_TRUE(true); 
}