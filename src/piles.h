#include <stdio.h>
#include <stdlib.h>
#include "points.h"

typedef struct Element Element;
struct Element
{
    point pt;
    Element *suivant;
};

typedef struct Pile {
    Element *premier;
} Pile;

Pile* creer_pile();
Pile* empiler(Pile* pile, point p);
Pile* depiler(Pile* pile);
point sommet(Pile* pile);
int hauteur(Pile* pile);
_Bool estVide(Pile* pile);
void afficher_pile(Pile* pile);
void supprimer(Pile *pile);
