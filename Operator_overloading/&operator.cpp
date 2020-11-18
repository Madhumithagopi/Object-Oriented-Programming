#include<iostream>
using namespace std;
class C{
public:
C(): x(0), y(0) {}
C(int xx, int yy): x(xx), y(yy) {}
private:
int x, y;
};
int main(){
C c1, c2(5,6);
C *ptr;
c1 = c2;
ptr =&c2;
}
