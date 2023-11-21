#include <iostream>
#include "Header.h"
#include <initializer_list>


int main()
{
	setlocale(LC_ALL, "ru");
	Vector<int> arr;
//	arr = { 1, 2, 3, 4 };
	Vector<int> a;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	
	arr[1] = 123;

	Vector<int>::iterator it = Vector<int>::iterator(arr.begin());
	Vector<int>::iterator it1 = Vector<int>::iterator(arr.end());
	for (it; it != it1; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << '\n';
	std::cout << '\n';
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(6);
	for (it; it != it1; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << '\n';
	std::cout << '\n';
	//arr.print();
	
	std::cout << *it1;

	
	std::cout << '\n';

	std::cout << '\n' << '\n';
	arr.push_back(1499);
	arr.push_back(1499);
	arr.push_back(1499);
	std::cout << '\n';
	arr.print();
	std::cout << "\n\n\n";




	arr.print();
	std::cout << "\n\n\n";



	for (it; it != it1; it++)
	{
		std::cout << *it << " пкуп ";
	}
	//	it = Vector<int>::iterator(arr.rbegin());
	//	it1 = Vector<int>::iterator(arr.rend());
	std::cout << '\n';
	for (it; it != it1; it--)
	{
		std::cout << *it << "  ";
	}
	std::cout << '\n';
	std::cout << arr.capacity();
	std::cout << '\n';
	arr.print();
	std::cout << '\n';
	std::cout << '\n';
	Vector<int> aa;
	aa.push_back(4);
	aa.push_back(43);
	aa.push_back(123);

	//	Vector<int>::Iterator it2 = Vector<int>::Iterator(arr.rbegin());
	//	Vector<int>::Iterator it3 = Vector<int>::Iterator(arr.rend());

	//	for (it2; it2 != it3; it2--)
	//	{
	//		cout << *it2 << "  ";
	//	}

	std::cout << '\n';
	std::cout << '\n';
	arr.print();
	std::cout << '\n';
	std::cout << '\n';
	std::cout << arr.back();
	std::cout << '\n';
	//	arr.back() = 4;
	std::cout << arr.back();
	std::cout << '\n';

	std::cout << '\n';
	std::cout << '\n';
	std::cout << arr.at(1);
	std::cout << '\n';
	arr.at(1) = 4;
	std::cout << arr.at(1);
	std::cout << '\n';

	std::cout << '\n';
	std::cout << '\n';
	std::cout << arr.front();
	std::cout << '\n';
	arr.front() = 4;
	std::cout << arr.front();
	std::cout << '\n';

	std::cout << '\n';
	std::cout << '\n';
	*arr.data() = 10;
	std::cout << *arr.data();
	std::cout << '\n';
	std::cout << '\n';
	Vector<int> arr1;
	arr1.push_back(100);
	arr1.push_back(500);
	arr1.push_back(600);
	//	arr.swap(arr1);
	arr.pop_back();
	arr.print();
	std::cout << '\n';
	arr.print();
	std::cout << '\n';
	std::cout << '\n' << arr.max_size();
	//	cout << '\n' << (it == it1);
	//	cout << '\n' << (it != it1);

	return 0;
}