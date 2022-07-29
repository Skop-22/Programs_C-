#include<iostream>
#include<conio.h>
using namespace std;
main(){
	int x1,x2,x3,x4,x5,x6,x7,x8,x9;
	x1=2+5;
	x2=8-4;
	x3=7-3;
	x4=2+5*5;
	x5=(2+5)*5;
	x6=2+(5*5);
	x7=2+1*5*2+4-3;
	x8=(2+1)*5*(2+4-3);
	x9=2+1*(5*2+4)-3;
	cout<<"x=2+5;              x="<<x1<<endl;
	cout<<"x=8-4;              x="<<x2<<endl;
	cout<<"x=7-3;              x="<<x3<<endl;
	cout<<"x=2+5*5;            x="<<x4<<endl;
	cout<<"x=(2+5)*5;          x="<<x5<<endl;
	cout<<"x=2+(5*5);          x="<<x6<<endl;
	cout<<"x=2+1*5*2+4-3;      x="<<x7<<endl;
	cout<<"x=(2+1)*5*(2+4-3);  x="<<x8<<endl;
	cout<<"x=2+1*(5*2+4)-3;    x="<<x9<<endl;
	getch();
	return 0;
}
