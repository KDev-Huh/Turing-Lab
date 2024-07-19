#include <iostream> //stdio.h
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int x;
    int y;
    struct ip{
        double dx;
        double dy;
    } ipt1, ipt2;
} Point;

const int COUNT = 10;

void print(const vector<Point>& pts)
{
    for (auto pt : pts) //auto 컴파일러가 자동으로 Point 바꿔준다.
    {
        cout << "(" << pt.x << "," << pt.y << "), ";
    }
        cout << "\b\b  " << endl;
}

int main()
{
    //vector<Point> pts = {
    // {5,9},{-3,4},{-5,6},{12,13},{0,0},
    // {-8,11},{13,-5},{7,4},{6,9}, {-7,-7}
    //};
    //
    //vector<int> ns = { 3,4,10,-4,8,38,45,84,93,91,66,23,23 };

    //sort(pts.begin(), pts.end(),
    // [](Point pt1, Point pt2) {return pt1.x <= pt2.x; } // 람다 함수  []는 외부의 것을 자기것처럼 쓸때 [a]는 밖에 a를 쓰겠다는것(캡쳐)
    //);
    //print(pts);

    //sort(ns.begin(), ns.end());

    //for (auto n : ns)
    //{
    // cout << n << " ";
    //}

    Point pt1 = { 30,50 };

    pt1.ipt1.dx = 203.424;
    pt1.ipt2.dy = 2935.234232;


    Point* ppt1 = &pt1;
    (*ppt1).x = 80; //*ppt1.x X *(ppt1.x) 이런식으로 되서 ppt주소의 .x라는 말이라서 말이 안됨

    ppt1->y = 990; // == (*ppt1).y

    printf("pt1.x = %d\n", pt1.x);
    printf("pt1.y = %d\n", pt1.y);
    printf("pt1.ipt1.dx = %llf\n", pt1.ipt1.dx);
    printf("pt1.ipt2.dy = %llf\n", ppt1->ipt2.dy);

    return 0;
}