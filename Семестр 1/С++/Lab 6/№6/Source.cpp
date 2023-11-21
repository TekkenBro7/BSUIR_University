#include <iostream>
#include <string>


long long answ(std::string arr)
{
	long long chislitel = 1, n = arr.size();
	for (int i = 1; i <= arr.size(); i++)
	{
		chislitel *= i;
	}
	for (int i = 0; i < n; i++)
	{
		long long count = 1;
		for (int k = i + 1; k < n; k++)
		{
			if (arr[i] == arr[k])
			{
				count++;
			}
		}
		chislitel /= count;
	}

	return chislitel;
}

int main()
{
	std::string arr;
	getline(std::cin, arr);
	long long otvet = answ(arr);
	std::cout << otvet;

	return 0;
}
