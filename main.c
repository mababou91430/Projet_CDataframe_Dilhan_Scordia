#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choix = -1;
    CDataframe* Dataframe = creation_CDataframe();
    remplissage_Dur_CDataframe(Dataframe);
    printf("Entrer un chiffre pour choisir une operation : \n"
        "0 : Arreter le programme\n"
               "1 : Ajouter une ligne\n"
               "2 : Supprimer une ligne\n"
               "3 : Ajouter une colonne\n"
               "4 : Supprimer une colonne\n"
               "5 : Changer toutes les valeurs\n"
               "6 : Changer une valeur\n"
               "7 : Afficher le Dataframe\n"
               "8 : Afficher une partie des lignes du Dataframe\n"
               "9 : Afficher une partie des colonnes du Dataframe\n"
               "10 : Afficher le nombre de ligne du Dataframe\n"
               "11 : Afficher le nombre de colonne du Dataframe\n"
               "12 : Nombre de cellule contenant une valeur\n"
               "13 : Nombre de cellule superieur a une valeur\n"
               "14 : Nombre de cellule inferieur a une valeur\n"
               "15 : Remplissage dur cdataframe");

    while (choix != 0) {
        scanf("%d",&choix);
        switch (choix) {
            case 0: {
                break;
            }
            case 1: {
                ajout_ligne_CDataFrame(Dataframe);
                remplissage_Dur_CDataframe(Dataframe);
                break;
            }
            case 2: {
                supr_ligne_CDataFrame(Dataframe);
                break;
            }
            case 3: {
                char * titre =(char*) malloc(50*sizeof(char));
                printf("Entrer un titre pour la nouvelle colonne");
                scanf("%s",titre);
                ajout_colonne_CDataFrame(Dataframe,titre);
                break;
            }
            case 4: {
                supr_colonne_CDataFrame(Dataframe);
                break;
            }
            case 5: {
                remplissage_CDataframe(Dataframe);
                break;
            }
            case 6: {
                int val=0;
                int i=0;
                int j=0;
                printf("Entrer la ligne de la valeur a remplacer : ");
                scanf("%d",&i);
                printf("Entrer la colonne de la valeur a remplacer : ");
                scanf("%d",&j);
                printf("Entrer la nouvelle valeur");
                scanf("%d",&val);
                remplacer_val(Dataframe,val,j,i);
                break;
            }
            case 7: {
                afficher_All_CDataframe(Dataframe);
                break;
            }
            case 8: {
                int x;
                printf("Entrer un nombre de ligne a afficher");
                scanf("%d",&x);
                afficher_Ligne_Limite_CDataframe(Dataframe,x);
                break;
            }
            case 9: {
                int x;
                printf("Entrer un nombre de colonne a afficher");
                scanf("%d",&x);
                afficher_Colonne_Limite_CDataframe(Dataframe,x);
                break;
            }
            case 10: {
                afficher_nombre_ligne_CDataframe(Dataframe);
                break;
            }
            case 11: {
                afficher_nombre_colonne_CDataframe(Dataframe);
                break;
            }
            case 12: {
                int x;
                printf("Entrer un nombre pour savoir combien de cellule sont egales a ce nombre dans le Dataframe");
                scanf("%d",&x);
                printf("%d",nombre_cellules_contenant_X(Dataframe,x));
                break;
            }
            case 13: {
                int x;
                printf("Entrer un nombre pour savoir combien de cellule sont superieures a ce nombre dans le Dataframe");
                scanf("%d",&x);
                printf("%d",nombre_cellules_superieur_X(Dataframe,x));
                break;
            }
            case 14 : {
                int x;
                printf("Entrer un nombre pour savoir combien de cellule sont inferieures a ce nombre dans le Dataframe");
                scanf("%d",&x);
                printf("%d",nombre_cellules_inferieur_X(Dataframe,x));
                break;
            }
            case 15 : {
                remplissage_Dur_CDataframe(Dataframe);
                break;
            }
            default: printf("Ce nombre n'est pas prit en compte");
        }
    }
    return 0;
}