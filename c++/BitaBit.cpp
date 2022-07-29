#include<iostream>
#include<conio.h>
using namespace std;
main(){
	unsigned int a=25,b=30,c=45,xa,xb,xc,xd,xe,xf,xg,xh,xi;
	xa=a&b;
	xb=a|b;
	xc=~c;
	xd=a&b&c;
	xe=a&b|c;
	xf=a|b&c;
	xg=~(a|b&c);
	xh=a>>2&b<<3;
	xi=!(a>>1 | c<<2);
	cout<<endl;
	cout<<"  a&b;--------->X= "<<xa<<endl;
	cout<<"  a|b;--------->X= "<<xb<<endl;
	cout<<"  ~c;---------->X= "<<xc<<endl;
	cout<<"  a&b&c;------->X= "<<xd<<endl;
	cout<<"  a&b|c;------->X= "<<xe<<endl;
	cout<<"  a|b&c;------->X= "<<xf<<endl;
	cout<<"  ~(a|b&c);---->X= "<<xg<<endl;
	cout<<"  a>>2&b<<3;--->X= "<<xh<<endl;
	cout<<"  !(a>>1|c<<2); X= "<<xi<<endl;
	getch();
	return 0;
}
