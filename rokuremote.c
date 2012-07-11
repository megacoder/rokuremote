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
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/stat.h>

GtkBuilder *builder;

//Windows and dialogs opening and closing
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

void close_bad_hostname()
{
    GtkWidget *bad_hostname;
    bad_hostname = GTK_WIDGET(gtk_builder_get_object( builder, "bad_hostname" ));
    gtk_widget_set_visible ( bad_hostname, false); 
}

void close_bad_address()
{
    GtkWidget *bad_address;
    bad_address = GTK_WIDGET(gtk_builder_get_object( builder, "bad_address" ));
    gtk_widget_set_visible ( bad_address, false); 
}

void save_clicked()
{
    GtkWidget  *textEntry = GTK_WIDGET( gtk_builder_get_object( builder, "textentry" ) );
    char *hostname = g_strdup (gtk_entry_get_text(GTK_ENTRY(textEntry)));

    char addresspath[1024];
    strcpy(addresspath, (getenv ("HOME")));
    strcat (addresspath, "/.rokuremote/address");

    FILE *addressfilew;
    addressfilew = fopen(addresspath, "w");
    fputs(hostname, addressfilew);
    fclose(addressfilew); 
}

void on_rokuremote_destroy_event() 
{
    gtk_main_quit(); 
}

//Stuff to actually send commands over the network
void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr); 
}

void sendcmd (char *msg)
{
    char *press = "POST /keypress/";
    char *nline = " HTTP/1.1\r\n\r\n";
    char cmd[100];
    strcpy(cmd, press);
    strcat(cmd, msg);
    strcat(cmd, nline);
    GtkWidget  *textEntry = GTK_WIDGET( gtk_builder_get_object( builder, "textentry" ) );
    char *hostname = g_strdup (gtk_entry_get_text(GTK_ENTRY(textEntry)));
    int sockfd, numbytes, rv;
    struct addrinfo hints, *servinfo, *p;
    char s[INET6_ADDRSTRLEN];
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(hostname, "8060", &hints, &servinfo)) == 0)
    {
        p = servinfo;
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == 0)
        {
            connect(sockfd, p->ai_addr, p->ai_addrlen);
            inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr), s, sizeof s);
            freeaddrinfo(servinfo);
            send(sockfd, cmd, strlen(cmd), 0);
            close(sockfd);
        }
        else
        {
	    //Tell them we couldn't resolve the name
            GtkWidget *bad_hostname;
            bad_hostname = GTK_WIDGET(gtk_builder_get_object( builder, "bad_hostname" ));
            gtk_widget_set_visible ( bad_hostname, true);
        }
    }
    else
    {   
	//Tell them the IP Address is bad, or at least, we couldn't connect
        GtkWidget *bad_address;
        bad_address = GTK_WIDGET(gtk_builder_get_object( builder, "bad_address" ));
        gtk_widget_set_visible ( bad_address, true);
    }
}

//All the button clicks
void on_replay_clicked() { sendcmd("InstantReplay"); }
void on_delete_clicked() { sendcmd("Backspace"); }
void on_space_clicked() { sendcmd ("Lit_%20"); }
void on_select_clicked() { sendcmd("Select"); }
void on_menuback_clicked() { sendcmd("Back"); }
void on_right_clicked() { sendcmd("Right"); }
void on_pause_clicked() { sendcmd("Play"); }
void on_home_clicked() { sendcmd("Home"); }
void on_down_clicked() { sendcmd("Down"); }
void on_left_clicked() { sendcmd("Left"); }
void on_rwind_clicked() { sendcmd("Rev"); }
void on_info_clicked() { sendcmd("Info"); }
void on_ffwd_clicked() { sendcmd("Fwd"); }
void on_up_clicked() { sendcmd("Up"); }
void on_0_clicked() { sendcmd ("Lit_0"); }
void on_1_clicked() { sendcmd ("Lit_1"); }
void on_2_clicked() { sendcmd ("Lit_2"); }
void on_3_clicked() { sendcmd ("Lit_3"); }
void on_4_clicked() { sendcmd ("Lit_4"); }
void on_5_clicked() { sendcmd ("Lit_5"); }
void on_6_clicked() { sendcmd ("Lit_6"); }
void on_7_clicked() { sendcmd ("Lit_7"); }
void on_8_clicked() { sendcmd ("Lit_8"); }
void on_9_clicked() { sendcmd ("Lit_9"); }
void on_a_clicked() { sendcmd ("Lit_a"); }
void on_b_clicked() { sendcmd ("Lit_b"); }
void on_c_clicked() { sendcmd ("Lit_c"); }
void on_d_clicked() { sendcmd ("Lit_d"); }
void on_e_clicked() { sendcmd ("Lit_e"); }
void on_f_clicked() { sendcmd ("Lit_f"); }
void on_g_clicked() { sendcmd ("Lit_g"); }
void on_h_clicked() { sendcmd ("Lit_h"); }
void on_i_clicked() { sendcmd ("Lit_i"); }
void on_j_clicked() { sendcmd ("Lit_j"); }
void on_k_clicked() { sendcmd ("Lit_k"); }
void on_l_clicked() { sendcmd ("Lit_l"); }
void on_m_clicked() { sendcmd ("Lit_m"); }
void on_n_clicked() { sendcmd ("Lit_n"); }
void on_o_clicked() { sendcmd ("Lit_o"); }
void on_p_clicked() { sendcmd ("Lit_p"); }
void on_q_clicked() { sendcmd ("Lit_q"); }
void on_r_clicked() { sendcmd ("Lit_r"); }
void on_s_clicked() { sendcmd ("Lit_s"); }
void on_t_clicked() { sendcmd ("Lit_t"); }
void on_u_clicked() { sendcmd ("Lit_u"); }
void on_v_clicked() { sendcmd ("Lit_v"); }
void on_w_clicked() { sendcmd ("Lit_w"); }
void on_x_clicked() { sendcmd ("Lit_x"); }
void on_y_clicked() { sendcmd ("Lit_y"); }
void on_z_clicked() { sendcmd ("Lit_z"); }

int
main( int    argc,
      char **argv )
{
    GtkWidget  *window;
    GError     *error = NULL;

    char rokuhome[1024];
    strcpy(rokuhome, (getenv ("HOME")));
    strcat (rokuhome, "/.rokuremote");
    mkdir(rokuhome,0750);

    char addresspath[256];
    strcpy (addresspath, rokuhome);
    strcat (addresspath, "/address");
   
    FILE *addressfile;
    
    char address[256];

    if (addressfile = fopen(addresspath, "r"))
    {
        fgets(address, 256, addressfile);
        fclose(addressfile);
    }
    else
    {
        strcpy (address,"Enter Roku's IP or Hostname");
    }
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

    GtkWidget *textEntry = GTK_WIDGET( gtk_builder_get_object( builder, "textentry" ) );
    gtk_entry_set_text(GTK_ENTRY(textEntry), address);

    /* Start main loop */
    gtk_main();

    return( 0 ); }
