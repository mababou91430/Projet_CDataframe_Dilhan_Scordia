#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>


COLUMN *create_column(char *title){
    int *tab[256];
    COLUMN * column = (COLUMN*)malloc(sizeof (COLUMN));
    column->titre=title;
    column->tab = *tab;
    column->taille_Logique=0;
    column->taille_Physique=256;
    return column;
}