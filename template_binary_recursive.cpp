#include<iostream>
using namespace std;
template<class T>
void binarySearch(T arr[],int p,int r,T num)
{
    if (r<p)
    {
        cout<<"Element not found\n";
    }
    else{
        int mid = (p + r)/2;
        if (arr[mid] == num)
            cout<<"Element found\n";
            else
            {
                   if (arr[mid] > num)
            return binarySearch(arr, p, mid-1, num);
        else
            return binarySearch(arr, mid+1, r, num);
    }
    }
}
int main()
{
    int n, i, arr[30], num,index,choice;
    char arrc[40],cho,numc;
    double arrd[30],numd;
    do
    {
        cout<<"-------------------------------\n";
        cout<<"1.Integer Array\n2.Character Array\n3.Float Array\n";
        cout<<"-------------------------------\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the size of array:";
            cin>>n;
            for (i=0; i<n; i++)
            {
                cout<<"Enter number "<<(i+1)<<": ";
                cin>>arr[i];
            }
            cout<<"Enter the element to search:";
            cin>>num;
            binarySearch (arr, 0, n-1, num);
            break;
        case 2:
            cout<<"Enter the size of array:";
            cin>>n;
            for (i=0; i<n; i++)
            {
                cout<<"Enter characters "<<(i+1)<<": ";
                cin>>arrc[i];
            }
            cout<<"Enter the element to search:";
            cin>>numc;
            binarySearch (arrc, 0, n-1, numc);
            break;
        case 3:
            cout<<"Enter the size of array:";
            cin>>n;
            for (i=0; i<n; i++)
            {
                cout<<"Enter Float values"<<(i+1)<<": ";
                cin>>arrd[i];
            }
            cout<<"Enter the element to search:";
            cin>>numd;
        binarySearch (arrd, 0, n-1, numd);
            break;
        default:
            cout<<"Invalid Choice\n";
        }
        cout<<"\nDo you want to continue(Y/N):";
        cin>>cho;
    }
    while(cho=='Y');
    return 0;
}
