/*Implement all the member functions only outside the class and as inline function wherever appropriate.
An University maintains the student details  OOD using Inheritance hierarchy as follows:
It has a Student class to maintain the protected data like rollno(int), Name(string), Yoadmission(integer), DoBirth(string) .
The class “Student” has a private data count(static int count to maintain the total number of studetns).
The university maintains another class named, “ Address” to store the students’ address like , city_name(string), phoneno(int)
Both  the classes, “Student” and “Address”  have a constant display function to display their member details.
Another class namely, “Academics” is inherited from both “Student” and “Address” classes. The class “Academics” has its own data members like, branch( degree studying as string type), dept(string), noyears(static constint),  This class overrides the disp function of their parents class.
Class “Marksheet”  is inherited from “Academics” class. It has data member sem1, sem2   to store percentage earned in two semesters. as float type .
It has other data members like overallPercentage (float to store the average %).
This “Marksheet” class overrides the disp function of its parent “Academics” class.
The class “Marksheet” has other member functions like
•	void studentMarksheet ()  // displays the individual students marksheet in the following format:
•	The class “Marksheet” is friend to a function ,
voidoverallPerformance(constMarksheet *, int size)
All the  four classes have their own Default constructor to initialize with 0 or null values.
It initializes the data members with actual values only through Parameterized constructor.  Provide copy constructor in all the classes.
Also provide a proper setter function in all classes to read all the data members (except overallPercentage) at run time from the user.
	Write a proper C++ driver program to create an object of Marksheetclass  through parameterized constructor.
Display the details of the object created using the :studentMarksheet () member function of Marksheet class.
	Create a dynamic “Marksheet” object using new operator by invoking default constructor .
Then by invoking the setter function assign the values to the object created. Display its details using the member function studentMarksheet  ()
	Create ‘n’ number of “Marksheet“ objects. Assign the values of this ‘n’ number of objects using setter function.
	Display the overall performance of ‘n’ number of students using the friend function
overallPerformance (constMarksheet *, int size)  .
*/
#include<iostream>
#include<cstring>
using namespace std;
class student
{
    static int count;
protected:
    int rollno,Yoadmission;
    string name,DoBirth;
public:
    student()
    {
        count++;
    }
    student(int rollno1,string name1,string dob1,int Yoadmission1):rollno(rollno1),name(name1),DoBirth(dob1),Yoadmission(Yoadmission1)
    {
        count++;
    }
    student(const student &X):rollno(X.rollno), Yoadmission(X.Yoadmission), name(X.name), DoBirth(X.DoBirth) {}
    ~student() {}
    void setter();
    void disp() const;
    static int countreturn();
};
class Address
{
protected:
    string city_name;
    long long int phoneno;
public:
    Address()
    {    }
    Address(string place1,long long int phone):city_name(place1),phoneno(phone) {}
    Address(const Address &X):city_name(X.city_name), phoneno(X.phoneno) {}
    ~Address() {}
    void setter();
    void disp() const;
};
class Academics:public student,public Address
{
protected:
    string branch,dept;
    static const int noyears=3;
public:
    Academics()
    {    }
    Academics(int rollno,string name,string DoBirth,int Yoadmission,string city_name,long long int phone,string dept1,string branch1):student(rollno,name,DoBirth,Yoadmission),Address(city_name,phone),dept(dept1),branch(branch1) {}
    Academics(const Academics &X):student(X),Address(X),branch(X.branch),dept(X.dept)
    {    }
    ~Academics() {}
    void setter();
    void disp() const;
};
class Marksheet:public Academics
{
    float sem1,sem2,overallpercentage;
public:
    Marksheet()
    {
    }
    Marksheet(int rollno,string name,string DoBirth,int Yoadmission,string city_name,long long int phone,string branch,string dept,int sem11,int sem21):Academics(rollno,name,DoBirth,Yoadmission,city_name,phone,branch,dept),sem1(sem11),sem2(sem21)
    {
        overallpercentage=(sem1+sem2)/2;
    }
    Marksheet(const Marksheet &X):Academics(X),sem1(X.sem1),sem2(X.sem2)
    {
        overallpercentage=(sem1+sem2)/2;
    }
    ~Marksheet() {}
    void setter();
    void disp() const;
    void studentMarksheet();
    friend void overallPerformance(const Marksheet *, int size);
};
inline void student::disp() const
{
    cout<<"Roll No:"<<rollno<<"          "<<"Name:"<<name<<"      "<<"DOB:"<<DoBirth<<endl;
}
inline void Address::disp() const
{
    cout<<"Native place:"<<city_name<<"      "<<"Phone Number:"<<phoneno<<endl;
}
inline void Academics::disp() const
{
    student :: disp()  ;
    Address :: disp() ;
    cout<<"Year of Admission:"<<Yoadmission<<"      "<<"Department:"<<dept<<"    "<<"Branch:"<<branch<<endl;
}
inline void Marksheet::disp() const
{
    Academics::disp();
    cout<<"sem1%:"<<sem1<<"   "<<"sem2%:"<<sem2<<endl;
}
inline void Marksheet::studentMarksheet()
{
    Marksheet::disp();
    cout<<"         Overall Percentage Obtained so far:"<<overallpercentage<<endl;
    cout<<"------------------------------------------------------------------------------\n";
}
inline void overallPerformance(const Marksheet *obj, int size)
{
    float sum=0,max,preMax=100;
    int i,j,k;
    for(i=0;i<size;i++)
    {
        max= 0 ;
        for(j=0;j<size;j++)
        {
            if(obj[j].overallpercentage > max && obj[j].overallpercentage < preMax)
            {
                max = obj[j].overallpercentage ;
                k = j ;
            }
        }
        preMax = obj[k].overallpercentage ;
        sum += preMax ;
        if(obj[k].city_name=="tripur")
        cout<<obj[k].rollno<<"         "<<obj[k].branch<<"        "<<obj[k].dept<<"        "<<(obj[k].overallpercentage)<<"         "<<obj[k].city_name<<endl;

    }
    cout<<"---------------------------------------------------------------------\n";
    cout<<"Total students:"<<student::countreturn()<<"     "<<"Average Percentage:"<<sum/student::countreturn() <<endl;
    cout<<"---------------------------------------------------------------------\n";
}
inline void student::setter()
{
    cout<<"Enter the Roll No:";
    cin>>rollno;
    cout<<"Enter the name:";
    cin>>name;
    cout<<"Enter the Year of admission:";
    cin>>Yoadmission;
    cout<<"Enter the DOB:";
    cin>>DoBirth;
}
inline int student::countreturn()
{
    return count;
}
inline void Address::setter()
{
    cout<<"Enter the Native place:";
    cin>>city_name;
    cout<<"Enter the phone number:";
    cin>>phoneno;
}
inline void Academics::setter()
{
    student ::setter() ;
    Address ::setter() ;
    cout<<"Enter the Department:";
    cin>>dept;
    cout<<"Enter the Branch:";
    cin>>branch;
}
inline void Marksheet::setter()
{
    Academics::setter();
    cout<<"Enter the sem1 and sem2 percentage:";
    cin>>sem1>>sem2;
    overallpercentage=(sem1+sem2)/2;
}
int student::count=0;
int main()
{
    int size,i;
    Marksheet m3(101,"aaa","19-08-2004",2019,"tripur",9078564321,"ccc","ddd",34,36);
    m3.studentMarksheet() ;
    cout<<"Enter the size:";
    cin>>size;
    Marksheet *m2=new Marksheet[size];
    for(i=0; i<size; i++)
    {
        m2[i].setter();
    }
    for(i=0; i<size; i++)
    {
        m2[i].studentMarksheet();
    }
    cout<<"Roll_No  Branch  Department  Overall_Percentage  Native\n";
    cout<<"----------------------------------------------------------------------\n";
    overallPerformance(m2,size);
    return 0;
}
