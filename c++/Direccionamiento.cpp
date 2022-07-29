#include<iostream>
#include<conio.h>
#include<string.h>
#include<math.h> 
using namespace std;
int bi,i,j,red,host;
string direccion;

void ClaseC(){
	cout<<"Introduce la direccion ip: ";
	cin>>direccion;
	cout<<"La direccion ip es de: "<<direccion<<endl;
	cout<<"Introduce los bits pretados de Red: ";
	cin>>bi;
	while((bi>8)||(bi<1)){
		cout<<"Introduce los bits pretados de Red: ";
		cin>>bi;
	}
	host=pow(2,(8-bi));
	cout<<"Red: "<<pow(2,bi)<<endl<<"Host: "<<host<<endl;
	for(i=0;i<255;i+=host){
		cout<<"               "<<direccion<<"."<<i<<"<-----------Red"<<endl;
		for(j=(i+1);j<(host+i);j++){
			cout<<direccion<<"."<<j<<"<-------host"<<endl;
		}
	}
}
void ClaseB(){
	cout<<"Introduce la direccion ip: ";
	cin>>direccion;
	cout<<"La direccion ip es de: "<<direccion<<endl;
	cout<<"Introduce los bits pretados de Red: ";
	cin>>bi;
	
}
void ClaseA(){
	cout<<"Introduce la direccion ip: ";
	cin>>direccion;
	cout<<"La direccion ip es de: "<<direccion<<endl;
	cout<<"Introduce los bits pretados de Red: ";
	cin>>bi;
	
}

main(){
	string clase,opc="s";
	while(opc=="s"){
		system("cls");
		cout<<"Introduce la clase:";
		cin>>clase;
		if((clase=="A")||(clase=="a")){
			ClaseA();
		}else if((clase=="B")||(clase=="b")){
			ClaseB();
		}else if((clase=="C")||(clase=="c")){
			ClaseC();
		}else{cout<<"Error no existe en este programa esa clase"<<endl;}
		cout<<"Desea continuar (s/n): ";
		cin>>opc;
	}
	return 0;
	getch();
}
