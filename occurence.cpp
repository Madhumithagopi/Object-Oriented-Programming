/*Write the function that returns the position of the last occurrence of the given number.
*/
#include<iostream>
using namespace std;
int lastoccurrence(int number,const int a[ ],int size1=10)
{
    int i,pos;
    for(i=1; i<=size1; i++)
    {
        a[i]++;
        if(a[i]==number)
            pos=i;
    }
    cout<<"The position of Last occurrence of element:"<<pos;
}
int main()
{
    int a[100],i,size1,num;
    cout<<"Enter the size of array:";
    cin>>size1;
    cout<<"Enter the elements:";
    for(i=1; i<=size1; i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the number to search:";
    cin>>num;
    if(size1==10)
        lastoccurrence(num,a);
    else
        lastoccurrence(num,a,size1);

}
