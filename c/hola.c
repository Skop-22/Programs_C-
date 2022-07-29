#include <stdio.h>                        //liberias
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int main ()                              //Inicio de main
{
char a[90], b[90], c[90];                //variables para la entrada de caracteres
double fx;                               //variable que tomara el valor de a[90] pero ya como número
int op, op2, w;                             //variable que tomara el valor de b[90], c[90] pero ya como número


do {                                     //Inicio de do para hacer y ciclar todo el programa

system ("clear");                        //Limpia pantalla
printf("                                 ****Bienvenidos****\n\n");                     //Bienvenida...
printf("En este programa se realiza la funcion para encontrar x en funcion de f(x)= (sin x)/((x^2)-4)"); 
printf("      \nQue desea realizar?\n");
printf("      \n1. Resolver funcion: f(x)= (sin x)/((x^2)-4)\n");
printf("      \n2. Salir\n\n");

printf("Elija una opcion: ");                                     //... fin de la bienvenida
scanf("%s",c);                           //guarda el dato ingresado, sea numero o culquier otro caracter en c[90]                                                  
op=atoi(c);                              // atoi convierte c[90] en un valor numerico y lo guarda en op, en caso de no poder convertilo lo regresa como 0

if (op!=1)                               //if realiza la comparación de si op es diferente de 1 que pase a la siguiente línea
  if (op!=2){                            //if realiza la comparación de si op es diferente de 2 que pase a la siguiente línea
   while(op!=1){                         //while indica que cuando op sea diferente de 1, solo así se ciclará su contenido hasta que no se la condición 
    system ("clear");
    printf("***Error, introduzca una opcion valida***\n");            //contenido de while...
    printf("      \nQue desea realizar?\n");            
    printf("\n1. Resolver funcion: f(x)= (sin x)/((x^2)-4)\n");      //... realiza la misma pregunta que en la bienvenida...
    printf("\n2. Salir\n");
    printf("Elija una opcion: ");
    scanf("%s",c);
    op=atoi(c);
}                  //fin de while
 }                 //fin del if

switch (op){       //inicio de switch para realizar el caso que se presente segun sea op

 case 1:             //inicio del caso 1 
                                                          
  system ("clear");                                                   //limpia pantalla
  printf("\n1. Resolver funcion: f(x)= (sin x)/((x^2)-4)\n");         //muestra la opción que fue elegida
  printf("\nx= ");                                                    //pregunta le valor de x
  scanf ("%s", a);                                                    //guarda el valor de x como un caracter en a[90]
   
   if(a[0]=='0'){                                            //if verifica si se ha ingresado como caracter un 0, si fue así, entonces realiza su contenido
    fx=atoi(a);                                              //atoi convierte el valor de a[90] en un valor numerico y si no lo regresa como 0 en la variable fx
    printf("\nX=%lf\n", (sin(fx))/(pow(fx,2)-4)*-1);
 } 
  else{
   fx=atoi(a);  //atoi convierte el valor de a[90] en un valor numerico y si no lo regresa como 0 en la variable fx

   if(fx==-2)
    fx=0;                                                
   else if(fx==2)
    fx=0;
   if (fx!=0)                                                //if verifica que el valor de fx sea difertente de 0                                           
   printf("\nX=%lf\n", (sin(fx))/(pow(fx,2)-4));            //si if es verdadero ejecuta esta linea

   else{                                                                //si no se cumple la condición realiza lo siguiente
   w=fx;                                                                //inicializa la variable w=fx
   while(w==fx){                                                  //inicia el ciclo hasta que w sea diferente de fx  
   system ("clear");                                                   
   printf("Error, debe ser un valor numerico o diferente de 2 o -2\n");      
   printf("\n1. Resolver funcion: f(x)= (sin x)/((x^2)-4)\n");         
   printf("\nx= ");                                                                                                        
   scanf ("%s", a);          //guarda la variable a[90] como caracter     
                                       
   if(a[0]=='0'){           //if verifica si se ha ingresado como caracter un 0, si fue así, entonces realiza su contenido
    fx=atoi(a);             //atoi convierte el valor de a[90] en un valor numerico y si no lo regresa como 0 en la variable fx
    printf("\nX=%lf\n", (sin(fx))/(pow(fx,2)-4)*-1);    
    fx=1;           //Es necesario igualar fx a 1 para que finalize el while
   }  //fin del if
  else{
  fx=atoi(a); 
                                                   
  if(fx==-2)
    fx=0;
  else if(fx==2)
    fx=0;
  if (fx!=0)                                               
   printf("\nX=%lf\n", (sin(fx))/(pow(fx,2)-4));           
}     
 }    
  }
   }

  printf ("Precionar el numero 1 para volver al menu o el numero 2 para salir: "); 
  scanf ("%s",b);                                                                   //pide que se introduzca una valor y lo guarda en b[90]

  op2=atoi(b);            //convierte a b en un valor numerico y lo guarda en op2

     if (op2!=1)          //si op2 es diferente de 1 realiza la siguiente instrucción
      if (op2!=2){        //si op2 es diferente de 2 realiza la siguiente instrucción
        while(op2!=1){      //iniicializa el ciclo hasta que op2 sea diferente de 1 
         system ("clear");  
         printf("Error, introduzca una opcion valida\n");
         printf ("Precionar el numero 1 para volver al menu o el numero 2 para salir: ");
         scanf ("%s",b);       //pide que se introduzca una valor y lo guarda en b[90]
         op2=atoi(b);          //convierte a b en un valor numerico y lo guarda en op2
        if (op2==2){           //si y solo si op2 es igual a 2, finaliza el programa, si no, repite el bucle
         printf("Fin del programa\n\n");             
         return 0;  
         }            //finalilza el programa
} //fin del while
 } //fin del if
   if(op2==2)        //si y solo si op2 es igual a 2, finaliza el programa, si no, repite el bucle 
    {
         printf("Fin del programa\n\n");            

         return 0;  
         }            //finalilza el programa
 break; //fin del case 1

} //fin del switch
 }while (op!=2);  //comprueba que op sea diferente de 2, si no finaliza el do

printf("\nEl programa finalizo\n\n");
return 0; //finaliza el programa
} //fin del main
