#include<iostream>
using namespace std;
class Rational
{
    int num,den;
public:
    Rational();
    Rational(int,int);
    void setnumden(int,int);
    friend Rational operator-(const Rational&);
    friend Rational operator+(const Rational&, const Rational&);
    friend Rational operator-(const Rational&, const Rational&);
    friend Rational operator*=(const Rational&, const Rational&);
    int operator++();
    int operator++(int);
    friend bool operator<(const Rational&,int);
    friend bool operator>(const Rational&, const Rational&);
    friend istream& operator>>( istream&, Rational& );
    friend ostream& operator<<( ostream&, const Rational& );
};
Rational::Rational()
{
    num=den= 0;
}
Rational::Rational(int a,int b)
{
    setnumden(a,b);
}
void Rational::setnumden(int x,int y)
{
    int temp,a,b;
    a = x;
    b = y;
    if(b > a)
    {
        temp = b;
        b = a;
        a = temp;
    }
    while(a != 0 && b != 0)
    {
        if(a % b == 0)
            break;
        temp = a % b;
        a = b;
        b = temp;
    }
    num = x / b;
    den = y / b;
}
Rational operator-(const Rational& t)
{
    return Rational(-t.num,t.den);
}
Rational operator-(const Rational& t, const Rational& u)
{
    return Rational(t.num * u.den - t.den * u.num,t.den * u.den);
}
Rational operator+(const Rational& t, const Rational& u)
{
    return Rational(t.num * u.den + t.den * u.num,t.den * u.den);
}
Rational operator*=(const Rational& t, const Rational& u)
{
    return Rational(t.num * u.num,t.den * u.den);
}
int Rational::operator++()
{
    int temp,a,b;
    a = num+den;
    b = den;
    if(b > a)
    {
        temp = b;
        b = a;
        a = temp;
    }
    while(a != 0 && b != 0)
    {
        if(a % b == 0)
            break;
        temp = a % b;
        a = b;
        b = temp;
    }
    num = num / b;
    den = den / b;
    return num,den;
}
int Rational::operator++(int)
{
    int temp,a,b;
    a = num+den;
    b = den;
    if(b > a)
    {
        temp = b;
        b = a;
        a = temp;
    }
    while(a != 0 && b != 0)
    {
        if(a % b == 0)
            break;
        temp = a % b;
        a = b;
        b = temp;
    }
    num = num / b;
    den = den / b;
    return num,den;
}
bool operator<(const Rational& c,int a)
{
    a=0;
    if(c.num<a || c.den<a)
        return true;
    else
        return false;
}
bool operator>(const Rational& t, const Rational& u)
{
    float a,b;
    a=t.num/t.den;
    b=u.num/u.den;
    if(a>b)
        return true;
    else
        return false;
}
istream& operator>>(istream& in, Rational& c  )
{
    return in >> c.num >> c.den ;
}
ostream& operator<<( ostream& out, const Rational& c )
{
    return out << c.num << " / " << c.den << "\n";
}
int main()
{
    Rational r1,r2;
    cin>>r1>>r2;
    r1=-r1;
    r1=r1-r2;
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
    Rational r5,r6;
    cin>>r5>>r6;
    if ( r5 < 0)
        cout<<" Object r5 is negative rational\n";
    else
        cout<<" Object r5 is positive rational\n";
    if (r5 > r6)
        cout<< " object r5 is greater than r6\n" ;
    else
        cout<<" Object r6 is greater than r5\n";
    return 0;
}







