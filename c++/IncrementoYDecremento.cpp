#include<iostream>
#include<conio.h>
using namespace std;
void x1();
void x2();
void x3();
void x4();
void x5();
void x6();
void x7();
void x8();
void x9();
main(){
	cout<<endl;
	x1();
	x2();
	x3();
	x4();
	x5();
	x6();
	x7();
	x8();
	x9();
	getch();
	return 0;
}
void x1(){
	int a=2,b=3,c=4,d=5,X;
	X=++a;
	cout<<"x=++a;                x= "<<X<<" a= "<<a<<endl<<endl;
}
void x2(){
	int a=2,b=3,c=4,d=5,X;
	X=b--;	
	cout<<"x=b--;                x= "<<X<<" b= "<<b<<endl<<endl;
}
void x3(){
	int a=2,b=3,c=4,d=5,X;
	X=--c;	
	cout<<"x=--c;                 x= "<<X<<" c= "<<c<<endl<<endl;
}
void x4(){
	int a=2,b=3,c=4,d=5,x;
	x=a+b--*c-3*4-(++d);
	cout<<"x=a+b--*c-3*4-(++d);   x= "<<x<<" a= "<<a<<" b= "<<b<<" c= "<<c<<" d= "<<d<<endl<<endl;
}
void x5(){
	int a=2,b=3,c=4,d=5,x;
	x=++a+b*c-3*4-d;
	cout<<"x=++a+b*c-3*4-d;       x= "<<x<<" a= "<<a<<" b= "<<b<<" c= "<<c<<" d= "<<d<<endl<<endl;
}
void x6(){
	int a=2,b=3,c=4,d=5,x;
	x=a+b---(--c)-3*4-(--d);
	cout<<"x=++a+b*c-3*4-d;        x= "<<x<<" a= "<<a<<" b= "<<b<<" c= "<<c<<" d= "<<d<<endl<<endl;
}
void x7(){
	int a=2,b=3,c=4,d=5,x;
	x=(++a)+a++-a*a-a;
	cout<<"x=(++a)+a++-a*a-a;       x= "<<x<<" a= "<<a<<endl<<endl;
}
void x8(){
	int a=2,b=3,c=4,d=5,x;
	x=b-- -b*b-- -b;
	cout<<"x=b-- -b*b-- -b;         x= "<<x<<" b= "<<b<<endl<<endl;
}
void x9(){
	int a=2,b=3,c=4,d=5,x;
	x=a+b--+(++a)+(d--)+d-c;
	cout<<"x=a+b--+(++a)+(d--)+d-c; x= "<<x<<" a= "<<a<<" b= "<<b<<" c= "<<c<<" d= "<<d<<endl<<endl;
}
