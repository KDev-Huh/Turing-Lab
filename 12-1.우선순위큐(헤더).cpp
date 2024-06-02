#ifndef _P_QUEUE_HPP_
#define _P_QUEUE_HPP_

#include <vector>
#include <stdexcept>
#include <iostream>


template <typename T>
class PQueue {
public:
	bool isFull();
	PQueue(int n = 100);
	void insert(T);
	void print();
private:
	std::vector<T> ptree;
	int size;
	int last;
};

template <typename T>
PQueue<T>::PQueue(int sz)
	:size(sz), last(0)
{
	ptree.resize(sz, -1);
}

template <typename T>
bool PQueue<T>::isFull()
{
	return last >= size;
}

template <typename T>
void PQueue<T>::insert(T v)
{
	if (isFull())
		throw std::out_of_range("Stack is full.");

	int i = ++last;

	while (i != 1 && v > ptree[i / 2])
	{
		ptree[i] = ptree[i / 2];
		i /= 2;
	}

	ptree[i] = v;
}

template <typename T>
void PQueue<T>::print()
{
	for (auto v : ptree)
	{
		if(v!=-1)
			std::cout << v << " ";
	}
}

#endif