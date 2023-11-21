#include <iostream>
#include <string>

int NewSystem(int Desiaytichnoe)
{
	int SimvolsInMass = 0;
	int NewCifra;
	std::string mas;
	std::cin >> Desiaytichnoe;
	while (Desiaytichnoe > 0)
	{
		if (Desiaytichnoe % 3 != 0)
		{
			NewCifra = Desiaytichnoe % 3;
			mas.push_back(NewCifra);
			Desiaytichnoe = Desiaytichnoe / 3;
			SimvolsInMass++;
		}
		else
		{
			NewCifra = 3;
			mas.push_back(NewCifra);
			Desiaytichnoe = Desiaytichnoe / 3 - 1;
			SimvolsInMass++;
		}

		return SimvolsInMass;
	}
}

int main()
{
	int Desiaytichnoe;
	int SimvolsInMass = 0;
	int NewCifra;
	std::string mas;
	std::cin >> Desiaytichnoe;
	while (Desiaytichnoe > 0)
	{
		if (Desiaytichnoe % 3 != 0)
		{
			NewCifra = Desiaytichnoe % 3;
			mas.push_back(NewCifra);
			Desiaytichnoe = Desiaytichnoe / 3;
			SimvolsInMass++;
		}
		else
		{
			NewCifra = 3;
			mas.push_back(NewCifra);
			Desiaytichnoe = Desiaytichnoe / 3 - 1;
			SimvolsInMass++;
		}
	}
	for (int i = SimvolsInMass - 1; i > -1; i--)    // Надо выводыть в обратном порядке
	{
		std::cout << (int)mas[i];
	}
	return 0;
}