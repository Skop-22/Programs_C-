#include<conio.h>
#include<iostream>
using namespace std;
main(){
	float Vutp,Vltp,r1,r2,Vsal;
	cout<<"Escrive el balor de V salida: ";
	cin>>Vsal;
	cout<<"Escrive la resistencia 1: ";
	cin>>r1;
	cout<<"Escrive la resistencia 2: ";
	cin>>r2;
	Vutp=Vsal*(r2/(r1+r2));
	Vltp=-Vutp;
	cout<<endl<<"Vutp: "<<Vutp<<endl<<"Vltp: "<<Vltp;
	return 0;
	getch();
}
