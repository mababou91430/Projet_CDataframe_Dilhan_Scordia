#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>

int insert_value_colonne(COLUMN *col, int value_insert){
    while(col->taille_Logique>=col->taille_Physique){
        col->tab = realloc(col->tab, ++col->taille_Physique*sizeof(int));
    }
    col->tab[col->taille_Logique++]=value_insert;
    if (col->tab[col->taille_Logique-1]==value_insert){return 1;}
    return 0;
}

COLUMN *create_column(char *title){
    int *tab = (int*) malloc(sizeof(int));
    COLUMN* column = (COLUMN*) malloc(sizeof(COLUMN));
    column->titre=title;
    column->tab = tab;
    column->taille_Logique=0;
    column->taille_Physique=1;
    return column;
}
void print_col(COLUMN* col){
    for(int i =0; i<col->taille_Logique; i++){
        printf("[%d] %d\n",i,col->tab[i]);
    }
}
int nombre_occurence(COLUMN* col, int x){
    int nombre_occurence = 0;
    for(int i = 0;i<col->taille_Logique;i++){
        if (col->tab[i] == x){
            nombre_occurence++;
        }
    }
    return  nombre_occurence;
}
int valeur_pos_x(COLUMN* col,int x){
    int pos = col->tab[x];
    return pos;
}
int valeur_superieur_x(COLUMN* col,int x){
    int superieur = 0;
    for(int i=0; i<col->taille_Logique;i++){
        if(col->tab[i] > x){
            superieur++;
        }
    }
    return superieur;
}
int valeur_inferieur_x(COLUMN* col,int x){
    int inferieur = 0;
    for(int i=0; i<col->taille_Logique;i++){
        if(col->tab[i] < x){
            inferieur++;
        }
    }
    return inferieur;
}
int valeur_egale_x(COLUMN* col,int x){
    int egale = 0;
    for(int i=0; i<col->taille_Logique;i++){
        if(col->tab[i] == x){
            egale++;
        }
    }
    return egale;
}

void delete_column(COLUMN *col) {
    free(col->tab);
    free(col);
}
CDataframe *creation_CDataframe(){
    CDataframe* Dataframe = (CDataframe*) malloc(sizeof(CDataframe));
    Dataframe->tab = (COLUMN*) malloc(sizeof(COLUMN));
    Dataframe->taille_Logique = 1;
    Dataframe->taille_Physique = 1;
    Dataframe->tab[0] = *create_column("title");
    return Dataframe;
}
void remplissage_CDataframe(CDataframe* Dataframe){
    char title[50];
    int valeur;
    for(int i = 0;i<Dataframe->taille_Logique;i++){
        printf("Entrer un titre pour la colonne %d : ",i);
        scanf("%s",title);
        Dataframe->tab[i].titre = title;
        for(int j = 0;j<Dataframe->tab[i].taille_Physique;j++){
            printf("Entrer une valeur pour la ligne %d : ",j);
            scanf("%d",&valeur);
            insert_value_colonne(&Dataframe->tab[i],valeur);
        }
    }
}
void remplissage_Dur_CDataframe(CDataframe* Dataframe){
    char title[50];
    int valeur;
    for(int i = 0;i<Dataframe->taille_Logique;i++){
        Dataframe->tab[i].titre = "title";
        for(int j = 0;j<Dataframe->tab[i].taille_Physique;j++){
            insert_value_colonne(&Dataframe->tab[i],0);
        }
    }
}