#ifndef _FRACT_H_
#define _FRACT_H_
#include <exception>
#include <ostream>
#include <istream>

class Fract {
public:
	Fract() :numer(0), denom(1) {};	//기본 생성자
	Fract(int n, int d) : numer(n), denom(d)	//매개변수 생성자
	{
		if (denom == 0)
			throw std::exception("Denominatior must not be 0.");

		normalize();
	}
	Fract(const Fract& fr) : numer(fr.numer), denom(fr.denom){};

	void print();
		
	friend std::ostream& operator<<(std::ostream&, const Fract&);
	friend std::istream& operator>>(std::istream&, Fract&);
	friend Fract operator*(const Fract&, const Fract&);
	friend Fract operator+(const Fract&, const Fract&);
	friend Fract operator-(const Fract&, const Fract&);
	friend Fract operator/(const Fract&, const Fract&);
private:
	int numer;
	int denom;

	int gcd();
	int rgcd(int, int);
	void normalize();	//약분, 부호조정
};

#endif