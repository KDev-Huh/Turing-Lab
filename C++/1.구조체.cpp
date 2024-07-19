#include <stdio.h>
#include <math.h>

// sqrt(c) = 제곱근

double distance(int x1, int y1, int x2, int y2)
{
    int a,b;
    a = (x1 > x2) ? x1 - x2 : x2 - x1;
    b = (y1 > y2) ? y1 - y2 : y2 - y1;
    return sqrt(a * a + b * b);
}

int* ga;
int* gb;
int* gt;

void test()
{
    int k = 1000;
    int m = 2000;
}

#define CNT 7

//c++ =>참조에 의한 전달
void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}



int main()
{
    int xs[CNT] = { 7, 5, 7, -4, -3,-2, -2 };
    int ys[CNT] = { 8, 7, 2, -3, -2, 6, 8 };

    int x = 30, y = 20;

    swap(x, y);


    printf("x = %d, y = %d \n", x,y);




    return 0;
}