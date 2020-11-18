#include <iostream>
using namespace std;
class Complex
{
public:
    Complex();
    Complex(double);
    Complex( double,double);
    void print() const;
    Complex operator+( const Complex& ) const;
    Complex operator-( const Complex& ) const;
    Complex operator*( const Complex& ) const;
    Complex operator/( const Complex& ) const;
    bool operator==( const Complex& ) const;
    bool operator!=( const Complex& ) const;
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
    real =re;
    imag = 0.0;
}
Complex::Complex( double re, double im )
{
    real = re;
    imag = im;
}
void Complex::print() const
{
    cout << real << " + " << imag << "i\n";
}
Complex Complex::operator+( const Complex& u ) const
{
    Complex v(real + u.real,imag + u.imag ) ;
    return v;
}
Complex Complex::operator-( const Complex& u ) const
{
    Complex v(real - u.real,imag - u.imag ) ;
    return v;
}
Complex Complex::operator*( const Complex& u ) const
{
    Complex v(real * u.real - imag * u.imag,imag * u.real + real * u.imag ) ;
    return v;
}
Complex Complex::operator/( const Complex& u ) const
{
    double abs_sq = real * u.real + imag * u.imag;
    Complex v( ( real * u.real + imag * u.imag ) / abs_sq,( imag * u.real - real * u.imag ) / abs_sq ) ;
    return v;
}
bool Complex::operator==( const Complex& u ) const
{
    return (real == u.real && imag == u.imag) ;
}
bool Complex::operator!=( const Complex& u ) const
{
    return !(real == u.real && imag == u.imag) ;
}
int main()
{
    Complex c1( 8.8, 0 ) ;
    Complex c2( 3.1, -4.3 ) ;
    Complex c3 = c1 + c2;
    Complex c4 = c2 - c1;
    c3.print();
    c4.print();
    if ( c3 == c4 )
        cout << "No way.";
    else
        cout << "Sure they are not equal.";
}
