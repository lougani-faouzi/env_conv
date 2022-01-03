#include "geometrie2d.h"

_Bool orientation (point pt1, point pt2, point pt3){
	int signe=0;
	float det;
	
	det=(pt2.x-pt1.x)*(pt3.y-pt1.y)-(pt2.y-pt1.y)*(pt3.x-pt1.x);
	if(det>0)
		signe=1;
	return signe;
	
}

void majES(Pile *ES, point p){
	if(hauteur(ES)<2){
		empiler(ES,p);
	}else{
		if(!orientation(p,sommet(ES),ES->premier->suivant->pt))
			empiler(ES,p);
		else{
			depiler(ES);
			majES(ES,p);
		}
	}
}

void majEI(Pile *EI, point p){
	if(hauteur(EI)<2)
		empiler(EI,p);
	else{
		if(orientation(p,sommet(EI),EI->premier->suivant->pt))
			empiler(EI,p);
		else{
			depiler(EI);
			majEI(EI,p);
		}
	}
}

Pile* env_convexe(point *nuage_pt, int nb){
	Pile *ES=creer_pile();
	Pile *EI=creer_pile();

	nuage_pt=tri_insertion(nuage_pt, nb);
	
	for(int i=0;i<nb;i++){
		majES(ES,nuage_pt[i]);
		majEI(EI,nuage_pt[i]);
	}
	
	depiler(ES);
	
	while(EI->premier!=NULL){
		empiler(ES, EI->premier->pt);
		depiler(EI);
	}
	supprimer(EI);
	return ES;
}

void tracer(Pile *p, point *nuage_pt,int nb){
	enregistrer(nuage_pt,nb);
	FILE *f = popen("gnuplot -persistent", "w");
	int h=hauteur(p);
	fprintf(f, "set title 'Enveloppe convexe'\nset key autotitle columnhead\nset xrange[0:1]\nset yrange[0:1]\nplot 'sortie/data_%d.txt' with points, '-' with linespoints pt %d,\n",nb,h);
	fprintf(f, "'enveloppe'\n");
	for(int i = 0; i < h; i++){
		fprintf(f, "%f %f\n", p->premier->pt.x, p->premier->pt.y);
		depiler(p);
	}
	fprintf(f, "e\n");
}
