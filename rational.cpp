#include "rational.h"
#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

rational::rational(int numerator,int denominator){
	if(denominator==0)
		denominator=1;
	if(denominator<0){
		numerator*=-1;
		denominator*=-1;
		
	}
	
		
	bool no_more=false;
		if(numerator>denominator){
			for(int i=numerator;i>=1;i--){
				if(numerator%i==0 && denominator%i==0){
					numerator/= i;
					denominator/=i;
				}
			}
		}else{
			 for(int i=denominator;i>=1;i--){
                                if(numerator%i==0 && denominator%i==0){
                                        numerator/=i;
                                        denominator/=i;
                                }
                        }

		}
	this-> numerator = numerator;
	this -> denominator = denominator;
}
const rational& rational:: simplificar(){
	if(numerator>denominator){
                        for(int i=numerator;i>=1;i--){
                                if(numerator%i==0 && denominator%i==0){
                                        numerator/= i;
                                        denominator/=i;
                                }
                        }
        }else{
                         for(int i=denominator;i>=1;i++){
                                if(numerator%i==0 && denominator%i==0){
                                        numerator/=i;
                                        denominator/=i;
                                }
                        }

                }
	return *this;
}
const string rational::toString(){
	bool no_more=false;
                if(numerator>denominator){
                        for(int i=1;i<=numerator;i++){
                                if(numerator%i==0 && denominator%i==0){
                                        numerator/= i;
                                        denominator/=i;
                                        no_more=true;
                                }
                        }
                }else{
                         for(int i=1;i<=denominator;i++){
                                if(numerator%i==0 && denominator%i==0){
                                        numerator/=i;
                                        denominator/=i;
                                        no_more=true;
                                }
                        }

                }

	stringstream ss;
	ss<<numerator<<"/"<<denominator;
	return ss.str();
}
const string rational:: toDouble()const{
	stringstream ss;
	ss << (numerator*1.0)/(denominator*1.0);
	return ss.str();
}
const rational operator+(const rational& r,const rational& h){
	rational devolver=r;
	devolver+=h;
                return devolver;
}
const rational& rational:: operator+=(const rational& r){
	numerator*=r.denominator;
	numerator+=r.numerator*denominator;
	denominator*=r.denominator;
	return *this;
}
const rational operator -(const rational& r,const rational& h){
	rational devolver=r;
	devolver-=h;
	return devolver;
}
const rational& rational:: operator-=(const rational& r){
	numerator*=r.denominator;
        numerator-=r.numerator*denominator;
        denominator*=r.denominator;
        return *this;
}
const rational& rational::operator=(const rational& r){
	numerator = r.numerator;
	denominator = r.denominator;
	return *this;
}
const rational operator*(const rational& r,const rational& h){
	rational devolver=r;
	devolver *= h;
	return devolver;	
}
const rational& rational::operator*=(const rational& r){
	numerator*=r.numerator;
	denominator*=r.denominator;
	return *this;
}
const rational operator/(const rational& r,const rational& h){
	rational devolver=r;
	devolver/=h;
	return devolver;
}
const rational& rational::operator/=(const rational& r){
	numerator*=r.denominator;
	denominator*=r.numerator;
	return *this;
}


ostream& operator<<(ostream& output, const rational& c){
	if(c.denominator>1)
		output<< c.numerator<<"/"<<c.denominator;
	else
		output<<c.numerator;
	return output;
}
istream& operator>>(istream& input, rational& c){
	input >> c.numerator >> c.denominator;
	return input;
}


