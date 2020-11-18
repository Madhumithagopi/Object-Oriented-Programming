#include<iostream>
using namespace std;
class Rational
{
		int num,den;
	public:
	    Rational();
	    Rational(int,int);
		friend Rational operator-(const Rational&);
		friend Rational operator+(const Rational&, const Rational&);
		friend Rational operator-(const Rational&, const Rational&);
		friend Rational operator*=(const Rational&, const Rational&);
        int operator++();
       int operator++(int);
		friend istream& operator>>( istream&, Rational& );
        friend ostream& operator<<( ostream&, const Rational& );
};
Rational::Rational()
{
    num=den= 0;
}

Rational::Rational(int a,int b) {
	num=a;
	den=b;
}

Rational operator-(const Rational& t) {
	return Rational(-t.num,t.den);
}
Rational operator-(const Rational& t, const Rational& u) {
	return Rational(t.num * u.den - t.den * u.num,t.den * u.den);
}
Rational operator+(const Rational& t, const Rational& u) {
	return Rational(t.num * u.den + t.den * u.num,t.den * u.den);
}
Rational operator*=(const Rational& t, const Rational& u) {
	return Rational(t.num * u.num,t.den * u.den);
}
int Rational::operator++() {
	return ++num,++den;
}
int Rational::operator++(int) {
	return (num++,den++);
}
istream& operator>>(istream& in, Rational& c  )
{
    return in >> c.num >> c.den ;
}
ostream& operator<<( ostream& out, const Rational& c )
{
    return out << c.num << " / " << c.den << "i\n";
}
int main() {
Rational r1,r2;
cin>>r1>>r2;
r1=-r1;
r1=r1+ r2;
r2 *= r1;
++r2;
Rational r3;
cin>>r3;
r3++;
cout<<r3;
Rational r4 = r1+ r2 - r3;
cout<<r1;
cout<<r2;
cout<<r4;
return 0;
}
