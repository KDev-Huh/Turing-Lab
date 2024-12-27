#include "Bigint.h"
#include <cctype>
#include <stdexcept>

bool BigInt::valid()
{
	if (_value[0] != '+' and _value[0] != '-' and !isdigit(_value[0])) return false;

	for (int idx = 1; idx < _value.size(); idx++) {
		if (!isdigit(_value[idx])) return false;
	}
	return true;
}

BigInt::BigInt(const std::string& value)
	:_value(value)
{
	if (!valid())
		throw std::domain_error(value + "is not a number.");
}
BigInt::BigInt(const BigInt& big)	// 복사 생성자
	:_value(big._value)			// 다른 객체가 아니고 지금 만들고 있는 과정이라서 다른 객체에 접근가능
{
}

BigInt::BigInt(const char* value)
	:_value(value)
{
	if (!valid())
		throw std::domain_error(_value + "is not a number.");
}


void BigInt::value(const std::string& value)
{
	_value = value;
	if (!valid())
		throw std::domain_error(value + "is not a number.");
}
std::string BigInt::value() const
{
	return _value;
}

BigInt operator+(const BigInt& opr1, const BigInt& opr2)
{
	auto iter1 = opr1._value.crbegin();
	auto iter2 = opr2._value.crbegin();

	int carry = 0;

	std::string sint = "";

	while (iter1 < opr1._value.crend() and iter2 < opr2._value.crend())
	{
		int result = (*iter1 - '0' + *iter2 - '0') + carry;
		carry = result / 10;
		sint = std::to_string(result%10) + sint;

		iter1++;
		iter2++;
	}

	while (iter1 < opr1._value.crend())
	{
		int result = *iter1 - '0' + carry;
		carry = result / 10;
		sint = std::to_string(result % 10) + sint;
		iter1++;
	}

	while (iter2 < opr2._value.crend())
	{
		int result = *iter2 - '0' + carry;
		carry = result / 10;
		sint = std::to_string(result % 10) + sint;
		iter2++;
	}

	return BigInt(sint);
}