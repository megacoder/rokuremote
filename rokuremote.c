/*
*This file is part of rokuremote.
*
*rokuremote is free software: you can redistribute it and/or modify
*it under the terms of the GNU General Public License as published by
*the Free Software Foundation, either version 3 of the License, or
*(at your option) any later version.
*
*rokuremote is distributed in the hope that it will be useful,
*but WITHOUT ANY WARRANTY; without even the implied warranty of
*MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*GNU General Public License for more details.
*
*You should have received a copy of the GNU General Public License
*along with rokuremote.  If not, see <http://www.gnu.org/licenses/>
*
*Compile me with:
*gcc -o rokuremote rokuremote.c $(pkg-config --cflags --libs gtk+-3.0 gmodule-2.0)
*/

#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>

GtkBuilder *builder;

void on_rokuremote_destroy_event() {
          gtk_main_quit();
}

void sendletter (char *msg, GtkEntry *object, gpointer user_data)
{
    char *press = "POST /keypress/Lit_";
    char *nline = " HTTP/1.1\r\n\r\n";
    char cmd[100];

    strcpy(cmd, press);
    strcat(cmd, msg);
    strcat(cmd, nline);

    GtkWidget  *textEntry = GTK_WIDGET( gtk_builder_get_object( builder, "textentry" ) );
    char *hostname = g_strdup (gtk_entry_get_text(GTK_ENTRY(textEntry)));

    int clientSock=socket(AF_INET,SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;

    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(8060);
    serv_addr.sin_addr.s_addr=inet_addr(hostname);

    connect(clientSock, (struct sockaddr*)&serv_addr, sizeof(struct sockaddr));
    write(clientSock, cmd, strlen(cmd));
    close(clientSock);
}

void on_delete_clicked (GtkEntry *object, gpointer user_data)
{
    char *cmd = "POST /keypress/Backspace  HTTP/1.1\r\n\r\n";

    GtkWidget  *textEntry = GTK_WIDGET( gtk_builder_get_object( builder, "textentry" ) );
    char *hostname = g_strdup (gtk_entry_get_text(GTK_ENTRY(textEntry)));

    int clientSock=socket(AF_INET,SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;

    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(8060);
    serv_addr.sin_addr.s_addr=inet_addr(hostname);

    connect(clientSock, (struct sockaddr*)&serv_addr, sizeof(struct sockaddr));
    write(clientSock, cmd, strlen(cmd));
    close(clientSock);
}

void on_space_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("%20", object, user_data);
}

void on_0_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("0", object, user_data);
}

void on_1_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("1", object, user_data);
}

void on_2_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("2", object, user_data);
}

void on_3_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("3", object, user_data);
}

void on_4_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("4", object, user_data);
}

void on_5_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("5", object, user_data);
}

void on_6_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("6", object, user_data);
}

void on_7_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("7", object, user_data);
}

void on_8_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("8", object, user_data);
}

void on_9_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("9", object, user_data);
}

void on_a_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("a", object, user_data);
}

void on_b_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("b", object, user_data);
}

void on_c_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("c", object, user_data);
}

void on_d_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("d", object, user_data);
}

void on_e_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("e", object, user_data);
}

void on_f_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("f", object, user_data);
}

void on_g_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("g", object, user_data);
}

void on_h_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("h", object, user_data);
}

void on_i_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("i", object, user_data);
}

void on_j_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("j", object, user_data);
}

void on_k_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("k", object, user_data);
}

void on_l_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("l", object, user_data);
}

void on_m_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("m", object, user_data);
}

void on_n_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("n", object, user_data);
}

void on_o_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("o", object, user_data);
}

void on_p_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("p", object, user_data);
}

void on_q_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("q", object, user_data);
}

void on_r_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("r", object, user_data);
}

void on_s_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("s", object, user_data);
}

void on_t_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("t", object, user_data);
}

void on_u_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("u", object, user_data);
}

void on_v_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("v", object, user_data);
}

void on_w_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("w", object, user_data);
}

void on_x_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("x", object, user_data);
}

void on_y_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("y", object, user_data);
}

void on_z_clicked (GtkEntry *object, gpointer user_data)
{
sendletter ("z", object, user_data);
}

void sendcommand (char *msg, GtkEntry *object, gpointer user_data)
{
    char *press = "press ";
    char *nline = "\n";
    char cmd[100];

    strcpy(cmd, press);
    strcat(cmd, msg);
    strcat(cmd, nline);

    GtkWidget  *textEntry = GTK_WIDGET( gtk_builder_get_object( builder, "textentry" ) );
    char *hostname = g_strdup (gtk_entry_get_text(GTK_ENTRY(textEntry)));

    int clientSock=socket(AF_INET,SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;

    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(8080);
    serv_addr.sin_addr.s_addr=inet_addr(hostname);

    connect(clientSock, (struct sockaddr*)&serv_addr, sizeof(struct sockaddr));
    write(clientSock, cmd, strlen(cmd));
    close(clientSock);
}

void on_pause_clicked(GtkEntry *object, gpointer user_data)
{
    sendcommand("p", object, user_data);
}

void on_home_clicked(GtkEntry *object, gpointer user_data)
{
    sendcommand("h", object, user_data);
}

void on_up_clicked(GtkEntry *object, gpointer user_data)
{
    sendcommand("u", object, user_data);
}

void on_down_clicked(GtkEntry *object, gpointer user_data)
{
    sendcommand("d", object, user_data);
}

void on_left_clicked(GtkEntry *object, gpointer user_data)
{
    sendcommand("l", object, user_data);
}

void on_right_clicked(GtkEntry *object, gpointer user_data)
{
    sendcommand("r", object, user_data);
}

void on_select_clicked(GtkEntry *object, gpointer user_data)
{
    sendcommand("s", object, user_data);
}

void on_menuback_clicked(GtkEntry *object, gpointer user_data)
{
    sendcommand("k", object, user_data);
}

void on_rwind_clicked(GtkEntry *object, gpointer user_data)
{
    sendcommand("b", object, user_data);
}

void on_ffwd_clicked(GtkEntry *object, gpointer user_data)
{
    sendcommand("f", object, user_data);
}

void on_info_clicked(GtkEntry *object, gpointer user_data)
{
    sendcommand("i", object, user_data);
}

void on_replay_clicked(GtkEntry *object, gpointer user_data)
{
    sendcommand("y", object, user_data);
}

void on_keyboard_clicked()
{
    GtkWidget *keywindow;
    keywindow = GTK_WIDGET(gtk_builder_get_object( builder, "keywindow" ));

    if ( ! gtk_widget_get_visible(keywindow) )
    {
        gtk_widget_set_visible ( keywindow, true);
        gtk_widget_grab_focus(keywindow);
    }
    else
    {
        gtk_widget_set_visible ( keywindow, false);
    }
}

void on_close_clicked()
{
    GtkWidget *keywindow;
    keywindow = GTK_WIDGET(gtk_builder_get_object( builder, "keywindow" ));
    gtk_widget_set_visible ( keywindow, false);
}

int
main( int    argc,
      char **argv )
{
    GtkWidget  *window;
    GError     *error = NULL;
    GtkWidget  *textEntry;

    /* Init GTK+ */
    gtk_init( &argc, &argv );

    /* Create new GtkBuilder object */
    builder = gtk_builder_new();
    // Load UI from file. If error occurs, report it and quit application.
    if( ! gtk_builder_add_from_file( builder, "/usr/share/rokuremote/rokuremote.glade", &error ) )
    {
        g_warning( "%s", error->message );
        g_free( error );
        return( 1 );
    }

    /* Get main window pointer from UI */
    window = GTK_WIDGET( gtk_builder_get_object( builder, "rokuremote" ) );

    /* Connect signals */
    gtk_builder_connect_signals( builder, NULL );

    /* Show window. All other widgets are automatically shown by GtkBuilder */
    gtk_widget_show( window );

    /* Start main loop */
    gtk_main();

    return( 0 );
}
