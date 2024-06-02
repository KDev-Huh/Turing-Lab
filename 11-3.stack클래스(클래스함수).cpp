#include "Stack.h"
#include <iostream>
#include <stdexcept>	
//표준 디렉터리에 있는 헤더파일

STACK::STACK()
	:capacity(10), tp(-1), data(0), name("none")// 초기화 리스트
{
	/*capacity = 10;
	tp = -1;*/
	data = new int[capacity];
}

STACK::STACK(int sz, std::string name)
	: capacity(sz), data(new int[capacity]), tp(-1), name(name) // 이렇게도 가능
{}

STACK::~STACK()
{
	std::cout << "Address of data before delete(): " + name + " : " << data << std::endl;

	delete [] data;
	data = 0;
	tp = -1;
	capacity = 0;

//	std::cout << "Address of data after delete():"  +name + " : "  << data << std::endl;
}

int STACK::top()
{
	if (isEmpty())
		throw std::out_of_range("Stack is empty.");

	return data[tp];
}

int STACK::size()
{
	return tp + 1;
}

bool STACK::isFull()
{
	return tp + 1 == capacity;
}


void STACK::push(int n)
{
	if (isFull())
		throw std::length_error("Stack is full.");
	data[++tp] = n;
}
bool STACK::isEmpty()	// 함수 시그니쳐 (함수의 헤더에서 반환 타입을 제외)
{
	return tp == -1;
}

void STACK::pop()
{
	if (isEmpty())
		throw std::length_error("Stack is empty.");

	tp--;
}