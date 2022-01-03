#include "nuage.h"

float hasard(){
	float x = (float)rand()/(float)(RAND_MAX/1);
	return x;
}

void afficher_nuage(point *nuage_pt, int nb){
	for(int i=0;i<nb;i++)
		afficher(nuage_pt[i]);
}

point* nuage(int nb){
	int i;
	point *nuage_pt=malloc(nb * sizeof(point));
	for(i=0;i<nb;i++){
		nuage_pt[i].x=hasard();
		nuage_pt[i].y=hasard();
	}
	return nuage_pt;
}

point* tri_insertion(point *nuage_pt,int nb){
	point pt;
	int i,j;
	for(i=1;i<nb;i++){
		pt=nuage_pt[i];
		j=i;
		while(j>0 && comparer_point(nuage_pt[j-1],pt)==1){
			nuage_pt[j]=nuage_pt[j-1];
			j--;
		}
		nuage_pt[j]=pt;
	}
	return nuage_pt;
}

void enregistrer(point *nuage_pt, int nb){
	FILE *fichier;
	char nom[100];
	int i;
	snprintf(nom, sizeof(nom), "%s%d%s", "sortie/data_", nb, ".txt");
	fichier=fopen(nom,"wb");
	fprintf(fichier,"%d\n",nb);
	for(i=0;i<nb;i++)
		fprintf(fichier,"%f %f\n", nuage_pt[i].x, nuage_pt[i].y);
	fclose(fichier);
}

point* lire(char nom[100]){
	FILE *fichier;
	int i,nb;
	fichier=fopen(nom,"rb");
	if (fichier == NULL){
		printf("Problème lors de l'ouverture du fichier !");
		exit(-1);
 	}
 	fscanf(fichier,"%d",&nb);
	point *nuage_pt=malloc(nb * sizeof(struct point));
	for(i=0;i<nb;i++){
		fscanf(fichier,"%f",&nuage_pt[i].x);
		fscanf(fichier,"%f",&nuage_pt[i].y);
	}
	fclose(fichier);
	return nuage_pt;
}

void graphe(point *nuage_pt, int nb){
	int i;
	FILE *p = popen("gnuplot -persistent", "w");
	fprintf(p, "set title 'Nuage'\nset xrange[0:1]\nset yrange[0:1]\nplot '-' with points\n");
	for(i = 0; i < nb; i++)
		fprintf(p, "%f %f\n", nuage_pt[i].x, nuage_pt[i].y);
	fprintf(p, "e\n");
	fprintf(p, "set terminal jpeg\nset output 'sortie/graph_%d.jpg'\nreplot\n",nb);
	printf("Image enregistrée dans le dossier ./sortie sous graph_%d.jpg\n",nb);
	pclose(p);
}
	
