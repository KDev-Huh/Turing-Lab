#include "Fract.h"
#include <iostream>

int Fract::gcd()
{
	if (numer > denom)
		return rgcd(numer, denom);
	else
		return rgcd(denom, numer);
}

int Fract::rgcd(int a, int b)
{
	if (b == 0)
		return a;

	return rgcd(b, a % b);
	int im = a;
	a = b;
	b = im % a;
	return rgcd(a, b);
}

void Fract::normalize()
{
	int g = gcd();
	denom /= g;
	numer /= g;

	if (denom < 0)
	{
		denom *= -1;
		numer *= -1;
	}

}

void Fract::print()
{
	std::cout << numer << "/" << denom;
}

std::ostream& operator<<(std::ostream& os, const Fract& fr)
{
	os << fr.numer << "/" << fr.denom;

	return os;
}

std::istream& operator>>(std::istream& is, Fract& fr)
{
	is >> fr.numer >> fr.denom;
	fr.normalize();
	return is;
}

Fract operator*(const Fract& fr1, const Fract& fr2)
{
	return Fract(fr2.numer * fr1.numer, fr1.denom * fr2.denom);
}

Fract operator+(const Fract& fr1, const Fract& fr2)
{
	return Fract(fr2.denom * fr1.numer + fr1.denom * fr2.numer, fr1.denom * fr2.denom);
}

Fract operator-(const Fract& fr1, const Fract& fr2)
{
	return Fract(fr2.denom * fr1.numer - fr1.denom * fr2.numer, fr1.denom * fr2.denom);
}

Fract operator/(const Fract& fr1, const Fract& fr2)
{
	return Fract(fr2.denom * fr1.numer, fr1.denom * fr2.numer);
}