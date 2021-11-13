enum COLOR { ROUGE,BLEU,JAUNE,VERT,BLANC,ORANGE};
enum FACE {HAUT,BAS,DEVANT,DERRIERE,GAUCHE,DROITE};

struct cel 
{
    enum COLOR color;
    enum FACE face;
} cellule;
typedef struct cel cellule;

typedef cellule Face[3][3];