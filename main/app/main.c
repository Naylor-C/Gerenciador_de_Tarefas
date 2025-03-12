#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *vbox;
  GtkWidget *menubar;
  GtkWidget *filemenu;
  GtkWidget *file;
  GtkWidget *quit;
  

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_window_set_title(GTK_WINDOW(window), "App-GT");
  gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
  gtk_window_set_position(GTK_WINDOW(window),
                          GTK_WIN_POS_CENTER);
  vbox = gtk_vbox_new(FALSE, 0);

  gtk_container_add(GTK_CONTAINER(window), vbox);
  menubar = gtk_menu_bar_new();

  menu_main = gtk_menu_new();
  menu2_main = gtk_menu_new();

  //ITENS OF MENU MAIN
  m_settings = gtk_menu_iten_new_with_label("Settings");
  m_window = gtk_menu_item_new_with_label("Window");


  //ITENS OF MENU ABOUT
  m_about = gtk_menu_item_new_with_label("About"); //Name//

  //Objetos De About//
  quit = gtk_menu_item_new_with_label("Quit"); 

  
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(m_settings), menu_main);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM((m_about), menu2_main));


  gtk_menu_shell_append(GTK_MENU_SHELL(menu_main), quit);

  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menu_main);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menu2_main);

  gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 3);

  gtk_widget_show(window);

  g_signal_connect_swapped(G_OBJECT(window), "destroy",
                           G_CALLBACK(gtk_main_quit), NULL);

  // FUNCTION DE menuBar

  g_signal_connect(G_OBJECT(quit), "activate",
                   G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}