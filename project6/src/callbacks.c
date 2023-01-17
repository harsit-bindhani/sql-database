#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "sql.h"
#include "sqlext.h"
#include "string.h"

struct student
{
	int roll;
	char name[30];
	char branch[20];
	char email[20];
	char phone[12];
};
        int i=1;

void
on_ADD_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *t1,*t2,*t3,*t4,*t5;

        char *roll,*name,*branch,*email,*phone;

        SQLHENV p;
        SQLHDBC q;
        SQLHSTMT r;
        struct student m ;

        t1=lookup_widget(GTK_WIDGET(button),"entry1");
        t2=lookup_widget(GTK_WIDGET(button),"entry2");
        t3=lookup_widget(GTK_WIDGET(button),"entry3");
        t4=lookup_widget(GTK_WIDGET(button),"entry4");
        t5=lookup_widget(GTK_WIDGET(button),"entry5");

        roll=gtk_entry_get_text(t1);
        name=gtk_entry_get_text(t2);
        branch=gtk_entry_get_text(t3);
	email=gtk_entry_get_text(t4);
	phone=gtk_entry_get_text(t5);

	if( (strlen(roll)==0) || strlen(name)==0 || strlen(branch)==0 || strlen(email)==0 || strlen(phone)==0)
	{
		return ;
	}

        m.roll=atoi(roll);
        strcpy(m.name,name);
        strcpy(m.branch,branch);
        strcpy(m.email,email);
        strcpy(m.phone,phone);
                printf("%s %s %s\n",roll,name,branch);
                SQLAllocHandle(SQL_HANDLE_ENV,0,&p);
                SQLSetEnvAttr(p,SQL_ATTR_ODBC_VERSION,SQL_OV_ODBC3,0);
        SQLAllocHandle(SQL_HANDLE_DBC,p,&q);
        SQLAllocHandle(SQL_HANDLE_STMT,q,&r);

        SQLConnect(q,"college",strlen("college"),"root",strlen("root"),"",strlen(""));
        char x[]="use college;";
        SQLPrepare(r,x,strlen(x));
        char y[]="insert into student values(?,?,?,?,?)";
        SQLPrepare(r,y,strlen(y));

        SQLBindParameter(r,1,SQL_PARAM_INPUT,SQL_INTEGER,SQL_C_LONG,4,0,&m.roll,sizeof(m.roll),0);
        SQLBindParameter(r,2,SQL_PARAM_INPUT,SQL_CHAR,SQL_C_CHAR,30,0,m.name,strlen(m.name),0);
        SQLBindParameter(r,3,SQL_PARAM_INPUT,SQL_CHAR,SQL_C_CHAR,20,0,m.branch,strlen(m.branch),0);
        SQLBindParameter(r,4,SQL_PARAM_INPUT,SQL_CHAR,SQL_C_CHAR,20,0,m.email,strlen(m.email),0);
        SQLBindParameter(r,5,SQL_PARAM_INPUT,SQL_CHAR,SQL_C_CHAR,12,0,m.phone,strlen(m.phone),0);

        SQLTransact(p,q,SQL_COMMIT);
        SQLExecute(r);
        SQLFreeHandle(SQL_HANDLE_STMT,r);
        SQLDisconnect(q);
        SQLFreeHandle(SQL_HANDLE_DBC,q);
        SQLFreeHandle(SQL_HANDLE_ENV,p);
        gtk_entry_set_text(t1,"");
        gtk_entry_set_text(t2,"");
        gtk_entry_set_text(t3,"");
        gtk_entry_set_text(t4,"");
        gtk_entry_set_text(t5,"");

        gtk_widget_grab_focus(t1);


}


void
on_DEL_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
 	GtkWidget *t1,*t2,*t3,*t4,*t5;
        char *roll,*name,*branch,*email,*phone;

        SQLHENV p;
        SQLHDBC q;
        SQLHSTMT r;
        struct student m ;

        t1=lookup_widget(GTK_WIDGET(button),"entry1");
        t2=lookup_widget(GTK_WIDGET(button),"entry2");
        t3=lookup_widget(GTK_WIDGET(button),"entry3");
        t4=lookup_widget(GTK_WIDGET(button),"entry4");
        t5=lookup_widget(GTK_WIDGET(button),"entry5");

        roll=gtk_entry_get_text(t1);
        name=gtk_entry_get_text(t2);
        branch=gtk_entry_get_text(t3);
        email=gtk_entry_get_text(t4);
        phone=gtk_entry_get_text(t5);


        m.roll=atoi(roll);
        strcpy(m.name,name);
        strcpy(m.branch,branch);
        strcpy(m.email,email);
        strcpy(m.phone,phone);
                printf("%s %s %s\n",roll,name,branch);
                SQLAllocHandle(SQL_HANDLE_ENV,0,&p);
                SQLSetEnvAttr(p,SQL_ATTR_ODBC_VERSION,SQL_OV_ODBC3,0);
        SQLAllocHandle(SQL_HANDLE_DBC,p,&q);
        SQLAllocHandle(SQL_HANDLE_STMT,q,&r);

        SQLConnect(q,"college",strlen("college"),"root",strlen("root"),"",strlen(""));
        char x[]="use college;";
        SQLPrepare(r,x,strlen(x));

	char y[100]="delete from student where roll = ";
        strcat(y,roll);
        strcat(y,";");
        SQLPrepare(r,y,strlen(y));


        SQLExecute(r);
        SQLFreeHandle(SQL_HANDLE_STMT,r);
        SQLDisconnect(q);
        SQLFreeHandle(SQL_HANDLE_DBC,q);
        SQLFreeHandle(SQL_HANDLE_ENV,p);

        gtk_entry_set_text(t1,"");
        gtk_entry_set_text(t2,"");
        gtk_entry_set_text(t3,"");
        gtk_entry_set_text(t4,"");
        gtk_entry_set_text(t5,"");

        gtk_widget_grab_focus(t1);

}


void
on_SEARCH_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
	  GtkWidget *t1,*t2,*t3,*t4,*t5;
        char *roll,*name,*branch,*email,*phone;

        SQLHENV p;
        SQLHDBC q;
        SQLHSTMT r;
        struct student m ;

        t1=lookup_widget(GTK_WIDGET(button),"entry1");
        t2=lookup_widget(GTK_WIDGET(button),"entry2");
        t3=lookup_widget(GTK_WIDGET(button),"entry3");
        t4=lookup_widget(GTK_WIDGET(button),"entry4");
        t5=lookup_widget(GTK_WIDGET(button),"entry5");

        roll=gtk_entry_get_text(t1);
        name=gtk_entry_get_text(t2);
        branch=gtk_entry_get_text(t3);
        email=gtk_entry_get_text(t4);
        phone=gtk_entry_get_text(t5);


        m.roll=atoi(roll);
        strcpy(m.name,name);
        strcpy(m.branch,branch);
        strcpy(m.email,email);
        strcpy(m.phone,phone);
                printf("%s %s %s\n",roll,name,branch);
                SQLAllocHandle(SQL_HANDLE_ENV,0,&p);
                SQLSetEnvAttr(p,SQL_ATTR_ODBC_VERSION,SQL_OV_ODBC3,0);
        SQLAllocHandle(SQL_HANDLE_DBC,p,&q);
        SQLAllocHandle(SQL_HANDLE_STMT,q,&r);

        SQLConnect(q,"college",strlen("college"),"root",strlen("root"),"",strlen(""));
        char x[]="use college;";
        SQLPrepare(r,x,strlen(x));

        char y[100]="select * from student where roll = ";
        strcat(y,roll);
        strcat(y,";");
        SQLPrepare(r,y,strlen(y));


	SQLBindCol(r,1,SQL_INTEGER,&m.roll,4,0);
	SQLBindCol(r,2,SQL_CHAR,m.name,30,0);
	SQLBindCol(r,3,SQL_CHAR,m.branch,20,0);
	SQLBindCol(r,4,SQL_CHAR,m.email,20,0);
	SQLBindCol(r,5,SQL_CHAR,m.phone,12,0);

	char rr[10];
	SQLFetch(r);


		sprintf(rr,"%d",m.roll);	
        	gtk_entry_set_text(t1,rr);
        	gtk_entry_set_text(t2,m.name);
        	gtk_entry_set_text(t3,m.branch);
        	gtk_entry_set_text(t4,m.email);
        	gtk_entry_set_text(t5,m.phone);
		
        SQLExecute(r);
        SQLFreeHandle(SQL_HANDLE_STMT,r);
        SQLDisconnect(q);
        SQLFreeHandle(SQL_HANDLE_DBC,q);
        SQLFreeHandle(SQL_HANDLE_ENV,p);

        gtk_widget_grab_focus(t1);

}


void
on_EDIT_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
	 GtkWidget *t1,*t2,*t3,*t4,*t5;
        char *roll,*name,*branch,*email,*phone;

        SQLHENV p;
        SQLHDBC q;
        SQLHSTMT r;
        struct student m ;

        t1=lookup_widget(GTK_WIDGET(button),"entry1");
        t2=lookup_widget(GTK_WIDGET(button),"entry2");
        t3=lookup_widget(GTK_WIDGET(button),"entry3");
        t4=lookup_widget(GTK_WIDGET(button),"entry4");
        t5=lookup_widget(GTK_WIDGET(button),"entry5");

        roll=gtk_entry_get_text(t1);
        name=gtk_entry_get_text(t2);
        branch=gtk_entry_get_text(t3);
        email=gtk_entry_get_text(t4);
        phone=gtk_entry_get_text(t5);


        SQLAllocHandle(SQL_HANDLE_ENV,0,&p);
        SQLSetEnvAttr(p,SQL_ATTR_ODBC_VERSION,SQL_OV_ODBC3,0);
        SQLAllocHandle(SQL_HANDLE_DBC,p,&q);
        SQLAllocHandle(SQL_HANDLE_STMT,q,&r);

        SQLConnect(q,"college",strlen("college"),"root",strlen("root"),"",strlen(""));
        char x[]="use college;";
        SQLPrepare(r,x,strlen(x));

        char y[200]="update student set ";
        
	strcat(y,"name=");
	strcat(y,"\"");
	strcat(y,name);
	strcat(y,"\"");
	strcat(y,",");
	
        strcat(y,"branch=");
	strcat(y,"\"");
	strcat(y,branch);
	strcat(y,"\"");
	strcat(y,",");

        strcat(y,"email=");
	strcat(y,"\"");
	strcat(y,email);
	strcat(y,"\"");
	strcat(y,",");

        strcat(y,"phone=");
	strcat(y,"\"");
	strcat(y,phone);
	strcat(y,"\"");
	strcat(y," ");
	
	strcat(y,"where ");

	strcat(y,"roll = ");
	strcat(y,"\"");
	strcat(y,roll);
	strcat(y,"\"");
	strcat(y,";");
	
	SQLPrepare(r,y,strlen(y));
	SQLExecute(r);
	
	printf("%s\n",y);

        SQLFreeHandle(SQL_HANDLE_STMT,r);
        SQLDisconnect(q);
        SQLFreeHandle(SQL_HANDLE_DBC,q);
        SQLFreeHandle(SQL_HANDLE_ENV,p);

        gtk_widget_grab_focus(t1);


}


void
on_PREV_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *t1,*t2,*t3,*t4,*t5;
        char *roll,*name,*branch,*email,*phone;

        SQLHENV p;
        SQLHDBC q;
        SQLHSTMT r;
        struct student m ;

        t1=lookup_widget(GTK_WIDGET(button),"entry1");
        t2=lookup_widget(GTK_WIDGET(button),"entry2");
        t3=lookup_widget(GTK_WIDGET(button),"entry3");
        t4=lookup_widget(GTK_WIDGET(button),"entry4");
        t5=lookup_widget(GTK_WIDGET(button),"entry5");

        roll=gtk_entry_get_text(t1);
        name=gtk_entry_get_text(t2);
        branch=gtk_entry_get_text(t3);
        email=gtk_entry_get_text(t4);
        phone=gtk_entry_get_text(t5);

         m.roll=atoi(roll);
        strcpy(m.name,name);
        strcpy(m.branch,branch);
        strcpy(m.email,email);
        strcpy(m.phone,phone);


        SQLAllocHandle(SQL_HANDLE_ENV,0,&p);
        SQLSetEnvAttr(p,SQL_ATTR_ODBC_VERSION,SQL_OV_ODBC3,0);
        SQLAllocHandle(SQL_HANDLE_DBC,p,&q);
        SQLAllocHandle(SQL_HANDLE_STMT,q,&r);

        SQLConnect(q,"college",strlen("college"),"root",strlen("root"),"",strlen(""));
        char x[]="use college;";
        SQLPrepare(r,x,strlen(x));

        char xx[100]="select * from student limit ";
        char y[100];
        char z[10];
                i--;
		if(i==-1)
			i=0;
                memset(y,0,sizeof(y));
                sprintf(z,"%d",i);
                strcpy(y,xx);
                strcat(y,z);
                strcat(y,",");
                strcat(y,"1");
                printf("%s \n",y);

        SQLPrepare(r,y,strlen(y));

        SQLBindCol(r,1,SQL_INTEGER,&m.roll,4,0);
        SQLBindCol(r,2,SQL_CHAR,m.name,30,0);
        SQLBindCol(r,3,SQL_CHAR,m.branch,20,0);
        SQLBindCol(r,4,SQL_CHAR,m.email,20,0);
        SQLBindCol(r,5,SQL_CHAR,m.phone,12,0);

        char rr[10];
        SQLFetch(r);
        sprintf(rr,"%d",m.roll);

                gtk_entry_set_text(t1,rr);
                gtk_entry_set_text(t2,m.name);
                gtk_entry_set_text(t3,m.branch);
                gtk_entry_set_text(t4,m.email);
                gtk_entry_set_text(t5,m.phone);


        SQLExecute(r);
        SQLFreeHandle(SQL_HANDLE_STMT,r);
        SQLDisconnect(q);
        SQLFreeHandle(SQL_HANDLE_DBC,q);
        SQLFreeHandle(SQL_HANDLE_ENV,p);

        gtk_widget_grab_focus(t1);

}


void
on_NEXT_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *t1,*t2,*t3,*t4,*t5;
        char *roll,*name,*branch,*email,*phone;

        SQLHENV p;
        SQLHDBC q;
        SQLHSTMT r;
        struct student m ;

        t1=lookup_widget(GTK_WIDGET(button),"entry1");
        t2=lookup_widget(GTK_WIDGET(button),"entry2");
        t3=lookup_widget(GTK_WIDGET(button),"entry3");
        t4=lookup_widget(GTK_WIDGET(button),"entry4");
        t5=lookup_widget(GTK_WIDGET(button),"entry5");

        roll=gtk_entry_get_text(t1);
        name=gtk_entry_get_text(t2);
        branch=gtk_entry_get_text(t3);
        email=gtk_entry_get_text(t4);
        phone=gtk_entry_get_text(t5);

	 m.roll=atoi(roll);
        strcpy(m.name,name);
        strcpy(m.branch,branch);
        strcpy(m.email,email);
        strcpy(m.phone,phone);


        SQLAllocHandle(SQL_HANDLE_ENV,0,&p);
        SQLSetEnvAttr(p,SQL_ATTR_ODBC_VERSION,SQL_OV_ODBC3,0);
        SQLAllocHandle(SQL_HANDLE_DBC,p,&q);
        SQLAllocHandle(SQL_HANDLE_STMT,q,&r);

        SQLConnect(q,"college",strlen("college"),"root",strlen("root"),"",strlen(""));
        char x[]="use college;";
        SQLPrepare(r,x,strlen(x));

	char xx[100]="select * from student limit ";
        char y[100];
        char z[10];
                memset(y,0,sizeof(y));
                sprintf(z,"%d",i);
                strcpy(y,xx);
                strcat(y,z);
                strcat(y,",");
                strcat(y,"1");
                printf("%s \n",y);
                i++;
	
        SQLPrepare(r,y,strlen(y));

	SQLBindCol(r,1,SQL_INTEGER,&m.roll,4,0);
        SQLBindCol(r,2,SQL_CHAR,m.name,30,0);
        SQLBindCol(r,3,SQL_CHAR,m.branch,20,0);
        SQLBindCol(r,4,SQL_CHAR,m.email,20,0);
        SQLBindCol(r,5,SQL_CHAR,m.phone,12,0);

        char rr[10];
        SQLFetch(r);
	sprintf(rr,"%d",m.roll);

                gtk_entry_set_text(t1,rr);
                gtk_entry_set_text(t2,m.name);
                gtk_entry_set_text(t3,m.branch);
                gtk_entry_set_text(t4,m.email);
                gtk_entry_set_text(t5,m.phone);


        SQLExecute(r);
        SQLFreeHandle(SQL_HANDLE_STMT,r);
        SQLDisconnect(q);
        SQLFreeHandle(SQL_HANDLE_DBC,q);
        SQLFreeHandle(SQL_HANDLE_ENV,p);

        gtk_widget_grab_focus(t1);


}


void
on_EXIT_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_main_quit();
}








void
on_window1_destroy                     (GtkObject       *object,
                                        gpointer         user_data)
{
	gtk_main_quit();
}

