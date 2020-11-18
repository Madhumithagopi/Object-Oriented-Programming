#include<iostream>
using namespace std;
template <class T1>
class Complex
{
    T1 real,img;
public:
    Complex(T1 x=0, T1 y=0): real(x), img(y) { }
    Complex<T1> operator+(const Complex<T1> &obj1);
    bool operator<(const Complex<T1> &obj1);
    bool operator==(const Complex<T1> &obj1);
    Complex<T1>& operator+=(const Complex<T1> &obj1);
    Complex<T1>& operator=(const Complex<T1> &obj1);
    bool operator!=(int);
    template<class U>
    friend istream& operator >>(istream&, Complex<U>&);
    template<class U>
    friend ostream& operator <<(ostream&, const Complex<U>&);
};
template <class T1>
Complex<T1>  Complex<T1> :: operator+(const Complex<T1> &obj1)
{
    Complex<T1>  temp;
    temp.real = real +obj1.real;
    temp.img = img + obj1.img;
    return temp;
}
template <class T1>
bool Complex<T1> :: operator<(const Complex<T1> &obj1)
{
    if(real<obj1.real)
        return true;
    else
        return false;
}
template <class T1>
bool Complex<T1> :: operator==(const Complex<T1> &obj1)
{
    if(real==obj1.real)
        return true;
    else
        return false;
}
template <class T1>
Complex<T1>& Complex<T1>::operator+=(const Complex<T1> &obj1)
{
    real+=obj1.real;
    img+=obj1.img;
    return *this;
}
template <class T1>
Complex<T1>& Complex<T1>::operator=(const Complex<T1> &obj1)
{
    real=obj1.real;
    img=obj1.img;
    return *this;
}
template <class T1>
bool Complex<T1> :: operator!=(int)
{
    if(img!=0)
        return true;
    else
        return false;
}
template <class T1>
istream & operator >>(istream &in, Complex<T1> &c)
{
    return in>>c.real>>c.img;
}
template <class T1>
ostream & operator <<(ostream &out, const Complex<T1> &c)
{
    return out<<c.real<<"+"<<c.img<<"i\n";
}
int main()
{
    int choice,ch;
    do
    {
        cout<<"---------------------------------\n";
        cout<<"1.Int Type\n2.Float Type\n3.Long Type\n";
        cout<<"---------------------------------\n";
        cout<<"Enter the choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            Complex<int> obj1,obj2,obj4,obj3;
            cin>>obj1;
            cin>>obj2;
            cout<<obj1;
            cout<<obj2;
            obj4=obj1+obj2;
            cout<<"Addition of two complex numbers:"<<obj4;
            if(obj2<obj1)
                cout<<"Obj1 is greater than Obj2\n";
            else
                cout<<"Obj2 is greater than Obj1\n";
            if(obj1==obj2)
                cout<<"Obj1 is Equal to Obj2\n";
            else
                cout<<"Obj1 is Not Equal to Obj2\n";
            obj1+=obj2;
            cout<<"Result obtained using += operator :"<<obj1;
            obj3=obj2;
            cout<<"Result obtained using Assignment operator :"<<obj3;
            if(obj2!=0)
                 cout<<"Imaginary part of object2 have non-zero\n";
            else
                cout<<"Imaginary part of object2 have zero\n";
        }
        break;
        case 2:
        {
            Complex<float> obj1,obj2,obj4,obj3;
            cin>>obj1;
            cin>>obj2;
            cout<<obj1;
            cout<<obj2;
            obj4=obj1+obj2;
            cout<<"Addition of two complex numbers:"<<obj4;
            if(obj2<obj1)
                cout<<"Obj1 is greater than Obj2\n";
            else
                cout<<"Obj2 is greater than Obj1\n";
            if(obj1==obj2)
                cout<<"Obj1 is Equal to Obj2\n";
            else
                cout<<"Obj1 is Not Equal to Obj2\n";
            obj1+=obj2;
            cout<<"Result obtained using += operator :"<<obj1;
            obj3=obj2;
            cout<<"Result obtained using Assignment operator :"<<obj3;
            if(obj2!=0.0)
                 cout<<"Imaginary part of object2 have non-zero\n";
            else
                cout<<"Imaginary part of object2 have zero\n";
        }
        break;
        case 3:
        {
            Complex<long> obj1,obj2,obj4,obj3;
            cin>>obj1;
            cin>>obj2;
            cout<<obj1;
            cout<<obj2;
            obj4=obj1+obj2;
            cout<<"Addition of two complex numbers:"<<obj4;
            if(obj2<obj1)
                cout<<"Obj1 is greater than Obj2\n";
            else
                cout<<"Obj2 is greater than Obj1\n";
            if(obj1==obj2)
                cout<<"Obj1 is Equal to Obj2\n";
            else
                cout<<"Obj1 is Not Equal to Obj2\n";
            obj1+=obj2;
            cout<<"Result obtained using += operator :"<<obj1;
            obj3=obj2;
            cout<<"Result obtained using Assignment operator :"<<obj3;
            if(obj2!=0000)
                cout<<"Imaginary part of object2 have non-zero\n";
            else
                cout<<"Imaginary part of object2 have zero\n";
        }
        break;
        default:
            cout<<"Invalid Choice...Try Again!!\n";
            break;
        }
        cout<<"Do you want to continue(1/0):\n";
        cin>>ch;
    }
    while(ch==1);
    return 0;
}
