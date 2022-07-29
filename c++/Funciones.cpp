#include<iostream>
#include<conio.h>
using namespace std;
// crear la funcion
void Suma();
void Resta();
//void Multiplicacion();
//void Divicion();
//lo que lleva la funcion
void Suma(int a,int b){
	cout<<"La suma de "<<a<<"+"<<b<<"="<<a+b<<endl;
}
void Resta(int c, int d){
	cout<<"La Resta de "<<c<<"-"<<d<<"="<<c-d<<endl;
}
main(){
	int Var1,Var2;
	cout<<"Introduce El primer valor: ";
	cin>>Var1;
	cout<<"Introduce El segundo valor: ";
	cin>>Var2;
	Suma(Var1,Var2);
	Resta(Var1,Var2);
	getch();
	return 0;
}
