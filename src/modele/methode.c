#include <stdio.h>
#include "struct.h"

Face *getFace(enum Direction dir,Face *rubikube)
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

void setFace(Face *face,enum Direction dir,Face *rubikube)
{
  for (int i = 0; i < 3;i++)
  {
    for (int j = 0; j < 3; j++)
    {
      face->tab[i][j].face = getFace(dir,rubikube);
    }
  }
}

void rotateLigneHaut(Face *rubikube)
{
  Face *avant = getFace(DEVANT,rubikube);
  Face *derrier = getFace(DERRIERE,rubikube);
  Face *gauhe = getFace(GAUCHE,rubikube);
  Face *droite = getFace(DROITE,rubikube);
  Face *haut = getFace(HAUT,rubikube);
  Face *bas = getFace(BAS,rubikube);


  // Face avant -> Face droite
  droite->tab[0][0] = avant->tab[0][0];
  droite->tab[0][1] = avant->tab[0][1];
  droite->tab[0][2] = avant->tab[0][2];
  setFace(droite,DROITE,rubikube);
}

int main(void)
{
  return 1;
}
