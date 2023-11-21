#include <iostream>
int main() 
{
	double X, Y, Z;
	std::cin >> X >> Y >> Z;
	if (X <= 0 or Y <= 0 or Z <= 0)
	{
		std::cout << "Error";
		return 0;
	}
	if (X + Y > Z && X + Z > Y && Y + Z > X)
	{
		std::cout << "YES";
		return 0;
	}
	else
	{
		std::cout << "NO";
		return 0;
	}
	return 0;
}


