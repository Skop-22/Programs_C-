#include<iostream>
#include<conio.h>
using namespace std;
main(){
	int x1,x2,x3,x4,x5,x6,x7,x8,x9;
	x1=50/2;
	x2=50%4;
	x3=50%34;
	x4=8/4%3;
	x5=8/(4%3);
	x6=(8/4)%3;
	x7=70/5/2*8/2%5;
	x8=70/5/((2*7)/2)%5;
	x9=70/2/(2+3)/(11%5);
	cout<<"x=50/2;              x="<<x1<<endl;
	cout<<"x=50%4;              x="<<x2<<endl;
	cout<<"x=50%34;             x="<<x3<<endl;
	cout<<"x=8/4%3;             x="<<x4<<endl;
	cout<<"x=8/(4%3);           x="<<x5<<endl;
	cout<<"x=(8/4)%3;           x="<<x6<<endl;
	cout<<"x=70/5/2*8/2%5;      x="<<x7<<endl;
	cout<<"x=70/5/((2*7)/2)%5;  x="<<x8<<endl;
	cout<<"x=70/2/(2+3)/(11%5); x="<<x9<<endl;
	getch();
	return 0;
}
