#pragma once
#include <string>
#include <iostream>
using std::string;
using std::ostream;
using std::istream;

class rational{
	int numerator,denominator;
	public:
		rational(int=0,int=1);
		const string toString();
		const string toDouble()const;
		const rational& operator=(const rational&);
                const rational& operator+=(const rational&);
                const rational& operator-=(const rational&);
		const rational& operator*=(const rational&);
		const rational& operator/=(const rational&);
		const rational& simplificar();
		friend ostream& operator<<(ostream&, const rational&);
		friend istream& operator>>(istream&, rational&);
};
const rational operator+(const rational&,const rational&);
const rational operator-(const rational&,const rational&);
const rational operator*(const rational&,const rational&);
const rational operator/(const rational&,const rational&);

