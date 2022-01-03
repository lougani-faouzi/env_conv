#include <math.h>
#include "nuage.h"
#include "piles.h"

_Bool orientation (point p1, point p2, point p3);
void majES(Pile *ES, point p);
void majEI(Pile *EI, point p);
Pile* env_convexe(point *nuage_pt, int nb);
void tracer(Pile *p, point *nuage_pt,int nb);
