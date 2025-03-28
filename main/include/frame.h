#include <gtk/gtk.h> 
#include <database.h>


static void
Frame (GtkApplication* app,
          gpointer        user_data)
{

typedef struct {
    GtkWidget *window;
    GtkWidget *user_entry;
    GtkWidget *pass_entry;
    GtkWidget *button;
    GtkWidget *box;
} AppWidgets;

  
 
 
  //Criando Janela App
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "App-Linux");
  gtk_window_set_default_size (GTK_WINDOW (window), 600, 480);
  gtk_window_present (GTK_WINDOW (window));

  //Criando Box
  box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_widget_set_halign (box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box, GTK_ALIGN_CENTER);
  
  //Colocando Box na Janela 
  gtk_window_set_child (GTK_WINDOW (window), box);

  //Criando botao de login e mecanismo de entrada
  //BL = Button of Login 
  BL = gtk_button_new_with_label ("Login");

  //Evento apos o click de BL
  g_signal_connect (BL, "clicked", G_CALLBACK (Db.Scan), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window);

  gtk_box_append (GTK_BOX (box), button);

  gtk_window_present (GTK_WINDOW (window));  

}



#include <gtk/gtk.h>

// Estrutura para armazenar os widgets
typedef struct {
    GtkWidget *window;
    GtkWidget *user_entry;
    GtkWidget *pass_entry;
} AppWidgets;

// Função de callback para o botão de login
void on_login_clicked(GtkButton *button, gpointer user_data) {
    AppWidgets *widgets = (AppWidgets *)user_data;
    const gchar *username = gtk_entry_get_text(GTK_ENTRY(widgets->user_entry));
    const gchar *password = gtk_entry_get_text(GTK_ENTRY(widgets->pass_entry));

    // Validação simples (substitua por sua lógica real)
    if (g_strcmp0(username, "admin") == 0 && g_strcmp0(password, "1234") == 0) {
        g_print("Login bem-sucedido!\n");
        // Aqui você pode abrir a janela principal do aplicativo
    } else {
        GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(widgets->window),
                                  GTK_DIALOG_DESTROY_WITH_PARENT,
                                  GTK_MESSAGE_ERROR,
                                  GTK_BUTTONS_OK,
                                  "Login falhou");
        gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog),
                                              "Usuário ou senha incorretos");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
}

// Função principal
int main(int argc, char *argv[]) {
    GtkWidget *box, *user_box, *pass_box, *user_label, *pass_label, *login_button;
    AppWidgets widgets;

    gtk_init(&argc, &argv);

    // Cria a janela principal
    widgets.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(widgets.window), "Login");
    gtk_window_set_default_size(GTK_WINDOW(widgets.window), 300, 150);
    gtk_container_set_border_width(GTK_CONTAINER(widgets.window), 10);
    g_signal_connect(widgets.window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Layout principal
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(widgets.window), box);

    // Campo de usuário
    user_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    user_label = gtk_label_new("Usuário:");
    widgets.user_entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(user_box), user_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(user_box), widgets.user_entry, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), user_box, FALSE, FALSE, 0);

    // Campo de senha
    pass_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    pass_label = gtk_label_new("Senha:");
    widgets.pass_entry = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(widgets.pass_entry), FALSE); // Esconde a senha
    gtk_box_pack_start(GTK_BOX(pass_box), pass_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(pass_box), widgets.pass_entry, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), pass_box, FALSE, FALSE, 0);

    // Botão de login
    login_button = gtk_button_new_with_label("Login");
    g_signal_connect(login_button, "clicked", G_CALLBACK(on_login_clicked), &widgets);
    gtk_box_pack_start(GTK_BOX(box), login_button, FALSE, FALSE, 0);

    // Mostra todos os widgets
    gtk_widget_show_all(widgets.window);

    gtk_main();

    return 0;
}