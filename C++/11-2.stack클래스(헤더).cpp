#ifndef _STACK_H_	//중복되지 않게 (다른사람이랑 겹치지않게) 하기 위해 쓴다.
#define _STACK_H_

#include <string>

class STACK {
public: // 공공의
	// 멤버 함수
	
	STACK(); //기본 생성자

	STACK(int, std::string);	// 생성자 데이터 멤버 초기화 (매개변수를 가진 생성자)
	~STACK();	// 소멸자

	int top();	// 인터페이스 (데이터를 다룰수있는 것들)
	int size();
	bool isFull();
	void push(int);
	bool isEmpty();
	void pop();
private: // 개인의
	//  데이터 멤버
	int* data = 0;
	int tp;
	int capacity;
	std::string name;
};



#endif
