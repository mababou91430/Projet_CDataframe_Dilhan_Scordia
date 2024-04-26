//
// Created by mathm on 29/03/2024.
//


enum enum_type {
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;
union column_type{
unsigned int uint_value;
signed int int_value;
char char_value;
float float_value;
double double_value;
char* string_value;
void* struct_value;
};
typedef union column_type COL_TYPE ;
struct column {
    char *titre;
    unsigned int taille_Logique; //logical size
    unsigned int taille_Physique; //physical size
    ENUM_TYPE column_type;
    COL_TYPE **tab; // array of pointers to stored data
    unsigned long long int *index; // array of integers
};
typedef struct column COLUMN;

typedef struct {
    COLUMN * tab;
    int taille_Physique;
    int taille_Logique;
}CDataframe;
#ifndef PROJET_FONCTION_H
#define PROJET_FONCTION_H

int insert_value_colonne(COLUMN *col, int value_insert);
COLUMN *create_column(ENUM_TYPE type, char *title);
void delete_column(COLUMN *col);
void print_col(COLUMN* col);
int nombre_occurence(COLUMN* col,int x);
int valeur_pos_x(COLUMN* col,int x);
int valeur_superieur_x(COLUMN* col,int x);
int valeur_inferieur_x(COLUMN* col,int x);
int valeur_egale_x(COLUMN* col,int x);
CDataframe* creation_CDataframe();
void remplissage_CDataframe(CDataframe*);
void remplissage_Dur_CDataframe(CDataframe*);
void afficher_All_CDataframe(CDataframe*);
void afficher_Ligne_Limite_CDataframe(CDataframe*,int x);
void afficher_Colonne_Limite_CDataframe(CDataframe*,int x);
void afficher_nombre_ligne_CDataframe(CDataframe*);
void afficher_nombre_colonne_CDataframe(CDataframe*);
int nombre_cellules_contenant_X(CDataframe*,int x);
int nombre_cellules_superieur_X(CDataframe* Dataframe, int x);
int nombre_cellules_inferieur_X(CDataframe* Dataframe, int x);

void ajout_ligne_CDataFrame(CDataframe* CDataFrame);
void supr_ligne_CDataFrame(CDataframe* CDataFrame);
void ajout_colonne_CDataFrame(CDataframe* CDataFrame, char *title);
void supr_colonne_CDataFrame(CDataframe* CDataFrame);
void renommer_colonne_CDataFrame(CDataframe* CDataFrame, int num_colonne, char *title);
int verif_existence(CDataframe* CDataFrame, int val);
void remplacer_val(CDataframe* CDataFrame, int val, int i, int j);
void afficher_nom_col(CDataframe* CDataFrame);
#endif //PROJET_FONCTION_H
