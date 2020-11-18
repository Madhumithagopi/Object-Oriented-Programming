#include <iostream>
using namespace std;
class C
{
public:
    C() : x(0), y(0) {}
    C(int xx, int yy) : x(xx), y(yy) {}
    void print() const;
    friend C operator+( const C&, const C& );
private:
    int x;
    int y;
};
void C::print() const
{
    cout << "x " << x << "y " << y << "\n";
}
// as stand-alone friend
C operator+( const C& c1, const C& c2 )
{
    C tmp( c1.x + c2.x, c1.y + c2.y );
    return tmp;
}
int main()
{
    C c1( 2, 3 );
    C c2( 3, 4 );
    C result;
    result = c1 + c2;
    result.print();
    return 0;
}
