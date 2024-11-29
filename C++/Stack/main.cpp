#include <iostream>
#include "Stack.h"
#include <string>
#include <format>

int main()
{
	Stack<std::string> st;

	for (int i = 0; i < 20; i++)
		st.push(std::format("{}", i + 1));

	while (!st.isEmpty())
	{
		std::cout << st.top() << std::endl;
		st.pop();
	}

	return 0;
}