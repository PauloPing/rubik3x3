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

char *letter(Cellule c)
{
    enum Color color = c.color;
    switch (color)
    {
    case ROUGE:
        return "R";
        break;
    case BLEU:
        return "B";
        break;
    case JAUNE:
        return "J";
        break;
    case ORANGE:
        return "O";
        break;
    case BLANC:
        return "b";
        break;
    case VERT:
        return "V";
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

void printTerminalFaceFile(FILE *file,Face *face)
{
    int nbEspace = 12;
    for (int j = 0; j < nbEspace; j++)
        fprintf(file," ");
    fprintf(file,"  - - - - -\n");
    int i, j;
    for (i = 0; i < TAILLE_MATRICE; i++)
    {
        for (int j = 0; j < nbEspace; j++)
            fprintf(file," ");
        fprintf(file," |");
        for (j = 0; j < TAILLE_MATRICE; j++)
        {
            fprintf(file," %d%s ",  face->tab[i][j].val,letter(face->tab[i][j])); //  + face->tab[i]->y * TAILLE_MATRICE
        }
        fprintf(file,"|\n");
    }
    for (int j = 0; j < nbEspace; j++)
        fprintf(file," ");
    fprintf(file,"  - - - - -\n");
}

void printTerminalRubikCubeFile(FILE *file,Face *rubikube[])
{
    int nbFaceMilieu = NB_FACE - 2;
    int i, j, k;
    printTerminalFaceFile(file,rubikube[HAUT]);
    for (i = 0; i < nbFaceMilieu; i++)
    {
        fprintf(file," - - - - -  ");
    }
    fprintf(file,"\n");
    for (i = 0; i < TAILLE_MATRICE; i++)
    {
        for (j = 1; j < nbFaceMilieu + 1; j++)
        {
            fprintf(file,"|");

            for (k = 0; k < TAILLE_MATRICE; k++)
            {
                fprintf(file," %d%s ",  rubikube[j]->tab[i][k].val,letter(rubikube[j]->tab[i][k])); //  + face->tab[i]->y * TAILLE_MATRICE
            }
            fprintf(file,"| ");
        }
        fprintf(file,"\n");
    }
    for (i = 0; i < nbFaceMilieu; i++)
    {
        fprintf(file," - - - - -  ");
    }
    fprintf(file,"\n");
    printTerminalFaceFile(file,rubikube[BAS]);
    fprintf(file," ");
}


/*--------------------------------Affichage Terminal --------------------------*/
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




int main(int argc, char *argv[])
{
    FILE *file = fopen("affichage","w");
    Face *rubikube[NB_FACE];
    creerRubikube(rubikube);
    fprintf(file,"RUBIKUBE DE DEPART : \n");
    printf("RUBIKUBE DE DEPART : \n");
    printTerminalRubikCube(rubikube);
    printTerminalRubikCubeFile(file,rubikube);
    melangerRubikCube(rubikube);
    fprintf(file,"RUBIKUBE MELANGE : \n");
    printf("RUBIKUBE MELANGE : \n");
    printTerminalRubikCube(rubikube);
    printTerminalRubikCubeFile(file,rubikube);
    mainCroixBlanche(rubikube);
    fprintf(file,"RUBIKUBE CROIX BLANCHE : \n");
    printf("RUBIKUBE CROIX BLANCHE : \n");
    printTerminalRubikCube(rubikube);
    printTerminalRubikCubeFile(file,rubikube);
    mainAngleFaceBlanche(rubikube);
    fprintf(file,"RUBIKUBE FACE BLANCHE : \n");
    printf("RUBIKUBE FACE BLANCHE : \n");
    printTerminalRubikCube(rubikube);
    printTerminalRubikCubeFile(file,rubikube);
    mainDeuxiemeCouche(rubikube);
    fprintf(file,"RUBIKUBE DEUXIEME COUCHE : \n");
    printf("RUBIKUBE DEUXIEME COUCHE : \n");
    printTerminalRubikCube(rubikube);
    printTerminalRubikCubeFile(file,rubikube);
    mainCroixJaune(rubikube);
    mainExtremiteCroixJaune(rubikube);
    fprintf(file,"RUBIKUBE CROIX JAUNE : \n");
    printf("RUBIKUBE CROIX JAUNE : \n");
    printTerminalRubikCube(rubikube);
    printTerminalRubikCubeFile(file,rubikube);
    mainAngleJaune(rubikube);
    fprintf(file,"RUBIKUBE COIN JAUNE : \n");
    printf("RUBIKUBE COIN JAUNE : \n");
    printTerminalRubikCube(rubikube);
    printTerminalRubikCubeFile(file,rubikube);
    mainFaceJaune(rubikube);
    fprintf(file,"RUBIKUBE FINAL : \n");
    printf("RUBIKUBE FINAL : \n");
    printTerminalRubikCube(rubikube);
    printTerminalRubikCubeFile(file,rubikube);
    
    


    
    
    


    
    return 0;
}
