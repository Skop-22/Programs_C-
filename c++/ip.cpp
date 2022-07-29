//programa que alluda en protocolos de red con las direcciones ip
#include<iostream>
#include<windows.h>
#include<winuser.h>
#include<math.h>
using namespace std;
main (){
	char Valor;
	int a;
	//variables para la clase B
	int b,b2;
	int Red2,Host2,Bits2,h2;
	int i,j;
	int excusa2;
	//variables para la clase c
	int c,c2,c3;
	int red,host,r,r2,Hostsalida=0;
	int bits,RedDeEntrada,BitsDeHost,h;
	int contador=0,excusa=0;
	//----------------------------------------------------------------------------
	cout<<endl<<"Introdusca La Clase de la Direccion ip (A-C) En Mayusculas"<<endl;
	cin>>Valor;
	//clase a
	if(Valor=='A'){
		cout<<"Clase A"<<endl;
		cout<<endl<<"La direccion ip deve empesar por numeros sin puto solo (1 a 255)"<<endl;
		cout<<"Introdusca la direccion ip: ";
		cin>>a;
		cout<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"   La direccion ip es: "<<a<<".0.0.0"<<endl;
		cout<<"La mascara por defaul: 255.0.0.0"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<endl;
		system("pause>nul");
		
		system("pause>nul");
		exit(0);
	}
	//clase b
	if(Valor=='B'){
		cout<<"Clase B"<<endl;
		cout<<endl<<"La direccion ip deve empesar por numeros sin puto solo (1 a 255)"<<endl;
		cout<<"Introdusca la Primera parte: ";
		cin>>b;
		if((b<128)||(b>191)){
			MessageBox(NULL,"ERROR - Valor incorrecto \nEs una clase B  va de la 128 � 191 \n(Vuelbe a ejecutar el programa)                                        ","ERROR",MB_OK|MB_ICONHAND);
			exit (0);
		}
		cout<<"Introdusca la segunda parte: ";
		cin>>b2;
		if((b2<1)||(b2>255)){
			MessageBox(NULL,"ERROR - Valor incorrecto (Vuelbe a ejecutar el programa)                                        ","ERROR",MB_OK|MB_ICONHAND);
			exit (0);
		}
		else
		cout<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"   La direccion ip es: "<<b<<"."<<b2<<".0.0"<<endl;
		cout<<"La mascara por defaul: 255.255.0.0"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<endl;
		system("pause>nul");
		//inicia las direcciones ip
		cout<<"--------------------------------------"<<endl;
		cout<<endl;
		cout<<"Bits Prestados: "<<endl;//bits prestados
		cin>>Bits2;
		h2=16-Bits2;
		Red2=pow(2,Bits2);
		Host2=pow(2,h2);
		cout<<endl<<"HOST: "<<Host2<<endl;
		cout<<" RED: "<<Red2;
		cout<<endl;
		//construccion de las direcciones ips
		//i y j son los bucles que imprimen la direccion ip
		int m2,m3;
		for (i=0; i<Red2; i++){
			cout<<endl<<i;
			for(j=0; j<Host2; j++){
			}
			cout<<" , "<<i<<"."<<j;
			cout<<endl;
			system("pause>nul");
		}
		system("pause>nul");
		exit(0);
	}
	//clase c
	if(Valor=='C'){
		cout<<"Clase C"<<endl;
		cout<<endl<<"La direccion ip deve empesar por numeros sin puto solo (1 a 255)"<<endl;
		cout<<"Introdusca la primera parte: ";
		cin>>c;
		if((c<192)||(c>223)){
			MessageBox(NULL,"ERROR - Valor incorrecto \nEs una clase C  va de la  192 � 223 \n(Vuelbe a ejecutar el programa)                                        ","ERROR",MB_OK|MB_ICONHAND);
			exit (0);
		}
		cout<<"Introdusca la segunda parte: ";
		cin>>c2;
		if((c2<1)||(c2>255)){
			MessageBox(NULL,"ERROR - Valor incorrecto (Vuelbe a ejecutar el programa)                                        ","ERROR",MB_OK|MB_ICONHAND);
			exit (0);
		}
		cout<<"Introdusca la tercera parte: ";
		cin>>c3;
		if((c3<1)||(c3>255)){
			MessageBox(NULL,"ERROR - Valor incorrecto (Vuelbe a ejecutar el programa)                                        ","ERROR",MB_OK|MB_ICONHAND);
			exit (0);}
		cout<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"   La direccion ip es: "<<c<<"."<<c2<<"."<<c3<<".0"<<endl;
		cout<<"La mascara por defaul: 255.255.255.0"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<endl;
		system("pause>nul");
		//inicia las direcciones ip
		cout<<"--------------------------------------"<<endl;
		cout<<endl;
		cout<<"Bits Prestados: "<<endl;//bits prestados
		cin>>bits;
		RedDeEntrada=pow(2,bits);
		BitsDeHost=8-bits;
		h=pow(2,BitsDeHost);
		cout<<endl<<"host: "<<h<<endl;
		cout<<"RED: "<<RedDeEntrada;
		cout<<endl;
		cout<<"--------------------------------------"<<endl;
		for(host=0;host<h;host++){
				contador=contador+1;
				cout<<contador<<":    "<<c<<"."<<c2<<"."<<c3<<"."<<host;
				excusa=h-1;
				if(excusa!=host){
				cout<<"  <------Rango utilizable";}
				if(host==excusa){
					cout<<"  <------Brotcasp";
				}
				else 
				cout<<endl;
			}
		cout<<endl;
		system("pause>nul");
		RedDeEntrada=RedDeEntrada-1;
		contador=h;
		r2=h-1;
		for(red=0;red<RedDeEntrada;red++){
			contador=contador+1;
			r=r+h;
			cout<<endl<<endl;
			cout<<contador<<":         "<<c<<"."<<c2<<"."<<c3<<"."<<r;
			cout<<"   <--------Red "<<red+2<<endl<<endl;
			Hostsalida=r;
			for(host=0;host<r2;host++){
				contador=contador+1;
				Hostsalida=Hostsalida+1;
				cout<<contador<<":    "<<c<<"."<<c2<<"."<<c3<<"."<<Hostsalida;
				excusa=r2-1;
				if(excusa!=host){
				cout<<"  <------Rango utilizable";}
				if(host==excusa){
					cout<<"  <------Brotcasp";
				}
				else 
				cout<<endl;
			}
			system("pause>nul");
		}
		system("pause>nul");
		exit(0);
	}
	if((Valor != 'A')&&(Valor != 'B')&&(Valor != 'C')){
		MessageBox(NULL,"ERROR - Valor incorrecto (Cierra y Vuelbe a ejecutar el programa)                                        ","ERROR",MB_OK|MB_ICONHAND);
		exit(0);
	}
}
/*
MessageBox(NULL,Mensage dentro,mensage de titulo,tipo de icono o cuadro);
MessageBox(NULL,"ERROR","ERROR",MB_ICONHAND);
Par�metros
hWnd

Tipo: HWND

Un identificador de la ventana del propietario del cuadro de mensaje que se va a crear. Si este par�metro es NULL , el cuadro de mensaje no tiene ventana de propietario.

lpText

Tipo: LPCTSTR

El mensaje que se mostrar�. Si la cadena consta de m�s de una l�nea, puede separar las l�neas usando un retorno de carro y / o un car�cter de salto de l�nea entre cada l�nea.

lpCaption

Tipo: LPCTSTR

El t�tulo del cuadro de di�logo. Si este par�metro es NULL , el t�tulo predeterminado es Error .

uType

Tipo: UINT

El contenido y el comportamiento del cuadro de di�logo. Este par�metro puede ser una combinaci�n de banderas de los siguientes grupos de banderas.

Para indicar los botones que se muestran en el cuadro de mensaje, especifique uno de los siguientes valores.
*/
