/*
	Programa 09_02.c
	analizador sintactico predictivo recirsivo para el reconocimiento 
	d expreciones, modelado con la gramatica
		E  -> TE'
		E' -> +TE'|vacio
		T  -> FT'
		T' -> *FT'|vacio
		p  -> (E) |0...9
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

unsigned char entrada[50];
unsigned char *ca = entrada; /*caracter actual*/

void E();
void Eprima();
void T();
void Tprima();
void F();

void main(){
	printf("Expresion: "); gets(entrada);
	E();
	printf("expresion valida");
}
void E(){/* E -> TE'*/
	T();
	Eprima();
}
void Eprima(){/* E' -> +TE'|vacio */
	if (*ca == '+'){
		ca++;
		T();
		Eprima();
	}
	/*vacio*/
}

void T(){
	F();
	Tprima();
}

void Tprima(){
	if (*ca == '*'){
		ca++;
		F();
		Tprima();
	}
	/*vacio*/
}

void F(){
	if(isdigit(*ca))
		ca++;
	else
	if(*ca == '('){
		ca++;
		E();
		if(*ca == ')')
			ca++;
		else{
			printf("Se espera parentesis derecho u operador");
			exit(0);
		}
	}
	else {
		printf("se espera digito o prarentesis izquierdo");
		exit(0);
	}
}
