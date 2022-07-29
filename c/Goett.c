#include <stdio.h>                        //liberias
#include <stdlib.h>
#include <ctype.h>
#include <curses.h>

 int i,w, n2, m2, e_aux,tru;
 float d,d_aux;
 int* a;
 char r, n[50], m[50], aux[50];
 
 void arreglo1(){  //uso de malloc

 printf("\nIngrese numero de elementos: ");
 scanf("%s",n);
 d=atof(n);
 n2=d; //convierte el num a entero
 
 if(d-n2||n2<=0)         //si es decimal, 0, caracteres o números negativos mandara mensaje de error
  while(d-n2||n2<=0){
   
   system("clear");
   printf("***Error, no se permite el 0 o cualquier otro caracter diferente de un numero***\n\n");
   printf("\nIngrese numero de elementos: ");
   scanf("%s",n);
   d=atof(n);
   n2=d; //convierte el num a entero

   }//fin while

 printf("\n");
 a=(int*)malloc(n2*sizeof(int));
 for(i=0;i<n2;i++) { //for 1
  system("clear");
  printf("Ingresa el valor entero para a[%d]: ",i+1); 
  scanf ("%s",&aux[i]);

  if(aux[i]=='0'){
   a[i]=atoi(&aux[i]);}

  else if (aux[i]!='0'){
    d_aux=atof(&aux[i]);
    e_aux=d_aux; 
   
    if(d_aux-e_aux||e_aux==0){
      tru=0;
     while (d_aux-e_aux||tru==0){
     system("clear");
     printf("***Error, solo se permiten numeros enteros***\n\n");
     printf("Ingresa el valor entero para a[%d]: ",i+1); 
     scanf ("%s",&aux[i]);
     
     if(aux[i]=='0'){
      a[i]=atoi(&aux[i]);
      tru=1;}
      
 
    else if (aux[i]!='0'){
    d_aux=atof(&aux[i]);
    e_aux=d_aux; 
   
    if(d_aux-e_aux||e_aux==0)
      tru=0;
    else 
     tru=1; }
       
       
}//fin while

}//fin if
    a[i]=e_aux;
}//fin else if
   


  }// fin for 1
 system("clear");
 printf("\n");
 printf ("Los valores agregados fueron:\n");
 for (i=0; i<n2; i++){//for 2
  printf ("Valor: %d --- ", a[i]);
  printf ("Localidad %p: \n", &a[i]);
  }//for 2
  getchar();
  printf("\n\n***Presione una tecla para ingresar valores nuevamente...***");
  getchar();
}//fin arreglo 1

 void arreglo2(){ //uso de realloc
 
 printf ("\n\nIngrese nuevamente el numero de elementos: ");
 scanf("%s",m);
 d=atof(m);
 m2=d; //convierte el num a entero
 
 if(d-m2||m2<=0)         //si es decimal, 0, caracteres o números negativos mandara mensaje de error
  while(d-m2||m2<=0){
   
   system("clear");
   printf("***Error, no se permite el 0 o cualquier otro caracter diferente de un numero***\n\n");
   printf("\nIngrese numero de elementos: ");
   scanf("%s",m);
   d=atof(m);
   m2=d; //convierte el num a entero

   }//fin while
 
 printf("\n");

 e_aux=0; d_aux=0;

 a=(int*) realloc(a, m2*sizeof(int));
 for(i=0;i<m2;i++) { //for 3
  system("clear");
  printf("Ingresa el valor entero para a[%d]: ",i+1);
  scanf ("%s",&aux[i]);

  if(aux[i]=='0'){
   a[i]=atoi(&aux[i]);}

  else if (aux[i]!='0'){
    d_aux=atof(&aux[i]);
    e_aux=d_aux; 
   
    if(d_aux-e_aux||e_aux==0){
      tru=0;
     while (d_aux-e_aux||tru==0){
     system("clear");
     printf("***Error, solo se permiten numeros enteros***\n\n");
     printf("Ingresa el valor entero para a[%d]: ",i+1);  
     scanf ("%s",&aux[i]);
     
     if(aux[i]=='0'){
      a[i]=atoi(&aux[i]);
      tru=1;}
      
 
    else if (aux[i]!='0'){
    d_aux=atof(&aux[i]);
    e_aux=d_aux; 
   
    if(d_aux-e_aux||e_aux==0)
      tru=0;
    else 
     tru=1; }
       
       
}//fin while

}//fin if
    a[i]=e_aux;
}//fin else if

  }// fin for 3
 system("clear");
 printf("\n");
 printf ("Los valores agregados fueron:\n");
 for (i=0; i<m2; i++){//for 4
  
  printf ("Valor: %d --- ", a[i]);
  printf ("Localidad %p: \n", &a[i]);

  }//for 4
  getchar();
  printf("\n\n***Presione una tecla para ver el arreglo total...***");
  getchar();
}//fin arreglo 2
 

void arreglo_total(){  //imprime arreglo total
system("clear");
w=n2+m2;
printf ("\n\nArreglo total:\n\n");
for (i=0; i<w; i++){//for 4

  printf ("Valor: %d --- ", a[i]);
  printf ("Localidad %p: \n", &a[i]);


  }//for 4
 printf("\n\n");
}//fin arreglo_total


 int main(){
 do{

 system ("clear");
 printf("                                 ****Bienvenidos****\n\n"); 
 printf("                          ****Manejo de memoria dinamica****\n\n"); 
 arreglo1();
 system("clear");
 arreglo2();
 free(a);
 arreglo_total();

  
  printf("----Para volver al programa presiona cualquier tecla, para terminar presiona 'n' minuscula---");
  r = getchar();

}while (r!='n');

 
 printf("\n\n***Fin del programa***\n\n");
 return 0;  

 }//fin main 
