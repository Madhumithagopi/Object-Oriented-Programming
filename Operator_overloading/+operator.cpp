#include<iostream>
using namespace std;
class C
{
public:
    void print() const;
    C operator+( const C& ) const;
    C() :x(0), y(0) {}
    C(int xx, int yy) : x(xx), y(yy) {}
private:
    int x, y;
};
void C::print() const
{
    cout << "x " << x << "y " << y << "\n";
}
C C::operator+( const C& c ) const
{
    C tmp( x+ c.x, y + c.y ) ;
    return tmp;
}
int main()
{
    C c1( 2, 3 ) ;
    C c2( 3, 4 ) ;
    C result = c1 + c2;
    result.print();
}
