#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <cassert>
#include <climits>
#include <iterator>
using namespace std;

namespace myFraction
{

template<typename T> class Fraction
{
private:
	T _numer, _denom;
};
 
class divideByZero : public std::runtime_error
{
public:
	divideByZero(string const & s) : runtime_error(s){}
};
 
 
template<> class Fraction <int>
{
public:
	Fraction():_numer(0), _denom(1) {}
	Fraction(int n, int d=1); // : _numer(n), _denom(1) {}
	Fraction(const Fraction<int>&);
	~Fraction(){}
	Fraction& operator=(const Fraction<int>&);
 
    // overloading self-assignment operators
	Fraction& operator+=(const Fraction<int>&);
	Fraction& operator-=(const Fraction<int>&);
	Fraction& operator*=(const Fraction<int>&);
	Fraction& operator/=(const Fraction<int>&);
	Fraction& operator+=(int);
	Fraction& operator-=(int);
	Fraction& operator*=(int);
	Fraction& operator/=(int);
	// overloading binary operators
	const Fraction operator+(const Fraction<int>&) const;
	const Fraction operator-(const Fraction<int>&) const;
	const Fraction operator*(const Fraction<int>&) const;
	const Fraction operator/(const Fraction<int>&) const;
	const Fraction operator+(int) const;
	const Fraction operator-(int) const;
	const Fraction operator*(int) const;
	const Fraction operator/(int) const;
	// overloading unary operators
	const Fraction operator-() const;
	// overloading IO stream operators
	friend ostream& operator<<(ostream&, const Fraction<int>&);
	// overloading relational operators
	friend bool operator==(const Fraction<int>&,const Fraction<int>&);
	friend bool operator!=(const Fraction<int>&,const Fraction<int>&);
 
    // Arithmetic functions
	Fraction<int> add(const Fraction<int>&) const;
	Fraction<int> sub(const Fraction<int>&) const;
	Fraction<int> mul(const Fraction<int>&) const;
	Fraction<int> div(const Fraction<int>&) const;
 
    // helper functions
    int gcd () const;
	Fraction& normalize();
    int numerator() const { return _numer; }
    int denominator() const { return _denom; }
    int to_Int() const { return static_cast<int>(_numer/_denom); }
    double to_Double() const { return static_cast<double>(_numer)/_denom; }

private:
	int _numer, _denom;
};
 
/*** Constructors ***/
Fraction<int>::Fraction(int n, int d) : _numer(n), _denom(d)
{
	if ( d == 0 ) throw ("divideByZero");
}
Fraction<int>& Fraction<int>::operator=(const Fraction<int>& other)
{
	if ( this != &other ) {
		this->_numer = other._numer;
		this->_denom = other._denom;
	}
	return *this;
}	
Fraction<int>::Fraction(const Fraction<int>& other)
{
	_numer = other._numer;
	_denom = other._denom;
}
 
/*** Self-assignment operators ***/
Fraction<int>& Fraction<int>::operator+=(const Fraction<int>& other)
{
    _numer = _numer * other._denom + _denom * other._numer;
    _denom *= other._denom;
    return this->normalize();
}
 
Fraction<int>& Fraction<int>::operator-=(const Fraction<int>& other)
{
    _numer = _numer * other._denom - _denom * other._numer;
    _denom *= other._denom;
    return this->normalize();
 
}
Fraction<int>& Fraction<int>::operator*=(const Fraction<int>& other)
{
    _numer *= other._numer;
    _denom *= other._denom;
    return this->normalize();
 
}
Fraction<int>& Fraction<int>::operator/=(const Fraction<int>& other)
{
	if ( other._numer == 0 ) throw ("divideByZero");
    _numer *= other._denom;
    _denom *= other._numer;
    return this->normalize();

}

Fraction<int>& Fraction<int>::operator+=(int N)
{
    _numer += N *_denom;
    return this->normalize();
}
Fraction<int>& Fraction<int>::operator-=(int N)
{
    _numer -= N *_denom;
    return this->normalize();
}

Fraction<int>& Fraction<int>::operator*=(int N)
{
    _numer *= N;
    return this->normalize();
}

Fraction<int>& Fraction<int>::operator/=(int N)
{
	if ( N == 0 ) throw ("divideByZero");
    _denom *= N;
    return this->normalize();
}

/*** Unary operators ***/
const Fraction<int> Fraction<int>::operator-() const
{
	return Fraction<int>(*this) * (-1);
}

/*** Binary operators ***/
const Fraction<int> Fraction<int>::operator+(const Fraction<int>& other) const
{
	return Fraction<int> (*this) += other;
}
const Fraction<int> Fraction<int>::operator-(const Fraction<int>& other) const
{
	return Fraction<int>(*this) -= other;
 
}
const Fraction<int> Fraction<int>::operator*(const Fraction<int>& other) const
{
	return Fraction<int>(*this) *= other;
}
const Fraction<int> Fraction<int>::operator/(const Fraction<int>& other) const
{
	return Fraction<int>(*this) /= other;
}
 
const Fraction<int> Fraction<int>::operator+(int N) const
{
	return Fraction<int>(*this) += N;
}
const Fraction<int> Fraction<int>::operator-(int N) const
{
	return Fraction<int>(*this) -= N;
}
const Fraction<int> Fraction<int>::operator*(int N) const
{
	return Fraction<int>(*this) *= N;
}
const Fraction<int> Fraction<int>::operator/(int N) const
{
	return Fraction<int>(*this) /= N;
 
}

/*** Arithmetic functions ***/
Fraction<int> Fraction<int>::add(const Fraction<int>& frac) const
{
	return *this + frac;
}
 
Fraction<int> Fraction<int>::sub(const Fraction<int>& frac) const
{
	return *this - frac;
}
 
Fraction<int> Fraction<int>::mul(const Fraction<int>& frac) const
{
	return *this * frac;
}
 
Fraction<int> Fraction<int>::div(const Fraction<int>& frac) const
{
	return *this / frac;
}
 
int Fraction<int>::gcd () const
{
    int a = _numer;
    int b = _denom;
 
	while ( b != 0 ) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}
 
	if ( a<0 ) a = -a;

	return a;
}
Fraction<int>& Fraction<int>::normalize()
{
   int _gcd = gcd();
    _numer /= _gcd;
    _denom /= _gcd;
   
    return *this;
}
 
/*** Relational operators ***/
bool operator==(const Fraction<int>& lhs, const Fraction<int>& rhs)
{
	return (lhs._numer==rhs._numer && lhs._denom==rhs._denom);
}
bool operator!=(const Fraction<int>& lhs,const Fraction<int>& rhs)
{
	return !(lhs == rhs);
}
 
/*** I/O stream operators ***/
ostream& operator<<(ostream& os, const Fraction<int>& frac)
{
	if ( frac._numer==0 ) os << 0;
	else if ( frac._denom==1 ) os << frac._numer;
	else os << frac._numer <<"/" << frac._denom;
 
	return os;
}
 
} // namespace myFraction

/************************************************************/
 

 
int main()
{
    using namespace myFraction;
	
	Fraction<int> F1(-2,3);
	Fraction<int> F2(2,9);
	Fraction<int> F3;
	
	cout<<"F1 = " << F1 <<"\nF2 = " << F2 << endl;
	
	F3 = -F1;
	cout<<"F3 = " << F3 << endl;
	
	F3 = F1 + F2;
	/*cout<<"F1 = " << F1 <<"\nF2 = " << F2 << endl;
	cout<< "F3 = F1 + F2 =  " << F3 << " " << (F1+F2)<< endl;
	
	cout<<"F1*F2= " << F1.mul(F2) << "\t" << F1*F2 << endl;
	//cout<<"F1*-2= " << F1.mul(F2) << "\t" << F1*F2 << endl;
	//cout<<"F1*1= " << F1.mul(F2) << "\t" << F1*F2 << endl;
	//cout<<"F1*0= " << F1.mul(F2) << "\t" << F1*F2 << endl;
	
	cout<<"F1/F2= " << F1.div(F2) << "\t" << (F1/F2)<<endl;
    
    cout<<"F1 + 3 = " << (F1 + 3) << endl;
    cout<<"F1 + 0 = " << (F1 + 0) << endl;
    cout<<"F1 + -3 = " << (F1 + -3) << endl;

cout<<"F1 - 3 = " << (F1 - 3) << endl;
cout<<"F1*3 = " << (F1*3) <<endl;
cout<<"F1*5 = " << (F1*5) <<endl;
cout<<"F1*-5 = " << (F1*(-5)) <<endl;
cout<<"F1*0 = " << (F1*0) <<endl;
*/
cout<<"F1/3 = " << (F1/3) <<endl;
cout<<"F1/5 = " << (F1/5) <<endl;
cout<<"F1/-5 = " << (F1/(-5)) <<endl;
try {
    F3 = F1 / 0;
} catch (string e) {
    cout<<e<<endl;
}
//cout<<"F1/0 = " << (F1/0) <<endl;


//cout<<"F1.to_Integer() = " <<F1.to_Int()<<endl;
//cout<<"F1.to_Double() = " <<F1.to_Double()<<endl;  
 cout<<endl;
    
}
 
