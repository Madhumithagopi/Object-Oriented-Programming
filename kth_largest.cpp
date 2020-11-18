/*2.3	Write the C++ program that prints the kth largest element in an integer and in a character array.
Use overloading concept giving the function names as
voidkth_largest_element( int *, int  k, int size=20)
voidkth_largest_element( char *, int  k, int size=20)
*/
#include<iostream>
using namespace std;
void kth_largest_element(int *a,int k,int size1=20)
{
    int i,j,t;
    for(i=0; i<size1; i++)
    {
        for(j=i+1;j<size1;j++)
        {
            if(*(a+i)<*(a+j))
            {
                t=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=t;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        t=*(a+i);
    }
    cout<<t<<"\n";
}
void kth_largest_element(char *a,int k,int size1=20)
{
int i,j;
char t;
    for(i=0; i<size1; i++)
    {
        for(j=i+1;j<size1;j++)
        {
            if(*(a+i)<*(a+j))
            {
                t=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=t;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        t=*(a+i);
    }
    cout<<t<<"\n";
}
int main()
{
    int k,size1,i,*a;
    char *a1;
    cout<<"Enter the size of array:";
    cin>>size1;
    a1=(char*)malloc(sizeof(size1));
    a=(int*)malloc(sizeof(size1));
    cout<<"Enter the elements(Integers):";
    for(i=0; i<size1; i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the elements(Characters):";
    for(i=0; i<size1; i++)
    {
        cin>>a1[i];
    }
    cout<<"Enter the k value:";
    cin>>k;
    kth_largest_element(a,k,size1);
    kth_largest_element(a1,k,size1);
}
