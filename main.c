#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    CDataframe* Dataframe = creation_CDataframe();
    remplissage_Dur_CDataframe(Dataframe);
    afficher_All_CDataframe(Dataframe);
    return 0;
}