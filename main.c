#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    COLUMN *colonne = create_column("test");
    printf("%s",colonne->titre);
    for(int i; i<2048;i++){
        insert_value_colonne(colonne, i);
    }
    printf("")
    return 0;
}