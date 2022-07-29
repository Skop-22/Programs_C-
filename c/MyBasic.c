/*
  PROGRAMA MIBASIC.C
  LENGUAJE MIBASIC
*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

/* DEFINICIÓN DE CONSTANTES PARA LOS TOKENS DE LÉXICO */
#define DELIMITADOR 1
#define VARIABLE    2
#define NUMERO      3
#define INSTRUCCION 4
#define CADENA      5
#define COMILLA     6

/* DEFINICIÓN DE CONSTANTES PARA LAS INSTRUCCIONES */
#define PRINT     1
#define INPUT     2
#define IF        3
#define THEN      4
#define FOR       5
#define NEXT      6
#define TO        7
#define GOTO      8
#define EOL       9   /* END OF LINE */
#define FINISHED  10  /* FIN DE ARCHIVO */
#define GOSUB     11
#define RETURN    12
#define END       13  /* FINALIZAR EL PROGRAMA FUENTE */

/* DEFINICIÓN DE CONSTANTES PARA LAS ETIQUETAS */
#define NUMERO_LABEL   100
#define LABEL_LONGITUD  10

/* DEFINICIÓN DE CONSTANTES PARA LA INSTRUCCIÓN FOR */
#define FOR_NEXT    25
#define GOSUB_NEXT  25

/* LONGITUD TOTAL DEL ARCHIVO A CARGAR */
#define TAMANIO_PROGRAMA 10000

/* TODAS LAS VARIABLES TIENEN VALOR INICIAL CERO */
int variables[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

struct instrucciones
{
  unsigned char nombre[20];
  unsigned char numero;
}tabla_instrucciones[] =
	   {  "print",    PRINT,
	      "input",    INPUT,
	      "if",       IF,
	      "then",     THEN,
	      "goto",     GOTO,
	      "for",      FOR,
	      "next",     NEXT,
	      "to",       TO,
	      "gosub",    GOSUB,
	      "return",   RETURN,
	      "end",      END,
	      "",         END  /* MARCA EL FINAL DE LA TABLA */
	   };

struct etiqueta                /* INSTRUCCIÓN GOTO */
{
  char nombre[LABEL_LONGITUD]; /* NOMBRE DE LA ETIQUETA */
  char *p;                     /* APUNTADOR AL ARCHIVO DE ENTRADA */
};
struct etiqueta tabla_etiquetas[NUMERO_LABEL];

struct pila_para_for
{
  int  inicio;  /* VALOR INICIAL */
  int  fin;     /* VALOR FINAL */
  char *p;      /* APUNTADOR AL ARCHIVO DE ENTRADA */
};
struct pila_para_for pila_for[FOR_NEXT];  /* PILA DEL CICLO FOR/NEXT */
int    for_tope;                          /* TOPE DE LA PILA FOR */

char *gosub_pila[GOSUB_NEXT];  /* PILA PARA GOSUB */
int  gosub_tope;               /* TOPE DE LA PILA GOSUB */

/* VARIABLES MÁS IMPORTANTES */
unsigned char *programa;   /* APUNTADOR AL PROGRAMA A ANALIZAR */
unsigned char token[80];   /* GUARDA LA CADENA DEL TOKEN ACTUAL */
unsigned char token_tipo;  /* GUARDA EL NÚMERO ECONÓMICO DEL TOKEN ACTUAL */
unsigned char instruccion; /* GUARDA EL NÚMERO DE LA "INSTRUCCIÓN", PRINT, INPUT, GOTO, ETC. */

/* PROTOTIPOS */

/* ETAPA DE LÉXICO */
int lexico();
int busca(char *s);
int esblanco(unsigned char c);
int esdelimitador(unsigned char c);

/* GENERADOR DE EXPRESIONES */
void nivel1(int *izquierdo);
void nivel2(int *izquierdo);
void nivel3(int *izquierdo);
void nivel4(int *izquierdo);
void nivel5(int *izquierdo);
void primitiva(int *izquierdo);
void aritmetica(unsigned char o, int *i, int *d);
void unario(unsigned char o, int *r);
int  encuentra_variable(unsigned char *s);

void asignar();     /* EJECUCIÓN DIRECTA */
void print();       /* EJECUCIÓN DIRECTA */
void input();       /* EJECUCIÓN DIRECTA */
void ejecuta_if();  /* EJECUCIÓN DIRECTA */

void ejecuta_goto();                       /* GOTO, EJECUCIÓN */
char *encuentra_etiquetas(char *s);        /* GOTO, GOSUB, AUXILIAR */
void examina_etiquetas();                  /* GOTO, AUXILIAR  */
void inicializa_etiquetas();               /* GOTO, AUXILIAR  */
int  obtiene_siguiente_etiqueta(char *s);  /* GOTO, AUXILIAR  */

void                 ejecuta_for();                      /* FOR, EJECUCIÓN */
void                 for_meter(struct pila_para_for i);  /* FOR, AUXILIAR  */
struct pila_para_for for_sacar();                        /* FOR, AUXILIAR  */
void                 next();                             /* FOR, AUXILIAR  */

void gosub();               /* GOSUB, EJECUCIÓN */
void gosub_meter(char *s);  /* GOSUB, AUXILIAR  */
void gosub_return();        /* GOSUB, AUXILIAR  */
char *gosub_sacar();        /* GOSUB, AUXILIAR  */

int  carga_programa(char *p, char *archivo_nombre);  /* GENÉRICA */
void encuentra_eol();                                /* GENÉRICA */
void error(int error);                               /* GENÉRICA */
void retorno();                                      /* GENÉRICA */

/* ------------------------------------------------------------------------------------- */
void main(int argc, char *argv[])
{
  char *apuntador_buffer;

  if (argc != 2)
  {
     printf(" Uso: MIBASIC <nombre_archivo>\n");
     exit(1);
  }

  /* ASIGNA MEMORIA AL PROGRAMA */
  if (!(apuntador_buffer = (char *) malloc(TAMANIO_PROGRAMA)))
  {
     printf("No hay suficiente memoria");
     exit(1);
  }
//-Fin de la pagina uno
  /* CARGA EL PROGRAMA A EJECUTAR */
  if (!carga_programa(apuntador_buffer, argv[1]))
     exit(1);

  programa = apuntador_buffer;

  examina_etiquetas();  /* ENCUENTRA LAS ETIQUETAS EN EL PROGRAMA */

  do
  {
     token_tipo = lexico();
     /* DEBE SER UNA INSTRUCCIÓN O UNA ASIGNACIÓN */
     if (token_tipo == VARIABLE)  /* ASIGNACIÓN */
     {
	retorno();  /* RETORNA LA VARIABLE A LA ENTRADA */
	asignar();  /* INTERPRETACIÓN DE LA INSTRUCCIÓN ASIGNAR */
     }
     else   /*  ES INSTRUCCIÓN */
	switch(instruccion)
	{
	   case PRINT  : print()       ; break;
	   case INPUT  : input()       ; break;
	   case IF     : ejecuta_if()  ; break;
	   case GOTO   : ejecuta_goto(); break;
	   case FOR    : ejecuta_for() ; break;
	   case NEXT   : next()        ; break;
	   case GOSUB  : gosub()       ; break;
	   case RETURN : gosub_return(); break;
	   case END    : exit(0)       ;
	}
  }while (instruccion != FINISHED);
}

/* --------------------------------- ETAPA DE LÉXICO -------------------------------- */
int lexico()
{
  unsigned char *temp;

  token_tipo = 0; instruccion = 0;
  temp = token;

  if (*programa=='\0')
  {  /* FIN DE ARCHIVO */
     *token = 0;
     instruccion = FINISHED;
     return(token_tipo = DELIMITADOR);
  }

  while (esblanco(*programa)) programa++;  /* OMITE ESPACIOS EN BLANCO */

  if (*programa == '\r')
  {  /* SALTO DE LÍNEA */
     programa++; programa++;
     instruccion = EOL;
     *token = '\r';
     token[1] = '\n';
     token[2] = 0;
     return (token_tipo = DELIMITADOR);
  }

  if (strchr("+-*/%()=><," , *programa))
  {  /* DELIMITADOR */
     *temp = *programa;
     programa++;
     temp++;
     *temp = 0;
     return (token_tipo = DELIMITADOR);
  }

  if (*programa == '"')
  {  /* CADENA ENTRE COMILLAS */
     programa++;
     while (*programa != '"' && *programa != '\r')
	*temp++ = *programa++;
     if (*programa == '\r')
	error(1);
     programa++;
     *temp = 0;    /* CIERRA LA CADENA */
     return(token_tipo = COMILLA);
  }

  if (isdigit(*programa))
  {  /* NÚMERO */
     while(!esdelimitador(*programa) && !esblanco(*programa) && *programa!='\r')
	*temp++ = *programa++;
     *temp = '\0';
     return (token_tipo = NUMERO);
  }

  if (isalpha(*programa))
  {  /* VARIABLE O INSTRUCCIÓN */
     while (!esdelimitador(*programa) && !esblanco(*programa) && *programa!='\r')
	*temp++ = *programa++;
     token_tipo = CADENA;
  }

  *temp='\0';

  /* VERIFICA SI UNA CADENA ES UNA INSTRUCCIÓN O UNA VARIABLE */
  if (token_tipo==CADENA)
  {
     instruccion = busca(token);
     if (!instruccion)
	token_tipo = VARIABLE;
     else
	token_tipo = INSTRUCCION;
  }
  return token_tipo;
}

/* BUSCA UNA REPRESENTACIÓN INTERNA DEL SÍMBOLO EN LA TABLA DE SÍMBOLOS */
int busca(char *s)
{
  register int i,j;
  char *p;
  /* CONVIERTE EN MINÚSCULAS */
  p=s;
  while(*p)
  {
     *p=tolower(*p);
     p++;
  }
  /* VERIFICA SI UN SÍMBOLO ESTÁ EN LA TABLA */
  for (i=0; *tabla_instrucciones[i].nombre; i++)
  if (!strcmp(tabla_instrucciones[i].nombre,s))
     return tabla_instrucciones[i].numero;
  return 0;  /* INSTRUCCIÓN NO DEFINIDA */
}

/* RETORNA 1 SI C ES BLANCO O TAB */
int esblanco(unsigned char c)
{
  if ( c==' ' || c=='\t')
     return 1;
  else
     return 0;
}

/* RETORNA 1 SI C ES UN DELIMITADOR */
int esdelimitador(unsigned char c)
{
  if (strchr("+-*/%()><=," , c))
     return 1;
  else
     return 0;
}


/* ----------------------------- GENERADOR DE EXPRESIONES ----------------------------- */
void nivel1(int *izquierdo)
{
  lexico();
  if (!*token)
  {
     error(2);
     return;
  }
  nivel2(izquierdo);
  retorno();
}

/* SUMA O RESTA */
void nivel2(int *izquierdo)
{
  unsigned char op;
  int derecho;

  nivel3(izquierdo);
  while((op=*token)=='+' || op=='-')
  {
     lexico();
     nivel3(&derecho);
     aritmetica(op, izquierdo, &derecho);
  }
}

/* MULTIPLICA, DIVIDE O RESIDUO */
void nivel3(int *izquierdo)
{
  register unsigned char op;
  int derecho;

  nivel4(izquierdo);
  while((op=*token)=='*' || op=='/' || op=='%')
  {
     lexico();
     nivel4(&derecho);
     aritmetica(op, izquierdo, &derecho);
  }
}

/* UNARIO */
void nivel4(int *izquierdo)
{
  register unsigned char op;

  op = 0;
  if ((token_tipo == DELIMITADOR) && *token=='+' || *token=='-')
  {
     op = *token;
     lexico();
  }
  nivel5(izquierdo);
  if (op)
     unario(op, izquierdo);
}

/* PROCESA EXPRESIONES ENTRE PARÉNTESIS */
void nivel5(int *izquierdo)
{
  if ((*token=='(') && (token_tipo==DELIMITADOR))
  {
     lexico();
     nivel2(izquierdo);
     if (*token != ')')
     error(1);
     lexico();
  }
  else
     primitiva(izquierdo);
}

/* ENCUENTRA EL VALOR DE UN NÚMERO O VARIABLE */
void primitiva(int *izquierdo)
{
  switch(token_tipo)
  {
     case VARIABLE : *izquierdo = encuentra_variable(token);
		     lexico();
		     return;
     case NUMERO   : *izquierdo = atoi(token);
		     lexico();
		     return;
     default       : error(0);
  }
}

/* REALIZA LAS OPERACIONES ARITMÉTICAS */
void aritmetica(unsigned char o, int *i, int *d)
{
  switch(o)
  {
     case '-' : *i = *i - *d;     break;
     case '+' : *i = *i + *d;     break;
     case '*' : *i = *i * *d;     break;
     case '/' : *i = (*i) / (*d); break;
     case '%' : *i = (*i) % (*d); break;
  }
}

/* CAMBIA EL SIGNO */
void unario(unsigned char o, int *i)
{
  if (o=='-')
     *i = -(*i);
}

/* ENCUENTRA EL VALOR DE UNA VARIABLE */
int encuentra_variable(unsigned char *s)
{
  if(!isalpha(*s))
  {
     error(4);
     return 0;
  }
  return variables[toupper(*token)-'A'];
}

/* -------------------------------- EJECUCIÓN DIRECTA --------------------------------- */

/* ASIGNA UN VALOR A UNA VARIABLE */
void asignar()
{
  int var, valor;

  /* OBTIENE EL NOMBRE DE LA VARIABLE */
  lexico();
  if (!isalpha(*token))
  {
     error(4);
     return;
  }

  var = toupper(*token) - 'A';

  /* OBTIENE EL SÍMBOLO IGUAL */
  lexico();
  if (*token != '=')
  {
     error(3);
     return;
  }

  /* OBTIENE EL VALOR PARA ASIGNAR A LA VARIABLE */
  nivel1(&valor);

  /* ASIGNA VALOR */
  variables[var] = valor;
}

/* EJECUTA LA INSTRUCCIÓN PRINT */
void print()
{
  int  resultado;
  char ultimo_delimitador;

  do
  {
     lexico();
     if (instruccion == EOL || instruccion == FINISHED) break;
     if (token_tipo == COMILLA)
     {  /* ES CADENA */
	printf(token);
	lexico();
     }
     else
     {  /* ES UNA EXPRESIÓN */
	retorno();
	nivel1(&resultado);
	lexico();
	printf("%d",resultado);
     }
     ultimo_delimitador = *token;
  }while(*token == ',');

  if (instruccion == EOL || instruccion == FINISHED)
  {
     if (ultimo_delimitador != ',')
	printf("\n");
  }
  else
     error(0);  /* ERROR NO ES , */
}

/* EJECUTA LA INSTRUCCIÓN INPUT */
void input()
{
  char cadena[80], var;
  float i;

  lexico();
  if (token_tipo == COMILLA )  /* EXISTE UN MENSAJE EN LA LECTURA */
  {//oja 3
     printf(token);  /* MUESTRA EL MENSAJE */
     lexico();
     if (*token != ',')
	error(1);
     lexico();
  }
  else
     printf("? ");  /* NO HAY MENSAJE, DESPLIEGA POR OMISIÓN ? */

  if (!isalpha(*token)) error(4);

  var = toupper(*token) - 'A';  /* OBTIENE LA VARIABLE */
  scanf("%d", &i);              /* LEE ENTRADA */
  variables[var] = i;           /* ALMACENA LA ENTRADA */
}

/* EJECUTA LA INSTRUCCIÓN IF */
void ejecuta_if()
{
  int izquierdo, derecho, condicion;
  char op;

  nivel1(&izquierdo);          /* OBTIENE LA EXPRESIÓN IZQUIERDA */
  lexico();                    /* OBTIENE AL OPERADOR */
  if (!strchr("=<>",*token))
  {
     error(0);                 /* NO ES UN OPERADOR PERMITIDO */
     return;
  }
  op = *token;

  nivel1(&derecho);  /* OBTIENE LA EXPRESIÓN DERECHA */

  /* DETERMINA EL RESULTADO */
  condicion = 0;
  switch (op)
  {
     case '=' : if (izquierdo==derecho) condicion = 1; break;
     case '<' : if (izquierdo<derecho)  condicion = 1; break;
     case '>' : if (izquierdo>derecho)  condicion = 1; break;
  }
  if (condicion)
  {  /* VERDADERO SE PROCESA LA PARTE AFIRMATIVA */
     lexico();
     if (instruccion != THEN)
     {
	error(8);
	return;
     }
  }
  else
     encuentra_eol();  /* ENCUENTRA EL COMIENZO DE LA SIGUIENTE LÍNEA */
}

/* -------------------------------------- GOTO --------------------------------------- */

/* EJECUTA LA INSTRUCCIÓN GOTO */
void ejecuta_goto()
{
  char *direccion;

  lexico();  /* OBTIENE ETIQUETA PARA SALTAR */
  /* ENCUENTRA LA POSICIÓN DE LA ETIQUETA */
  direccion = encuentra_etiquetas(token);
  if (direccion == '\0')
     error(7);  /* ETIQUETA NO DEFINIDA */
  else
     programa = direccion;  /* EJECUTA EL SALTO */
}

/* ENCUENTRA LA POSICIÓN DE UNA ETIQUETA DADA. SE RETORNA NULO SI LA ETIQUETA NO ES ENCONTRADA, 
   EN OTRO CASO ES RETORNADO UN APUNTADOR A LA POSICIÓN DE LA ETIQUETA */
char *encuentra_etiquetas(char *s)
{
  int t;

  for (t=0; t<NUMERO_LABEL; t++)
     if (!strcmp(tabla_etiquetas[t].nombre,s))
	return tabla_etiquetas[t].p;
  return '\0';
}

/* ENCUENTRA TODAS LAS ETIQUETAS */
void examina_etiquetas()
{
  int  indice;
  char *temp;

  inicializa_etiquetas();  /* CERO TODAS LAS ETIQUETAS */
  temp = programa;         /* SALVA EL INICIO DEL PROGRAMA FUENTE */
  /* SI EL PRIMER SÍMBOLO EN EL PROGRAMA ES UNA ETIQUETA */
  lexico();
  if (token_tipo == NUMERO)
  {
     strcpy(tabla_etiquetas[0].nombre,token);
     tabla_etiquetas[0].p=programa;
  }
  encuentra_eol();
  do
  {
     lexico();
     if (token_tipo == NUMERO)
     {
	indice = obtiene_siguiente_etiqueta(token);
	if (indice == -1 || indice == -2)
	   (indice == -1) ? error(5) : error(6);
	strcpy(tabla_etiquetas[indice].nombre,token);
	tabla_etiquetas[indice].p = programa;  /* DIRECCIÓN ACTUAL DEL PROGRAMA */
     }
     /* SI NO ES UNA LÍNEA EN BLANCO ENCUENTRA LA SIGUIENTE LÍNEA */
     if (instruccion != EOL) encuentra_eol();
  } while (instruccion != FINISHED);
  programa = temp;  /* RESTAURA EL PROGRAMA */
}

void inicializa_etiquetas()
{
  int t;

  for(t=0; t<NUMERO_LABEL; ++t)
     tabla_etiquetas[t].nombre[0] = '\0';
}

/* RETORNA EL ÍNDICE DE LA SIGUIENTE POSICIÓN LIBRE EN LA TABLA ETIQUETA
   -1 ES RETORNADO SI LA TABLA ESTÁ LLENA
   -2 ES RETORNADO SI UNA ETIQUETA DUPLICADA ES ENCONTRADA */
int obtiene_siguiente_etiqueta(char *s)
{
  register int t;

  for (t=0; t<NUMERO_LABEL; ++t)
     if (tabla_etiquetas[t].nombre[0]==0) return t;
		if (!strcmp(tabla_etiquetas[t].nombre,s)) return -2;
  return -1;
}

/* ---------------------------------------- FOR --------------------------------------- */

/* EJECUTA EL BUCLE FOR */
void ejecuta_for()
{
  struct pila_para_for i;
  int valor;

  lexico();  /* LEE LA VARIABLE DE CONTROL */
  if (!isalpha(*token))
  {
     error(4);
     return;
  }

  i.inicio = toupper(*token) - 'A';  /* SALVA SUS ÍNDICES */
  lexico();  /* LEE EL SIGNO IGUAL */
  if (*token != '=')
  {
     error(3);
     return;
  }

  nivel1(&valor);  /* OBTIENE EL VALOR INICIAL */
  variables[i.inicio] = valor;

  lexico();
  if (instruccion != TO)  /* INSTRUCCIÓN SÓLO PARA EFECTOS SINTÁCTICOS */
     error(9);

  nivel1(&i.fin);  /* OBTIENE EL VALOR FINAL */

  /* SI EL CICLO SE PUEDE EJECUTAR AL MENOS UNA VEZ, SE METE EN LA PILA */
  if (i.fin >= variables[i.inicio])
  {
     i.p = programa;
     for_meter(i);
  }
  else
     /* OTRO CASO SALTA EL BLOQUE DEL CICLO */
     while (instruccion != NEXT )
	lexico();
}

/* METER EN LA PILA FOR */
void for_meter(struct pila_para_for i)
{
  if (for_tope > FOR_NEXT)  /* ANIDAMIENTO COMPLETO */
     error(10);
  pila_for[for_tope] = i;
  for_tope++;
}

struct pila_para_for for_sacar()
{
  for_tope--;
  if (for_tope < 0)
     error(11);
  return(pila_for[for_tope]);
}

/* EJECUTA LA INSTRUCCIÓN NEXT */
void next()
{
  struct pila_para_for i;

  i = for_sacar();  /* LEE EL CICLO */

  variables[i.inicio]++;  /* INCREMENTA LA VARIABLE DE CONTROL */
  if (variables[i.inicio] > i.fin ) return;  /* TODO TERMINADO */
  for_meter(i);    /* OTRO CASO, RESTAURA EL CICLO */
  programa = i.p;  /* SALTO AL INICIO DEL CICLO */
}

/* ------------------------------------- GOSUB ---------------------------------------- */

/* EJECUTA LA INSTRUCCIÓN GOSUB */
void gosub()
{
  char *direccion;

  lexico();
  /* ENCUENTRA LA ETIQUETA A LLAMAR */
  direccion = encuentra_etiquetas(token);
  if (direccion == '\0')
     error(7);  /* ETIQUETA NO DEFINIDA */
  else
  {
     gosub_meter(programa);  /* SALVA DIRECCIÓN PARA RETORNAR */
     programa = direccion;   /* EL PROGRAMA SE EJECUTA A PARTIR DE DIRECCIÓN */
  }
}

/* METER EN LA PILA GOSUB */
void gosub_meter(char *s)
{
  gosub_tope++;
  if (gosub_tope == GOSUB_NEXT)
  {
     error(12);
     return;
  }
  gosub_pila[gosub_tope] = s;
}

/* RETORNA DESDE GOSUB */
void gosub_return()
{
  programa = gosub_sacar();
}

char *gosub_sacar()
{
  if (gosub_tope == 0)
  {
     error(13);
     return 0;
  }
  return (gosub_pila[gosub_tope--]);
}

/* ------------------------------------- GENÉRICAS ------------------------------------ */

int carga_programa(char *p, char *archivo_nombre)
{
  FILE *fp;
  int i=0;

  if (!(fp=fopen(archivo_nombre,"rb"))) return 0;

  i=0;
  do
  {
     *p = getc(fp);
     p++;
     i++;
  }while(!feof(fp) && i<TAMANIO_PROGRAMA);
  *(p-1) = '\0';  /* CIERRA EL BUFFER */
  fclose(fp);

  return 1;
}

void encuentra_eol()
{
  while (*programa != '\n' && *programa != '\0')
     programa++;
  if (*programa)
     programa++;
}

void error(int error)
{
  unsigned char *e[] =
  {
     "ERROR DE SINTAXIS",
     "PARENTESIS NO BALANCEADOS",
     "NINGUNA EXPRESION PRESENTE",
     "SIGNO IGUAL ESPERADO",
     "NO ES UNA VARIABLE",
     "TABLA DE ETIQUETAS LLENAS",
     "ETIQUETA DUPLICADA",
     "ETIQUETA NO DEFINIDA",
     "THEN ESPERADO",
     "TO ESPERADO",
     "DEMASIADOS BUCLES FOR ANIDADOS",
     "NEXT SIN FOR",
     "DEMASIADOS GOSUB ANIDADOS",
     "RETURN SIN GOSUB",
  };
  printf("%s\n", e[error]);
  exit(1);
}

/* RETORNA UN SÍMBOLO A LA ENTRADA */
void retorno()
{
  unsigned char *t;
  t=token;
  for (; *t; t++)
     programa--;
}
