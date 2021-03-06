#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <cassert>
#include <climits>
#include <iterator>
#include <type_traits>
#include <typeinfo>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long ul;
typedef unsigned long long ull;

namespace myFraction
{
typedef unsigned uint;
typedef unsigned long ul;
typedef unsigned long long ull;

template <typename T> struct is_validType
{
    static const bool is_valid() { return false; }
}; 

template <> struct is_validType<int>
{
    static const bool is_valid() { return true; }
}; 

template <> struct is_validType<uint>
{
    static const bool is_valid() { return true; }
}; 

template <> struct is_validType<long>
{
    static const bool is_valid() { return true; }
}; 
template <> struct is_validType<ul>
{
    static const bool is_valid() { return true; }
}; 
template <> struct is_validType<long long>
{
    static const bool is_valid() { return true; }
}; 
template <> struct is_validType<ull>
{
    static const bool is_valid() { return true; }
}; 


/*
template<class T>
class A<T, typename std::enable_if<std::is_floating_point<T>::value >::type> {
}; // note: for this use case, static_assert may be more appropriate
*/
template<typename T> 
class Fraction
//class Fraction <T, typename enable_if<is_integral<T>::value>::type>
{
public:
    Fraction (T n, T d=0) : _numer(n),_denom(d) 
    {
        static_assert ( is_validType<T>::is_valid(), "error: unsupported type");
    }

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
	Fraction(int n, int d=1);
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
	Fraction<int> add(int) const;
	Fraction<int> sub(int) const;
	Fraction<int> mul(int) const;
	Fraction<int> div(int) const;
 
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
	this->normalize();
}

Fraction<int>::Fraction(const Fraction<int>& other)
{
	_numer = other._numer;
	_denom = other._denom;
}
 
Fraction<int>& Fraction<int>::operator=(const Fraction<int>& other)
{
	if ( this != &other ) {
		this->_numer = other._numer;
		this->_denom = other._denom;
	}
	return *this;
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
    return  Fraction<int>(*this) += Fraction<int>(N);
}

Fraction<int>& Fraction<int>::operator-=(int N)
{
    return  Fraction<int>(*this) -= Fraction<int>(N);
}

Fraction<int>& Fraction<int>::operator*=(int N)
{
    return  Fraction<int>(*this) *= Fraction<int>(N);
}

Fraction<int>& Fraction<int>::operator/=(int N)
{
    return  Fraction<int>(*this) /= Fraction<int>(N);
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
    return  Fraction<int>(*this) += Fraction<int>(N);
}

const Fraction<int> Fraction<int>::operator-(int N) const
{
    return  Fraction<int>(*this) -= Fraction<int>(N);
}

const Fraction<int> Fraction<int>::operator*(int N) const
{
    return  Fraction<int>(*this) *= Fraction<int>(N);
}

const Fraction<int> Fraction<int>::operator/(int N) const
{
    return  Fraction<int>(*this) /= Fraction<int>(N);
}

/*** Arithmetic functions ***/
Fraction<int> Fraction<int>::add(const Fraction<int>& frac) const
{
	return *this + frac;
}
 
Fraction<int> Fraction<int>::add(int N) const
{
    return *this + Fraction<int>(N);
}
 
Fraction<int> Fraction<int>::sub(const Fraction<int>& frac) const
{
	return *this - frac;
}
 
Fraction<int> Fraction<int>::sub(int N) const
{
    return *this - Fraction<int>(N);
}
 
Fraction<int> Fraction<int>::mul(const Fraction<int>& frac) const
{
	return *this * frac;
}
 
Fraction<int> Fraction<int>::mul(int N) const
{
    return *this * Fraction<int>(N);
}
 
Fraction<int> Fraction<int>::div(const Fraction<int>& frac) const
{
	return *this / frac;
}
 
Fraction<int> Fraction<int>::div(int N) const
{
    return *this / Fraction<int>(N);
}

/*** Function gcd 
 * Compute the greatest common divisor of the numerator and 
 * the denominator of the fraction.
 * Return: a common divisor
 */
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

/*** Function normalize
 * Apply the gcd computed from gcd() and switch the negative
 * sign of the fraction.
 * e.g. (4/-10) -> (-2/5), (-4/-10) -> (2/5)
 */
Fraction<int>& Fraction<int>::normalize()
{
   int _gcd = gcd();
   if (( _numer > 0 && _denom < 0) || ( _numer < 0 && _denom < 0)) {
       _numer = -_numer;
       _denom = -_denom;
    }
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
	else os << "(" << frac._numer <<"/" << frac._denom << ")";
 
	return os;
}
 
} // namespace myFraction

/************************************************************/


void test_fraction()
{
    using namespace myFraction;

    Fraction<int> F1(-2,3);
    Fraction<int> F2(2,9);
    Fraction<int> F3;

    cout<<"F1 = " << F1 <<"\nF2 = " << F2 << endl;

    cout<<"---- Test negate: " << endl;
    cout<<"-F1 = " << -F1 << endl;

    F3 = F1 + F2;
    cout<<"---- Test add: " << endl;
    cout<< "F3 = " << F1 << " + " << F2 << " = " << F3 << "\t" << (F1+F2)<< endl;
    cout<<F1 <<" + 3 = " << (F1 + 3) << "\tusing add = " << F1.add(3) << endl;
    cout<<F1 <<" + 0 = " << (F1 + 0)<< "\tusing add = " << F1.add(0)  << endl;
    cout<<F1 <<" + -3 = " << (F1 + -3) << "\tusing add = " << F1.add(-3) << endl;

    cout<<"---- Test subtract: " << endl;
    cout<<F1 <<" - 3 = " << (F1 - 3) << "\tusing sub = " << F1.sub(3) << endl;
    cout<<F3 << " - " << F2 << " = " << (F3-F2) << "\tshould get F1 = " << F1<< endl;
    cout<<"using sub = " << F3.sub(F2) << "\tshould get F1 = " << F1<< endl;
    
    cout<<"---- Test multiply: " << endl;
    cout<<F1 <<" * " << F2 <<"= " << F1*F2 << "\tusing mul = " << F1.mul(F2) << endl;
    cout<<F1 <<" * 2 = " << F1*2 << "\tusing mul = " << F1.mul(2) << endl;
    cout<<F1 <<" * -2 = " << F1*(-2) << "\tusing mul = " << F1.mul(-2) << endl;
    cout<<F1 <<" * 0 = " << F1*(0) << "\tusing mul = " << F1.mul(-0) << endl;
	cout<<F1 <<" * 1 = " << F1*(1) << "\tusing mul = " << F1.mul(1) << endl;
	cout<<F1 <<" * -1 = " << F1*(-1) << "\tusing mul = " << F1.mul(-1) << endl;
    
	cout<<"---- Test divide: " << endl;
    cout<<F1 <<" / " << F2 <<"= " << F1/F2 << "\tusing div = " << F1.div(F2) << endl;
    cout<<F1 <<" / 2 = " << F1/2 << "\tusing div = " << F1.div(2) << endl;
    cout<<F1 <<" / -2 = " << F1/(-2) << "\tusing div = " << F1.div(-2) << endl;
	cout<<F1 <<" / 1 = " << F1/(1) << "\tusing div = " << F1.div(1) << endl;
	cout<<F1 <<" / -1 = " << F1/(-1) << "\tusing div = " << F1.div(-1) << endl;
	
	//cout<<"!!! Error divide by zero..." << endl;
    //cout<<F1 <<" / 0 = " << F1/(0) << "\tusing div = " << F1.div(-0) << endl;


    //cout<<"F1.to_Integer() = " <<F1.to_Int()<<endl;
    //cout<<"F1.to_Double() = " <<F1.to_Double()<<endl;  

}
 
int main()
{
	 test_fraction();
}
