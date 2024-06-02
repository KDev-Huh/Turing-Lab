#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct _student {
    int id;
    int kor;
    int math;
    int eng;
    int tot;
    int rank;
}Student;

void printNums(Student nums[], int n)
{
    printf(" ID 국어 수학 영어 총점 등수\n");
    printf("==========================\n");
    for (int i = 0; i < n; i++)
    {
        printf("{%3d, %3d, %3d, %3d, %3d, %2d}\n",
        nums[i].id, nums[i].kor, nums[i].math, nums[i].eng, nums[i].tot, nums[i].rank);
    }

}

void swap(int& x, int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void bubble(Student nums[], int len)
{
    for (int i = 1; i <= len; i++)
    {
        bool flag = false;
        for (int j = 0; j < len - i; j++)
        {
            if (nums[j].tot < nums[j + 1].tot)
            {
                swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
    //cout << i <<endl;
    }
}

void evalRank(Student nums[], int len)
{
    bubble(nums, len);
    int rank = 0; //현재 등수
    int ptot = 900; //이전 총점
    int srank = 0; //동점자 수

    for (int i = 0; i < len; i++)
    {
        if (nums[i].tot == ptot)
        {
            srank++;
        }
        else
        {
            rank = rank + srank + 1;
            srank = 0;
        }

        ptot = nums[i].tot;
        nums[i].rank = rank;
    }
}

int main()
{
    Student nums[100];
    srand(time(0));

    for (int i = 0; i < 100; i++)
    {
        nums[i].id = i+1;
        nums[i].kor = rand() % 101;     // %101을 해주는 이유는 랜덤 수들을 100점 이하로 맞추기 위해서다.
        nums[i].math = rand() % 101;
        nums[i].eng = rand() % 101;
        nums[i].tot = nums[i].kor + nums[i].math + nums[i].eng;
        nums[i].rank = 0;
    }

    evalRank(nums, 100);
    //bubble(nums, 100);
    printNums(nums, 100);


    return 0;
}