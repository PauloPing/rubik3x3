#define NB_FUNCTION 18


void UPrime(Face **);
void U(Face **);
void ré(Face **);
void réPrime(Face **);
void LPrime(Face **);
void L(Face **);
void R(Face **);
void RPrime(Face **);
void BPrime(Face **);
void B(Face **);
void FPrime(Face **);
void F(Face **);
void E(Face **);
void EPrime(Face **);
void MPrime(Face **);
void M(Face **);
void S(Face **);
void SPrime(Face **);
void switchFace(Face *,Face *);
void milieuFace(Face **);

void *mouvement[NB_FUNCTION] = {
    U,
    UPrime,
    L,
    LPrime,
    F,
    FPrime,
    R,
    RPrime,
    B,
    BPrime,
    ré,
    réPrime,
    M,
    MPrime,
    E,
    EPrime,
    S,
    SPrime
};