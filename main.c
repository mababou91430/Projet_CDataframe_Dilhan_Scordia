#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    COLUMN *colonne = create_column("test");
    for(int i=0; i<5;i++){
        insert_value_colonne(colonne, i);
    }
    print_col(colonne);
    return 0;
}