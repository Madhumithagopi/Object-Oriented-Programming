#include<iostream>
using namespace std;
class Vector
{
public:
    Vector():size(0), ptr(0)
    {
        cout << "default constructor" << endl;
    }
    Vector(int);
    Vector(const Vector&);
    Vector& operator=( const Vector& ) ;
private:
    int size;
    int* ptr;
};
Vector::Vector(int n)
{
    size = n;
    ptr = new int[size];
    for ( int i =0; i<size; i++)
        ptr[i]= 0;
    cout << "constructor Vector(n)" << endl;
}
Vector::Vector(const Vector& rhs)
{
    if (rhs.ptr != 0 )
    {
        size = rhs.size;
        ptr = new int[size];
        for (int i=0; i<size; i++)
            ptr[i]= rhs.ptr[i];
    }
    else
    {
        ptr = 0;
        size = 0;
    }
    cout << "copy constructor" << endl;
}
// overload = for class Vector
Vector& Vector::operator=( const Vector& rhs )
{
    if (this!= &rhs)
    {
        if ( rhs.ptr != 0 )
        {
            size= rhs.size;
            delete [ ]ptr;
            ptr = new int[size];
            for ( int i=0; i<size; i++ )
                ptr[i]= rhs.ptr[i];
        }
        else
        {
            size = 0;
            delete[] ptr;
            ptr = 0;
        }
    }
    cout << "assignment =" << endl;
    return *this;
}
int main()
{
    Vector v1(5);
    Vector v2;
    v2 = v1;
    Vector v3 = v2;
}
