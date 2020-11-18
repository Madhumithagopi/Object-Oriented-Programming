/*Write a C++ function right-angled( int size, int type = 1) to print the following shapes.
The function should take the defaulted value for type.
The function should print the following type of triangles based on the type value passed.
If the type is not passed as actual argument, the default value is assigned for type and always the pattern for right angle triangle is printed.
If type ==1,  Right angle TriangleIf type ==3 Mirrored inverted Right angle Triangle
*/
#include<iostream>
using namespace std;
void right_angled ( int size11, int type = 1)
{
    int i,j;
    if(type==1)
    {
        for(i=1; i<=size11; i++)
        {
            for(j=1; j<=i; j++)
            {
                cout<<"*";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    if(type==2)
    {
        for(int i=0; i<size11; i++)
        {
            for(j=i; j<size11; j++)
            {
                cout<<"*";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }

   /* if(type==3)
    {
        for(int i=0; i<size11; i++)
        {
            int t=0;
            while(t<i && i!=0)
            {
                cout<<" ";
                t++;
            }
            for(j=i; j<size11; j++)
            {
                cout<<"*";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }*/
    if(type==3)
    {
        for(int i=0; i<size11; i++)
        {
            for(j=0; j<size11; j++)
            {
                if(j<i)
                    cout<<" ";
                else
                    cout<<"*";
            }
            cout<<"\n";
        }
    }
}
int main()
{
    int size1;
    cout<<"Enter the size of pattern:";
    cin>>size1;
    right_angled (size1);
    right_angled (size1,2);
    right_angled (size1,3);
}
