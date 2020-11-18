#include <iostream>
using namespace std;
class C
{
public:
    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return y;
    }
    void print() const;
    C() : x(0), y(0) {}
    C(int xx, int yy) : x(xx), y(yy) {}
private:
    int x;
    int y;
};
void C::print() const
{
    cout << "x " << x << "y " << y << "\n";
}
C operator+( const C& c1, const C& c2 )
{
    C tmp( c1.getX() + c2.getX(), c1.getY() + c2.getY() );
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
