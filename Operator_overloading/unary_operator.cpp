#include <iostream>
using namespace std;
class C
{
public:
    void print() const;
    C operator!(); // unary operator; takes no argument
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
C C::operator!()
{
    C tmp( -x, -y );
    return tmp;
}
int main()
{
    C c1, c2( 2, 3 );
    c1 = !c2;
    c1.print();
    c2.print();
}
