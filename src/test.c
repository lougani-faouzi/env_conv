#include "test.h"

void test(){
	//lire()
	point *lect=malloc(4 * sizeof(struct pile*));
	float tab[4][2]={{0.1,0.3},{0.2,0.1},{0.9,0.4},{0.7,0.3}};
	for(int i=0;i<4;i++){
		lect[i].x=tab[i][0];
		lect[i].y=tab[i][1];
	}
	point *lecture=lire("test/lecture.txt");
	res_test(comparer(lecture,lect,4), "lire");
	
	
	//tri_insertion()
	point *pt=lire("test/reference_pt.txt");
	point *tri=lire("test/tri.txt");
	pt=tri_insertion(pt,7);
	res_test(comparer(tri,pt,7), "tri_insertion");

	//hasard()
	int res_hasard=1;
	for(int i=0;i<50;i++){
		if(hasard()>1 || hasard()<0)
			res_hasard=0;
	}
	res_test(res_hasard, "hasard");
	
	//nuage()
	point *testnuage=nuage(20);
	int erreur_nuage=0;
	point max,min;
	max.x=1;
	max.y=1;
	min.x=0;
	min.y=0;
	for(int i=0;i<20;i++){
		if(comparer_point(testnuage[i],min)==0 || comparer_point(max,testnuage[i])==0)
			erreur_nuage=1;
	}
	res_test(!erreur_nuage, "nuage");

	//comparer_point()
	int res_comparer=1;
	point *c=tri_insertion(nuage(20),20);
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			if((i<j && comparer_point(c[i],c[j])!=0) || (i==j && comparer_point(c[i],c[j])!=2) || (i>j && comparer_point(c[i],c[j])!=1))
				res_comparer=0;
		}
	}
	res_test(res_comparer, "comparer_point");

	
	//enregistrer()
	enregistrer(lecture,4);
	pt=lire("sortie/data_4.txt");
	res_test(comparer(pt,lect,4), "enregistrer");
		
	//orientation()
	point moy;
	moy.x=0.3;
	moy.y=0.6;
	res_test(!orientation(min,moy,max) && orientation(moy,min,max), "orientation");
	
	//majES() et majEI()
	Pile *ES1=creer_pile();
	Pile *EI1=creer_pile();
	for(int i=0;i<7;i++){
		majES(ES1,tri[i]);
		majEI(EI1,tri[i]);
	}
	point *ES2=lire("test/ES2.txt");
	point *EI2=lire("test/EI2.txt");
	res_test(comparer_pile(ES1,ES2,4), "majES");
	res_test(comparer_pile(EI1,EI2,3), "majEI");

	//env_convexe()
	Pile *E1=creer_pile();
	E1=env_convexe(tri,7);
	point *E2=lire("test/E2.txt");
	res_test(comparer_pile(E1,E2,6), "env_convexe");
	
	//Libération de la mémoire
	free(pt);
	free(tri);
	free(c);
	free(testnuage);
	free(lecture);
	free(lect);
	free(EI2);
	free(ES2);
	free(E2);
	supprimer(ES1);
	supprimer(EI1);
	supprimer(E1);
}

_Bool comparer(point *nua1,point *nua2,int nb){
	int res=1,i=0;
	while(i<nb && res==1){
		if(comparer_point(nua1[i],nua2[i])!=2)
			res=0;
		i++;
	}
	return res;
}

_Bool comparer_pile(Pile *p, point *nuage_pt,int taille){
	int res=1,i=0;
	if(hauteur(p)==taille){
		Element *actuel=p->premier;
		while(actuel!=NULL){
			if(comparer_point(actuel->pt,nuage_pt[i])!=2)
				res=0;
			i++;
			actuel=actuel->suivant;
		}
	}else
		res=0;
	return res;
}

void res_test(int res, char fonction[25]){
	if(res)
		printf("Fonction %s() validée\n",fonction);
	else
		printf("Erreur fonction %s()\n",fonction);
}
				
