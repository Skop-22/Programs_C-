/*
	David Emanuel Flores Beltran
	programa 02_01.c
	lenguaje para recetas de cocina 
*/
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<process.h>
#include<ctype.h>
/* constantes de numeros de tokens */
#define NUMERO_INGREDIENTE  32
#define NUMERO_MEDIDA        8
#define NUMERO_PRESENTACION 14

/* tokens */
#define ADEREZO                  0
#define CANTIDAD_1               1  /* se define 3 consatantes para cantidad*/
#define CANTIDAD_2_O_MAS         2  /* por custiones semanticas             */
#define CANTIDAD_FRACCION        3
#define COMA                     4
#define CONJUNCION               5
#define FIN                      6
#define INGREDIENTE              7
#define MEDIDA                   8
#define PREPOSICION              9
#define PRESENTACION            10
#define SALTO_LINEA             11

char *entrada;  /* apuntador que contiene la receta */
int numero_linea =1; /* contador de lineas */

/* variables de lexico */
unsigned int token;              /* numero economico de token */
unsigned char cadena_token[50];  /* cadena actual del token   */

/* variables de semantica */
int indice_cantidad, indice_medida, indice_ingrediente, indice_presentacion;

/* prototipos de funciones */
void cargar_archivo_memoria(int a, char *b);
void error(int a);
void lexico();
void semantica_cantidad_medida();
void semantica_ingrediente_presentacion();
void sintaxis();

/**********************************************/
void main(int argc, char * argv[]){
	cargar_archivo_memoria(argc, argv[1]);
	do{
		sintaxis();
	}while (token!=FIN);
	printf("Receta correcta");
}
/*********************************************************************/

void cargar_archivo_memoria(int a, char *b){
	FILE *fp;
	char *auxiliar;
	
	entrada =(char *) malloc(2000); /* la receta no puede contener mas de 2000 caracteres */
	auxiliar = entrada; /* auxiliar copia el archivo a memoria */
	if (entrada == 0) error(1); /* memoria no asignada */
	if (a != 2) error(2);/* validacion para archivo que contiene la receta */
	fp=fopen(b,"rb");/* apertura del archivo que contiene la receta */ 
	if (fp == NULL) error(0);
	
	while(!feof(fp)) { /* transferencia del archivo a la memoria */
		*auxiliar =getc (fp);
		auxiliar++;
	}
	*(auxiliar-1) = 0; /*cierre del buffer*/
	fclose(fp);
}
/*********************************************************************/

void error (int a){
	unsigned char errores [7][70]={
		"Apertura del archivo erronea, AMBIENTE",
		"Asgnacion de memoria no realizada, AMBIENTE",
		"Archivo con la receta no enviado, AMBIENTE",
		"Ingrediente no definido no enviado, AMBIENTE",
		"Palabra no definida, USUARIO",
		"Relacion no valida entre cantidad y medida, USUARIO",
		"Relacion no valida entre ingrediente y presentacion, USUARIO",
	};
	printf("Linea %d: %s",numero_linea,errores[a]);
	exit(1);
}
/***********************************************************************/
void lexico(){
	static unsigned char ingrediente[NUMERO_INGREDIENTE][50]={
		"aceite_de_oliva","aguacate","ajo","apio","carne_de_res","cabolla",
		"champinones","chiles_ancho","chiles_chipotles_en_escabeche",
		"chiles_huajillo","consome_de_pollo","diente_de_ajo","falda_de_res",
		"germinado_de_soya","huevo","jengibre","jugo_maggi","lechuga","mayonesa",
		"mostaza","pimientas","pimientas_gordas","pimiento_morron","pollo",
		"queso_panela","salsa_inglesa","tomates","tomillo","tripa_de_puerco",
		"sal","vinagre","zanahorias"
	};
	static unsigned char medida[NUMERO_MEDIDA][50]={
	"cucharada","cucharadas","gramos","kilo","kilos","lata","ramas_de","taza" };
	
	static unsigned char presentacion[NUMERO_PRESENTACION][50]={
		"al_gusto","cortada_a_lo_alto","duro","en_tiras","finamente_ralladas",
		"fresco","la_necesaria","molida","molido","picado","picados","rallado",
		"rebanada","rebanados"
	};
	char *auxiliar;
	int i;
	auxiliar = cadena_token;  /*auxiliar va almacenada la cadena del token*/
	while(*entrada == ' ' || *entrada == '\t')/*consume blancos*/
		entrada ++;
	if(*entrada=='\r'){
		token=SALTO_LINEA;
		entrada =entrada+2;/*hasta la siguiente linea*/
		return;
	}
	if(*entrada == NULL){
		token = FIN;
		return;
	}
	while(!isspace(*entrada)&& *entrada != 0){ /* agrupa la cadena de la entrada */
		*auxiliar =*entrada;
		entrada++;
		auxiliar++;
	}
	*auxiliar = NULL;  /*cierra la cadena del token */
	if( (strcmp(cadena_token,"y") && strcmp(cadena_token,"o"))==0){
		token = CONJUNCION;
		return;
	}
	if (strcmp(cadena_token,"de") == 0){
		token = PREPOSICION;
		return;
	}
	if(strcmp(cadena_token,"aderezo:")==0){
		token = ADEREZO;
		return;
	}
	if(strcmp(cadena_token,"1") == 0){
		token = CANTIDAD_1;
		indice_cantidad =0;
		return;
	}
	if((strcmp(cadena_token,"2") && strcmp(cadena_token,"3") &&
		strcmp(cadena_token,"4") && strcmp(cadena_token,"5") &&
		strcmp(cadena_token,"6") && strcmp(cadena_token,"10") &&
		strcmp(cadena_token,"200"))==0){
			token = CANTIDAD_2_O_MAS;
			indice_cantidad = 1;
			return;
		}
	if((strcmp(cadena_token,"1/2") && strcmp(cadena_token,"1/4")) == 0){
		token = CANTIDAD_FRACCION;
		indice_cantidad = 2;
		return;
	}
	if(strcmp(cadena_token,",") == 0){
		token = COMA;
		return;
	}
	for (i=0;i<NUMERO_INGREDIENTE;i++) /* busqueda de ingredientes */
		if (strcmp(cadena_token,ingrediente[i]) == 0){
			token =INGREDIENTE;
			indice_ingrediente = i; /* para la fila de la matriz de semantica */
			return;
		}
	for (i=0;i<NUMERO_MEDIDA;i++) /* busqueda de medidas */
		if(strcmp(cadena_token,medida[i]) == 0){
			token = MEDIDA;
			indice_medida = 1;
			return;
		}
	for (i=0;i<NUMERO_PRESENTACION;i++) /* busqueda de presentaciones */
		if(strcmp(cadena_token,presentacion[i]) == 0){
			token = PRESENTACION;
			indice_presentacion = 1;
			return;
		}
	error(4);
}
/********************************************************************************************/
void semantica_cantidad_medida(){
	static unsigned int relacion_cantidad_medida[3][NUMERO_MEDIDA] ={
		/* Cucharada cucharadas gramos kilo kilos lata ramasde taza */
/*1     */     1,      0,        0,     1,    0,   1,     0,    1,
/*>=2   */     0,      1,        1,     0,    1,   0,     1,    0,
/*fraccion*/   1,      0,        0,     1,    0,   1,     1,    1
	};
	if(relacion_cantidad_medida[indice_cantidad][indice_medida] != 1)
	error(5);
}
/********************************************************************************************/
void semantica_ingrediente_presentacion(){
	static unsigned int relacion_ingrediente_presentacion[NUMERO_INGREDIENTE][NUMERO_PRESENTACION] ={
				/*  gusto      duro      finrall necesar molido   picados  rebanada */
/* oliva          */  1,   0,   0,    0,   0,  0,  0,  0,  0,  0,   0,  0,   0,  0,
/* aguacate       */  1,   0,   0,    0,   0,  0,  0,  0,  1,  1,   1,  0,   0,  1,
/* ajo            */  1,   0,   0,    0,   1,  0,  0,  0,  1,  1,   1,  0,   0,  1,
/* apio           */  0,   0,   0,    1,   1,  1,  0,  0,  1,  1,   1,  0,   0,  0,
/* carne res      */  0,   1,   0,    1,   0,  0,  0,  1,  0,  0,   0,  0,   1,  0,
/* cebolla        */  1,   1,   0,    1,   1,  0,  0,  1,  0,  1,   1,  1,   1,  0,
/* champiñones    */  1,   0,   0,    1,   0,  0,  0,  0,  0,  0,   1,  0,   0,  1,
/* chile ancho    */  0,   0,   0,    1,   0,  0,  0,  0,  1,  1,   1,  0,   0,  1,
/* chiles chipo   */  1,   0,   0,    0,   0,  0,  0,  0,  0,  1,   0,  0,   0,  0,
/* chiles huaji   */  1,   0,   0,    0,   0,  0,  1,  0,  1,  0,   1,  0,   0,  1,
/* consome pollo  */  0,   0,   0,    0,   0,  0,  0,  0,  0,  0,   0,  0,   0,  0,
/* dientes ajo    */  1,   0,   0,    0,   0,  0,  0,  0,  0,  0,   1,  0,   0,  0,
/* falde res      */  0,   1,   0,    1,   0,  0,  0,  1,  0,  1,   0,  0,   1,  0,
/* germ soya      */  0,   0,   0,    0,   0,  0,  0,  0,  0,  0,   0,  0,   0,  0,
/* huevo          */  0,   0,   1,    0,   0,  0,  0,  0,  0,  0,   0,  0,   0,  0,
/* jengibre       */  1,   0,   0,    0,   1,  0,  0,  0,  1,  1,   0,  1,   0,  1,
/* jugo maggi     */  1,   0,   0,    0,   0,  0,  0,  0,  0,  0,   0,  0,   0,  0,
/* lechuga        */  1,   0,   0,    1,   1,  0,  0,  0,  0,  1,   0,  0,   0,  0,
/* mayonesa       */  1,   0,   0,    0,   0,  0,  0,  0,  0,  0,   0,  0,   0,  0,
/* moztaza        */  1,   0,   0,    0,   0,  0,  0,  0,  0,  0,   0,  0,   0,  0,
/* pimientas      */  1,   0,   0,    0,   0,  0,  0,  1,  0,  0,   0,  0,   0,  0,
/* pim gordas     */  1,   0,   0,    0,   0,  0,  0,  1,  0,  0,   0,  0,   0,  0,
/* pim morron     */  0,   0,   0,    1,   0,  0,  0,  0,  1,  1,   0,  0,   0,  0,
/* pollo          */  0,   0,   0,    1,   0,  0,  0,  1,  0,  1,   1,  0,   0,  0,
/* queso panela   */  1,   0,   0,    1,   0,  0,  0,  0,  0,  0,   0,  0,   0,  0,
/* salsa inglesa  */  1,   0,   0,    0,   0,  0,  0,  0,  0,  0,   0,  0,   0,  0,
/* tomates        */  1,   0,   0,    1,   0,  0,  0,  0,  1,  0,   1,  1,   0,  1,
/* tomillo        */  1,   0,   0,    0,   0,  0,  0,  0,  1,  0,   0,  0,   0,  0,
/* tripa puerco   */  0,   0,   0,    0,   0,  0,  1,  0,  0,  0,   0,  0,   0,  0,
/* sal            */  1,   0,   0,    0,   0,  0,  0,  0,  0,  0,   0,  0,   0,  0,
/* vinagre        */  1,   0,   0,    0,   0,  0,  0,  0,  0,  0,   0,  0,   0,  0,
/* zanahorias     */  1,   0,   0,    1,   1,  0,  0,  0,  0,  0,   0,  0,   0,  0
	};            /*  cort  alto  tiras     fresco  molida  picado   rallado  rebanados*/
	if(relacion_ingrediente_presentacion[indice_ingrediente][indice_presentacion] != 1 )
		error(6);
}
/********************************************************************************************/
void sintaxis(){
	unsigned char semantica_cantidad[50], semantica_ingrediente[50];
	lexico(); /* se toma el primer token */
	switch (token){ /* camino opcional */
		case CANTIDAD_1         :
		case CANTIDAD_2_O_MAS   :
		case CANTIDAD_FRACCION  : lexico();  /* tomar el siguiente token */
		/*cantidad -medida*/    if(token ==MEDIDA){
								semantica_cantidad_medida();
								lexico();
/* cantidad-medida preposicion*/if(token == PREPOSICION)
									lexico();}
								else
									if (token == PREPOSICION)
									lexico();
								break;
		case ADEREZO  :         lexico();    /* alcanza el fin de línea         */
								return;    /* puede haber n aderezos          */
		case SALTO_LINEA :      return;    /* realiza la siguiente iteración  */
		case FIN         :      return;    /* no hace nada                    */
	}
	/* cualquier camino prvio lleva a ingrediente, inclusive ninguno */
	if (token != INGREDIENTE) /* se exige ingrediente */
	error(3);
	
	lexico();
	
	if (token == COMA){
		while (token == COMA){
			lexico();
			if (token != INGREDIENTE)
				error(3);
			lexico();
		}
		if (token == CONJUNCION){
			lexico();
			if (token != INGREDIENTE)
				error(3);
			lexico();
		}
	}
	else 
		if (token == CONJUNCION){
			lexico();
			if (token != INGREDIENTE)
				error(3);
				lexico();
		}
	if (token == SALTO_LINEA || token == FIN) return; /* concluye línea */
	/* cualquier camino lleva a presentacion, inclusive ninguno*/
	if (token == PRESENTACION){
		semantica_ingrediente_presentacion();
		lexico();
	}
}
