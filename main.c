#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x;
    int y;
    int z;
    COLUMN *colonne = create_column("test");
    for(int i=0; i<10;i++){
        insert_value_colonne(colonne, i);
    }
    insert_value_colonne(colonne, 3);
    print_col(colonne);
    scanf("%d",&x);
    printf("%d\n", valeur_egale_x(colonne,x));

    return 0;
}