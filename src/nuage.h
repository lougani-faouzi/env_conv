#include "points.h"
#include <string.h>

float hasard();
point* nuage(int nb);
void enregistrer(point *nuage_pt,int nb);
point* lire(char nom[100]);
void graphe(point *nuage_pt, int nb);
point* tri_insertion(point *nuage_pt, int nb);
void afficher_nuage(point *nuage_pt, int nb);
