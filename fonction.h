//
// Created by mathm on 29/03/2024.
//
typedef struct {
    char* titre;
    int* tab;
    int taille_Physique;
    int taille_Logique;
}COLUMN;
typedef struct {
    COLUMN * tab;
    int taille_Physique;
    int taille_Logique;
}CDataframe;
#ifndef PROJET_FONCTION_H
#define PROJET_FONCTION_H

int insert_value_colonne(COLUMN *col, int value_insert);
COLUMN *create_column(char *title);
void delete_column(COLUMN *col);
void print_col(COLUMN* col);
int nombre_occurence(COLUMN* col,int x);
int valeur_pos_x(COLUMN* col,int x);
int valeur_superieur_x(COLUMN* col,int x);
int valeur_inferieur_x(COLUMN* col,int x);
int valeur_egale_x(COLUMN* col,int x);
void delete_column(COLUMN *col);
CDataframe* creation_CDataframe();
void remplissage_CDataframe(CDataframe*);
void remplissage_Dur_CDataframe(CDataframe*);
void afficher_All_CDataframe(CDataframe*);
void afficher_Ligne_Limite_CDataframe(CDataframe*,int x);
void afficher_Colonne_Limite_CDataframe(CDataframe*,int x);

void ajout_ligne_CDataFrame(CDataframe* CDataFrame);
void supr_ligne_CDataFrame(CDataframe* CDataFrame);

#endif //PROJET_FONCTION_H
