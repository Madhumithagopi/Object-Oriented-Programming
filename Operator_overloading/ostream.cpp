#include <iostream>
using namespace std;
class Complex
{
public:
    Complex();
    Complex( double );
    Complex( double, double );
    friend Complex operator+( const Complex&, const Complex& );
    friend Complex operator-( const Complex&, const Complex& );
    friend Complex operator*( const Complex&, const Complex& );
    friend Complex operator/( const Complex&, const Complex& );
    friend bool operator==( const Complex&, const Complex& );
    friend bool operator!=( const Complex&, const Complex& );
    friend istream& operator>>( istream&, Complex& );
    friend ostream& operator<<( ostream&, const Complex& );
private:
    double real;
    double imag;
};
Complex::Complex()
{
    real = imag = 0.0;
}
Complex::Complex( double re )
{
    real = re;
    imag = 0.0;
}
Complex::Complex( double re, double im )
{
    real = re;
    imag = im;
}
Complex operator+( const Complex& t, const Complex& u )
{
    return Complex( t.real + u.real, t.imag + u.imag );
}
Complex operator-( const Complex& t, const Complex& u )
{
    return Complex( t.real - u.real, t.imag - u.imag );
}
Complex operator*( const Complex& t, const Complex& u )
{
    return Complex( t.real * u.real - t.imag * u.imag, t.imag * u.real + t.real * u.imag );
}
Complex operator/( const Complex& t, const Complex& u )
{
    double abs_sq = t.real * u.real + t.imag * u.imag;
    return Complex( ( t.real * u.real + t.imag * u.imag ) / abs_sq, ( t.imag * u.real - t.real * u.imag ) / abs_sq );
}
bool operator==( const Complex& t, const Complex& u )
{
    return ( t.real == u.real && t.imag == u.imag) ;
}
bool operator!=( const Complex& t, const Complex& u )
{
    return !( t.real == u.real && t.imag == u.imag) ;
}
istream& operator>>( istream& in, Complex& c )
{
    return in >> c.real >> c.imag ;
}
ostream& operator<<( ostream& out, const Complex& c )
{
    return out << c.real << " + " << c.imag << "i\n";
}
int main()
{
    Complex c1, c2;
    cin >> c1 >> c2;
    cout << c1 << c2;
    cout << c1 + c2;
    return 0;
}
