//
// Created by mathm on 29/03/2024.
//
typedef struct {
    char* titre;
    int* tab;
    int taille_Physique;
    int taille_Logique;
}COLUMN;
#ifndef PROJET_FONCTION_H
#define PROJET_FONCTION_H

COLUMN *create_column(char*title);

#endif //PROJET_FONCTION_H
