#include <stdio.h>
#include "struct.h"
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

char *printCellule(Cellule c)
{
    enum Color color = c.color;
    switch(color)
    {
        case ROUGE:
            return "ROUGE";
            break;
        case BLEU:
            return "BLEU";
            break;
        case JAUNE:
            return "JAUNE";
            break;
        case ORANGE:
            return "ORANGE";
            break;
        case BLANC:
            return "BLANC";
            break;
        case VERT:
            return "VERT";
            break;
    }
}

void printFace(Face face)
{
    int i,j;
    for (i = 0; i < TAILLE_MATRICE;i++)
    {
        for (j = 0; j < TAILLE_MATRICE; j++)
        {
            printf("%s ",printCellule(face.tab[i][j]));
        }
        printf("\n");
    }
}

void printRubikube(Face *rubikube)
{
    for (int i = 0; i < NB_FACE;i++)
    {
        printFace(rubikube[i]);
    }
}

Face creerFace(enum Direction dir,enum Color color)
{
    Face newFace;
    newFace.dir = dir;
    Cellule **tab;
    tab = malloc(sizeof(Cellule)*(TAILLE_MATRICE));
    for (int k = 0; k < TAILLE_MATRICE;k++)
    {
        tab[k] = malloc(sizeof(Cellule)*(TAILLE_MATRICE));
    }
    int i,j;
    for (i = 0; i < TAILLE_MATRICE;i++)
    {
        for (j = 0; j < TAILLE_MATRICE;j++)
        {
            Cellule c;
            c.color = color;
            c.x = i;
            c.y = j;
            printCellule(c);
            tab[i][j] = c;
        }
    }
    newFace.tab = tab;
    return newFace;
}

Face *creerRubikube()
{
    Face *rubikube = malloc(sizeof(Face)*NB_FACE);
    for (int i = 0; i < NB_FACE;i++)
    {
        Face face = creerFace(i,i);
        rubikube[i] = face;
    }
    return rubikube;
}




int main(int argc, char *argv[])
{
    Face *rubikube;
    rubikube = creerRubikube();
    printRubikube(rubikube);

    return 0;
}