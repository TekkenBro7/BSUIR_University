#include <iostream>
#include <string>

                           // Делал как всегда сам, посмотрите на количество попыток и их время отправки

long long answ(std::string arr)
{
	int n = arr.size();
	int mid = n / 2;
	int count = 0;
	int count1 = 0;
	if (n == 1)
	{
		return -1;
	}
	else if (n == 2 && arr[0] == arr[1])
	{
		return -1;
	}
	for (int i = 0; i <= mid; i++)
	{
		if (arr[i] == arr[n - i - 1])
		{
			count++;
		}
	}
	if (count == mid)
	{
		return n;
	}

	for (int i = 0; i <= mid; i++)
	{
		if (arr[i] == arr[n - i - 1])
		{
			count = 1;
		}
		if (arr[0] != arr[n - 1])
		{
			return n;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			count1++;
		}
	}
	if (count1 == n - 1)
	{
		return -1;
	}
	if (count == 1)
	{
		return n - 1;
	}
	if (count == 0)
	{
		return n;
	}
}

int main()
{
	std::string arr;
	getline(std::cin, arr);
	/*
	int n = arr.size();
	int mid = n / 2;
	int count = 0;
	int count1 = 0;
	if (n == 1)
	{
		std::cout << "-1";
		return 0;
	}
	else if (n == 2 && arr[0] == arr[1])
	{
		std::cout << "-1";
		return 0;
	}
	for (int i = 0; i <= mid; i++)  
	{
		if (arr[i] == arr[n - i - 1])
		{
			count++;
		}
	}
	if (count == mid)
	{
		std::cout << n;
		return 0;
	}

	for (int i = 0; i <= mid; i++)
	{
		if (arr[i] == arr[n - i - 1])
		{
			count = 1;
		}
		if (arr[0] != arr[n - 1])
		{
			std::cout << n;
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			count1++;
		}
	}
	if (count1 == n - 1)
	{
		std::cout << "-1";
		return 0;
	}
	if (count == 1)
	{
		std::cout << n - 1;
		return 0;
	}
	if (count == 0)
	{
		std::cout << n;
		return 0;
	}

	*/

	long long n;
	n = answ(arr);
	std::cout << n;


	/*

	if (n % 2 == 1)
	{
		for (i = 0; i <= mid; i++)
		{
			if (arr[i] != arr[n - i - 1] && i != mid)
			{
				count2++;
			}
			if (arr[i] == arr[n - 1 - i])
			{
				count++;
			}
			else if (arr[i] == arr[i + 1])
			{
				count1++;
			}

		}
	}
	else
	{
		for (i = 0; i <= mid; i++)
		{
			if (arr[i] != arr[n - i - 1] && i != mid)
			{
				count2++;
			}
			if (arr[i] == arr[n - 1 - i])
			{
				count++;
			}
			else if (arr[i] == arr[n - 1 - i] && arr[i] == arr[i + 1])
			{
				count1++;
			}


		}
	}
	if (arr[0] != arr[n - 1])
	{
		std::cout << n;
		return 0;
	}
	if (n % 2 == 1 && count2 == mid)
	{
		std::cout << n;
		return 0;
	}
	if (n % 2 == 0 && count2 == mid)
	{
		std::cout << n;
		return 0;
	}
	if (count1 == n / 2 && n % 2 == 0)
	{
		std::cout << "-1";
		return 0;
	}
	else if (count1 == mid + 1 && n % 2 == 1)
	{
		std::cout << "-1";
		return 0;
	}
	else
		std::cout << count;

	return 0;
}

// a b c d f

*/

	return 0;
}
