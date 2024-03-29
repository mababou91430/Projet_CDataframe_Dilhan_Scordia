#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    char titre[50] = "test";
    COLUMN *colonne = create_column(titre);
    printf("%s",colonne->titre);

    return 0;
}