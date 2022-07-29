#include<iostream>
#include<conio.h>
using namespace std;
main(){
	int a=2,b=4,c=6,x1,x2,x3,x4,x5,x6,x7,x8,x9;
	x1=a>b;
	x2=a<b;
	x3=c>b;
	x4=a>b&&b<c;
	x5=a>b||b<c;
	x6=a==b||b!=c;
	x7=!(a>b&&b<c);
	x8=!(a>b)&&b<c;
	x9=!(a>b||b<c);
	cout<<"x=a>b;         x="<<x1<<endl;
	cout<<"x=a<b;         x="<<x2<<endl;
	cout<<"x=c>b;         x="<<x3<<endl;
	cout<<"x=a>b&&b<c;    x="<<x4<<endl;
	cout<<"x=a>b||b<c;    x="<<x5<<endl;
	cout<<"x=a==b||b!=c;  x="<<x6<<endl;
	cout<<"x=!(a>b&&b<c); x="<<x7<<endl;
	cout<<"x=!(a>b)&&b<c; x="<<x8<<endl;
	cout<<"x=!(a>b||b<c); x="<<x9<<endl;
	getch();
	return 0;
}
