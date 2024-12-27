#ifndef BIGINT_
#define _BIGINT_
#include <string>

class BigInt
{
public:
	BigInt(const std::string & = "");
	BigInt(const BigInt&);	// ���� ������
	BigInt(const char*);

	void value(const std::string&);
	std::string value() const;

	friend BigInt operator+(const BigInt&, const BigInt&);	// operator : ������ �����ε�
private:
	std::string _value;
	bool valid();
};

#endif