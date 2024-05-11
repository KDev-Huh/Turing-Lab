#include <iostream>
#include <vector>

using namespace std;

void print(const vector<vector<int>> &board)
{
    const int row = board.size();
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < 10; c++)
        {
            printf("%3d ", board[r][c]);
        }
        printf("\n");
    }
}

int fellUpperTriangle(std::vector<std::vector<int>>& board)
{
    int g = 0;
    int value = 1;
    int row = 0, col = 0;
    const int crow = board.size();

    while (g < crow)
    {
        row = g;
        while (row >= 0)
        {
            board[row][g - row] = value++;
            row--;
        }
        g++;
    }

    return value;
}

int fillLowerTriangle(std::vector<std::vector<int>>& board, int svalue)
{
    const int crow = board.size();
    int g = crow;
    int row;
    int col;

    while (g <= crow * 2 - 2)
    {
        row = crow - 1;
        col = g - row;

        while (col <= crow -1)
        {
            board[row][col] = svalue;
            svalue++;
            row--;
            col++;
        }
        g++;
    }
    return svalue;
}


int main()
{
    //int board[10][10] = { 0 };
    std::vector<std::vector<int>> board(10, std::vector<int>(10, { 0 }));
    int svalue;

    svalue=fellUpperTriangle(board);
    fillLowerTriangle(board, svalue);

    print(board);

    /*for (i = 0; i < 10; i++)
    {
        x += c;
        for (j = 0; j <10; j++) {
            y += x+j;
            if (x+j > 10)
            {
                y -=m-1;
                m++;
            }
            printf("%d ", y);
        }
        y = 0;
        m = 1;
        c++;
        printf("\n");
    }*/



    return 0;
}