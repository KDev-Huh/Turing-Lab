#include "PQUEUE.hpp"


int main()
{
	PQueue<int> pq;

	pq.insert(100);
	pq.insert(200);
	pq.insert(50);
	pq.insert(75);
	pq.insert(60);
	pq.insert(90);
	pq.insert(110);

	pq.print();

	return 0;
}