#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    CDataframe* Dataframe = creation_CDataframe();
    for(int i=0;i<5;i++){
        ajout_ligne_CDataFrame(Dataframe);
    }
    remplissage_Dur_CDataframe(Dataframe);
    afficher_Ligne_Limite_CDataframe(Dataframe,3);

    return 0;
}