#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>

int insert_value_colonne(COLUMN *col, int value_insert){
    while(col->taille_Logique>=col->taille_Physique){
        col->taille_Physique=col->taille_Physique+1;
        col->tab = realloc(col->tab, col->taille_Physique);
    }
    col->tab[col->taille_Logique++]=value_insert;
}
