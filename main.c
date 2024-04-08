#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    CDataframe* Dataframe = creation_CDataframe();
    for(int i=0;i<5;i++){
        ajout_ligne_CDataFrame(Dataframe);
    }
    remplissage_Dur_CDataframe(Dataframe);
    afficher_All_CDataframe(Dataframe);
    ajout_ligne_CDataFrame(Dataframe);
    remplissage_Dur_CDataframe(Dataframe);
    afficher_All_CDataframe(Dataframe);
    printf("case contenant 0 %d", nombre_cellules_contenant_X(Dataframe,0));
    return 0;
}