#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
    
    void funcion1 (GtkButton * boton, gpointer data);
    void funcion2 (GtkButton * boton, gpointer data);

    
    // Aqui delaramos la funcion del boton uno
    void funcion1 (GtkButton * boton, gpointer data)
{
    
    system("xdg-open hola.txt");  // con xdg-open le decimos que abra el archivo en este cao es hola
}


    // Aqui declaramos la funcion del boton 2
   void funcion2 (GtkButton * boton, gpointer data)
{

   
     system("clear");
	 system("killall gedit"); //cerremos el archivo
    gtk_main_quit();


}

int main(int argc, char *argv[])
{
	// Esta es la línea que declara e inicializa el Widget llamado window
	GtkWidget *window = NULL;
    GtkWidget *vbox;   //*vbox   es puntero a un boton osea vox   y la -v- es para si es vertical u horisontal -h-
    GtkWidget *boton1, *boton2;  //declaramos botones
	
	gtk_init(&argc, &argv);
	
	// EN ESTE BLOQUE DIBUJAMOS LA VENTANA PRINCIPAL
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	
	//Conecto la señal de cerrar ventana a cerrar el programa
	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	
	// Le digo que al iniciar la ventana esté centrada en la pantalla
	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);  
	
	// Defino el título de la ventana
	gtk_window_set_title (GTK_WINDOW (window), "Proyecto Boton");
	
	// Defino el borde de la ventana
	gtk_container_set_border_width (GTK_CONTAINER (window), 6);
	
	// Defino el tamaño inicial (y será el mínimo)
	gtk_widget_set_size_request(window, 720, 720);

    // Damos nombre a los botones
	boton1 = gtk_button_new_with_label("Toca para abrir el archivo");
	boton2 = gtk_button_new_with_label("Cerrar el archivo");
	vbox = gtk_vbox_new(TRUE,50);
    
    // Damos inicio a los botones
	gtk_box_pack_start((GtkBox *) vbox,boton1,TRUE,TRUE,2);

	gtk_box_pack_start((GtkBox *) vbox,boton2,TRUE,TRUE,2);

    // se les da la accion a los botones 
	gtk_container_add((GtkContainer *) window, vbox);

	g_signal_connect((GObject *) boton1,"clicked",(GCallback ) funcion1,NULL);

    g_signal_connect((GObject *) boton2,"clicked",(GCallback) funcion2,NULL);

	g_signal_connect((GObject *) window,"delete-event",(GCallback) gtk_main_quit,NULL);
    
	gtk_widget_show_all(window);


	gtk_main();
	return 0;
} 
