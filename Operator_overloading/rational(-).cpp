#include<iostream>
using namespace std;
class Rational
{
		int num,den;
	public:
		void show();
		Rational(int=1,int=1);
		void setnumden(int,int);
		Rational operator-(Rational object);
};
void Rational::show() {
	cout << num << "/" << den << "\n";
}
Rational::Rational(int a,int b) {
	setnumden(a,b);
}
void Rational::setnumden(int x,int y) {
	int temp,a,b;
	a = x;
	b = y;
	if(b > a) {
		temp = b;
		b = a;
		a = temp;
	}
	while(a != 0 && b != 0) {
		if(a % b == 0)
			break;
		temp = a % b;
		a = b;
		b = temp;
	}
 	num = x / b;
	den = y / b;
}
Rational Rational::operator-(Rational object) {
    Rational temp;
	temp.num = num * object.den - den * object.num;
	temp.den = den * object.den;
	return temp;
}
int main() {
	Rational obj3(33,99), obj4(30,99), result2;
	result2 = obj3 - obj4;
	result2.show();
	return 0;
}
