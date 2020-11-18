#include <iostream>
using namespace std;
double division(float a, float b)
{
    if( b == 0 )
    {
        throw "Zzz - Could not divide by zero";
    }
    return (a/b);
}
int main ()
{
    float numerator,denominator;
    double result;
    cout<<"Enter the numerator:";
    cin>>numerator;
    cout<<"Enter the denominator:";
    cin>>denominator;
    try
    {
        result = division(numerator,denominator);
        cout <<result << endl;
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }
    return 0;
}
