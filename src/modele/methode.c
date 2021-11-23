#include <stdio.h>
#include "struct.h"
#include "methode.h"


void permuteCellule(Cellule *c1, Cellule *c2)
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




/* ENSEMBLE DES ROTATIONS POSSIBLES */

void UPrime(Face *rubikube[])
{
  // Face AVANT -> Face DROITE
  Face *droite = getFace(DROITE, rubikube);
  Face *avant = getFace(DEVANT, rubikube);
  permuteCellule(&droite->tab[0][0], &avant->tab[0][0]);
  permuteCellule(&droite->tab[0][1], &avant->tab[0][1]);
  permuteCellule(&droite->tab[0][2], &avant->tab[0][2]);
  // Face DROITE -> Face ARRIERE
  Face *derriere = getFace(DERRIERE, rubikube);
  permuteCellule(&avant->tab[0][0], &derriere->tab[0][0]);
  permuteCellule(&avant->tab[0][1], &derriere->tab[0][1]);
  permuteCellule(&avant->tab[0][2], &derriere->tab[0][2]);
  // Face ARRIERE -> Face GAUCHE
  Face *gauche = getFace(GAUCHE, rubikube);
  permuteCellule(&avant->tab[0][0], &gauche->tab[0][0]);
  permuteCellule(&avant->tab[0][1], &gauche->tab[0][1]);
  permuteCellule(&avant->tab[0][2], &gauche->tab[0][2]);
  // Modification de la face HAUT
  Face *haut = getFace(HAUT, rubikube);
  permuteCellule(&haut->tab[0][0], &haut->tab[2][0]);
  permuteCellule(&haut->tab[1][0], &haut->tab[0][1]);
  permuteCellule(&haut->tab[0][0], &haut->tab[0][2]);
  permuteCellule(&haut->tab[0][1], &haut->tab[2][1]);
  permuteCellule(&haut->tab[0][1], &haut->tab[1][2]);
  permuteCellule(&haut->tab[0][2], &haut->tab[2][2]);
}

void U(Face *rubikube[])
{
  // Face AVANT -> Face GAUCHE
  Face *gauche = getFace(GAUCHE, rubikube);
  Face *avant = getFace(DEVANT, rubikube);
  permuteCellule(&gauche->tab[0][0], &avant->tab[0][0]);
  permuteCellule(&gauche->tab[0][1], &avant->tab[0][1]);
  permuteCellule(&gauche->tab[0][2], &avant->tab[0][2]);
  // Face DROITE -> Face ARRIERE
  Face *derriere = getFace(DERRIERE, rubikube);
  permuteCellule(&avant->tab[0][0], &derriere->tab[0][0]);
  permuteCellule(&avant->tab[0][1], &derriere->tab[0][1]);
  permuteCellule(&avant->tab[0][2], &derriere->tab[0][2]);
  // Face ARRIERE -> Face DROITE
  Face *droite = getFace(DROITE, rubikube);
  permuteCellule(&avant->tab[0][0], &droite->tab[0][0]);
  permuteCellule(&avant->tab[0][1], &droite->tab[0][1]);
  permuteCellule(&avant->tab[0][2], &droite->tab[0][2]);
  // Modification de la face HAUT
  Face *haut = getFace(HAUT, rubikube);
  permuteCellule(&haut->tab[0][0], &haut->tab[0][2]);
  permuteCellule(&haut->tab[0][1], &haut->tab[1][2]);
  permuteCellule(&haut->tab[0][1], &haut->tab[1][0]);
  permuteCellule(&haut->tab[0][0], &haut->tab[2][2]);
  permuteCellule(&haut->tab[1][0], &haut->tab[2][1]);
  permuteCellule(&haut->tab[0][0], &haut->tab[2][0]);
}

void ré(Face *rubikube[])
{
  // Face AVANT -> Face DROITE
  Face *droite = getFace(DROITE, rubikube);
  Face *avant = getFace(DEVANT, rubikube);
  permuteCellule(&droite->tab[2][0], &avant->tab[2][0]);
  permuteCellule(&droite->tab[2][1], &avant->tab[2][1]);
  permuteCellule(&droite->tab[2][2], &avant->tab[2][2]);
  // Face DROITE -> Face ARRIERE
  Face *derriere = getFace(DERRIERE, rubikube);
  permuteCellule(&avant->tab[2][0], &derriere->tab[2][0]);
  permuteCellule(&avant->tab[2][1], &derriere->tab[2][1]);
  permuteCellule(&avant->tab[2][2], &derriere->tab[2][2]);
  // Face ARRIERE -> Face GAUCHE
  Face *gauche = getFace(GAUCHE, rubikube);
  permuteCellule(&avant->tab[2][0], &gauche->tab[2][0]);
  permuteCellule(&avant->tab[2][1], &gauche->tab[2][1]);
  permuteCellule(&avant->tab[2][2], &gauche->tab[2][2]);
  // Modification de la face HAUT
  Face *bas = getFace(BAS, rubikube);
  permuteCellule(&bas->tab[0][0], &bas->tab[0][2]);
  permuteCellule(&bas->tab[0][1], &bas->tab[1][2]);
  permuteCellule(&bas->tab[0][1], &bas->tab[1][0]);
  permuteCellule(&bas->tab[0][0], &bas->tab[2][2]);
  permuteCellule(&bas->tab[1][0], &bas->tab[2][1]);
  permuteCellule(&bas->tab[0][0], &bas->tab[2][0]);
}

void réPrime(Face *rubikube[])
{
  // Face AVANT -> Face GAUCHE
  Face *gauche = getFace(GAUCHE, rubikube);
  Face *avant = getFace(DEVANT, rubikube);
  permuteCellule(&gauche->tab[2][0], &avant->tab[2][0]);
  permuteCellule(&gauche->tab[2][1], &avant->tab[2][1]);
  permuteCellule(&gauche->tab[2][2], &avant->tab[2][2]);
  // Face DROITE -> Face ARRIERE
  Face *derriere = getFace(DERRIERE, rubikube);
  permuteCellule(&avant->tab[2][0], &derriere->tab[2][0]);
  permuteCellule(&avant->tab[2][1], &derriere->tab[2][1]);
  permuteCellule(&avant->tab[2][2], &derriere->tab[2][2]);
  // Face ARRIERE -> Face DROITE
  Face *droite = getFace(DROITE, rubikube);
  permuteCellule(&avant->tab[2][0], &droite->tab[2][0]);
  permuteCellule(&avant->tab[2][1], &droite->tab[2][1]);
  permuteCellule(&avant->tab[2][2], &droite->tab[2][2]);
  // Modification de la face Bas
  Face *bas = getFace(BAS, rubikube);
  permuteCellule(&bas->tab[0][0], &bas->tab[2][0]);
  permuteCellule(&bas->tab[1][0], &bas->tab[0][1]);
  permuteCellule(&bas->tab[0][0], &bas->tab[0][2]);
  permuteCellule(&bas->tab[0][1], &bas->tab[2][1]);
  permuteCellule(&bas->tab[0][1], &bas->tab[1][2]);
  permuteCellule(&bas->tab[0][2], &bas->tab[2][2]);
}

void LPrime(Face *rubikube[])
{
  // Face AVANT -> Face HAUT
  Face *haut = getFace(HAUT, rubikube);
  Face *avant = getFace(DEVANT, rubikube);
  permuteCellule(&avant->tab[0][0], &haut->tab[0][0]);
  permuteCellule(&avant->tab[1][0], &haut->tab[1][0]);
  permuteCellule(&avant->tab[2][0], &haut->tab[2][0]);
  // Face HAUT -> Face DERRIERE
  Face *derriere = getFace(DERRIERE, rubikube);
  permuteCellule(&avant->tab[0][0], &derriere->tab[2][2]);
  permuteCellule(&avant->tab[1][0], &derriere->tab[1][2]);
  permuteCellule(&avant->tab[2][0], &derriere->tab[0][2]);
  // Face DERRIERE -> Face BAS
  Face *bas = getFace(BAS, rubikube);
  permuteCellule(&avant->tab[0][0], &bas->tab[0][0]);
  permuteCellule(&avant->tab[1][0], &bas->tab[1][0]);
  permuteCellule(&avant->tab[2][0], &bas->tab[2][0]);
  // Rotation face GAUCHE
  Face *gauche = getFace(GAUCHE, rubikube);
  permuteCellule(&gauche->tab[0][0], &gauche->tab[2][0]);
  permuteCellule(&gauche->tab[1][0], &gauche->tab[0][1]);
  permuteCellule(&gauche->tab[0][0], &gauche->tab[0][2]);
  permuteCellule(&gauche->tab[0][1], &gauche->tab[2][1]);
  permuteCellule(&gauche->tab[0][1], &gauche->tab[1][2]);
  permuteCellule(&gauche->tab[0][2], &gauche->tab[2][2]);
}

void L(Face *rubikube[])
{
  // Face AVANT -> Face BAS
  Face *bas = getFace(BAS, rubikube);
  Face *avant = getFace(DEVANT, rubikube);
  permuteCellule(&avant->tab[0][0], &bas->tab[0][0]);
  permuteCellule(&avant->tab[1][0], &bas->tab[1][0]);
  permuteCellule(&avant->tab[2][0], &bas->tab[2][0]);
  // Face BAS -> Face DERRIERE
  Face *derriere = getFace(DERRIERE, rubikube);
  permuteCellule(&avant->tab[0][0], &derriere->tab[2][2]);
  permuteCellule(&avant->tab[1][0], &derriere->tab[1][2]);
  permuteCellule(&avant->tab[2][0], &derriere->tab[0][2]);
  // Face DERRIERE -> Face BAS
  Face *haut = getFace(HAUT, rubikube);
  permuteCellule(&avant->tab[0][0], &haut->tab[0][0]);
  permuteCellule(&avant->tab[1][0], &haut->tab[1][0]);
  permuteCellule(&avant->tab[2][0], &haut->tab[2][0]);
  // Rotation face GAUCHE
  Face *gauche = getFace(GAUCHE, rubikube);
  permuteCellule(&gauche->tab[0][0], &gauche->tab[0][2]);
  permuteCellule(&gauche->tab[0][1], &gauche->tab[1][2]);
  permuteCellule(&gauche->tab[0][1], &gauche->tab[1][0]);
  permuteCellule(&gauche->tab[0][0], &gauche->tab[2][2]);
  permuteCellule(&gauche->tab[1][0], &gauche->tab[2][1]);
  permuteCellule(&gauche->tab[0][0], &gauche->tab[2][0]);
}

void R(Face *rubikube[])
{
  // Face AVANT -> Face HAUT
  Face *haut = getFace(HAUT, rubikube);
  Face *avant = getFace(DEVANT, rubikube);
  permuteCellule(&avant->tab[0][2], &haut->tab[0][2]);
  permuteCellule(&avant->tab[1][2], &haut->tab[1][2]);
  permuteCellule(&avant->tab[2][2], &haut->tab[2][2]);
  // Face HAUT -> Face DERRIERE
  Face *derriere = getFace(DERRIERE, rubikube);
  permuteCellule(&avant->tab[0][2], &derriere->tab[2][0]);
  permuteCellule(&avant->tab[1][2], &derriere->tab[1][0]);
  permuteCellule(&avant->tab[2][2], &derriere->tab[0][0]);
  // Face DERRIERE -> Face BAS
  Face *bas = getFace(BAS, rubikube);
  permuteCellule(&avant->tab[0][2], &bas->tab[0][2]);
  permuteCellule(&avant->tab[1][2], &bas->tab[1][2]);
  permuteCellule(&avant->tab[2][2], &bas->tab[2][2]);
  // Rotation face DROITE
  Face *droite = getFace(DROITE, rubikube);
  permuteCellule(&droite->tab[0][0], &droite->tab[0][2]);
  permuteCellule(&droite->tab[0][1], &droite->tab[1][2]);
  permuteCellule(&droite->tab[0][1], &droite->tab[1][0]);
  permuteCellule(&droite->tab[0][0], &droite->tab[2][2]);
  permuteCellule(&droite->tab[1][0], &droite->tab[2][1]);
  permuteCellule(&droite->tab[0][0], &droite->tab[2][0]);
}

void RPrime(Face *rubikube[])
{
  // Face AVANT -> Face BAS
  Face *bas = getFace(BAS, rubikube);
  Face *avant = getFace(DEVANT, rubikube);
  permuteCellule(&avant->tab[0][2], &bas->tab[0][2]);
  permuteCellule(&avant->tab[1][2], &bas->tab[1][2]);
  permuteCellule(&avant->tab[2][2], &bas->tab[2][2]);
  // Face BAS -> Face DERRIERE
  Face *derriere = getFace(DERRIERE, rubikube);
  permuteCellule(&avant->tab[0][2], &derriere->tab[2][0]);
  permuteCellule(&avant->tab[1][2], &derriere->tab[1][0]);
  permuteCellule(&avant->tab[2][2], &derriere->tab[0][0]);
  // Face DERRIERE -> Face HAUT
  Face *haut = getFace(HAUT, rubikube);
  permuteCellule(&avant->tab[0][2], &haut->tab[0][2]);
  permuteCellule(&avant->tab[1][2], &haut->tab[1][2]);
  permuteCellule(&avant->tab[2][2], &haut->tab[2][2]);
  // Rotation face DROITE
  Face *droite = getFace(DROITE, rubikube);
  permuteCellule(&droite->tab[0][0], &droite->tab[2][0]);
  permuteCellule(&droite->tab[1][0], &droite->tab[0][1]);
  permuteCellule(&droite->tab[0][0], &droite->tab[0][2]);
  permuteCellule(&droite->tab[0][1], &droite->tab[2][1]);
  permuteCellule(&droite->tab[0][1], &droite->tab[1][2]);
  permuteCellule(&droite->tab[0][2], &droite->tab[2][2]);
}

void BPrime(Face *rubikube[])
{
  Face *haut = getFace(HAUT, rubikube);
  Face *droite = getFace(DROITE, rubikube);
  // Face HAUTE -> Face DROITE
  permuteCellule(&haut->tab[0][0], &droite->tab[0][2]);
  permuteCellule(&haut->tab[0][1], &droite->tab[1][2]);
  permuteCellule(&haut->tab[0][2], &droite->tab[2][2]);
  // Face DROITE -> Face BAS
  Face *bas = getFace(BAS, rubikube);
  permuteCellule(&haut->tab[0][0], &bas->tab[2][2]);
  permuteCellule(&haut->tab[0][1], &bas->tab[2][1]);
  permuteCellule(&haut->tab[0][2], &bas->tab[2][0]);
  // Face BAS -> Face GAUCHE
  Face *gauche = getFace(GAUCHE, rubikube);
  permuteCellule(&haut->tab[0][0], &gauche->tab[2][0]);
  permuteCellule(&haut->tab[0][1], &gauche->tab[1][0]);
  permuteCellule(&haut->tab[0][2], &gauche->tab[0][0]);
  // Rotation Face Arriere
  Face *derriere = getFace(DERRIERE, rubikube);
  permuteCellule(&derriere->tab[0][0], &derriere->tab[2][0]);
  permuteCellule(&derriere->tab[1][0], &derriere->tab[0][1]);
  permuteCellule(&derriere->tab[0][0], &derriere->tab[0][2]);
  permuteCellule(&derriere->tab[0][1], &derriere->tab[2][1]);
  permuteCellule(&derriere->tab[0][1], &derriere->tab[1][2]);
  permuteCellule(&derriere->tab[0][2], &derriere->tab[2][2]);
}

void B(Face *rubikube[])
{
  Face *haut = getFace(HAUT, rubikube);
  Face *gauche = getFace(GAUCHE, rubikube);
  // Face HAUTE -> Face GAUCHE
  permuteCellule(&haut->tab[0][0], &gauche->tab[2][0]);
  permuteCellule(&haut->tab[0][1], &gauche->tab[1][0]);
  permuteCellule(&haut->tab[0][2], &gauche->tab[0][0]);
  // Face GAUCHE -> Face BAS
  Face *bas = getFace(BAS, rubikube);
  permuteCellule(&haut->tab[0][0], &bas->tab[2][2]);
  permuteCellule(&haut->tab[0][1], &bas->tab[2][1]);
  permuteCellule(&haut->tab[0][2], &bas->tab[2][0]);
  // Face BAS -> Face DROITE
  Face *droite = getFace(DROITE, rubikube);
  permuteCellule(&haut->tab[0][0], &droite->tab[0][2]);
  permuteCellule(&haut->tab[0][1], &droite->tab[1][2]);
  permuteCellule(&haut->tab[0][2], &droite->tab[2][2]);
  // Rotation Face Arriere
  Face *derriere = getFace(DERRIERE, rubikube);
  permuteCellule(&derriere->tab[0][0], &derriere->tab[0][2]);
  permuteCellule(&derriere->tab[0][1], &derriere->tab[1][2]);
  permuteCellule(&derriere->tab[0][1], &derriere->tab[1][0]);
  permuteCellule(&derriere->tab[0][0], &derriere->tab[2][2]);
  permuteCellule(&derriere->tab[1][0], &derriere->tab[2][1]);
  permuteCellule(&derriere->tab[0][0], &derriere->tab[2][0]);
}

void FPrime(Face *rubikube[])
{
  Face *haut = getFace(HAUT, rubikube);
  Face *gauche = getFace(GAUCHE, rubikube);
  // Face HAUT -> Face GAUCHE
  permuteCellule(&haut->tab[2][0], &gauche->tab[2][2]);
  permuteCellule(&haut->tab[2][1], &gauche->tab[1][2]);
  permuteCellule(&haut->tab[2][2], &gauche->tab[0][2]);
  // Face GAUCHE -> Face BAS
  Face *bas = getFace(BAS, rubikube);
  permuteCellule(&haut->tab[2][0], &bas->tab[0][2]);
  permuteCellule(&haut->tab[2][1], &bas->tab[0][1]);
  permuteCellule(&haut->tab[2][2], &bas->tab[0][0]);
  // Face BAS -> Face DROITE
  Face *droite = getFace(DROITE, rubikube);
  permuteCellule(&haut->tab[2][0], &droite->tab[0][0]);
  permuteCellule(&haut->tab[2][1], &droite->tab[1][0]);
  permuteCellule(&haut->tab[2][2], &droite->tab[2][0]);
  // Rotation Face AVANT
  Face *avant = getFace(DEVANT, rubikube);
  permuteCellule(&avant->tab[0][0], &avant->tab[2][0]);
  permuteCellule(&avant->tab[1][0], &avant->tab[0][1]);
  permuteCellule(&avant->tab[0][0], &avant->tab[0][2]);
  permuteCellule(&avant->tab[0][1], &avant->tab[2][1]);
  permuteCellule(&avant->tab[0][1], &avant->tab[1][2]);
  permuteCellule(&avant->tab[0][2], &avant->tab[2][2]);
}

void F(Face *rubikube[])
{
  Face *haut = getFace(HAUT, rubikube);
  Face *droite = getFace(DROITE, rubikube);
  // Face HAUT -> Face DROITE
  permuteCellule(&haut->tab[2][0], &droite->tab[0][0]);
  permuteCellule(&haut->tab[2][1], &droite->tab[1][0]);
  permuteCellule(&haut->tab[2][2], &droite->tab[2][0]);
  // Face DROITE -> Face BAS
  Face *bas = getFace(BAS, rubikube);
  permuteCellule(&haut->tab[2][0], &bas->tab[0][2]);
  permuteCellule(&haut->tab[2][1], &bas->tab[0][1]);
  permuteCellule(&haut->tab[2][2], &bas->tab[0][0]);
  // Face BAS -> Face GAUCHE
  Face *gauche = getFace(GAUCHE, rubikube);
  permuteCellule(&haut->tab[2][0], &gauche->tab[2][2]);
  permuteCellule(&haut->tab[2][1], &gauche->tab[1][2]);
  permuteCellule(&haut->tab[2][2], &gauche->tab[0][2]);
  // rotation face AVANT
  Face *avant = getFace(DEVANT, rubikube);
  permuteCellule(&avant->tab[0][0], &avant->tab[0][2]);
  permuteCellule(&avant->tab[0][1], &avant->tab[1][2]);
  permuteCellule(&avant->tab[0][1], &avant->tab[1][0]);
  permuteCellule(&avant->tab[0][0], &avant->tab[2][2]);
  permuteCellule(&avant->tab[1][0], &avant->tab[2][1]);
  permuteCellule(&avant->tab[0][0], &avant->tab[2][0]);
}

void E(Face *rubikube[])
{
  Face *avant = getFace(DEVANT,rubikube);
  Face *droite = getFace(DROITE,rubikube);
  // Face AVANT -> Face DROITE
  permuteCellule(&avant->tab[1][0],&droite->tab[1][0]);
  permuteCellule(&avant->tab[1][1],&droite->tab[1][1]);
  permuteCellule(&avant->tab[1][2],&droite->tab[1][2]);
  // Face DROITE -> Face DERRIERE
  Face *derriere = getFace(DERRIERE,rubikube);
  permuteCellule(&avant->tab[1][0],&derriere->tab[1][0]);
  permuteCellule(&avant->tab[1][1],&derriere->tab[1][1]);
  permuteCellule(&avant->tab[1][2],&derriere->tab[1][2]);
  // Face DERRIERE -> Face GAUCHE
  Face *gauche = getFace(GAUCHE,rubikube);
  permuteCellule(&avant->tab[1][0],&gauche->tab[1][0]);
  permuteCellule(&avant->tab[1][1],&gauche->tab[1][1]);
  permuteCellule(&avant->tab[1][2],&gauche->tab[1][2]);
}

void EPrime(Face *rubikube[])
{
  Face *avant = getFace(DEVANT,rubikube);
  Face *gauche = getFace(GAUCHE,rubikube);
  // Face AVANT -> Face GAUCHE
  permuteCellule(&avant->tab[1][0],&gauche->tab[1][0]);
  permuteCellule(&avant->tab[1][1],&gauche->tab[1][1]);
  permuteCellule(&avant->tab[1][2],&gauche->tab[1][2]);
  // Face DROITE -> Face DERRIERE
  Face *derriere = getFace(DERRIERE,rubikube);
  permuteCellule(&avant->tab[1][0],&derriere->tab[1][0]);
  permuteCellule(&avant->tab[1][1],&derriere->tab[1][1]);
  permuteCellule(&avant->tab[1][2],&derriere->tab[1][2]);
  // Face DERRIERE -> Face DROITE
  Face *droite = getFace(DROITE,rubikube);
  permuteCellule(&avant->tab[1][0],&droite->tab[1][0]);
  permuteCellule(&avant->tab[1][1],&droite->tab[1][1]);
  permuteCellule(&avant->tab[1][2],&droite->tab[1][2]);
}

void MPrime(Face *rubikube[])
{
  Face *avant = getFace(DEVANT,rubikube);
  Face *haut = getFace(HAUT,rubikube);
  // Face AVANT -> Face HAUT
  permuteCellule(&avant->tab[0][1],&haut->tab[0][1]);
  permuteCellule(&avant->tab[1][1],&haut->tab[1][1]);
  permuteCellule(&avant->tab[2][1],&haut->tab[2][1]);
  // Face HAUT -> Face DERRIERE
  Face *derriere = getFace(DERRIERE,rubikube);
  permuteCellule(&avant->tab[0][1],&derriere->tab[2][1]);
  permuteCellule(&avant->tab[1][1],&derriere->tab[1][1]);
  permuteCellule(&avant->tab[2][1],&derriere->tab[0][1]);
  // Face DERRIERE -> Face BAS
  Face *bas = getFace(BAS,rubikube);
  permuteCellule(&avant->tab[0][1],&bas->tab[0][1]);
  permuteCellule(&avant->tab[1][1],&bas->tab[1][1]);
  permuteCellule(&avant->tab[2][1],&bas->tab[2][1]);
}

void M(Face *rubikube[])
{
  Face *avant = getFace(DEVANT,rubikube);
  Face *bas = getFace(BAS,rubikube);
  // Face AVANT -> Face BAS
  permuteCellule(&avant->tab[0][1],&bas->tab[0][1]);
  permuteCellule(&avant->tab[1][1],&bas->tab[1][1]);
  permuteCellule(&avant->tab[2][1],&bas->tab[2][1]);
  // Face BAS -> Face DERRIERE
  Face *derriere = getFace(DERRIERE,rubikube);
  permuteCellule(&avant->tab[0][1],&derriere->tab[2][1]);
  permuteCellule(&avant->tab[1][1],&derriere->tab[1][1]);
  permuteCellule(&avant->tab[2][1],&derriere->tab[0][1]);
  // Face DERRIERE -> Face BAS
  Face *haut = getFace(HAUT,rubikube);
  permuteCellule(&avant->tab[0][1],&haut->tab[0][1]);
  permuteCellule(&avant->tab[1][1],&haut->tab[1][1]);
  permuteCellule(&avant->tab[2][1],&haut->tab[2][1]);
}

void S(Face *rubikube[])
{
  Face *haut = getFace(HAUT,rubikube);
  Face *droite = getFace(DROITE,rubikube);
  // Face HAUT -> Face Droite
  permuteCellule(&haut->tab[1][0],&droite->tab[0][1]);
  permuteCellule(&haut->tab[1][1],&droite->tab[1][1]);
  permuteCellule(&haut->tab[1][2],&droite->tab[2][1]);
  // Face DROITE -> Face BAS
  Face *bas = getFace(BAS,rubikube);
  permuteCellule(&haut->tab[1][0],&bas->tab[1][2]);
  permuteCellule(&haut->tab[1][1],&bas->tab[1][1]);
  permuteCellule(&haut->tab[1][2],&bas->tab[1][0]);
  // Face BAS -> Face GAUCHE
  Face *gauche = getFace(GAUCHE,rubikube);
  permuteCellule(&haut->tab[1][0],&gauche->tab[2][1]);
  permuteCellule(&haut->tab[1][1],&gauche->tab[1][1]);
  permuteCellule(&haut->tab[1][2],&gauche->tab[0][1]);
}

void SPrime(Face *rubikube[])
{
  Face *haut = getFace(HAUT,rubikube);
  Face *gauche = getFace(GAUCHE,rubikube);
  // Face HAUT -> Face GAUCHE
  permuteCellule(&haut->tab[1][0],&gauche->tab[2][1]);
  permuteCellule(&haut->tab[1][1],&gauche->tab[1][1]);
  permuteCellule(&haut->tab[1][2],&gauche->tab[0][1]);
  // Face GAUCHE -> Face BAS
  Face *bas = getFace(BAS,rubikube);
  permuteCellule(&haut->tab[1][0],&bas->tab[1][2]);
  permuteCellule(&haut->tab[1][1],&bas->tab[1][1]);
  permuteCellule(&haut->tab[1][2],&bas->tab[1][0]);
  // Face BAS -> Face DROITE
  Face *droite = getFace(DROITE,rubikube);
  permuteCellule(&haut->tab[1][0],&droite->tab[0][1]);
  permuteCellule(&haut->tab[1][1],&droite->tab[1][1]);
  permuteCellule(&haut->tab[1][2],&droite->tab[2][1]);
}



/* ROTATION DE RUBIKUBE */
void switchFace(Face *f1,Face *f2)
{
  Face tmp;
  tmp.tab = f1->tab;
  f1->tab = f2->tab;
  f2->tab = tmp.tab;
}

/* ON TOURNE LE RUBIKUBE */



// VERS LA GAUCHE
void tournerRubikubeVersGauche(Face *rubikube[])
{
  // on recupere toutes les faces
  Face *avant = getFace(DEVANT,rubikube);
  Face *arriere = getFace(DERRIERE,rubikube);
  Face *gauche = getFace(GAUCHE,rubikube);
  Face *droite = getFace(DROITE,rubikube);
  Face *haut = getFace(HAUT,rubikube);
  Face *bas = getFace(BAS,rubikube);

  switchFace(avant,droite);
  switchFace(avant,arriere);
  switchFace(avant,gauche);

  // rotation face haut
  permuteCellule(&haut->tab[0][0], &haut->tab[2][0]);
  permuteCellule(&haut->tab[1][0], &haut->tab[0][1]);
  permuteCellule(&haut->tab[0][0], &haut->tab[0][2]);
  permuteCellule(&haut->tab[0][1], &haut->tab[2][1]);
  permuteCellule(&haut->tab[0][1], &haut->tab[1][2]);
  permuteCellule(&haut->tab[0][2], &haut->tab[2][2]);
  // rotation face bas
  permuteCellule(&bas->tab[0][0], &bas->tab[0][2]);
  permuteCellule(&bas->tab[0][1], &bas->tab[1][2]);
  permuteCellule(&bas->tab[0][1], &bas->tab[1][0]);
  permuteCellule(&bas->tab[0][0], &bas->tab[2][2]);
  permuteCellule(&bas->tab[1][0], &bas->tab[2][1]);
  permuteCellule(&bas->tab[0][0], &bas->tab[2][0]);
}

// VERS LA DROITE
void tournerRubikubeVersDroite(Face *rubikube[])
{
  // on recupere toutes les faces
  Face *avant = getFace(DEVANT,rubikube);
  Face *arriere = getFace(DERRIERE,rubikube);
  Face *gauche = getFace(GAUCHE,rubikube);
  Face *droite = getFace(DROITE,rubikube);
  Face *haut = getFace(HAUT,rubikube);
  Face *bas = getFace(BAS,rubikube);

  switchFace(avant,gauche);
  switchFace(avant,arriere);
  switchFace(avant,droite);

  // rotation face haut
  permuteCellule(&bas->tab[0][0], &bas->tab[2][0]);
  permuteCellule(&bas->tab[1][0], &bas->tab[0][1]);
  permuteCellule(&bas->tab[0][0], &bas->tab[0][2]);
  permuteCellule(&bas->tab[0][1], &bas->tab[2][1]);
  permuteCellule(&bas->tab[0][1], &bas->tab[1][2]);
  permuteCellule(&bas->tab[0][2], &bas->tab[2][2]);
  // rotation face bas
  permuteCellule(&haut->tab[0][0], &haut->tab[0][2]);
  permuteCellule(&haut->tab[0][1], &haut->tab[1][2]);
  permuteCellule(&haut->tab[0][1], &haut->tab[1][0]);
  permuteCellule(&haut->tab[0][0], &haut->tab[2][2]);
  permuteCellule(&haut->tab[1][0], &haut->tab[2][1]);
  permuteCellule(&haut->tab[0][0], &haut->tab[2][0]);
}

// VERS LE HAUT
void tournerRubikubeVersHaut(Face *rubikube[])
{
  // on recupere toutes les faces
  Face *avant = getFace(DEVANT,rubikube);
  Face *arriere = getFace(DERRIERE,rubikube);
  Face *gauche = getFace(GAUCHE,rubikube);
  Face *droite = getFace(DROITE,rubikube);
  Face *haut = getFace(HAUT,rubikube);
  Face *bas = getFace(BAS,rubikube);

  switchFace(avant,bas);
  switchFace(avant,arriere);
  switchFace(avant,haut);

  // rotation face gauche
  permuteCellule(&gauche->tab[0][0], &gauche->tab[0][2]);
  permuteCellule(&gauche->tab[0][1], &gauche->tab[1][2]);
  permuteCellule(&gauche->tab[0][1], &gauche->tab[1][0]);
  permuteCellule(&gauche->tab[0][0], &gauche->tab[2][2]);
  permuteCellule(&gauche->tab[1][0], &gauche->tab[2][1]);
  permuteCellule(&gauche->tab[0][0], &gauche->tab[2][0]);
  // rotation face droite
  permuteCellule(&droite->tab[0][0], &droite->tab[2][0]);
  permuteCellule(&droite->tab[1][0], &droite->tab[0][1]);
  permuteCellule(&droite->tab[0][0], &droite->tab[0][2]);
  permuteCellule(&droite->tab[0][1], &droite->tab[2][1]);
  permuteCellule(&droite->tab[0][1], &droite->tab[1][2]);
  permuteCellule(&droite->tab[0][2], &droite->tab[2][2]);
}

// VERS LE BAS
void tournerRubikubeVersBas(Face *rubikube[])
{
  // on recupere toutes les faces
  Face *avant = getFace(DEVANT,rubikube);
  Face *arriere = getFace(DERRIERE,rubikube);
  Face *gauche = getFace(GAUCHE,rubikube);
  Face *droite = getFace(DROITE,rubikube);
  Face *haut = getFace(HAUT,rubikube);
  Face *bas = getFace(BAS,rubikube);

  switchFace(avant,haut);
  switchFace(avant,arriere);
  switchFace(avant,bas);

  // rotation face gauche
  permuteCellule(&droite->tab[0][0], &droite->tab[0][2]);
  permuteCellule(&droite->tab[0][1], &droite->tab[1][2]);
  permuteCellule(&droite->tab[0][1], &droite->tab[1][0]);
  permuteCellule(&droite->tab[0][0], &droite->tab[2][2]);
  permuteCellule(&droite->tab[1][0], &droite->tab[2][1]);
  permuteCellule(&droite->tab[0][0], &droite->tab[2][0]);
  // rotation face droite
  permuteCellule(&gauche->tab[0][0], &gauche->tab[2][0]);
  permuteCellule(&gauche->tab[1][0], &gauche->tab[0][1]);
  permuteCellule(&gauche->tab[0][0], &gauche->tab[0][2]);
  permuteCellule(&gauche->tab[0][1], &gauche->tab[2][1]);
  permuteCellule(&gauche->tab[0][1], &gauche->tab[1][2]);
  permuteCellule(&gauche->tab[0][2], &gauche->tab[2][2]);
}


/* FAIRE LA CROIX BLANCHE */

int estSurFace(Face *face,int val,enum Color color)
{
  for (int i = 0; i < 3;i++)
  {
    for (int j = 0;j < 3;j++)
    {
      if (face->tab[i][j].color == color && face->tab[i][j].val == val)
      {
        return 1;
      }
    }
  }
  return 0;
}

void milieuFace(Face *rubikube[])
{
  Face *avant = getFace(DEVANT,rubikube);
  Face *haut = getFace(HAUT,rubikube);
  int index = 0;
  while (haut->tab[1][1].color != BLANC && index < 3)
  {
    MPrime(rubikube);
    index++;
  }
  if (haut->tab[1][1].color != BLANC)
  {
    index = 0;
    while (haut->tab[1][1].color != BLANC && index < 3)
    {
      S(rubikube);
      index++;
    }
  }
  while (avant->tab[1][1].color != ROUGE)
  {
    E(rubikube);
  }
}

void extremiteCroixBlanche(Face *rubikube[])
{
  Face *avant = getFace(DEVANT,rubikube);
  Face *haut = getFace(HAUT,rubikube);
  Face *arriere = getFace(DERRIERE,rubikube);
  Face *bas = getFace(BAS,rubikube);
  // On place le blanc 7;
  while (haut->tab[2][1].color != BLANC && haut->tab[2][1].val != 1)
  {
    if (avant->tab[2][1].color == BLANC && avant->tab[2][1].val == 7)
    {
      FPrime(rubikube);
      UPrime(rubikube);
      R(rubikube);
      U(rubikube);
    } else if (avant->tab[1][0].color == BLANC && avant->tab[1][0].val == 7)
    {
      U(rubikube);
      LPrime(rubikube);
      UPrime(rubikube);
    } else if (avant->tab[1][2].color == BLANC && avant->tab[1][2].val == 7)
    {
      UPrime(rubikube);
      R(rubikube);
      U(rubikube);
    } else if (bas->tab[0][1].color == BLANC && bas->tab[0][1].val == 7)
    {
      U(rubikube);
      U(rubikube);
    }
    B(rubikube);
    R(rubikube);
    L(rubikube);
  }
}

int isValideCroixBlanche(Face *rubikube[])
{
  Face *haut = getFace(HAUT,rubikube);
  Face *avant = getFace(DEVANT,rubikube);
  Face *gauche = getFace(GAUCHE,rubikube);
  Face *droite = getFace(DROITE,rubikube);
  Face *arriere = getFace(DERRIERE,rubikube);
  if (haut->tab[1][1].color == BLANC && haut->tab[1][0].color == BLANC && haut->tab[1][2].color == BLANC && haut->tab[0][1].color == BLANC && haut->tab[2][1].color == BLANC)
  {
    if ((avant->tab[0][1].color == ROUGE && avant->tab[1][1].color == ROUGE) && (gauche->tab[0][1].color == VERT && gauche->tab[1][1].color == VERT) && (droite->tab[0][1].color == BLEU && droite->tab[1][1].color == BLEU) && (arriere->tab[0][1].color == ORANGE && arriere->tab[1][1].color == ORANGE))
    {
      return 1;
    }
  }
  return 0;
}

