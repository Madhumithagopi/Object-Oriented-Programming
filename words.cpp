#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
int main()
{
    char str[100];
    int i,count=1;
    cout<<"Enter the string:";
    gets(str);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]!=' ')
            cout<<str[i];
        else
        {
            cout<<"\n";
            count++;
        }
    }
    cout<<"Total  words : "<<count;
return 0;
}
