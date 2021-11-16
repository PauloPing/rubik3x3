#include <stdio.h>
#include <gtk-3.0/gtk/gtk.h>

int main(int argc, char **argv)
{
  GtkWidget *window;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Rubik Cube");
  gtk_window_set_default_size(GTK_WINDOW(window), 750, 500);

  // GtkWidget *rubik = gtk_table_new(9, 9, TRUE);
  // gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(rubik));

  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_show_all(window);
  gtk_main();
  return 0;
}