
#include "pch.h"
std::string Test(std::string* lots_of_A, long long a, std::string* lots_of_B, long long b, long long k_bit, long long input_number, long long& all_numbers);
bool Google(std::string lots_of_A, long long k_bit);

TEST(Test_1)
{
    long long all_numbers = 0;
    long long input_number;
    input_number = 10000;

    std::string* lots_of_A = new std::string[1];
    std::string* lots_of_B = new std::string[1];
    lots_of_A[0] = "0";
    lots_of_B[0] = "";


    ASSERT_EQ(Test(lots_of_A, 1, lots_of_B, 1, 1, input_number, all_numbers), "11001000000011100110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
}
TEST(Test_2)
{
    long long all_numbers = 0;
    long long input_number;
    input_number = 0;

    std::string* lots_of_A = new std::string[1];
    std::string* lots_of_B = new std::string[1];
    lots_of_A[0] = "0";
    lots_of_B[0] = "";


    ASSERT_EQ(Test(lots_of_A, 1, lots_of_B, 1, 1, input_number, all_numbers), "0");
}


std::string Test(std::string* lots_of_A, long long a, std::string* lots_of_B, long long b, long long k_bit, long long input_number, long long& all_numbers)
{
    //A - for all nums, B - for nums that we can use in future thats why we check k bit 
    std::string* holds_all_newA = new std::string[1000];
    std::string* holds_reuse_newB = new std::string[1000];
    bool check_true = 0;

    long long new_A_index = 0, new_B_index = 0;

    for (int i = 0; i < a; i++)
    {
        long long length_of_A = lots_of_A[i].length();
        check_true = Google(lots_of_A[i], k_bit);

        if (check_true)
        {
            holds_all_newA[new_A_index] = lots_of_A[i];
            new_A_index++;

            if (k_bit > length_of_A)
            {
                lots_of_A[i].insert(0, k_bit - length_of_A - 1, '0');
            }
            if (lots_of_A[i] == "0" && k_bit == 1)
            {
                holds_reuse_newB[new_B_index] = "1";

            }
            if (!(lots_of_A[i] == "0" && k_bit == 1))
            {
                holds_reuse_newB[new_B_index] = '1' + lots_of_A[i];

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
        if (k_bit == 1)
        {
            break;
        }

        long long lB = lots_of_B[i].length();
        check_true = Google(lots_of_B[i], k_bit);

        if (check_true)
        {
            holds_all_newA[new_A_index] = lots_of_B[i];
            new_A_index++;

            if (lots_of_B[i] == "0" && k_bit == 1)
            {
                holds_reuse_newB[new_B_index] = "1";
            }
            else if (!(lots_of_B[i] == "0" && k_bit == 1))
            {
                holds_reuse_newB[new_B_index] = '1' + lots_of_B[i];
            }

            new_B_index++;
            all_numbers++;

            if (all_numbers == input_number)
            {
                return holds_reuse_newB[new_B_index - 1];
            }
        }
    }
    return Test(holds_all_newA, new_A_index, holds_reuse_newB, new_B_index, k_bit + 1, input_number, all_numbers);
}
bool Google(std::string lots_of_A, long long k_bit)
{
    std::string lots_of_B;
    long long reversed_k = 0;

    long long length_A = lots_of_A.length();
    long long  length_B = lots_of_B.length();

    while (length_A > 0)
    {
        lots_of_B = (char)(((lots_of_A[length_A - 1] - 48) % 2) + 48) + lots_of_B;
        reversed_k++;

        for (long long i = 0; i < length_A - 1; i++)
        {
            lots_of_A[i + 1] += ((lots_of_A[i] - 48) % 2) * 10;
            lots_of_A[i] = (lots_of_A[i] - 48) / 2 + 48;
        }

        lots_of_A[length_A - 1] = ((lots_of_A[length_A - 1] - 48) / 2) + 48;

        while (lots_of_A[0] == '0')
        {
            lots_of_A.erase(0, 1);
        }
        length_A = lots_of_A.length();

        if (reversed_k == k_bit)
        {
            return (lots_of_B[0] == 48);
        }
    }
    return true;
}