#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    /*int choix = -1;
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
               "14 : Nombre de cellule inferieur a une valeur\n");
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
            default: printf("Ce nombre n'est pas prit en compte");
        }
    }*/
    ENUM_TYPE type_colonne ;//= (ENUM_TYPE) malloc(sizeof(ENUM_TYPE));
    int type;
    char * titre = (char *) malloc(50*sizeof(char));
    //void *value;
    printf("Type de valeur\nInt\nChar\nFloat\nDouble\nString\nStruct\nUnsigned int\n");
    scanf("%d",&type);
    switch (type) {
        case 1:{
            type_colonne = INT;
            break;
        }
        case 2 :{
            type_colonne = CHAR;
            break;
        }
        case 3 :{
            type_colonne = FLOAT;
            break;
        }
        case 4 :{
            type_colonne = DOUBLE;
            break;
        }
        case 5 :{
            type_colonne = STRING;
            break;
        }
        case 6 :{
            type_colonne = STRUCTURE;
            break;
        }
        case 7 :{
            type_colonne = UINT;
        }
        default: printf("Chiffre pas pris en compte");
    }
    printf("Entrer un titre");
    scanf("%s",titre);
    COLUMN *col = create_column(type_colonne,titre);
    printf("saisir une valeur :");
    switch (type_colonne) {
        case INT:{
            int val;
            scanf("%d",&val);
            insert_value_colonne(col,(void*)&val);
            break;
        }
        case CHAR :{
            char val;
            scanf("%c",&val);
            insert_value_colonne(col,(void*)&val);
            break;
        }
        case FLOAT :{
            float val;
            scanf("%f",&val);
            insert_value_colonne(col,(void*)&val);
            break;
        }
        case DOUBLE :{
            double val;
            scanf("%lf",&val);
            insert_value_colonne(col,(void*)&val);
            break;
        }
        case STRING :{
            char * val = (char *) malloc(50*sizeof(char));
            scanf("%s",val);
            insert_value_colonne(col,(void*)&val);
            break;
        }
        case STRUCTURE :{
            void * val;
            break;
        }
        case UINT :{
            unsigned int val;
            scanf("%d",&val);
            insert_value_colonne(col,(void*)&val);
            break;
        }
        default: printf("Chiffre pas pris en compte");
    }
    switch (col->column_type) {
        case INT:{
            printf("%d",col->tab[0]->int_value);
            break;
        }
        case CHAR :{
            printf("%c",col->tab[0]->char_value);
            break;
        }
        case FLOAT :{
            printf("%f",col->tab[0]->float_value);
            break;
        }
        case DOUBLE :{
            printf("%f",col->tab[0]->double_value);
            break;
        }
        case STRING :{
            printf("%s",col->tab[0]->string_value);
            break;
        }
        case UINT :{
            printf("%d",col->tab[0]->uint_value);
            break;
        }
        default: printf("pas pris");
    }
    return 0;
}