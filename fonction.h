//
// Created by mathm on 29/03/2024.
//
typedef struct {
    char* titre;
    int* tab;
    int taille_Physique;
    int taille_Logique;
}COLUMN;
#ifndef PROJET_FONCTION_H
#define PROJET_FONCTION_H

int insert_value_colonne(COLUMN *col, int value_insert);
COLUMN *create_column(char *title);
void print_col(COLUMN* col);
int nombre_occurence(COLUMN* col,int x);
int valeur_pos_x(COLUMN* col,int x);
int valeur_superieur_x(COLUMN* col,int x);
int valeur_inferieur_x(COLUMN* col,int x);
int valeur_egale_x(COLUMN* col,int x);
#endif //PROJET_FONCTION_H
