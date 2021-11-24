#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "methode.c"

#define TRUE 1
#define FALSE 0
#define NB_MOUVEMENT 1000

char *printCellule(Cellule c)
{
    enum Color color = c.color;
    switch (color)
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

char *color(Cellule c)
{
    enum Color color = c.color;
    switch (color)
    {
    case ROUGE:
        return "\x1b[31m";
        break;
    case BLEU:
        return "\x1b[34m";
        break;
    case JAUNE:
        return "\x1b[35m";
        break;
    case ORANGE:
        return "\x1b[33m";
        break;
    case BLANC:
        return "\x1b[37m";
        break;
    case VERT:
        return "\x1b[32m";
        break;
    }
}

Face *creerFace(enum Direction dir, enum Color color)
{
    int val = 0;
    Face *newFace = malloc(sizeof(Face));
    newFace->dir = dir;
    Cellule **tab = malloc(sizeof(Cellule) * (TAILLE_MATRICE));
    for (int k = 0; k < TAILLE_MATRICE; k++)
    {
        tab[k] = malloc(sizeof(Cellule) * (TAILLE_MATRICE));
    }
    int i, j;
    for (i = 0; i < TAILLE_MATRICE; i++)
    {
        for (j = 0; j < TAILLE_MATRICE; j++)
        {
            Cellule c;
            c.color = color;
            c.val = val++;
            printCellule(c);
            tab[i][j] = c;
        }
    }
    newFace->tab = tab;
    return newFace;
}

void creerRubikube(Face *rubikube[])
{
    for (int i = 0; i < NB_FACE; i++)
    {
        Face *face = creerFace(i, i);
        rubikube[i] = face;
    }
}

void printTerminalFace(Face *face)
{
    int nbEspace = 12;
    for (int j = 0; j < nbEspace; j++)
        printf(" ");
    printf("\x1b[30m - - - - -\n");
    int i, j;
    for (i = 0; i < TAILLE_MATRICE; i++)
    {
        for (int j = 0; j < nbEspace; j++)
            printf(" ");
        printf("|");
        for (j = 0; j < TAILLE_MATRICE; j++)
        {
            printf("%s %d \x1b[0m", color(face->tab[i][j]), face->tab[i][j].val); //  + face->tab[i]->y * TAILLE_MATRICE
        }
        printf("\x1b[30m|\n");
    }
    for (int j = 0; j < nbEspace; j++)
        printf(" ");
    printf(" - - - - -\n");
}

void printTerminalRubikCube(Face *rubikube[])
{
    int nbFaceMilieu = NB_FACE - 2;
    int i, j, k;
    printTerminalFace(rubikube[HAUT]);
    for (i = 0; i < nbFaceMilieu; i++)
    {
        printf("\x1b[30m - - - - -  ");
    }
    printf("\n");
    for (i = 0; i < TAILLE_MATRICE; i++)
    {
        for (j = 1; j < nbFaceMilieu + 1; j++)
        {
            printf("\x1b[30m|");

            for (k = 0; k < TAILLE_MATRICE; k++)
            {
                printf("%s %d ", color(rubikube[j]->tab[i][k]), rubikube[j]->tab[i][k].val); //  + face->tab[i]->y * TAILLE_MATRICE
            }
            printf("\x1b[30m| ");
        }
        printf("\n");
    }
    for (i = 0; i < nbFaceMilieu; i++)
    {
        printf("\x1b[30m - - - - -");
    }
    printf("\n");
    printTerminalFace(rubikube[BAS]);
    printf("\x1b[0m");
}

void melangerRubikCube(Face *rubikube[])
{
    srand(time(NULL));
    int r, i = 0;
    for (i = 0; i < NB_MOUVEMENT; i++)
    {
        r = rand() % (NB_FUNCTION);
        void (*fun_ptr)(Face * rubikube[]) = mouvement[r];
        (*fun_ptr)(rubikube);
    }
}



int main(int argc, char *argv[])
{
    Face *rubikube[NB_FACE];
    creerRubikube(rubikube);
    melangerRubikCube(rubikube);
    mainCroixBlanche(rubikube);
    mainAngleFaceBlanche(rubikube);

    mainDeuxiemeCouche(rubikube);
    for (int i = 0; i < 100000; i++)
    {
       deuxiemeCouche(rubikube,ROUGE);
    tournerRubikubeVersDroite(rubikube);
    deuxiemeCouche(rubikube,VERT);
    tournerRubikubeVersDroite(rubikube);
    deuxiemeCouche(rubikube,ORANGE);
    tournerRubikubeVersDroite(rubikube);
    deuxiemeCouche(rubikube,BLEU);
    tournerRubikubeVersDroite(rubikube); 
    }
    
    


    printTerminalRubikCube(rubikube);
    
    return 0;
}
