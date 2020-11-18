#include <iostream>
using namespace std;
class C
{
public:
    void print() const;
    C operator++( );
    C operator++(int);
    C() : x(0), y(0) {} C(int xx, int yy) : x(xx), y(yy) {}
private:
    int x;
    int y;
};
void C::print() const
{
    cout << "x " << x << "y " << y << "\n";
}
C C::operator++()
{
    x++;
    y++;
    return *this;
}
C C::operator++(int n)
{
    C tmp = *this;
    x++;
    y++;
    return tmp;
}
int main()
{
    C a(1,1), b(1, 1);
    C c;
    c = a++;
    a.print();
    c.print(); // x 1 y 1
    c = ++b;
    b.print();
    c.print(); // x 2 y 2
}
