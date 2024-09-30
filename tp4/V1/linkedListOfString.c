// gcc -W -Wall -std=c99 linkedList.c linkedListOfString.c -o linkedListOfString
// gcc -W -Wall -fsanitize=address -g -std=c99 linkedList.c linkedListOfString.c -o linkedListOfString
// gcc -W -Wall -Wno-unused-parameter -std=c99 linkedList.c linkedListOfString.c -o linkedListOfString

#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void afficheElement(Element e){
    printf("%s",(char*)e);
}

void detruireElement(Element e){
}

bool equalsElement(Element e1, Element e2){
	return strcmp((char*)e1, (char*)e2)==0;
}


int main(void){
	Liste l, p;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

	l = ajoutTete("feurrr\n",l);
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");
	l = ajoutTete("c'est super\n",l);
	l = ajoutTete("c'est pas mal\n",l);
	l = ajoutTete("ça marche tjr\n",l);
	l = ajoutTete("c'est chiant\n",l);
	l = ajoutTete("c'est long nan ? \n",l);
	l = ajoutTete("c'est bientôt la fin\n",l);
	l = ajoutTete("c'est fini youhou\n",l);
    l = ajoutTete("c'est long nan ? \n",l);
	l = ajoutTete("ah non c'est fini mtn\n",l);

	afficheListe_i(l);
	afficheListe_r(l);

	ajoutFin_i("le dernier\n",l);
	afficheListe_i(l);

	ajoutFin_r("ah non\n",l);
	afficheListe_i(l);

	p = cherche_i("quoi ?\n",l);
	printf("cherche_i(quoi) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_i("c'est long nan ? \n",l);
	if(estVide(p))
		printf("cherche_i(c'est long nan ?) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_i(c'est long nan ?) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	p = cherche_r("quoi \n",l);
	printf("cherche_r(quoi) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_r("c'est long nan ? \n",l);
	if(estVide(p))
		printf("cherche_r(c'est long nan ?) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_r(c'est long nan ? ) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	printf("retirePremier_i(c'est long nan ?)   : ");
	l = retirePremier_i("c'est long nan ? \n",l);
	afficheListe_r(l);

	printf("retirePremier_i(c'est long nan ?)   : ");
	l = retirePremier_i("c'est long nan ? \n",l);
	afficheListe_r(l);

	printf("retirePremier_i(c'est fini youhou) : ");
	l = retirePremier_i("c'est fini youhou\n",l);
	afficheListe_r(l);

	printf("retirePremier_r(ah non c'est fini mtn)   : ");
	l = retirePremier_r("ah non c'est fini mtn\n",l);
	afficheListe_r(l);

	printf("afficheEnvers_r(l)  : ");
	afficheEnvers_r(l);

	detruire_r(l);
	l=NULL;

	return EXIT_SUCCESS;
}