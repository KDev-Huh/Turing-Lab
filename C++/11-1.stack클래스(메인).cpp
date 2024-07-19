#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	STACK st1,st2(20, "st2"); // 객체

	cout << "st1의 크기: " << st1.size() << endl;
	cout << "st2의 크기: " << st2.size() << endl;

	{
		STACK st3(100, "st3");
	}
	

	st1.push(10);
	st1.push(20);
	st1.push(30);
	st1.push(40);
	st1.push(50);
	st1.push(60);
	st1.push(70);
	st1.push(80);
	st1.push(90);
	st1.push(100);

	cout << "st1의 크기: " << st1.size() << endl;


	while (!st1.isEmpty())
	{
		cout << st1.top() << ", ";
		st1.pop();
	}
	cout << "\b\b \n";
	cout << "st1의 크기: " << st1.size() << endl;

	cout << "st2의 크기: " << st2.size() << endl;
	st2.push(5);
	st2.push(15);
	st2.push(25);
	st2.push(35);
	st2.push(45);
	st2.push(55);
	st2.push(65);
	st2.push(75);
	st2.push(85);
	st2.push(95);
	st2.push(105);

	
	while (!st2.isEmpty())
	{
		cout << st2.top() << ", ";
		st2.pop();
	}
	cout << "\b\b \n";


	return 0;
}