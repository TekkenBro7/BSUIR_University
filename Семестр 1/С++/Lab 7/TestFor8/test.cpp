#include "pch.h"

int NewSystem(int Desiaytichnoe)
{
	int SimvolsInMass = 0;
	int NewCifra;
	std::string mas;
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

	return SimvolsInMass;
}

TEST(TestCaseName1, TestName1)
{
	int Desiaytichnoe = 6;
	ASSERT_EQ(NewSystem(Desiaytichnoe), 2);
}

TEST(TestCaseName2, TestName2)
{
	int Desiaytichnoe = 1;
	ASSERT_EQ(NewSystem(Desiaytichnoe), 1);
}

TEST(TestCaseName3, TestName3)
{
	int Desiaytichnoe = 21;
	ASSERT_EQ(NewSystem(Desiaytichnoe), 3);
}
