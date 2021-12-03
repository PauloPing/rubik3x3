#include <stdio.h>
#include "struct.h"
#include "methode.h"
#include <time.h>
#include <stdlib.h>


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

void D(Face *rubikube[])
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

void DPrime(Face *rubikube[])
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
  // permutation face arriere
  permuteCellule(&arriere->tab[0][0], &arriere->tab[2][2]);
  permuteCellule(&arriere->tab[0][1], &arriere->tab[2][1]);
  permuteCellule(&arriere->tab[0][2], &arriere->tab[2][0]);
  permuteCellule(&arriere->tab[1][0], &arriere->tab[1][2]);
  // permutation face haut
  permuteCellule(&haut->tab[0][0], &haut->tab[2][2]);
  permuteCellule(&haut->tab[0][1], &haut->tab[2][1]);
  permuteCellule(&haut->tab[0][2], &haut->tab[2][0]);
  permuteCellule(&haut->tab[1][0], &haut->tab[1][2]);
  
}

/* MELANGER */

void melangerRubikCube(Face *rubikube[])
{
    srand(time(NULL));
    int r, i = 0;
    for (i = 0; i < 1000; i++)
    {
        r = rand() % (NB_FUNCTION);
        void (*fun_ptr)(Face * rubikube[]) = mouvement[r];
        (*fun_ptr)(rubikube);
    }
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

/* CROIX BLANCHE */

void extremiteCroixBlanche(Face *rubikube[])
{
  Face *avant = getFace(DEVANT,rubikube);
  Face *haut = getFace(HAUT,rubikube);
  Face *bas = getFace(BAS,rubikube);
  while (haut->tab[2][1].color != BLANC)
  {
      if (avant->tab[0][1].color == BLANC)
      {
        FPrime(rubikube);
        U(rubikube);
        LPrime(rubikube);
        UPrime(rubikube);
      } else if (avant->tab[1][0].color == BLANC)
      {
        U(rubikube);
        LPrime(rubikube);
        UPrime(rubikube);
      } else if (avant->tab[1][2].color == BLANC)
      {
        UPrime(rubikube);
        R(rubikube);
        U(rubikube);
      } else if (avant->tab[2][1].color == BLANC)
      {
        F(rubikube);
        U(rubikube);
        LPrime(rubikube);
        UPrime(rubikube);
      } else if (bas->tab[0][1].color == BLANC)
      {
        F(rubikube);
        F(rubikube);
      }
      tournerRubikubeVersDroite(rubikube);
  }
}

int croixBlancheFaite(Face *rubikube[])
{
  Face *haut = getFace(HAUT,rubikube);
  if (haut->tab[1][1].color == BLANC && haut->tab[1][0].color == BLANC && haut->tab[1][2].color == BLANC && haut->tab[0][1].color == BLANC && haut->tab[2][1].color == BLANC)
  {
    return 1;
  }
  return 0;

}

void switchExtremiteCroixBlanche(Face *rubikube[],int val)
{
  Face *haut = getFace(HAUT,rubikube);
  if (haut->tab[2][1].val != val)
  {
    if (haut->tab[1][0].val == val)
    {
      L(rubikube);
      U(rubikube);
      LPrime(rubikube);
      UPrime(rubikube);
      E(rubikube);
      UPrime(rubikube);
      F(rubikube);
      U(rubikube);
    } else if (haut->tab[1][2].val == val)
    {
      RPrime(rubikube);
      UPrime(rubikube);
      R(rubikube);
      U(rubikube);
      EPrime(rubikube);
      U(rubikube);
      FPrime(rubikube);
      UPrime(rubikube);
    } else {
      BPrime(rubikube);
      EPrime(rubikube);
      UPrime(rubikube);
      R(rubikube);
      U(rubikube);
      U(rubikube);
      RPrime(rubikube);
      UPrime(rubikube);
    }
  }
}

void faireCroixBlanche(Face *rubikube[])
{
  milieuFace(rubikube);
  while (croixBlancheFaite(rubikube) == 0)
  {
    extremiteCroixBlanche(rubikube);
    UPrime(rubikube);
  }
  milieuFace(rubikube);
}

void mainCroixBlanche(Face *rubikube[])
{
  faireCroixBlanche(rubikube);
    switchExtremiteCroixBlanche(rubikube,7);
    tournerRubikubeVersDroite(rubikube);
    switchExtremiteCroixBlanche(rubikube,5);
    tournerRubikubeVersDroite(rubikube);
    switchExtremiteCroixBlanche(rubikube,1);
    tournerRubikubeVersDroite(rubikube);
    switchExtremiteCroixBlanche(rubikube,3);
    tournerRubikubeVersDroite(rubikube);
    milieuFace(rubikube);
}


/* ANGLE FACE BLANCHE */

int verifFaceBlanche(Face *rubikube[])
{
  Face *haut = getFace(HAUT,rubikube);
  for (int i = 0;i < 3; i++)
  {
    for (int j = 0; j < 3;j++)
    {
      if (haut->tab[i][j].color != BLANC)
      {
        return 0;
      }
    }
  }
  return 1;
}

void decalerAngleVersGauche(Face *rubikube[])
{
  L(rubikube);
  D(rubikube);
  LPrime(rubikube);
  RPrime(rubikube);
  DPrime(rubikube);
  R(rubikube);
}

void angleFaceBlanche(Face *rubikube[],int valeur)
{
  Face *avant = getFace(DEVANT,rubikube);
  Face *droite = getFace(DROITE,rubikube);
  Face *haut = getFace(HAUT,rubikube);
  Face *bas = getFace(BAS,rubikube);
  int index = 0;
  while (haut->tab[2][2].color != BLANC || haut->tab[2][2].val != valeur)
  {
    if (droite->tab[2][0].color == BLANC && droite->tab[2][0].val == valeur)
    {
      RPrime(rubikube);
      DPrime(rubikube);
      R(rubikube);
    } else if (avant->tab[2][2].color == BLANC && avant->tab[2][2].val == valeur)
    {
      F(rubikube);
      D(rubikube);
      FPrime(rubikube);
    } else if (bas->tab[0][2].color == BLANC && bas->tab[0][2].val == valeur)
    {
      F(rubikube);
      L(rubikube);
      D(rubikube);
      D(rubikube);
      LPrime(rubikube);
      FPrime(rubikube);
    } else if (droite->tab[0][0].color == BLANC && droite->tab[0][0].val == valeur)
    {
      LPrime(rubikube);
      MPrime(rubikube);
      FPrime(rubikube);
      L(rubikube);
      M(rubikube);
      D(rubikube);
      LPrime(rubikube);
      MPrime(rubikube);
      FPrime(rubikube);
      L(rubikube);
      M(rubikube);
    } else if (avant->tab[0][2].color == BLANC && avant->tab[0][2].val == valeur)
    {
      B(rubikube);
      SPrime(rubikube);
      R(rubikube);
      BPrime(rubikube);
      S(rubikube);
      DPrime(rubikube);
      F(rubikube);
      D(rubikube);
      FPrime(rubikube);
    }
    D(rubikube);
    index++;
    if (index == 4)
    {
      break;
    }
  }
}

void mainAngleFaceBlanche(Face *rubikube[])
{
  int i = 0;
  while (verifFaceBlanche(rubikube) != 1 && i < 10)
    {
        angleFaceBlanche(rubikube,8);
        tournerRubikubeVersDroite(rubikube);
        angleFaceBlanche(rubikube,2);
        tournerRubikubeVersDroite(rubikube);
        angleFaceBlanche(rubikube,0);
        tournerRubikubeVersDroite(rubikube);
        angleFaceBlanche(rubikube,6);
        tournerRubikubeVersDroite(rubikube);
        i++;
    }
    if (i == 10)
    {
      melangerRubikCube(rubikube);
      faireCroixBlanche(rubikube);
      mainAngleFaceBlanche(rubikube);
    }
}

/* DEUXIEME COUCHE */


int verifCoucheRouge(Face *rubikube[])
{
  Face *avant = getFace(DEVANT,rubikube);
  if (avant->tab[1][0].color == ROUGE && avant->tab[1][0].val == 5 && avant->tab[1][2].color == ROUGE && avant->tab[1][2].val == 3 )
  {
    printf("valeur 5 et 3 ok\n");
    return 1;
  }
  printf("pas ok rouge\n");
  return 0;
}

int verifCoucheBleu(Face *rubikube[])
{
  Face *gauche = getFace(GAUCHE,rubikube);
  if (gauche->tab[1][0].color == BLEU && gauche->tab[1][0].val == 5 && gauche->tab[1][2].color == BLEU && gauche->tab[1][2].val == 3 )
  {
    printf("valeur 5 et 3 ok\n");
    return 1;
  }
  printf("pas ok bleu\n");
  return 0;
}

int verifCoucheOrange(Face *rubikube[])
{
  Face *derriere = getFace(DERRIERE,rubikube);
  if (derriere->tab[1][0].color == ORANGE && derriere->tab[1][0].val == 5 && derriere->tab[1][2].color == ORANGE && derriere->tab[1][2].val == 3 )
  {
    printf("valeur 5 et 3 ok\n");
    return 1;
  }
  printf("pas ok orange\n");
  return 0;
}

int verifCoucheVerte(Face *rubikube[])
{
  Face *droite = getFace(DROITE,rubikube);
  if (droite->tab[1][0].color == VERT && droite->tab[1][0].val == 5 && droite->tab[1][2].color == VERT && droite->tab[1][2].val == 3 )
  {
    printf("valeur 5 et 3 ok\n");
    return 1;
  }
  printf("pas ok vert\n");
  return 0;
}

int verifDeuxiemeCouche(Face *rubikube[]) 
{
  Face *avant = getFace(DEVANT,rubikube);
  Face *gauche = getFace(GAUCHE,rubikube);
  Face *derriere = getFace(DERRIERE,rubikube);
  Face *droite = getFace(DROITE,rubikube);
  if (avant->tab[1][0].color == ROUGE && avant->tab[1][2].color == ROUGE)
  {
  } else {
    return 0;
  }
  if (gauche->tab[1][0].color == BLEU && gauche->tab[1][2].color == BLEU)
  {
  } else {
    return 0;
  }
  if (derriere->tab[1][0].color == ORANGE && derriere->tab[1][2].color == ORANGE)
  {
  } else {
    return 0;
  }
  if (droite->tab[1][0].color == VERT && droite->tab[1][2].color == VERT)
  {
  } else {
    return 0;
  }

  return 1;
}

void deuxiemeCoucheDroite(Face *rubikube[])
{
  U(rubikube);
  R(rubikube);
  UPrime(rubikube);
  RPrime(rubikube);
  UPrime(rubikube);
  FPrime(rubikube);
  U(rubikube);
  F(rubikube);
}

void deuxiemeCoucheGauche(Face *rubikube[])
{
  UPrime(rubikube);
  LPrime(rubikube);
  U(rubikube);
  L(rubikube);
  U(rubikube);
  F(rubikube);
  UPrime(rubikube);
  FPrime(rubikube);
}

void deuxiemeCouche(Face *rubikube[],enum Color color)
{
  Face *avant = getFace(DEVANT,rubikube);
  Face *droite = getFace(DROITE,rubikube);
  Face *gauche = getFace(GAUCHE,rubikube);
  int i;
  for (i = 0;i < 4;i++)
  {
    if (avant->tab[0][1].color == color)
    {
      if (avant->tab[0][1].val == 3)
      {
        deuxiemeCoucheDroite(rubikube);
      } else if (avant->tab[0][1].val == 5)
      {
        deuxiemeCoucheGauche(rubikube);
      } else if (droite->tab[1][0].color == color && droite->tab[1][0].val == 3)
      {
        deuxiemeCoucheDroite(rubikube);
        deuxiemeCoucheDroite(rubikube);
      } else if (gauche->tab[1][2].color == color && gauche->tab[1][2].val == 5)
      {
        deuxiemeCoucheGauche(rubikube);
        deuxiemeCoucheGauche(rubikube);
      }
    }
    U(rubikube);
  }
  
}

void mainDeuxiemeCouche(Face *rubikube[])
{
  Face *avant = getFace(DEVANT,rubikube);
  Face *droite = getFace(DROITE,rubikube);
  tournerRubikubeVersBas(rubikube);
  tournerRubikubeVersBas(rubikube);
  tournerRubikubeVersGauche(rubikube);
  tournerRubikubeVersGauche(rubikube);
  int i = 0;
  while (verifDeuxiemeCouche(rubikube) != 1 && i < 10)
    {
        deuxiemeCouche(rubikube,ROUGE);
        EPrime(rubikube);
        DPrime(rubikube);
        deuxiemeCouche(rubikube,VERT);
        EPrime(rubikube);
        DPrime(rubikube);
        deuxiemeCouche(rubikube,ORANGE);
        EPrime(rubikube);
        DPrime(rubikube);
        deuxiemeCouche(rubikube,BLEU);
        EPrime(rubikube);
        DPrime(rubikube);
        i++;
    }
  tournerRubikubeVersBas(rubikube);
  tournerRubikubeVersBas(rubikube);
  tournerRubikubeVersGauche(rubikube);
  tournerRubikubeVersGauche(rubikube);
  if (i == 10 || avant->tab[0][1].color != ROUGE || avant->tab[0][0].color != ROUGE || droite->tab[0][1].color != BLEU)
  {
    melangerRubikCube(rubikube);
    mainCroixBlanche(rubikube);
    mainAngleFaceBlanche(rubikube);
    mainDeuxiemeCouche(rubikube);
  } 
}


/* CROIX JAUNE */

int verifCroixJaune(Face *rubikube[])
{
  Face *haut = getFace(HAUT,rubikube);
  if (haut->tab[0][1].color == JAUNE && haut->tab[1][0].color == JAUNE && haut->tab[1][1].color == JAUNE && haut->tab[1][1].color == JAUNE && haut->tab[2][1].color == JAUNE)
  {
    return 1;
  }
  return 0;
}

void algoCroixJaune(Face *rubikube[])
{
  F(rubikube);
  R(rubikube);
  U(rubikube);
  RPrime(rubikube);
  UPrime(rubikube);
  FPrime(rubikube);
}

void faireCroixJaune(Face *rubikube[])
{
  Face *haut = getFace(HAUT,rubikube);
  Face *avant = getFace(DEVANT,rubikube);
  Face *droite = getFace(DROITE,rubikube);
  Face *gauche = getFace(GAUCHE,rubikube);
  Face *derriere = getFace(DERRIERE,rubikube);
  if (avant->tab[0][1].color == JAUNE && droite->tab[0][1].color == JAUNE && gauche->tab[0][1].color == JAUNE && derriere->tab[0][1].color == JAUNE)
  {
    algoCroixJaune(rubikube);
    tournerRubikubeVersDroite(rubikube);
    tournerRubikubeVersDroite(rubikube);
    algoCroixJaune(rubikube);
    tournerRubikubeVersDroite(rubikube);
    tournerRubikubeVersDroite(rubikube);
    algoCroixJaune(rubikube);
  } else if (avant->tab[0][1].color == JAUNE && droite->tab[0][1].color == JAUNE && haut->tab[0][1].color == JAUNE && haut->tab[1][0].color == JAUNE)
  {
    F(rubikube);
    U(rubikube);
    R(rubikube);
    UPrime(rubikube);
    RPrime(rubikube);
    FPrime(rubikube);
  }
}

void mainCroixJaune(Face *rubikube[])
{
  tournerRubikubeVersBas(rubikube);
  tournerRubikubeVersBas(rubikube);
  tournerRubikubeVersGauche(rubikube);
  tournerRubikubeVersGauche(rubikube);
  int i = 0;
  while (verifCroixJaune(rubikube) == 0 && i < 10)
  {
    for (int i = 0; i < 4;i++)
    {
      for (int j = 0; j < 4;j++)
      {
        faireCroixJaune(rubikube);
        U(rubikube);
      }
      tournerRubikubeVersDroite(rubikube);
    }
    i++; 
  }
  if (i == 10)
  {
    melangerRubikCube(rubikube);
    mainCroixBlanche(rubikube);
    mainAngleFaceBlanche(rubikube);
    mainDeuxiemeCouche(rubikube);
    mainCroixJaune(rubikube);
  }
}


/* SWITCH EXTREMITE CROIX JAUNE */

int verifExtremiteCroixJaune(Face *rubikube[])
{
  Face *haut = getFace(HAUT,rubikube);
  if (haut->tab[0][1].val == 7 && haut->tab[1][0].val == 5 && haut->tab[1][2].val == 3 && haut->tab[2][1].val == 1)
  {
    return 1;
  }
  return 0;
}

void faireExtremiteCroixJaune(Face *rubikube[],enum Color color)
{
  Face *gauche = getFace(GAUCHE,rubikube);
  Face *derriere = getFace(DERRIERE,rubikube);
  if (gauche->tab[0][1].color == color)
  {
    R(rubikube);
    U(rubikube);
    RPrime(rubikube);
    U(rubikube);
    R(rubikube);
    U(rubikube);
    U(rubikube);
    RPrime(rubikube);
    U(rubikube);
  } else if (derriere->tab[0][1].color == color)
  {
    U(rubikube);

    R(rubikube);
    U(rubikube);
    RPrime(rubikube);
    U(rubikube);
    R(rubikube);
    U(rubikube);
    U(rubikube);
    RPrime(rubikube);
    U(rubikube);

    tournerRubikubeVersDroite(rubikube);
    tournerRubikubeVersDroite(rubikube);
    R(rubikube);
    U(rubikube);
    RPrime(rubikube);
    U(rubikube);
    R(rubikube);
    U(rubikube);
    U(rubikube);
    RPrime(rubikube);
    U(rubikube);
    tournerRubikubeVersDroite(rubikube);
    tournerRubikubeVersDroite(rubikube);
  }
}

void mainExtremiteCroixJaune(Face *rubikube[])
{
  int i = 0;
  while (verifExtremiteCroixJaune(rubikube) == 0 && i < 10)
  {
    faireExtremiteCroixJaune(rubikube,ROUGE);
    tournerRubikubeVersDroite(rubikube);
    faireExtremiteCroixJaune(rubikube,VERT);
    tournerRubikubeVersDroite(rubikube);
    faireExtremiteCroixJaune(rubikube,ORANGE);
    tournerRubikubeVersDroite(rubikube);
    faireExtremiteCroixJaune(rubikube,BLEU);
    tournerRubikubeVersDroite(rubikube);
    i++;
  }
  if (i == 10)
  {
    melangerRubikCube(rubikube);
    mainCroixBlanche(rubikube);
    mainAngleFaceBlanche(rubikube);
    mainDeuxiemeCouche(rubikube);
    mainCroixJaune(rubikube);
    mainExtremiteCroixJaune(rubikube);

  }
}

/* FAIRE ANGLES JAUNE */

int verifAngleJaune(Face *rubikube[])
{
  Face *avant = getFace(DEVANT,rubikube);
  Face *droite = getFace(DROITE,rubikube);
  Face *gauche = getFace(GAUCHE,rubikube);
  Face *derriere = getFace(DERRIERE,rubikube);
  Face *haut = getFace(HAUT,rubikube);
  if ((haut->tab[2][2].color == JAUNE && haut->tab[2][2].val == 0) || (avant->tab[0][2].color == JAUNE && avant->tab[0][2].val == 0) || (droite->tab[0][0].color == JAUNE && droite->tab[0][0].val == 0))
  {
    if ((haut->tab[2][0].color == JAUNE && haut->tab[2][0].val == 2) || (avant->tab[0][0].color == JAUNE && avant->tab[0][0].val == 0) || (gauche->tab[0][2].color == JAUNE && gauche->tab[0][2].val == 0))
    {
      if ((haut->tab[0][0].color == JAUNE && haut->tab[0][0].val == 8) || (derriere->tab[0][2].color == JAUNE && derriere->tab[0][2].val == 8) || (gauche->tab[0][0].color == JAUNE && gauche->tab[0][0].val == 8))
      {
        if ((haut->tab[0][2].color == JAUNE && haut->tab[0][2].val == 6) || (derriere->tab[0][0].color == JAUNE && derriere->tab[0][0].val == 6) || (droite->tab[0][2].color == JAUNE && droite->tab[0][2].val == 6))
        {
          return 1;
        }
      }
    }
  }
  return 0;
}

void algoAngleJaune(Face *rubikube[])
{
  U(rubikube);
  R(rubikube);
  UPrime(rubikube);
  LPrime(rubikube);
  U(rubikube);
  RPrime(rubikube);
  UPrime(rubikube);
  L(rubikube);
}

void faireAngleJaune(Face *rubikube[])
{
  Face *avant = getFace(DEVANT,rubikube);
  Face *droite = getFace(DROITE,rubikube);
  Face *gauche = getFace(GAUCHE,rubikube);
  Face *derriere = getFace(DERRIERE,rubikube);
  Face *haut = getFace(HAUT,rubikube);
  if ((haut->tab[2][2].color == JAUNE && haut->tab[2][2].val == 0) || (avant->tab[0][2].color == JAUNE && avant->tab[0][2].val == 0) || (droite->tab[0][0].color == JAUNE && droite->tab[0][0].val == 0))
  {
    algoAngleJaune(rubikube);
  } else if ((haut->tab[2][0].color == JAUNE && haut->tab[2][0].val == 2) || (avant->tab[0][0].color == JAUNE && avant->tab[0][0].val == 0) || (gauche->tab[0][2].color == JAUNE && gauche->tab[0][2].val == 0))
  {
    tournerRubikubeVersDroite(rubikube);
    tournerRubikubeVersDroite(rubikube);
    tournerRubikubeVersDroite(rubikube);
    algoAngleJaune(rubikube);
  } else if ((haut->tab[0][0].color == JAUNE && haut->tab[0][0].val == 8) || (derriere->tab[0][2].color == JAUNE && derriere->tab[0][2].val == 8) || (gauche->tab[0][0].color == JAUNE && gauche->tab[0][0].val == 8))
  {
    tournerRubikubeVersDroite(rubikube);
    tournerRubikubeVersDroite(rubikube);
    algoAngleJaune(rubikube);
  } else if ((haut->tab[0][2].color == JAUNE && haut->tab[0][2].val == 6) || (derriere->tab[0][0].color == JAUNE && derriere->tab[0][0].val == 6) || (droite->tab[0][2].color == JAUNE && droite->tab[0][2].val == 6))
  {
    tournerRubikubeVersDroite(rubikube);
    algoAngleJaune(rubikube);
  }
  while (avant->tab[1][1].color != ROUGE)
  {
    tournerRubikubeVersDroite(rubikube);
  }
}


void mainAngleJaune(Face *rubikube[])
{
  int index = 0;
  while (verifAngleJaune(rubikube) == 0 && index < 10)
  {
    faireAngleJaune(rubikube);
    index++;
  }
  if (index == 10)
  {
    melangerRubikCube(rubikube);
    mainCroixBlanche(rubikube);
    mainAngleFaceBlanche(rubikube);
    mainDeuxiemeCouche(rubikube);
    mainCroixJaune(rubikube);
    mainExtremiteCroixJaune(rubikube);
    mainAngleJaune(rubikube);
  }
}


/* FIN DE LA FACE JAUNE */

int verifFaceJaune(Face *rubikube[])
{
  Face *haut = getFace(HAUT,rubikube);
  if (haut->tab[0][0].color == JAUNE && haut->tab[0][2].color == JAUNE && haut->tab[2][0].color == JAUNE && haut->tab[2][2].color == JAUNE)
  {
    return 1;
  }
  return 0;
}

void algoFaceJaune(Face *rubikube[])
{
  RPrime(rubikube);
  DPrime(rubikube);
  R(rubikube);
  D(rubikube);
}

void faireFaceJaune(Face *rubikube[])
{
  Face *gauche = getFace(GAUCHE,rubikube);
  Face *droite = getFace(DROITE,rubikube);
  Face *avant = getFace(DEVANT,rubikube);
  Face *derriere = getFace(DERRIERE,rubikube);
  if (droite->tab[0][0].color == JAUNE && gauche->tab[0][2].color == JAUNE)
  {
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    UPrime(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    U(rubikube);
  } else if (avant->tab[0][0].color == JAUNE && avant->tab[0][2].color == JAUNE)
  {
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    UPrime(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    U(rubikube);
  } else if (avant->tab[0][0].color == JAUNE && droite->tab[0][0].color == JAUNE && derriere->tab[0][0].color == JAUNE)
  {
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    U(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    U(rubikube);
    U(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    U(rubikube);
  } else if (gauche->tab[0][2].color == JAUNE && avant->tab[0][2].color == JAUNE && droite->tab[0][2].color == JAUNE)
  {
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    U(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    U(rubikube);
    U(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    U(rubikube);
  } else if (gauche->tab[0][2].color == JAUNE && derriere->tab[0][0].color == JAUNE)
  {
    U(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    U(rubikube);
    U(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    U(rubikube);
  } else if (avant->tab[0][0].color == JAUNE && avant->tab[0][2].color == JAUNE && droite->tab[0][2].color == JAUNE && gauche->tab[0][0].color == JAUNE)
  {
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    U(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    U(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    U(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    U(rubikube);
  } else if (droite->tab[0][0].color == JAUNE && derriere->tab[0][0].color == JAUNE && derriere->tab[0][2].color == JAUNE && gauche->tab[0][2].color == JAUNE)
  {
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    U(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    U(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    U(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    algoFaceJaune(rubikube);
    U(rubikube);
  }
}

void mainFaceJaune(Face *rubikube[])
{
  Face *avant = getFace(DEVANT,rubikube);
  while (verifFaceJaune(rubikube) == 0)
  {
    faireFaceJaune(rubikube);
    tournerRubikubeVersDroite(rubikube);
    faireFaceJaune(rubikube);
    tournerRubikubeVersDroite(rubikube);
    faireFaceJaune(rubikube);
    tournerRubikubeVersDroite(rubikube);
    faireFaceJaune(rubikube);
    tournerRubikubeVersDroite(rubikube);
  }
  tournerRubikubeVersBas(rubikube);
  tournerRubikubeVersBas(rubikube);
  while (avant->tab[1][1].color != ROUGE)
  {
    tournerRubikubeVersDroite(rubikube);
  }
}




 


  