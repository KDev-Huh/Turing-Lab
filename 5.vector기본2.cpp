#include <iostream>
#include <vector>

using namespace std;

void print(const vector<vector<int>>& board)
{
    for (auto vec : board) //너가 자료형 아니까 알아서 넣어줘
    {
        for (auto v : vec)
        {
            printf("%3d", v); //-는 왼쪽 정렬 그냥은 오른쪽 정렬 자리수 맞춰주기
        }
        printf("\n");
    }
}

void rotate(const vector<vector<int>>& org, vector <vector<int>>& dest)
{
    const int SIZE = org.size();
    for (int r = 0; r <SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            dest[SIZE - c - 1][r] = org[r][c];
        }
    }
}
int main()
{
    vector<vector<int>> org(5, vector<int>(5, { 0 }));
    vector<vector<int>> dest(5, vector<int>(5, { 0 }));

    int value = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            org[i][j] = value++;
        }
    }

    rotate(org, dest);

    print(dest);

    return 0;
}