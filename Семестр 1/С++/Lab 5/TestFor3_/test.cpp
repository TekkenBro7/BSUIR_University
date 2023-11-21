#include "pch.h"

long long amount0(long long** arr, long long n, long long k, long long amount)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (arr[i][j] == 0)
            {
                amount++;
            }
        }
    }
    return amount;
}

TEST(TestCaseName_1)
{
    long long rows = 3, cols = 3, amount = 0;
    long long** arr = new long long* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new long long[cols];
    }
    arr[0][0] = 1; arr[0][1] = 2; arr[0][2] = 0; arr[1][0] = 4; arr[1][1] = 5; arr[1][2] = 6; arr[2][0] = 7; arr[2][1] = 8; arr[2][2] = 9;
    ASSERT_EQ(amount0(arr, rows, cols, amount), 1);
}
TEST(TestCaseName_2)
{
    long long rows = 2, cols = 2, amount = 2;
    long long** arr = new long long* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new long long[cols];
    }
    arr[0][0] = 1; arr[0][1] = 2; arr[1][0] = 4; arr[1][1] = 4;
    ASSERT_EQ(amount0(arr, rows, cols, amount), 2);
}
TEST(TestCaseName_3)
{
    long long rows = 1, cols = 1, amount = 1;
    long long** arr = new long long* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new long long[cols];
    }
    arr[0][0] = 1;
    ASSERT_EQ(amount0(arr, rows, cols, amount), 1);
}
