#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <cstdlib>
#include <vector>
#include <new>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <cassert>
#include <climits>
#include <iterator>
using namespace std;


class divideByZero : public std::runtime_error
{
public:
	divideByZero(string const & s) :
            std::runtime_error(s){}
};

template<typename T> T gcd (T a, T b)
{
	if ( b==0 ) return a;
	else
		return gcd (b, a%b);
}

template<typename T> class Fraction
{
private:
	T numerator, denominator;	
};

template<> class Fraction <int>
{
public:
	Fraction():numerator(0), denominator(1){}
	Fraction(int n) : numerator(n), denominator(1){}
	Fraction(int, int);
	Fraction(const Fraction<int>&);
	~Fraction(){}
	Fraction& operator=(const Fraction<int>&);
	
	Fraction<int> add(const Fraction<int>&);
	Fraction<int> sub(const Fraction<int>&);
	Fraction<int> mul(const Fraction<int>&);
	Fraction<int> div(const Fraction<int>&);
	
	friend Fraction operator+(const Fraction<int>&,const Fraction<int>&);
	friend Fraction operator-(const Fraction<int>&,const Fraction<int>&);
	friend Fraction operator*(const Fraction<int>&,const Fraction<int>&);
	friend Fraction operator/(const Fraction<int>&,const Fraction<int>&);
	friend ostream& operator<<(ostream&, const Fraction<int>&);
	friend bool operator==(const Fraction<int>&,const Fraction<int>&);
	friend bool operator!=(const Fraction<int>&,const Fraction<int>&);
private:
	int numerator, denominator;
};

/*** Constructors ***/
Fraction<int>::Fraction(int n, int d) : numerator(n), denominator(d)
{
	if ( d == 0 ) throw ("divideByZero");
}
Fraction<int>& Fraction<int>::operator=(const Fraction<int>& other)
{
	if ( this != &other ) {
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}
	return *this;
}	
Fraction<int>::Fraction(const Fraction<int>& other)
{
	numerator = other.numerator;
	denominator = other.denominator;
}

/*** Arithmetic operations ***/
Fraction<int> operator+(const Fraction<int>& frac1, const Fraction<int>& frac2)
{
	Fraction<int> t(frac1.numerator * frac2.denominator + 
					frac1.denominator * frac2.numerator,
					frac1.denominator * frac2.denominator);
	
	return t;
}
Fraction<int> operator-(const Fraction<int>& frac1, const Fraction<int>& frac2)
{
	Fraction<int> t(frac1.numerator * frac2.denominator - 
					frac1.denominator * frac2.numerator,
					frac1.denominator * frac2.denominator);
	
	return t;
}
Fraction<int> operator*(const Fraction<int>& frac1, const Fraction<int>& frac2)
{
	Fraction<int> t(frac1.numerator * frac2.numerator,
					frac1.denominator * frac2.denominator);
	
	return t;
}
Fraction<int> operator/(const Fraction<int>& frac1, const Fraction<int>& frac2)
{
	if ( frac2.numerator == 0 ) throw ("divideByZero");
	Fraction<int> t(frac1.numerator * frac2.denominator,
					frac2.numerator * frac1.denominator);
	
	return t;
}

Fraction<int> Fraction<int>::add(const Fraction<int>& frac)
{
	return *this + frac;
}

Fraction<int> Fraction<int>::sub(const Fraction<int>& frac)
{
	return *this - frac;
}

Fraction<int> Fraction<int>::mul(const Fraction<int>& frac)
{
	return *this * frac;
}

Fraction<int> Fraction<int>::div(const Fraction<int>& frac)
{
	return *this / frac;
}

/*** Relational operations ***/
bool operator==(const Fraction<int>& lhs, const Fraction<int>& rhs)
{
	return (lhs.numerator==rhs.numerator && lhs.denominator==rhs.denominator);
}
bool operator!=(const Fraction<int>& lhs,const Fraction<int>& rhs)
{
	return !(lhs == rhs);
}
	
ostream& operator<<(ostream& os, const Fraction<int>& frac)
{
	if ( frac.numerator==0 ) os << 0;
	else if ( frac.denominator==1 ) os << frac.numerator;
	else {
		int gcd_ = gcd (frac.numerator, frac.denominator);
		os << frac.numerator/gcd_;
		os <<"/";
		os << frac.denominator/gcd_;
		os << "[gcd=" << gcd_ << "]";
	}
	return os;
}

/************************************************************/
int main()
{
	int a = -5, b = 7;
	
	Fraction<int> F1(a,b);
	Fraction<int> F2(2,-3);
	Fraction<int> F3 = F1 + F2;
	
	cout<<"F1 = " << F1 <<"\nF2 = " << F2 << "\nF3 = " << F3<< endl;
	cout<< F1.mul(F2) << endl;
	cout<< (F1*F2)<<endl;
}



