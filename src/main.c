#include "test.h"

	
int main(void){
	char choix;
	printf("Tracer une enveloppe convexe (e) ou lancer les tests unitaires (t)?\n");
	scanf(" %c",&choix);
	int nombre;
	if(choix=='e'){
		printf("Nombre de points aléatoires dans le nuage ?\n");
		scanf("%d",&nombre);
		point *nuage_pt=malloc(nombre*sizeof(point*));
		nuage_pt=nuage(nombre);
		tracer(env_convexe(nuage_pt,nombre),nuage_pt,nombre);
		afficher_pile(env_convexe(nuage_pt,nombre));
		free(nuage_pt);
	}else if(choix=='t')
		test();
	return 0;
}
