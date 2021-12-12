#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"tree.h"
#include"foyer.h"

void
on_AcceuilGestion_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
/*preparation du treeView*/
GtkWidget *p;
GtkWidget *p1;
GtkWidget *p2;
gtk_widget_hide (acceuil);
gestion = create_gestion ();
p=lookup_widget(gestion,"treeview1");
p1=lookup_widget(gestion,"treeview2");
p2=lookup_widget(gestion,"treeview3");
i=0;
j=0;
k=0;
Afficherfoyer(p,"foyer.txt");
Afficherfoyer1(p1,"foyer.txt");
AfficherExcursion(p2,"excursions.txt");
gtk_widget_show (gestion);
}


void
on_Ajouterfoyer_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
 foyer c;
GtkWidget *entryNom;
GtkWidget *entryCin;
GtkWidget *entryPrenom;
GtkWidget *entryAdresse;
GtkWidget *entryNumtel;
GtkWidget *labelCin;
GtkWidget *labelnom;
GtkWidget *labelprenom;
GtkWidget *labeladresse;
GtkWidget *labelnumtel;
GtkWidget *existe;
GtkWidget* success;
GtkWidget *comboboxaz;
GtkWidget *labelsexe;
int b=1;



entryCin=lookup_widget(gestion,"entry5");
entryNom=lookup_widget(gestion,"entry1");
entryPrenom=lookup_widget(gestion,"entry2");
entryAdresse=lookup_widget(gestion,"entry4");
entryNumtel=lookup_widget(gestion,"entry3");
comboboxaz=lookup_widget(gestion,"comboboxaz");

labelCin=lookup_widget(gestion,"label13");
labelnom=lookup_widget(gestion,"label7");
labelprenom=lookup_widget(gestion,"label8");
labeladresse=lookup_widget(gestion,"label9");
labelnumtel=lookup_widget(gestion,"label10");
labelsexe=lookup_widget(gestion,"labelsexe");
existe=lookup_widget(gestion,"label34");
success=lookup_widget(gestion,"label35");
        strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(entryCin) ) );
        strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(entryNom) ) );
        strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(entryPrenom) ) );
        strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(entryAdresse) ) );
        strcpy(c.numtel,gtk_entry_get_text(GTK_ENTRY(entryNumtel) ) );
	strcpy(c.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxaz)));

 gtk_widget_hide (success);

// controle saisie
if(strcmp(c.cin,"")==0){
		  gtk_widget_show (labelCin);
b=0;
}
else {
		  gtk_widget_hide(labelCin);
}

if(strcmp(c.nom,"")==0){
		  gtk_widget_show (labelnom);
b=0;
}
else {
		  gtk_widget_hide(labelnom);
}
if(strcmp(c.prenom,"")==0){
		  gtk_widget_show (labelprenom);
b=0;
}
else {
		  gtk_widget_hide(labelprenom);
}
if(strcmp(c.adresse,"")==0){
		  gtk_widget_show (labeladresse);
b=0;
}
else {
		  gtk_widget_hide(labeladresse);
}
if(strcmp(c.numtel,"")==0){
		  gtk_widget_show (labelnumtel);
b=0;
}

else {
		  gtk_widget_hide(labelnumtel);
}
if(strcmp(c.sexe,"")==0){
		  gtk_widget_show (labelsexe);
b=0;
}
else {
		  gtk_widget_hide(labelsexe);
}



if(b==1){

        if(exist_foyer(c.cin)==1)
        {

				  gtk_widget_show (existe);
        }
        else {
						  gtk_widget_hide (existe);
                ajouter_foyer(c);

						  gtk_widget_show (success);
        }
//mise a jour du treeView
        GtkWidget* p=lookup_widget(gestion,"treeview1");

        Afficherfoyer(p,"foyer.txt");
}











}


void
on_Modifierfoyer_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
       	 foyer c;

        strcpy(c.cin,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion,"label20"))));
        strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry6"))));
        strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry7"))));
        strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry9"))));
        strcpy(c.numtel,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry8"))));            strcpy(c.sexe,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entrySexe"))));

        supprimer_foyer(c.cin);
        ajouter_foyer(c);
//mise ajour du tree view 
        Afficherfoyer(lookup_widget(gestion,"treeview1"),"foyer.txt");
		gtk_widget_show(lookup_widget(gestion,"label37"));



}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)//signale du treeView (Double click)
{
	gchar *cin;
        gchar *nom;
        gchar *prenom;
        gchar *adresse;
        gchar *numtel;
        gchar *sexe;

        int x;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(gestion,"treeview1");
        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
		gtk_widget_hide(lookup_widget(gestion,"label37"));
		
                gtk_tree_model_get (model,&iter,0,&cin,1,&nom,2,&prenom,3,&adresse,4,&numtel,5,&sexe,-1);//recuperationnn des info de la l select
		//remplir les  entry
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entry6")),nom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entry7")),prenom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entry9")),adresse);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entry8")),numtel);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entrySexe")),sexe);



                GtkWidget* msgCin=lookup_widget(gestion,"label20");
                GtkWidget* msg1=lookup_widget(gestion,"label36");
                gtk_label_set_text(GTK_LABEL(msgCin),cin);
                gtk_widget_show(msgCin);
                gtk_widget_show(msg1);
                gtk_widget_show(lookup_widget(gestion,"button4"));
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(gestion,"notebook1")));
        }



}


void
on_Supprimerfoye_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar* cin;
        label=lookup_widget(gestion,"label23");
        p=lookup_widget(gestion,"treeview1");




        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//testerr la lg select
        {  gtk_tree_model_get (model,&iter,0,&cin,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprission du lg m treeview

           supprimer_foyer(cin);// supprission la lg m foyer.txt

           gtk_widget_hide (label);}
else{
                gtk_widget_show (label);
        }

}


void
on_chercherfoyer_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelnom;
GtkWidget *nbResultat;
GtkWidget *message;
char nom[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(gestion,"entry10");
labelnom=lookup_widget(gestion,"label28");
p1=lookup_widget(gestion,"treeview2");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(entry)));

if(strcmp(nom,"")==0){
  gtk_widget_show (labelnom);b=0;
}else{
b=1;
gtk_widget_hide (labelnom);}

if(b==0){return;}else{

nb=Chercherfoyer(p1,"foyer.txt",nom);
// affiche le nbre des resultats obtenue ml recherche
sprintf(chnb,"%d",nb);//convertir entier en chaine khater la fct gtk_label_set_text tacceptich ken chaine
nbResultat=lookup_widget(gestion,"label27");
message=lookup_widget(gestion,"label26");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);

gtk_widget_show (nbResultat);
gtk_widget_show (message);



}

}


void
on_GestionAcceuil_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuil);
gtk_widget_destroy (gestion);

}


void
on_Reserver_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *labelSelection;
        GtkWidget *labelInvalid;
        GtkWidget *labelsuccess;

        int nbPlaceDispo,prix,nbE;
       gchar *date_depart;
        gchar *date_retour;
        gchar *destination;
	excursion e;


        labelSelection=lookup_widget(gestion,"label43");
        labelInvalid=lookup_widget(gestion,"label44");
        labelsuccess=lookup_widget(gestion,"label45");
        p=lookup_widget(gestion,"treeview3");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
                gtk_tree_model_get (model,&iter,0,&date_depart,1,&date_retour,2,&destination,3,&nbPlaceDispo,4,&prix,-1);//recuperation des info de la lg selectt
		//remplissage du structure foyer
		strcpy(e.date_depart,date_depart);
		strcpy(e.date_retour,date_retour);
		strcpy(e.destination,destination);
		e.prix=prix;
		e.nbPlaceDispo=nbPlaceDispo;
		nbE =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion,"spinbutton1")));



		if(e.nbPlaceDispo<nbE){

		gtk_widget_show (labelInvalid);

		}else
		{
		gtk_widget_hide(labelInvalid);


		

		gtk_widget_show (labelsuccess);









		//m a j du treeView
		AfficherExcursion(lookup_widget(gestion,"treeview3"),"excursions.txt");

	 	gtk_widget_hide (labelSelection); }

	}else{

                gtk_widget_show (labelSelection);
        }




}



int x;
int t[2]={0,0};

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton)) 

   {t[1]=1;}    
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton)) 
  {t[0]=1;}   
}

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {x=1;} 
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{x=2;} 
}




void
on_OkAZ_clicked                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
char ch1[200]=" \n \n \n \n ";
char ch2[200]=" ";
char ch3[200]=" ";
if (x==1) 
strcpy(ch2," nouveau ");
 else  
strcpy(ch2," ancien ");
 if (t[0]==1)
 strcat(ch3," ESE "); 
if(t[1]==1)
 strcat (ch3," ESB");
strcat(ch3,ch1);
strcat(ch3,ch2);
output = lookup_widget(button, "label234");

gtk_label_set_text(GTK_LABEL(output),ch3);

}


void
on_button12_azz_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.instagram.com/");
}


void
on_button13azz_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.facebook.com/esprit.tn");
}


void
on_button14quitaz_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}





void
on_buttonnb_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ty,*nb;


char nom[20];
char prenom[20];
char matricule[20];
char role[20];
char ddn[20];
char mail[20];
char res[20];
char fayer[20];
char sexe[20];
char n[20];

char niveauComb[20];

ty = lookup_widget(objet_graphique,"entrynb");
nb = lookup_widget(objet_graphique, "spinbuttonnb");

strcpy(niveauComb,gtk_entry_get_text(GTK_ENTRY(ty)));
 FILE* F;


int nb1=0;


F=fopen("user.txt","r");
if(F!=NULL)
{
    
while (fscanf (F,"%s %s %s %s %s %s %s %s %s %s \n",nom,prenom,matricule,role,ddn,mail,res,fayer,sexe,n) != EOF)
    {
if(strcmp(nom,"etudiant")==0){
      if(strcmp(n,niveauComb)==0)
      nb1++;
    }
}
fclose(F); 
}

gtk_spin_button_set_value(GTK_SPIN_BUTTON(nb),nb1);


}


void
on_button15nbetud_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *etud;
  

etud = create_nb ();
  gtk_widget_show (etud);
}

