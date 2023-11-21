#include <iostream>
int main()
{
    int ROWS, COLS, sum = 0;
    bool left, up, right, down;
    std::cin >> ROWS >> COLS;
    int mat[100][100]{};
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            std::cin >> mat[i][j];
        }
    }
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            left = false;
            right = false;
            up = false;
            down = false;
            if (j - 1 < 0 || mat[i][j - 1] > mat[i][j])
                left = true;
            if ((j + 1 == COLS) || (mat[i][j + 1] > mat[i][j]))
                right = true;
            if ((i > 0 && mat[i - 1][j] > mat[i][j]) || (i - 1 < 0))
                up = true;
            if ((i + 1 == ROWS) || (mat[i + 1][j] > mat[i][j]))
                down = true;
            if (left && right && up && down)
                sum++;
        }
    }
    std::cout << sum << '\n';
    return 0;
}