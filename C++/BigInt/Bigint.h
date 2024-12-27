#ifndef BIGINT_
#define _BIGINT_
#include <string>

class BigInt
{
public:
	BigInt(const std::string & = "");
	BigInt(const BigInt&);	// 복사 생성자
	BigInt(const char*);

	void value(const std::string&);
	std::string value() const;

	friend BigInt operator+(const BigInt&, const BigInt&);	// operator : 연산자 오버로딩
private:
	std::string _value;
	bool valid();
};

#endif