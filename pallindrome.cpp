//Write C++ overloaded function to check whether the given integer or word is a palindrome number or word.
#include<iostream>
#include<string.h>
using namespace std;
bool palindrome(int n)
{
    int s=0,a,g=n;
    while(n!=0)
    {
        a=n%10;
        s=(s*10)+a;
        n=n/10;
    }
    if(s==g)
        return true;
    else
        return false;
}
bool palindrome(char *string1, int size1=20)
{
    int i,flag=0,length;
    length = strlen(string1);
    if(length!=20)
    {
        for(i=0; i < length ; i++)
        {
            if(*(string1+i) != string1[length-i-1])
            {
                flag = 1;
                break;
            }
        }
    }
    else
    {
        for(i=0; i < size1 ; i++)
        {
            if(string1[i] != string1[size1-i-1])
            {
                flag = 1;
                break;
            }
        }
    }
    if(flag)
        return false;
    else
        return true;
}
int main()
{
    int num;
    char word[100];
    cout<<"Enter the number:";
    cin>>num;
    cout<<"Enter the word:";
    cin>>word;
    if(palindrome(num))
        cout<<"The Integer is palindrome\n";
    else
        cout<<"The Integer is not a palindrome\n";
    if(palindrome(word))
        cout<<"The Word is palindrome\n";
    else
        cout<<"The word is not a palindrome\n";
}
