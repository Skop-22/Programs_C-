//david Emanuel Flores Beltran
//Cabeceras
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.1415926 //al valor de PI
FILE *flujo;//para abrir el archivo
char caracter;

// Funciones declaradas
void EnArchivo(char*);//funcion para leer el archivo
float Calculo(int);//funcionen para Calcular los datos
void SaArchivo();//Funcion de salidad de datos en un archivo;

//funcion para leer archivos
void EnArchivo(char *Archivo){
	flujo= fopen(Archivo,"r");
	if(flujo==NULL){
		printf("Error al leer el archivo");
		exit(1);
	}else{
		while(feof(flujo)==0) {
			caracter=fgetc(flujo);
			printf("%c\n",caracter);
		}
	}
	fclose(flujo);
}

//funcion para calcular los datos
float Calculo(int x){
	float Fun,rad;
	rad=x*PI/180;//convierte de grados a radianes para seno y coseno
	if ((x%2)!=0){ 
		Fun=((exp(x))*(sin(rad)))/x; 
		return Fun;}//retorna la salida
	else{
		Fun=((exp(x))*(cos(rad)))/x; 
		return Fun;}//retorna la salida
}

//Metodo Principal
int main(int argc, char *argv[]){
	int Convert;
	EnArchivo(argv[1]);
	return 0;
}