#include <gtk/gtk.h>
  GtkWidget *acceuil;
  GtkWidget *gestion;
typedef struct foyer foyer;
struct foyer{
char cin[30];
char nom[30];
char prenom[30];
char adresse[30];
char numtel[9];
char sexe[20];

};

typedef struct excursion excursion;
struct excursion{
char date_depart[30];
char date_retour[30];
char destination[30];
int nbPlaceDispo;
int prix;
};
int i,j,k;
void
on_AcceuilGestion_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_Ajouterfoyer_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifierfoyer_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_Supprimerfoye_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercherfoyer_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_GestionAcceuil_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_Reserver_clicked                    (GtkButton       *button,
                                        gpointer         user_data);


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_OkAZ_clicked                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button12_azz_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button13azz_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button14quitaz_clicked              (GtkButton       *button,
                                        gpointer         user_data);


void
on_buttonnb_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button15nbetud_clicked              (GtkButton       *button,
                                        gpointer         user_data);
