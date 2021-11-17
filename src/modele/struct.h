#define NB_FACE 6
#define TAILLE_MATRICE 3

enum Color
{
    BLANC,
    VERT,
    ROUGE,
    BLEU,
    ORANGE,
    JAUNE,
};

enum Direction
{   HAUT,
    GAUCHE,
    DEVANT,
    DROITE,
    DERRIERE,
    BAS,
};

typedef struct face Face;

struct cel
{
    enum Color color;
    Face *face;
    int val;
} cellule;
typedef struct cel Cellule;

struct face
{
    enum Direction dir;
    Cellule **tab;
} face;
typedef struct face Face;
