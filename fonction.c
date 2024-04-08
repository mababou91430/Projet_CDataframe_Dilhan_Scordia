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
    int *tab = NULL;
    COLUMN * column = (COLUMN*)malloc(sizeof (COLUMN));
    column->titre=title;
    column->tab = tab;
    column->taille_Logique=0;
    column->taille_Physique=0;
    return column;
}

void delete_column(COLUMN *col) {
    free(col->tab);
    free(col);
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

void ajout_ligne_CDataFrame(CDataframe* CDataFrame) {
    //vérification taille physique max Colonne
    int taille_phys_max = CDataFrame->tab[0].taille_Physique;
    for (int i = 1; i < CDataFrame->taille_Physique; i++) {
        if (CDataFrame->tab[i].taille_Physique >
            taille_phys_max) { taille_phys_max = CDataFrame->tab[i].taille_Physique; }
    }
    //ajout ligne
    for (int i = 0; i < CDataFrame->taille_Physique; i++) {
        CDataFrame->tab[i].taille_Physique = taille_phys_max + 1;
        CDataFrame->tab[i].tab= realloc(CDataFrame->tab[i].tab, CDataFrame->tab[i].taille_Physique*sizeof(int));
    }
}
    void supr_ligne_CDataFrame(CDataframe* CDataFrame) {
        //vérification taille physique min Colonne
        int taille_phys_min = CDataFrame->tab[0].taille_Physique;
        for (int i = 1; i < CDataFrame->taille_Physique; i++) {
            if (CDataFrame->tab[i].taille_Physique <
                taille_phys_min) { taille_phys_min = CDataFrame->tab[i].taille_Physique; }
        }
        //suppresion ligne
        for (int i = 0; i < CDataFrame->taille_Physique; i++) {
            CDataFrame->tab[i].taille_Physique = taille_phys_min - 1;
            CDataFrame->tab[i].tab = realloc(CDataFrame->tab[i].tab, CDataFrame->tab[i].taille_Physique * sizeof(int));
        }
    }
void ajout_colonne_CDataFrame(CDataframe* CDataFrame, char *title){
    while(CDataFrame->taille_Logique>=CDataFrame->taille_Physique){
        CDataFrame->tab = realloc(CDataFrame->tab, ++CDataFrame->taille_Physique*sizeof(COLUMN));
    }
    CDataFrame->tab[CDataFrame->taille_Logique++]=*create_column(title);
    CDataFrame->tab[CDataFrame->taille_Logique-1].taille_Physique=CDataFrame->tab[0].taille_Physique;
}