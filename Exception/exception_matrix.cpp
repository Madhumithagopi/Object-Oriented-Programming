#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
     float a[10][10],b[10][10],mul[10][10];
     int row1,col1,row2,col2,i,j,k;
     cout<<"Enter the rows and columns :";
     cin>>row1>>col1;
     cout<<"Enter the rows and columns :";
     cin>>row2>>col2;
   try
    {
        if(col1!=row2)
             throw "Not Suitable for multiplication";
      else
      {
          if(row1<=0  || col1<=0 || row2<=0 || col2<=0)
          {
            cout<<"Invalid value for rows and columns\n";
            exit(0);
          }
          else
          {
        cout<<"First matrix elements : ";
       for(i=0;i<row1;i++)
       {
         for(j=0;j<col1;j++)
         {
             cin>>a[i][j];
         }
       }
     cout<<"Second matrix elements : ";
      for(i=0;i<row2;i++)
       {
         for(j=0;j<col2;j++)
         {
           cin>>b[i][j];
         }
       }
     cout<<"Multiplication of the two matrices \n";
      for(i=0;i<row1;i++)
       {
          for(j=0;j<col2;j++)
          {
             mul[i][j]=0;
             for(k=0;k<col1;k++)
              {
                mul[i][j]+=a[i][k]*b[k][j];
              }
          }
        }
      for(i=0;i<row1;i++)
       {
         for(j=0;j<col2;j++)
          {
            cout<<setprecision(2)<<mul[i][j]<<"\t";
          }
           cout<<"\n";
        }
      }
    }
    }
    catch(const char *msg)
     {
         cout<<"\n "<<msg;
     }
 return 0;
}
