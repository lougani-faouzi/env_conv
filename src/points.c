#include "points.h"

void afficher(point pt){
	printf("(%f,%f)\n",pt.x,pt.y);
 }
	
int comparer_point(point pt1, point pt2){
	if(pt1.x >= pt2.x){
		if(pt1.x>pt2.x)
			return 1;
		else if(pt1.x==pt2.x && pt1.y>pt2.y)
			return 1;
		else if(pt1.x==pt2.x && pt1.y==pt2.y)
			return 2;
		else
			return 0;
	}else
		return 0;
}
		

void points(int nb){
	point p1;
	point p2;
	printf("x1:");
	scanf("%f",&p1.x);
	printf("y1:");
	scanf("%f",&p1.y);
	printf("x2:");
	scanf("%f",&p2.x);
	printf("y2:");
	scanf("%f",&p2.y);
	afficher(p1);
	afficher(p2);
	if(comparer_point(p1,p2)==1)
		printf("Le point 1 est plus grand que le point 2.\n");
	else if(comparer_point(p1,p2)==2)
		printf("Le point 1 et 2 sont égaux.\n");
	else
		printf("Le point 2 est plus petit que le point 1.\n");
}

