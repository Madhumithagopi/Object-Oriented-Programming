#include<iostream>
#include<stdlib.h>
#define SIZE 100
using namespace std;
template<typename T>
class Stack
{
    T s[SIZE];
    int top,n;
public:
    Stack();
    void push(T elt);
    void pop();
    void stk_operation();
    void peek();
    int isfull();
    int isempty();
    ~Stack() {}
    template<typename U>
    friend ostream &operator <<(ostream&, const Stack<U>&);
};
template<typename T>
Stack<T>::Stack()
{
    top=-1;
    cout<<"Enter the Stack Size:";
    cin>>n;
}
template<typename T>
void Stack<T>:: push(T elt)
{
    if(!isfull())
        s[++top]=elt;
    else
        cout<<"stack is full!!!!Can't insert the element:"<<elt<<endl;
}
template<typename T>
void Stack<T>::pop()
{
    if(isempty())
        cout<<"stack is empty\n";
    else
        cout<<"Popped element : "<<s[top--];
}
template<typename T>
void Stack<T>::peek()
{
    if(!isempty())
        cout<<"Peek Element: "<<s[top]<<"\n";
    else
        cout<<"stack is empty\n";
}
template<typename T>
int Stack<T>::isfull()
{
    if(top==n-1)
        return 1;
    else
        return 0;
}
template<typename T>
int Stack<T>::isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
template<typename T>
ostream &operator <<(ostream &out, const Stack<T> &s1)
{
    for(int i=s1.top; i>=0; i--)
        out<<s1.s[i]<<"\t";
    return out;
}
template<typename T>
void Stack<T> :: stk_operation()
{
    int choice=1,i;
    T elt;
    while(choice>0 && choice<4)
    {
        cout<<"\n---------------------------\n";
        cout<<"1.PUSH\n2.POP\n3.PEEK\n4.Exit\n";
        cout<<"---------------------------\n";
        cout<<"Enter the operation to be performed:\n";
        cin>>choice;
        switch(choice)
        {
        case 1 :
            cout<<"\nEnter the Element to push : ";
            cin>>elt;
            push(elt);
            break;
        case 2 :
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            break;
        }
    }
}
int main()
{
    cout<<"---------------------------\nSTACK OPERATION USING TEMPLATE\n---------------------------\n";
    cout<<"1.INT\n";
    Stack<int> stk1;
    cout<<"2.FLOAT\n";
    Stack<float> stk2;
    cout<<"3.LONG\n";
    Stack<long> stk3;
    cout<<"4.CHAR\n";
    Stack<char> stk4;
    int ch;
    while(1)
    {
        cout<<"\n---------------------------\n";
        cout<<"1.INT STACK\n2.FLOAT STACK\n3.LONG STACK\n4.CHAR STACK\n5.Exit\n";
        cout<<"---------------------------\n";
        cin>>ch;
        switch(ch)
        {
        case 1 :
            stk1.stk_operation();
            cout<<"INT Stack Content\n";
            cout<<stk1;
            break;
        case 2 :
            stk2.stk_operation();
            cout<<"FLOAT Stack Content\n";
            cout<<stk2;
            break;
        case 3:
            stk3.stk_operation();
            cout<<"LONG Stack Content\n";
            cout<<stk3;
            break;
        case 4:
            stk4.stk_operation();
            cout<<"CHAR Stack Content\n";
            cout<<stk4;
            break;
        default :
            exit(0);
        }
    }
}
