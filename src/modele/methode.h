#define NB_FUNCTION 13

void rotationLigneHautVersDroite(Face **);
void rotationLigneHautVersGauche(Face **);
void rotationLigneBasVersDroite(Face **);
void rotationLigneBasVersGauche(Face **);
void rotationColonneGaucheVersHaut(Face **);
void rotationColonneGaucheVersBas(Face **);
void rotationColonneGaucheVersBas(Face **);
void rotationColonneDroiteVersHaut(Face **);
void rotationColonneDroiteVersBas(Face **);
void rotationFaceArriereVersDroite(Face **);
void rotationFaceArriereVersGauche(Face **);
void rotationFaceAvantVersGauche(Face **);
void rotationFaceAvantVersDroite(Face **);

void *mouvement[NB_FUNCTION] = {
    rotationLigneHautVersDroite,
    rotationLigneHautVersGauche,
    rotationLigneBasVersDroite,
    rotationLigneBasVersGauche,
    rotationColonneGaucheVersHaut,
    rotationColonneGaucheVersBas,
    rotationColonneGaucheVersBas,
    rotationColonneDroiteVersHaut,
    rotationColonneDroiteVersBas,
    rotationFaceArriereVersDroite,
    rotationFaceArriereVersGauche,
    rotationFaceAvantVersGauche,
    rotationFaceAvantVersDroite,
};