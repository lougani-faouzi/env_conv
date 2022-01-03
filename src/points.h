#include <stdio.h>
#include <stdlib.h>

#ifndef POINT_H
#define POINT_H
typedef struct point{	
	float x;
	float y;
} point;

void afficher(point pt);
int comparer_point(point p1,point p2);
void points(int nb);

#endif
