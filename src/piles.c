#include "piles.h"

Pile* creer_pile(){
	Pile *pile = malloc(sizeof(*pile));
	Element *element = malloc(sizeof(*element));

	if (pile == NULL || element == NULL)
		exit(EXIT_FAILURE);
	
   	element->pt.x=-1;
   	element->pt.y=-1;
	element->suivant = NULL;
	pile->premier = element;
	return pile;
}
		

Pile* empiler(Pile *pile, point p){
	Element *nouveau = malloc(sizeof(*nouveau));
    	if (nouveau == NULL)
    		exit(EXIT_FAILURE);
    	if(estVide(pile) || (hauteur(pile)==1 && pile->premier->pt.x==-1 && pile->premier->pt.y==-1)){
    		nouveau->pt=p;
		nouveau->suivant = NULL;
		pile->premier = nouveau;
	}else{
		nouveau->pt=p;
    		nouveau->suivant = pile->premier;
    		pile->premier = nouveau;
    	}
	return pile;
}

Pile* depiler(Pile* pile){
	if (pile == NULL)
        	exit(EXIT_FAILURE);

	if (pile->premier != NULL){
		Element *aSupprimer = pile->premier;
		pile->premier = pile->premier->suivant;
		free(aSupprimer);
	}
	return pile;
}

point sommet(Pile* pile){
	if(pile->premier!=NULL){
		return pile->premier->pt;
	}else{
		printf("Erreur sommet: pile vide\n");
		exit(EXIT_FAILURE);
	}
}

int hauteur(Pile* pile){
	int i=0;
	Element *actuel = pile->premier;

	while (actuel != NULL){
        	i++;
        	actuel = actuel->suivant;
    	}
    	return i;
}

_Bool estVide(Pile *pile){
	if(pile->premier==NULL)
		return 1;
	return 0;
}

void afficher_pile(Pile* pile){
	if (pile == NULL)
		exit(EXIT_FAILURE);

	Element *actuel = pile->premier;

	while (actuel != NULL){
        	printf("(%f;%f) -> ", actuel->pt.x, actuel->pt.y);
        	actuel = actuel->suivant;
    	}
    	printf("NULL\n");
}

void supprimer(Pile *pile){
    if (pile == NULL){
    	printf("Erreur suppression pile\n");
        exit(EXIT_FAILURE);
    }

    if (pile->premier != NULL){
        Element *aSupprimer = pile->premier;
        pile->premier = pile->premier->suivant;
        free(aSupprimer);
    }
}
