#include <stdio.h>
#include "struct.h"
#include <stdlib.h>
#include <string.h>
#include "methode.h"

#define TRUE 1
#define FALSE 0

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

void printFace(Face *face)
{
    int i, j;
    for (i = 0; i < TAILLE_MATRICE; i++)
    {
        for (j = 0; j < TAILLE_MATRICE; j++)
        {
            printf("%s ", printCellule(face->tab[i][j]));
        }
        printf("\n");
    }
}

void printRubikube(Face *rubikube)
{
    for (int i = 0; i < NB_FACE; i++)
    {
        printFace(&rubikube[i]);
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
        printf("\x1b[30m - - - - -  ");
    }
    printf("\n");
    printTerminalFace(rubikube[BAS]);
}

/*--------------------------------------------*/
void permuteCellule(Cellule *c1,Cellule *c2)
{
    Cellule c3;
    c3.color = c1->color;
    c3.face = c1->face;
    c3.val = c1->val;
    c1->color = c2->color;
    c1->face = c2->face;
    c1->val = c2->val;
    c2->color = c3.color;
    c2->face = c3.face;
    c2->val = c3.val;
}

Face *getFace(enum Direction dir, Face *rubikube[])
{
  return rubikube[dir];
}

void setFace(Face *face, enum Direction dir, Face *rubikube[])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      face->tab[i][j].face = getFace(dir, rubikube);
    }
  }
}

void rotationLigneHautVersDroite(Face *rubikube[])
{
  // Face AVANT -> Face DROITE
  Face *droite = getFace(DROITE,rubikube);
  Face *avant = getFace(DEVANT,rubikube);
  permuteCellule(&droite->tab[0][0],&avant->tab[0][0]);
  permuteCellule(&droite->tab[0][1],&avant->tab[0][1]);
  permuteCellule(&droite->tab[0][2],&avant->tab[0][2]);
  // Face DROITE -> Face ARRIERE
  Face *derriere = getFace(DERRIERE,rubikube);
  permuteCellule(&avant->tab[0][0],&derriere->tab[0][0]);
  permuteCellule(&avant->tab[0][1],&derriere->tab[0][1]);
  permuteCellule(&avant->tab[0][2],&derriere->tab[0][2]);
  // Face ARRIERE -> Face GAUCHE
  Face *gauche = getFace(GAUCHE,rubikube);
  permuteCellule(&avant->tab[0][0],&gauche->tab[0][0]);
  permuteCellule(&avant->tab[0][1],&gauche->tab[0][1]);
  permuteCellule(&avant->tab[0][2],&gauche->tab[0][2]);
  // Modification de la face HAUT
  Face *haut = getFace(HAUT,rubikube);
  permuteCellule(&haut->tab[0][0],&haut->tab[2][0]);
  permuteCellule(&haut->tab[1][0],&haut->tab[0][1]);
  permuteCellule(&haut->tab[0][0],&haut->tab[0][2]);
  permuteCellule(&haut->tab[0][1],&haut->tab[2][1]);
  permuteCellule(&haut->tab[0][1],&haut->tab[1][2]);
  permuteCellule(&haut->tab[0][2],&haut->tab[2][2]);
}

void rotationLigneHautVersGauche(Face *rubikube[])
{
  // Face AVANT -> Face GAUCHE
  Face *gauche = getFace(GAUCHE,rubikube);
  Face *avant = getFace(DEVANT,rubikube);
  permuteCellule(&gauche->tab[0][0],&avant->tab[0][0]);
  permuteCellule(&gauche->tab[0][1],&avant->tab[0][1]);
  permuteCellule(&gauche->tab[0][2],&avant->tab[0][2]);
  // Face DROITE -> Face ARRIERE
  Face *derriere = getFace(DERRIERE,rubikube);
  permuteCellule(&avant->tab[0][0],&derriere->tab[0][0]);
  permuteCellule(&avant->tab[0][1],&derriere->tab[0][1]);
  permuteCellule(&avant->tab[0][2],&derriere->tab[0][2]);
  // Face ARRIERE -> Face DROITE
  Face *droite = getFace(DROITE,rubikube);
  permuteCellule(&avant->tab[0][0],&droite->tab[0][0]);
  permuteCellule(&avant->tab[0][1],&droite->tab[0][1]);
  permuteCellule(&avant->tab[0][2],&droite->tab[0][2]);
  // Modification de la face HAUT
  Face *haut = getFace(HAUT,rubikube);
  permuteCellule(&haut->tab[0][0],&haut->tab[0][2]);
  permuteCellule(&haut->tab[0][1],&haut->tab[1][2]);
  permuteCellule(&haut->tab[0][1],&haut->tab[1][0]);
  permuteCellule(&haut->tab[0][0],&haut->tab[2][2]);
  permuteCellule(&haut->tab[1][0],&haut->tab[2][1]);
  permuteCellule(&haut->tab[0][0],&haut->tab[2][0]);
}

void rotationLigneBasVersDroite(Face *rubikube[])
{
  // Face AVANT -> Face DROITE
  Face *droite = getFace(DROITE,rubikube);
  Face *avant = getFace(DEVANT,rubikube);
  permuteCellule(&droite->tab[2][0],&avant->tab[2][0]);
  permuteCellule(&droite->tab[2][1],&avant->tab[2][1]);
  permuteCellule(&droite->tab[2][2],&avant->tab[2][2]);
  // Face DROITE -> Face ARRIERE
  Face *derriere = getFace(DERRIERE,rubikube);
  permuteCellule(&avant->tab[2][0],&derriere->tab[2][0]);
  permuteCellule(&avant->tab[2][1],&derriere->tab[2][1]);
  permuteCellule(&avant->tab[2][2],&derriere->tab[2][2]);
  // Face ARRIERE -> Face GAUCHE
  Face *gauche = getFace(GAUCHE,rubikube);
  permuteCellule(&avant->tab[2][0],&gauche->tab[2][0]);
  permuteCellule(&avant->tab[2][1],&gauche->tab[2][1]);
  permuteCellule(&avant->tab[2][2],&gauche->tab[2][2]);
  // Modification de la face HAUT
  Face *bas = getFace(BAS,rubikube);
  permuteCellule(&bas->tab[0][0],&bas->tab[2][0]);
  permuteCellule(&bas->tab[1][0],&bas->tab[0][1]);
  permuteCellule(&bas->tab[0][0],&bas->tab[0][2]);
  permuteCellule(&bas->tab[0][1],&bas->tab[2][1]);
  permuteCellule(&bas->tab[0][1],&bas->tab[1][2]);
  permuteCellule(&bas->tab[0][2],&bas->tab[2][2]);
}

void rotationLigneBasVersGauche(Face *rubikube[])
{
  // Face AVANT -> Face GAUCHE
  Face *gauche = getFace(GAUCHE,rubikube);
  Face *avant = getFace(DEVANT,rubikube);
  permuteCellule(&gauche->tab[2][0],&avant->tab[2][0]);
  permuteCellule(&gauche->tab[2][1],&avant->tab[2][1]);
  permuteCellule(&gauche->tab[2][2],&avant->tab[2][2]);
  // Face DROITE -> Face ARRIERE
  Face *derriere = getFace(DERRIERE,rubikube);
  permuteCellule(&avant->tab[2][0],&derriere->tab[2][0]);
  permuteCellule(&avant->tab[2][1],&derriere->tab[2][1]);
  permuteCellule(&avant->tab[2][2],&derriere->tab[2][2]);
  // Face ARRIERE -> Face DROITE
  Face *droite = getFace(DROITE,rubikube);
  permuteCellule(&avant->tab[2][0],&droite->tab[2][0]);
  permuteCellule(&avant->tab[2][1],&droite->tab[2][1]);
  permuteCellule(&avant->tab[2][2],&droite->tab[2][2]);
  // Modification de la face Bas
  Face *bas = getFace(BAS,rubikube);
  permuteCellule(&bas->tab[0][0],&bas->tab[0][2]);
  permuteCellule(&bas->tab[0][1],&bas->tab[1][2]);
  permuteCellule(&bas->tab[0][1],&bas->tab[1][0]);
  permuteCellule(&bas->tab[0][0],&bas->tab[2][2]);
  permuteCellule(&bas->tab[1][0],&bas->tab[2][1]);
  permuteCellule(&bas->tab[0][0],&bas->tab[2][0]);
}

void rotationColonneGaucheVersHaut(Face *rubikube[])
{
    // Face AVANT -> Face HAUT
    Face *haut = getFace(HAUT,rubikube);
    Face *avant = getFace(DEVANT,rubikube);
    permuteCellule(&avant->tab[0][0],&haut->tab[0][0]);
    permuteCellule(&avant->tab[1][0],&haut->tab[1][0]);
    permuteCellule(&avant->tab[2][0],&haut->tab[2][0]);
    // Face HAUT -> Face DERRIERE
    Face *derriere = getFace(DERRIERE,rubikube);
    permuteCellule(&avant->tab[0][0],&derriere->tab[0][0]);
    permuteCellule(&avant->tab[1][0],&derriere->tab[1][0]);
    permuteCellule(&avant->tab[2][0],&derriere->tab[2][0]);
    // Face DERRIERE -> Face BAS
    Face *bas = getFace(BAS,rubikube);
    permuteCellule(&avant->tab[0][0],&bas->tab[0][0]);
    permuteCellule(&avant->tab[1][0],&bas->tab[1][0]);
    permuteCellule(&avant->tab[2][0],&bas->tab[2][0]);
    // Rotation face GAUCHE
    Face *gauche = getFace(GAUCHE,rubikube);
    permuteCellule(&gauche->tab[0][0],&gauche->tab[2][0]);
    permuteCellule(&gauche->tab[1][0],&gauche->tab[0][1]);
    permuteCellule(&gauche->tab[0][0],&gauche->tab[0][2]);
    permuteCellule(&gauche->tab[0][1],&gauche->tab[2][1]);
    permuteCellule(&gauche->tab[0][1],&gauche->tab[1][2]);
    permuteCellule(&gauche->tab[0][2],&gauche->tab[2][2]);
}

void rotationColonneGaucheVersBas(Face *rubikube[])
{
    // Face AVANT -> Face BAS
    Face *bas = getFace(BAS,rubikube);
    Face *avant = getFace(DEVANT,rubikube);
    permuteCellule(&avant->tab[0][0],&bas->tab[0][0]);
    permuteCellule(&avant->tab[1][0],&bas->tab[1][0]);
    permuteCellule(&avant->tab[2][0],&bas->tab[2][0]);
    // Face HAUT -> Face DERRIERE
    Face *derriere = getFace(DERRIERE,rubikube);
    permuteCellule(&avant->tab[0][0],&derriere->tab[0][0]);
    permuteCellule(&avant->tab[1][0],&derriere->tab[1][0]);
    permuteCellule(&avant->tab[2][0],&derriere->tab[2][0]);
    // Face DERRIERE -> Face BAS
    Face *haut = getFace(HAUT,rubikube);
    permuteCellule(&avant->tab[0][0],&haut->tab[0][0]);
    permuteCellule(&avant->tab[1][0],&haut->tab[1][0]);
    permuteCellule(&avant->tab[2][0],&haut->tab[2][0]);
    // Rotation face GAUCHE
    Face *gauche = getFace(GAUCHE,rubikube);
    permuteCellule(&gauche->tab[0][0],&gauche->tab[0][2]);
    permuteCellule(&gauche->tab[0][1],&gauche->tab[1][2]);
    permuteCellule(&gauche->tab[0][1],&gauche->tab[1][0]);
    permuteCellule(&gauche->tab[0][0],&gauche->tab[2][2]);
    permuteCellule(&gauche->tab[1][0],&gauche->tab[2][1]);
    permuteCellule(&gauche->tab[0][0],&gauche->tab[2][0]);
}

void rotationColonneDroiteVersHaut(Face *rubikube[])
{
    // Face AVANT -> Face HAUT
    Face *haut = getFace(HAUT,rubikube);
    Face *avant = getFace(DEVANT,rubikube);
    permuteCellule(&avant->tab[0][2],&haut->tab[0][2]);
    permuteCellule(&avant->tab[1][2],&haut->tab[1][2]);
    permuteCellule(&avant->tab[2][2],&haut->tab[2][2]);
    // Face HAUT -> Face DERRIERE
    Face *derriere = getFace(DERRIERE,rubikube);
    permuteCellule(&avant->tab[0][2],&derriere->tab[0][2]);
    permuteCellule(&avant->tab[1][2],&derriere->tab[1][2]);
    permuteCellule(&avant->tab[2][2],&derriere->tab[2][2]);
    // Face DERRIERE -> Face BAS
    Face *bas = getFace(BAS,rubikube);
    permuteCellule(&avant->tab[0][2],&bas->tab[0][2]);
    permuteCellule(&avant->tab[1][2],&bas->tab[1][2]);
    permuteCellule(&avant->tab[2][2],&bas->tab[2][2]);
    // Rotation face GAUCHE
    Face *droite = getFace(DROITE,rubikube);
    permuteCellule(&droite->tab[0][0],&droite->tab[2][0]);
    permuteCellule(&droite->tab[1][0],&droite->tab[0][1]);
    permuteCellule(&droite->tab[0][0],&droite->tab[0][2]);
    permuteCellule(&droite->tab[0][1],&droite->tab[2][1]);
    permuteCellule(&droite->tab[0][1],&droite->tab[1][2]);
    permuteCellule(&droite->tab[0][2],&droite->tab[2][2]);
}

void rotationColonneDroiteVersBas(Face *rubikube[])
{
    // Face AVANT -> Face BAS
    Face *bas = getFace(BAS,rubikube);
    Face *avant = getFace(DEVANT,rubikube);
    permuteCellule(&avant->tab[0][2],&bas->tab[0][2]);
    permuteCellule(&avant->tab[1][2],&bas->tab[1][2]);
    permuteCellule(&avant->tab[2][2],&bas->tab[2][2]);
    // Face BAS -> Face DERRIERE
    Face *derriere = getFace(DERRIERE,rubikube);
    permuteCellule(&avant->tab[0][2],&derriere->tab[0][2]);
    permuteCellule(&avant->tab[1][2],&derriere->tab[1][2]);
    permuteCellule(&avant->tab[2][2],&derriere->tab[2][2]);
    // Face DERRIERE -> Face HAUT
    Face *haut = getFace(HAUT,rubikube);
    permuteCellule(&avant->tab[0][2],&haut->tab[0][2]);
    permuteCellule(&avant->tab[1][2],&haut->tab[1][2]);
    permuteCellule(&avant->tab[2][2],&haut->tab[2][2]);
    // Rotation face DROITE
    Face *droite = getFace(DROITE,rubikube);
    permuteCellule(&droite->tab[0][0],&droite->tab[0][2]);
    permuteCellule(&droite->tab[0][1],&droite->tab[1][2]);
    permuteCellule(&droite->tab[0][1],&droite->tab[1][0]);
    permuteCellule(&droite->tab[0][0],&droite->tab[2][2]);
    permuteCellule(&droite->tab[1][0],&droite->tab[2][1]);
    permuteCellule(&droite->tab[0][0],&droite->tab[2][0]);
}

void rotationFaceArriereVersDroite(Face *rubikube[])
{
    Face *haut = getFace(HAUT,rubikube);
    Face *droite = getFace(DROITE,rubikube);
    // Face HAUTE -> Face DROITE
    permuteCellule(&haut->tab[0][0],&droite->tab[0][2]);
    permuteCellule(&haut->tab[0][1],&droite->tab[1][2]);
    permuteCellule(&haut->tab[0][2],&droite->tab[2][2]);
    // Face DROITE -> Face BAS
    Face *bas = getFace(BAS,rubikube);
    permuteCellule(&haut->tab[0][0],&bas->tab[2][0]);
    permuteCellule(&haut->tab[0][1],&bas->tab[2][1]);
    permuteCellule(&haut->tab[0][2],&bas->tab[2][2]);
    // Face BAS -> Face GAUCHE
    Face *gauche = getFace(GAUCHE,rubikube);
    permuteCellule(&haut->tab[0][0],&gauche->tab[0][0]);
    permuteCellule(&haut->tab[0][1],&gauche->tab[1][0]);
    permuteCellule(&haut->tab[0][2],&gauche->tab[2][0]);
    // Rotation Face Arriere
    Face *derriere = getFace(DERRIERE,rubikube);
    permuteCellule(&derriere->tab[0][0],&derriere->tab[2][0]);
    permuteCellule(&derriere->tab[1][0],&derriere->tab[0][1]);
    permuteCellule(&derriere->tab[0][0],&derriere->tab[0][2]);
    permuteCellule(&derriere->tab[0][1],&derriere->tab[2][1]);
    permuteCellule(&derriere->tab[0][1],&derriere->tab[1][2]);
    permuteCellule(&derriere->tab[0][2],&derriere->tab[2][2]);
}

void rotationFaceArriereVersGauche(Face *rubikube[])
{
    Face *haut = getFace(HAUT,rubikube);
    Face *gauche = getFace(GAUCHE,rubikube);
    // Face HAUTE -> Face GAUCHE
    permuteCellule(&haut->tab[0][0],&gauche->tab[0][0]);
    permuteCellule(&haut->tab[0][1],&gauche->tab[1][0]);
    permuteCellule(&haut->tab[0][2],&gauche->tab[2][0]);
    // Face GAUCHE -> Face BAS
    Face *bas = getFace(BAS,rubikube);
    permuteCellule(&haut->tab[0][0],&bas->tab[2][2]);
    permuteCellule(&haut->tab[0][1],&bas->tab[2][1]);
    permuteCellule(&haut->tab[0][2],&bas->tab[2][0]);
    // Face BAS -> Face DROITE
    Face *droite = getFace(DROITE,rubikube);
    permuteCellule(&haut->tab[0][0],&droite->tab[0][2]);
    permuteCellule(&haut->tab[0][1],&droite->tab[1][2]);
    permuteCellule(&haut->tab[0][2],&droite->tab[2][2]);
    // Rotation Face Arriere
    Face *derriere = getFace(DERRIERE,rubikube);
    permuteCellule(&derriere->tab[0][0],&derriere->tab[0][2]);
    permuteCellule(&derriere->tab[0][1],&derriere->tab[1][2]);
    permuteCellule(&derriere->tab[0][1],&derriere->tab[1][0]);
    permuteCellule(&derriere->tab[0][0],&derriere->tab[2][2]);
    permuteCellule(&derriere->tab[1][0],&derriere->tab[2][1]);
    permuteCellule(&derriere->tab[0][0],&derriere->tab[2][0]);
}

void rotationFaceAvantVersGauche(Face *rubikube[])
{
    Face *haut = getFace(HAUT,rubikube);
    Face *gauche = getFace(GAUCHE,rubikube);
    // Face HAUT -> Face GAUCHE
    permuteCellule(&haut->tab[2][0],&gauche->tab[2][2]);
    permuteCellule(&haut->tab[2][1],&gauche->tab[1][2]);
    permuteCellule(&haut->tab[2][2],&gauche->tab[0][2]);
    // Face GAUCHE -> Face BAS
    Face *bas = getFace(BAS,rubikube);
    permuteCellule(&haut->tab[2][0],&bas->tab[0][2]);
    permuteCellule(&haut->tab[2][1],&bas->tab[0][1]);
    permuteCellule(&haut->tab[2][2],&bas->tab[0][0]);
    // Face BAS -> Face DROITE
    Face *droite = getFace(DROITE,rubikube);
    permuteCellule(&haut->tab[2][0],&droite->tab[0][0]);
    permuteCellule(&haut->tab[2][1],&droite->tab[1][0]);
    permuteCellule(&haut->tab[2][2],&droite->tab[2][0]);
    // Rotation Face AVANT
    Face *avant = getFace(DEVANT,rubikube);
    permuteCellule(&avant->tab[0][0],&avant->tab[2][0]);
    permuteCellule(&avant->tab[1][0],&avant->tab[0][1]);
    permuteCellule(&avant->tab[0][0],&avant->tab[0][2]);
    permuteCellule(&avant->tab[0][1],&avant->tab[2][1]);
    permuteCellule(&avant->tab[0][1],&avant->tab[1][2]);
    permuteCellule(&avant->tab[0][2],&avant->tab[2][2]);


}

void rotationFaceAvantVersDroite(Face *rubikube[])
{
    Face *haut = getFace(HAUT,rubikube);
    Face *droite = getFace(DROITE,rubikube);
    // Face HAUT -> Face DROITE
    permuteCellule(&haut->tab[2][0],&droite->tab[0][0]);
    permuteCellule(&haut->tab[2][1],&droite->tab[1][0]);
    permuteCellule(&haut->tab[2][2],&droite->tab[2][0]);
    // Face DROITE -> Face BAS
    Face *bas = getFace(BAS,rubikube);
    permuteCellule(&haut->tab[2][0],&bas->tab[0][2]);
    permuteCellule(&haut->tab[2][1],&bas->tab[0][1]);
    permuteCellule(&haut->tab[2][2],&bas->tab[0][0]);
    // Face BAS -> Face GAUCHE
    Face *gauche = getFace(GAUCHE,rubikube);
    permuteCellule(&haut->tab[2][0],&gauche->tab[2][2]);
    permuteCellule(&haut->tab[2][1],&gauche->tab[1][2]);
    permuteCellule(&haut->tab[2][2],&gauche->tab[0][2]);
    // rotation face AVANT
    Face *avant = getFace(DEVANT,rubikube);
    permuteCellule(&avant->tab[0][0],&avant->tab[0][2]);
    permuteCellule(&avant->tab[0][1],&avant->tab[1][2]);
    permuteCellule(&avant->tab[0][1],&avant->tab[1][0]);
    permuteCellule(&avant->tab[0][0],&avant->tab[2][2]);
    permuteCellule(&avant->tab[1][0],&avant->tab[2][1]);
    permuteCellule(&avant->tab[0][0],&avant->tab[2][0]);

}

int main(int argc, char *argv[])
{
    Face *rubikube[NB_FACE];
    creerRubikube(rubikube);
    // printRubikube(rubikube);
    rotationFaceAvantVersDroite(rubikube);
    printTerminalRubikCube(rubikube);
    return 0;
}
