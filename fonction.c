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
    int taillePhys = Dataframe->tab[0].taille_Physique;
    for(int i = 0;i<Dataframe->taille_Physique;i++){
        Dataframe->tab[i].titre = "title";
        for(int j = 0;j<taillePhys;j++){
            if(Dataframe->tab[i].tab[j] != 0) {
                insert_value_colonne(&Dataframe->tab[i], 0);
            }
        }
    }
}
void afficher_All_CDataframe(CDataframe* Dataframe){
    for(int i = 0; i<Dataframe->taille_Logique;i++){
        printf("%s\n",Dataframe->tab[i].titre);
        print_col(&Dataframe->tab[i]);
    }
}
void afficher_Ligne_Limite_CDataframe(CDataframe* Dataframe,int x) {
    if (x <= Dataframe->tab[0].taille_Logique && x >= 0) {
        for (int i = 0; i < Dataframe->taille_Logique; i++) {
            printf("%s\n", Dataframe->tab[i].titre);
            for (int j = 0; j < x; j++) {
                printf("[%d] %d\n",j, Dataframe->tab[i].tab[j]);
            }
        }
    } else {
        printf("Limite trop grande");
    }
}
void afficher_Colonne_Limite_CDataframe(CDataframe* Dataframe,int x){
    if(x <= Dataframe->taille_Logique && x >= 0){
        for(int i=0;i<x;i++){
            printf("%s\n",Dataframe->tab[i].titre);
            print_col(&Dataframe->tab[i]);
        }
    }
}
void afficher_nombre_ligne_CDataframe(CDataframe* Dataframe){
    printf("Nombre de ligne du CDataframe : %d",Dataframe->tab[0].taille_Logique);
}
void afficher_nombre_colonne_CDataframe(CDataframe* Dataframe){
    printf("Nombre de colonne du CDataframe : %d",Dataframe->taille_Logique);
}
void ajout_ligne_CDataFrame(CDataframe* CDataFrame) {
    //vérification taille physique max Colonne
    int taille_phys_max = CDataFrame->tab[0].taille_Physique;
    for (int i = 1; i < CDataFrame->taille_Logique; i++) {
        if (CDataFrame->tab[i].taille_Physique >
            taille_phys_max) { taille_phys_max = CDataFrame->tab[i].taille_Physique; }
    }
    //ajout ligne
    for (int i = 0; i < CDataFrame->taille_Logique; i++) {
        CDataFrame->tab[i].taille_Physique = taille_phys_max + 1;
        CDataFrame->tab[i].tab= realloc(CDataFrame->tab[i].tab, CDataFrame->tab[i].taille_Physique*sizeof(int));
    }
}
void supr_ligne_CDataFrame(CDataframe* CDataFrame){
            //vérification taille physique min Colonne
            int taille_phys_min = CDataFrame->tab[0].taille_Physique;
            for (int i = 1; i < CDataFrame->taille_Logique; i++) {
                if (CDataFrame->tab[i].taille_Physique <taille_phys_min) { taille_phys_min = CDataFrame->tab[i].taille_Physique; }
            }
            //ajout ligne
            for (int i = 0; i < CDataFrame->taille_Logique; i++) {
                CDataFrame->tab[i].taille_Physique = taille_phys_min - 1;
                CDataFrame->tab[i].tab= realloc(CDataFrame->tab[i].tab, CDataFrame->tab[i].taille_Physique*sizeof(int));
            }
}
int nombre_cellules_contenant_X(CDataframe* Dataframe, int x){
    int nombre = 0;
    for(int i =0; i<Dataframe->taille_Logique;i++){
        nombre = valeur_egale_x(&Dataframe->tab[i],x);
    }
    return nombre;
}
int nombre_cellules_superieur_X(CDataframe* Dataframe, int x){
    int nombre = 0;
    for(int i =0; i<Dataframe->taille_Logique;i++){
        nombre = valeur_superieur_x(&Dataframe->tab[i],x);
    }
    return nombre;
}
int nombre_cellules_inferieur_X(CDataframe* Dataframe, int x){
    int nombre = 0;
    for(int i =0; i<Dataframe->taille_Logique;i++){
        nombre = valeur_inferieur_x(&Dataframe->tab[i],x);
        }

    return nombre;
}

void ajout_colonne_CDataFrame(CDataframe* CDataFrame, char *title){
    while(CDataFrame->taille_Logique>=CDataFrame->taille_Physique){
        CDataFrame->tab = realloc(CDataFrame->tab, ++CDataFrame->taille_Physique*sizeof(COLUMN));
    }
    CDataFrame->tab[CDataFrame->taille_Logique++]=*create_column(title);
    CDataFrame->tab[CDataFrame->taille_Logique-1].taille_Physique=CDataFrame->tab[0].taille_Physique;
    CDataFrame->tab[CDataFrame->taille_Logique-1].tab= realloc(CDataFrame->tab[CDataFrame->taille_Logique-1].tab,CDataFrame->tab[CDataFrame->taille_Logique-1].taille_Physique*sizeof(COLUMN));
    CDataFrame->tab[CDataFrame->taille_Logique-1].taille_Logique=CDataFrame->tab[0].taille_Logique;
    for(int i=0; i<CDataFrame->tab[CDataFrame->taille_Logique-1].taille_Logique; i++){
        CDataFrame->tab[CDataFrame->taille_Logique-1].tab[i]=0;
    }
}