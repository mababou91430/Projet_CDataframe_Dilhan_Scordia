#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    COLUMN *colonne = create_column("test");
    printf("%s\n",colonne->titre);
    for(int i; i<2048;i++){
        insert_value_colonne(colonne, i);
    }
    printf("%d\n",colonne->tab[400]);
    printf("%s\n",colonne->titre);
    delete_column(colonne);
    printf("%d\n",colonne->tab[400]);
    printf("%s\n",colonne->titre);
    printf("finish\n");
    return 0;
}