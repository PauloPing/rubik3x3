#include <stdio.h>
#include "struct.h"

void permuteCellule(Cellule *c1, Cellule *c2)
{
  Cellule *c3;
  c3 = c1;
  c1 = c2;
  c1->face = c3.face;
}

int main(void)
{
  return 1;
}
