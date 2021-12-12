#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include<string.h>


void ajouter_foyer( foyer c){
FILE*f=NULL;
f=fopen("foyer.txt","a");
fprintf(f,"%s %s %s %s %s %s\n",c.cin,c.nom,c.prenom,c.adresse,c.numtel,c.sexe);
fclose(f);

}

int exist_foyer(char*cin){
FILE*f=NULL;
 foyer c;
f=fopen("foyer.txt","r");
while(fscanf(f,"%s %s %s %s %s %s\n",c.cin,c.nom,c.prenom,c.adresse,c.numtel,c.sexe)!=EOF){
if(strcmp(c.cin,cin)==0)return 1;
}
fclose(f);
return 0;
}


void supprimer_foyer(char*cin){
FILE*f=NULL;
FILE*f1=NULL;
foyer c ;
f=fopen("foyer.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s\n",c.cin,c.nom,c.prenom,c.adresse,c.numtel,c.sexe)!=EOF){
if(strcmp(cin,c.cin)!=0)fprintf(f1,"%s %s %s %s %s\n",c.cin,c.nom,c.prenom,c.adresse,c.numtel);
}
fclose(f);
fclose(f1);
remove("foyer.txt");
rename("ancien.txt","foyer.txt");
}


















