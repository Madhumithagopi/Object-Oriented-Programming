#include<iostream>
using namespace std;
class NUM
{
    int n;

public:
    //function to get number
    void getNum(int x)
    {
        n=x;
    }
    //function to display number
    void dispNum(void)
    {
        cout << "value of n is: " << n;
    }
    //unary ! operator overloading
    void operator ! (void)
    {
        n=!n;
    }
};
int main()
{
    NUM num;
    num.getNum(10);
    cout << "Before calling Operator Overloading:";
    num.dispNum();
    cout << endl;

    !num;
    cout << "After  calling Operator Overloading:";
    num.dispNum();
    cout << endl;
    return 0;
}
