#define NB_FACE 6
#define TAILLE_MATRICE 3

enum Color { ROUGE,BLEU,JAUNE,VERT,BLANC,ORANGE};

enum Direction {DEVANT,DERRIERE,GAUCHE,DROITE,HAUT,BAS};

typedef struct face Face;

struct cel
{
    enum Color color;
    Face *face;
    int x,y;
}cellule;
typedef struct cel Cellule;

struct face
{
    enum Direction dir;
    Cellule **tab;
}face;
typedef struct face Face;

