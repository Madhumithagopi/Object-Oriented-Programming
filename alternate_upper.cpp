#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
int main()
{
    char str[100];
    int i,flag=0;
    cout<<"Enter the string:";
    gets(str);
    for(i=0;str[i]!='\0';i++)
    {
        if(flag%2==0)
            cout<<str[i];
        if(str[i]==' ')
           //cout<<' ';
            flag++;
        if(flag%2!=0)
        {
            str[i]=str[i]-32;
            cout<<str[i];
        }
    }
return 0;
}
