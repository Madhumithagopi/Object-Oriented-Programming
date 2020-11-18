#include<iostream>
using namespace std;
class Complex
{
    int *real,*img;
public:
    Complex():real(new int()),img(new int()) {}
    Complex(int,int);
    Complex(const Complex &X);
    void show() const;
    Complex operator +(Complex);
    Complex operator -(Complex);
    Complex operator *(Complex);
    Complex operator /(Complex);
    ~Complex()
    {
        delete real,img;
    }
};
Complex::Complex(int x, int y):real(new int(x)),img(new int(y)) {}
Complex::Complex(const Complex &X):real(new int(*X.real)),img(new int(*X.img)) {}
void Complex:: show() const
{
    cout<<*real<<"+i"<<*img;
}
Complex Complex::operator +(Complex obj)
{
    Complex temp;
    *(temp.real)=*real+(*(obj.real));
    *(temp.img)=*img+(*(obj.img));
    return temp;
}
Complex Complex::operator -(Complex obj)
{
    Complex temp;
    *(temp.real)=*real-*(obj.real);
    *(temp.img)=*img-*(obj.img);
    return temp;
}
Complex Complex::operator*(Complex obj2)
{
    Complex temp;
    *(temp.real)=(*(real)*(*(obj2.real)))-(*(img)*(*(obj2.img)));
    *(temp.img)=(*(img)*(*(obj2.real)))+(*(real)*(*(obj2.img)));
    return temp;

}
Complex Complex::operator/(Complex a2)
{
    Complex temp;
    *(temp.real)=((*(real)*(*(a2.real)))+(*(img)*(*(a2.img))))/((*(a2.real)*(*(a2.real)))+(*(a2.img)*(*(a2.img))));
    *(temp.img)=((*(img)*(*(a2.img)))-(*(real)*(*(a2.img))))/((*(a2.real)*(*(a2.real)))+(*(a2.img)*(*(a2.img))));
    return temp;
}
int main()
{
    Complex c1(8,6),c2(4,3);
    cout<<"The 1st number is:";
    c1.show();
    cout<<"\nThe 2nd number is:";
    c2.show();
   Complex c3=c1+c2;
   Complex c4=c1-c2;
   Complex c5=c1*c2;
   Complex c6=c1/c2;
    cout<<"\nAddition is:";
    c3.show();
    cout<<"\nSubtraction is:";
    c4.show();
    cout<<"\nMultiplication is:";
    c5.show();
    cout<<"\nDivision is:";
    c6.show();
    return 0;
}
