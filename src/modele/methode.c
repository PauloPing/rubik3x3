#include <stdio.h>
#include "struct.h"

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

Face *getFace(enum Direction dir, Face *rubikube)
{
  switch (dir)
  {
  case HAUT:
    return &rubikube[0];
    break;
  case BAS:
    return &rubikube[5];
    break;
  case GAUCHE:
    return &rubikube[1];
    break;
  case DROITE:
    return &rubikube[3];
    break;
  case DEVANT:
    return &rubikube[2];
    break;
  case DERRIERE:
    return &rubikube[4];
    break;
  }
}

void setFace(Face *face, enum Direction dir, Face *rubikube)
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      face->tab[i][j].face = getFace(dir, rubikube);
    }
  }
}

void rotationLigneHaut(Face *rubikube)
{
  // Face AVANT -> Face DROITE
  Face *droite = getFace(DROITE,rubikube);
  Face *avant = getFace(DEVANT,rubikube);
  permuteCellule(&droite->tab[0][0],&avant->tab[0][0]);
  permuteCellule(&droite->tab[0][1],&avant->tab[0][1]);
  permuteCellule(&droite->tab[0][2],&avant->tab[0][2]);
}

int main(void)
{
  return 1;
}
