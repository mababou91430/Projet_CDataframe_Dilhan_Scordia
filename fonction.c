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