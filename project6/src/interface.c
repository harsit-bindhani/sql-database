/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_window1 (void)
{
  GtkWidget *window1;
  GtkWidget *fixed1;
  GtkWidget *entry1;
  GtkWidget *entry2;
  GtkWidget *entry3;
  GtkWidget *entry4;
  GtkWidget *entry5;
  GtkWidget *ROLL;
  GtkWidget *NAME;
  GtkWidget *BRANCH;
  GtkWidget *EMAIL;
  GtkWidget *MOB;
  GtkWidget *NEXT;
  GtkWidget *PREV;
  GtkWidget *EXIT;
  GtkWidget *EDIT;
  GtkWidget *DEL;
  GtkWidget *ADD;
  GtkWidget *SEARCH;

  window1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window1), _("window1"));

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (window1), fixed1);

  entry1 = gtk_entry_new ();
  gtk_widget_show (entry1);
  gtk_fixed_put (GTK_FIXED (fixed1), entry1, 136, 24);
  gtk_widget_set_size_request (entry1, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry1), 8226);

  entry2 = gtk_entry_new ();
  gtk_widget_show (entry2);
  gtk_fixed_put (GTK_FIXED (fixed1), entry2, 136, 64);
  gtk_widget_set_size_request (entry2, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry2), 8226);

  entry3 = gtk_entry_new ();
  gtk_widget_show (entry3);
  gtk_fixed_put (GTK_FIXED (fixed1), entry3, 136, 104);
  gtk_widget_set_size_request (entry3, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry3), 8226);

  entry4 = gtk_entry_new ();
  gtk_widget_show (entry4);
  gtk_fixed_put (GTK_FIXED (fixed1), entry4, 136, 144);
  gtk_widget_set_size_request (entry4, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry4), 8226);

  entry5 = gtk_entry_new ();
  gtk_widget_show (entry5);
  gtk_fixed_put (GTK_FIXED (fixed1), entry5, 136, 176);
  gtk_widget_set_size_request (entry5, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry5), 8226);

  ROLL = gtk_label_new (_("ROLL"));
  gtk_widget_show (ROLL);
  gtk_fixed_put (GTK_FIXED (fixed1), ROLL, 32, 32);
  gtk_widget_set_size_request (ROLL, 67, 16);

  NAME = gtk_label_new (_("NAME"));
  gtk_widget_show (NAME);
  gtk_fixed_put (GTK_FIXED (fixed1), NAME, 32, 64);
  gtk_widget_set_size_request (NAME, 66, 16);

  BRANCH = gtk_label_new (_("BRANCH"));
  gtk_widget_show (BRANCH);
  gtk_fixed_put (GTK_FIXED (fixed1), BRANCH, 32, 112);
  gtk_widget_set_size_request (BRANCH, 67, 16);

  EMAIL = gtk_label_new (_("E-MAIL"));
  gtk_widget_show (EMAIL);
  gtk_fixed_put (GTK_FIXED (fixed1), EMAIL, 32, 144);
  gtk_widget_set_size_request (EMAIL, 66, 16);

  MOB = gtk_label_new (_("MOB"));
  gtk_widget_show (MOB);
  gtk_fixed_put (GTK_FIXED (fixed1), MOB, 32, 184);
  gtk_widget_set_size_request (MOB, 67, 16);

  NEXT = gtk_button_new_with_mnemonic (_("NEXT"));
  gtk_widget_show (NEXT);
  gtk_fixed_put (GTK_FIXED (fixed1), NEXT, 264, 272);
  gtk_widget_set_size_request (NEXT, 70, 29);

  PREV = gtk_button_new_with_mnemonic (_("PREV"));
  gtk_widget_show (PREV);
  gtk_fixed_put (GTK_FIXED (fixed1), PREV, 72, 272);
  gtk_widget_set_size_request (PREV, 70, 29);

  EXIT = gtk_button_new_with_mnemonic (_("EXIT"));
  gtk_widget_show (EXIT);
  gtk_fixed_put (GTK_FIXED (fixed1), EXIT, 304, 224);
  gtk_widget_set_size_request (EXIT, 69, 29);

  EDIT = gtk_button_new_with_mnemonic (_("EDIT"));
  gtk_widget_show (EDIT);
  gtk_fixed_put (GTK_FIXED (fixed1), EDIT, 216, 224);
  gtk_widget_set_size_request (EDIT, 70, 29);

  DEL = gtk_button_new_with_mnemonic (_("DEL"));
  gtk_widget_show (DEL);
  gtk_fixed_put (GTK_FIXED (fixed1), DEL, 128, 224);
  gtk_widget_set_size_request (DEL, 69, 29);

  ADD = gtk_button_new_with_mnemonic (_("ADD"));
  gtk_widget_show (ADD);
  gtk_fixed_put (GTK_FIXED (fixed1), ADD, 40, 224);
  gtk_widget_set_size_request (ADD, 70, 29);

  SEARCH = gtk_button_new_with_mnemonic (_("SEARCH"));
  gtk_widget_show (SEARCH);
  gtk_fixed_put (GTK_FIXED (fixed1), SEARCH, 168, 272);
  gtk_widget_set_size_request (SEARCH, 70, 29);

  g_signal_connect ((gpointer) NEXT, "clicked",
                    G_CALLBACK (on_NEXT_clicked),
                    NULL);
  g_signal_connect ((gpointer) PREV, "clicked",
                    G_CALLBACK (on_PREV_clicked),
                    NULL);
  g_signal_connect ((gpointer) EXIT, "clicked",
                    G_CALLBACK (on_EXIT_clicked),
                    NULL);
  g_signal_connect ((gpointer) EDIT, "clicked",
                    G_CALLBACK (on_EDIT_clicked),
                    NULL);
  g_signal_connect ((gpointer) DEL, "clicked",
                    G_CALLBACK (on_DEL_clicked),
                    NULL);
  g_signal_connect ((gpointer) ADD, "clicked",
                    G_CALLBACK (on_ADD_clicked),
                    NULL);
  g_signal_connect ((gpointer) SEARCH, "clicked",
                    G_CALLBACK (on_SEARCH_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window1, window1, "window1");
  GLADE_HOOKUP_OBJECT (window1, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (window1, entry1, "entry1");
  GLADE_HOOKUP_OBJECT (window1, entry2, "entry2");
  GLADE_HOOKUP_OBJECT (window1, entry3, "entry3");
  GLADE_HOOKUP_OBJECT (window1, entry4, "entry4");
  GLADE_HOOKUP_OBJECT (window1, entry5, "entry5");
  GLADE_HOOKUP_OBJECT (window1, ROLL, "ROLL");
  GLADE_HOOKUP_OBJECT (window1, NAME, "NAME");
  GLADE_HOOKUP_OBJECT (window1, BRANCH, "BRANCH");
  GLADE_HOOKUP_OBJECT (window1, EMAIL, "EMAIL");
  GLADE_HOOKUP_OBJECT (window1, MOB, "MOB");
  GLADE_HOOKUP_OBJECT (window1, NEXT, "NEXT");
  GLADE_HOOKUP_OBJECT (window1, PREV, "PREV");
  GLADE_HOOKUP_OBJECT (window1, EXIT, "EXIT");
  GLADE_HOOKUP_OBJECT (window1, EDIT, "EDIT");
  GLADE_HOOKUP_OBJECT (window1, DEL, "DEL");
  GLADE_HOOKUP_OBJECT (window1, ADD, "ADD");
  GLADE_HOOKUP_OBJECT (window1, SEARCH, "SEARCH");

  return window1;
}

