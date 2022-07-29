#include<iostream>
#include<conio.h>
using namespace std;
void DUno();
void DDos();
void DTre();
void DCuatro();
void DCinc();
void DSeis();
void DSiet();
main(){
	cout<<" x+=a;= ";DUno();
	cout<<" x-=a;= ";DDos();
	cout<<" x*=a;= ";DTre();
	cout<<" x/=a;= ";DCuatro();
	cout<<" x%=a;= ";DCinc();
	cout<<" x&=a;= ";DSeis();
	cout<<" x/=a;= ";DSiet();
	return 0;
	getch();
}
void DUno(){
	int a=2,x=3;
	x +=a;
	cout<<" X= "<<x<<" A= "<<a<<endl;
}
void DDos(){
	int a=2,x=3;
	x -=a;
	cout<<" X= "<<x<<" A= "<<a<<endl;
}
void DTre(){
	int a=2,x=3;
	x *=a;
	cout<<" X= "<<x<<" A= "<<a<<endl;
}
void DCuatro(){
	int a=2,x=3;
	x /=a;
	cout<<" X= "<<x<<" A= "<<a<<endl;
}
void DCinc(){
	int a=2,x=3;
	x %=a;
	cout<<" X= "<<x<<" A= "<<a<<endl;
}
void DSeis(){
	int a=2,x=3;
	x &=a;
	cout<<" X= "<<x<<" A= "<<a<<endl;
}
void DSiet(){
	int a=2,x=3;
	x |=a;
	cout<<" X= "<<x<<" A= "<<a<<endl;
}
