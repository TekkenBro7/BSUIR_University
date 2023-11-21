#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::string Test(std::string* A, long long a, std::string* B, long long b, long long bit, long long input_number, long long& all_numbers);
bool bits(string el, int bit);
bool Google(std::string A, long long bit);
string mainresheniye(vector<string> a, vector<string> b, int& n);

int main()
{
	int number;
	cin >> number;
	if (number == 1)
	{
		cout << "1";
		return 0;
	}
	else
	{
		number--;
		vector<string> a = { "0" }, b = { "1" };
		cout << mainresheniye(a, b, number);
	}
}

std::string Test(std::string* A, long long a, std::string* B, long long b, long long bit, long long input_number, long long& all_numbers)
{
    //A - for all nums, B - for nums that we can use in future thats why we check k bit 
    std::string* holds_all_newA = new std::string[1000];
    std::string* holds_reuse_newB = new std::string[1000];
    bool check_true = 0;

    long long new_A_index = 0, new_B_index = 0;

    for (int i = 0; i < a; i++)
    {
        long long length_of_A = A[i].length();
        check_true = Google(A[i], bit);

        if (check_true)
        {
            holds_all_newA[new_A_index] = A[i];
            new_A_index++;

            if (bit > length_of_A)
            {
                A[i].insert(0, bit - length_of_A - 1, '0');
            }
            if (A[i] == "0" && bit == 1)
            {
                holds_reuse_newB[new_B_index] = "1";

            }
            if (!(A[i] == "0" && bit == 1))
            {
                holds_reuse_newB[new_B_index] = '1' + A[i];

            }

            all_numbers++;
            new_B_index++;

            if (all_numbers == input_number)
            {
                return holds_reuse_newB[new_B_index - 1];
            }
        }
    }

    for (int i = 0; i < b; i++)
    {
        if (bit == 1)
        {
            break;
        }

        long long lB = B[i].length();
        check_true = Google(B[i], bit);

        if (check_true)
        {
            holds_all_newA[new_A_index] = B[i];
            new_A_index++;

            if (B[i] == "0" && bit == 1)
            {
                holds_reuse_newB[new_B_index] = "1";
            }
            else if (!(B[i] == "0" && bit == 1))
            {
                holds_reuse_newB[new_B_index] = '1' + B[i];
            }

            new_B_index++;
            all_numbers++;

            if (all_numbers == input_number)
            {
                return holds_reuse_newB[new_B_index - 1];
            }
        }
    }
    return Test(holds_all_newA, new_A_index, holds_reuse_newB, new_B_index, bit + 1, input_number, all_numbers);
}
bool Google(std::string A, long long bit)
{
    std::string lots_of_B;
    long long reversed_k = 0;

    long long length_A = A.length();
    long long  length_B = lots_of_B.length();

    while (length_A > 0)
    {
        lots_of_B = (char)(((A[length_A - 1] - 48) % 2) + 48) + lots_of_B;
        reversed_k++;

        for (long long i = 0; i < length_A - 1; i++)
        {
            A[i + 1] += ((A[i] - 48) % 2) * 10;
            A[i] = (A[i] - 48) / 2 + 48;
        }

        A[length_A - 1] = ((A[length_A - 1] - 48) / 2) + 48;

        while (A[0] == '0')
        {
            A.erase(0, 1);
        }
        length_A = A.length();

        if (reversed_k == bit)
        {
            return (lots_of_B[0] == 48);
        }
    }
    return true;
}


int k = 1;
bool bits(string s1, int bit) 
{
	int delitel = 0;
	for (int i = 0; i < bit; i++) 
	{
		if (s1 == "0" || s1 == "")
		{
			return true;
		}
		delitel = 0;
		for (int j = 0; j < s1.size(); j++)
		{
			int dopolnit = (int)s1[j] - 48 + delitel * 10;
			s1[j] = dopolnit / 2 + 48;
			delitel = dopolnit % 2;
		}
		if (s1[0] == '0') 
		{
			s1.erase(0, 1);
		}
	}
	if (delitel == 1)
	{
		return false;
	}
	return true;
}
string mainresheniye(vector<string> a, vector<string> b, int& number)
{
	vector<string> str1, str2;
	string dop = "1";
	dop.insert(1, k, '0');
	for (int i = 0; i < a.size(); i++)
	{
		if (bits(a[i], k + 1))
		{
			str1.push_back(a[i]);
			string str3 = a[i]; str3.insert(0, 1, '1'); 
			str3.insert(1, k - a[i].size(), '0');
			str2.push_back(str3);
			if (number == 1) 
			{
				return 	str2[str2.size() - 1];
			}
			number--;
		}
	}
	for (int i = 0; i < b.size(); i++) 
	{
		if (bits(b[i], k + 1)) 
		{
			str1.push_back(b[i]);
			string add = b[i]; add.insert(0, 1, '1'); add.insert(1, k - b[i].size(), '0');
			str2.push_back(add);
			if (number == 1)
			{
				return str2[str2.size() - 1];
			}
			number--;
		}
	}
	k++;
	return mainresheniye(str1, str2, number);
}