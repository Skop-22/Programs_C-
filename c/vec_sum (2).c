#include <stdio.h>                        //liberias
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

double *a;
double *b;
double *sum;
double *rest;
int *unit;
double mod, raiz;

char r;
double n2, aux_mod;
int i, n, w;

void vector_1 (){

 printf ("Ingrese la cantidad de numeros a almacenar en el vector:");
  if(!(scanf("%lf", &n2)))
   w=1;
  else 
   n=n2;

 while(w==1||n2-n||n<=0){
  w=0;
  system("clear");
  printf("\n----Error, solo se permiten numeros positivos, enteros y mayores que cero---\n\n");
  getchar();
  printf ("Ingrese la cantidad de numeros a almacenar en el vector:");
  if(!(scanf("%lf", &n2)))
   w=1;
  else 
   n=n2;

   }//fin while
 

 a=(double*)malloc(n*sizeof(int));
 for (i=0; i<n; i++){
  system("clear");
  printf ("Vector 1\n");
  printf ("\nIngresa el valor para el vector a[%d]: ", i+1);
  if(!(scanf("%lf", &a[i]))){w=1;}
 
  while(w==1){
   system("clear");
   printf("\n----Error, solo se permiten numeros---\n\n");
   getchar();   
   printf ("\nIngresa el valor para el vector a[%d]: ", i+1);
   if(!(scanf("%lf", &a[i]))){ w=1;}
   else w=0;

  }//fin while
 }//fin for

 getchar();
 printf("\n----El vector 1 se guardardo correctamente, presione cualquier tecla para continuar---\n\n");
 r = getchar();

}//fin vector 1

void vector_2 (){

 b=(double*)malloc(n*sizeof(int));
 for (i=0; i<n; i++){
  system("clear");
  printf ("Vector 2\n");
  printf ("\nIngresa el valor para el vector b[%d]: ", i+1);
  if(!(scanf("%lf", &b[i]))){w=1;}
 
  while(w==1){
   system("clear");
   printf("\n----Error, solo se permiten numeros---\n\n");
   getchar();   
   printf ("\nIngresa el valor para el vector b[%d]: ", i+1);
   if(!(scanf("%lf", &b[i]))){w=1;}
   else w=0;

  }//fin while
 }//fin for

 getchar();
 printf("\n----El vector 2 se guardardo correctamente, presione cualquier tecla para continuar---\n\n");
 r = getchar();

}//fin vector 2

void suma(){

 printf ("Vector 3: contiene el resultado de la suma del vector 1 y del vector 2\n");
 sum=(double*)malloc(n*sizeof(int));

 
 for (i=0; i<n; i++)
  sum[i]=a[i]+b[i];
 int entero;
 FILE*archivo;

 if((archivo=fopen("Vector.txt","w+"))==NULL)
  printf ("El archivo no se pudo abrir");

 else {
  
  for (i=0; i<n; i++)
   fprintf(archivo,"\t%.2lf ",sum[i]);
  
  fclose(archivo);
  }//fin else

 getchar();
 printf("----Se a realizado la suma correctamente, presione cualquier tecla para continuar---\n\n");
 r = getchar();
} //fin suma

void vector_unitario(){

 unit=(int*)malloc(n*sizeof(int));
 
 for(i=0;i<n;i++)
  unit[i]=1;

}//fin vector unitario


void resta(){
 
 printf("Vector 4: contiene el resultado de la resta del vector 3 menos el vector unitario\n");
 rest=(double*)malloc(n*sizeof(int));

 FILE *archivo;
 archivo=fopen("Vector.txt","rt");
 if(archivo != NULL) {
  for (i=0; i<n; i++) {
   fscanf(archivo, "%lf",&rest[i]);
   rest[i]=rest[i]-unit[i];

   }//fin for
 }//fin if
 
 fclose(archivo);
  
 FILE*archivo_2;

 if((archivo_2=fopen("vector_2.txt","w+"))==NULL)
  printf ("El archivo no se pudo abrir");

 else {
    
 for(i=0; i<n; i++)
   fprintf (archivo_2, "\t%.2lf ",rest[i]);

 fclose(archivo_2);
 
 }//fin else
 
 getchar();
 printf("----Se a realizado la resta correctamente, presione cualquier tecla para continuar---\n\n");
 r = getchar();
}//fin resta


void modulo(){
 
 printf ("Vector 5: contiene el modulo del vector 2 (el vector de la resta)\n");

 FILE *archivo_2;
 archivo_2=fopen("vector_2.txt","rt");
 if(archivo_2 != NULL) {
  for (i=0; i<n; i++) {
   fscanf(archivo_2, "%lf",&mod);
   aux_mod=aux_mod+(mod*mod);

   } //fin for
 } //fin if
 
 fclose(archivo_2);

 raiz=sqrt(aux_mod);
 
 FILE*archivo_3;

 if((archivo_3=fopen("vector_3.txt","w+"))==NULL)
  printf ("El archivo no se pudo abrir");

 else {

  fprintf(archivo_3, "\t%.2lf ",raiz);

  fclose(archivo_3);

 }//fin else


 getchar();
 printf("----Se a realizado el modulo correctamente, presione cualquier tecla para continuar---\n\n");
 r = getchar();

  remove("vector_3.txt");
 

  getchar();
  printf("----Se a elimiado el archivo del modulo correctamente, presione cualquier tecla para finalizar---\n\n");
  r = getchar();



}//fin modulo



int main(){
 do {
 system("clear");
 printf("                                                                     ---Bienvenidos---\n\n");
 printf("                        ---Este programa realiza operaciones con vectores y los resultados se leen y escriben en archivos TXT---\n\n");
 vector_1();
 vector_2 ();
 system("clear");
 suma();
 vector_unitario();
 system("clear");
 resta();
 system("clear");
 modulo();

 printf("                              ***Para volver al programa presiona cualquier tecla, para terminar presiona 'n' minuscula***\n");
 r = getchar();

}while (r!='n');

 printf("\n                                                                     ----Fin del programa!!---\n\n");

free(a);
free(b);
free(sum);
free(rest);
free(unit);

return 0;  



}//fin main
