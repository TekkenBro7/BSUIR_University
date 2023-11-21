#include <iostream>
#include <string>

int main()
{
	int rank;
	std::string num;
	std::cin >> num >> rank;
	int sum = num.length();
	int count = 0;
	int* array = new int[sum];
	for (int i = 0; i < sum; i++)
	{
		array[i] = num[i];
		int j = 0;
		while (j < i && array[j] != array[i]) j++;
		if (i == j)
			count++;
	}
	std::cout << count << '\n';
	for (int i = sum; i > 0; i--)
	{
		if (array[rank - 1] == array[i - 1])
			std::cout << sum - i << " ";
	}
	delete[] array;
	return 0;
}