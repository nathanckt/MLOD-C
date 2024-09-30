#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste l = malloc(sizeof(Cellule));
	l->val = v;
	l->suiv = NULL;
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste newListe = creer(v);
	newListe->suiv = l;
	return newListe;
}


// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	while(l != NULL){
		afficheElement(l->val);
		l = l->suiv;
	}
	printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
	if(l==NULL){
		printf("\n");
	}
	else{
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}
}

// void detruireElement(Element e) {}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste tmp;
	while(l!=NULL){
		tmp=l;
		l=l->suiv;
		detruireElement(tmp->val);
		free(tmp);
		tmp = NULL;
	}
}

// version récursive
void detruire_r(Liste l) {
	if(l!=NULL){
		detruireElement(l->val);
		detruire_r(l->suiv);
		free(l);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste pointer;
	Liste prec = NULL;
	pointer = l;
	while(pointer!=NULL){
		prec = pointer;
		pointer = pointer->suiv;
	}

	if(prec != NULL){
		prec->suiv = creer(v);
	}
	else{
		l = creer(v);
	}
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(l==NULL){
		return creer(v);
	}
	else{
		l->suiv = ajoutFin_r(v,l->suiv);
		return l;
	}
}


// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	while(l!=NULL){
		if(equalsElement(v, l->val)){
			return l;
		}
		l = l->suiv;
	}
	return l;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if(l==NULL){
		return l;
	}
	if(equalsElement(v, l->val)){
		return l;
	}
	return cherche_r(v,l->suiv);
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste p;
	if(l==NULL){
		return NULL;
	}
	if(l->val == v){
		p = l->suiv;
		detruireElement(l->val);
		free(l);
		return p;
	}

	Liste precedent=l;
	p =l->suiv;
	while(!estVide(p) && !equalsElement(p->val,v)){
		precedent = p;
		p = p->suiv;
	}

	if(!estVide(p)){
		precedent->suiv = p->suiv;
		p->suiv = NULL;
		detruire_i(p);
	}
	return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if(l == NULL) {
        return NULL;
    }
    if(equalsElement(l->val, v)) {
        Liste temp = l->suiv;
        l->suiv = NULL;
        detruireElement(l->val);  // Ajoute la destruction de l'élément
        free(l);  // Libère la mémoire de l'élément supprimé
        return temp;
    }
    l->suiv = retirePremier_r(v, l->suiv);
    return l;
}


void afficheEnvers_r(Liste l) {
	if (l == NULL) {
        return;
    }
    afficheEnvers_r(l->suiv); 
    afficheElement(l->val);
}
