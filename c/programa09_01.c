/*
	programa 09_01.c
	analizador sintactico predictivo recursivo para numeros
	enteros con signo, modelado con la gramatica
	En -> SE
	E  -> DR
	R  -> DR|vacio
	D  -> 0...9
	S  -> +|-|vacio
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

unsigned char entrada[50];
unsigned char *ca = entrada; /* caracter actual */

void entero_signo();
void entero();
void resto_entero();
void signo();

void main(){
	printf("Expresion : ");gets(entrada);
	entero_signo();
	printf("Expresion valida");
}
void entero_signo()/* ke -> SE*/
{
	signo();
	entero();
}
void entero(){/*e -> DR*/
	if (isdigit(*ca)){//* D -> 0...9
		ca++;
		resto_entero();
	}
	else{
		printf("Se espera digito");
		exit (0);
	}
}
void resto_entero(){
	if (isdigit(*ca)){
		ca++;
		resto_entero();
	}
	/* vacio */
}
void signo(){
	if(*ca=='+' || *ca=='-')
		ca++;
	/* Vacio */
}













