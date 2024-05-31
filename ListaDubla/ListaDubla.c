//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//typedef struct
//{
//	int* cod;
//	char* denumire;
//	float pret;
//	float cantitate;
//}produs;
//
//typedef struct {
//	produs* inf;
//	struct nodLs* next, * prev;
//}nodLs;
//
//nodLs* inserareNod(nodLs* cap, nodLs** coada, produs* p) {
//	nodLs* nou = (nodLs*)malloc(sizeof(nodLs));
//	nou->inf = (produs*)malloc(sizeof(produs));
//	nou->inf->cod = (int*)malloc(sizeof(int));
//	*(nou->inf->cod) = *(p->cod);
//	nou->inf->denumire = (char*)malloc((strlen(p->denumire) + 1) * sizeof(char));
//	strcpy(nou->inf->denumire, p->denumire);
//	nou->inf->pret = p->pret;
//	nou->inf->cantitate = p->cantitate;
//	nou->next = NULL;
//	nou->prev = NULL;
//
//	if (cap == NULL) {
//		cap = nou;
//		*coada = nou;
//	}
//	else {
//		nodLs* temp = cap;
//		while (temp->next != NULL)
//			temp = temp->next;
//		temp->next = nou;
//		temp->prev = temp;
//		*coada = nou;
//	}
//	return cap;
//}
//
//void traversare(nodLs* cap) {
//	nodLs* temp = cap;
//	while (temp != NULL) {
//		printf("\nCod=%d, Denumire=%s, Pret=%5.2f, Cantitate=%5.2f",
//			*(temp->inf->cod), temp->inf->denumire, temp->inf->pret, temp->inf->cantitate);
//		temp = temp->next;
//	}
//
//}
//
//void traversareInversa(nodLs* coada) {
//	nodLs* temp = coada;
//	while (temp != NULL) {
//		printf("\nCod=%d, Denumire=%s, Pret=%5.2f, Cantitate=%5.2f",
//			*(temp->inf->cod), temp->inf->denumire, temp->inf->pret, temp->inf->cantitate);
//		temp = temp->prev;
//	}
// }
//
//void conversieListaVector(nodLs* cap, produs** vect, int* nr) {
//	nodLs* temp = cap;
//	while (temp != NULL) {
//		vect[*nr] = (produs*)malloc(1 * sizeof(produs));
//		vect[*nr]->cod = (int*)malloc(sizeof(int));
//		*(vect[*nr]->cod )= temp->inf->cod;
//		vect[*nr]->denumire = (char*)malloc((strlen(temp->inf->denumire) + 1) * sizeof(char));
//		strcpy(vect[*nr]->denumire, temp->inf->denumire);
//		vect[*nr]->pret = temp->inf->pret;
//		vect[*nr]->cantitate = temp->inf->cantitate;
//		(*nr)++;
//		temp = temp->next;
//	}
//}
//
//void dezalocare(nodLs* cap) {
//	nodLs* temp = cap;
//	while (temp != NULL) {
//		nodLs* temp2 = temp->next;
//		free(temp->inf->denumire);
//		free(temp->inf->cod);
//		free(temp->inf);
//		free(temp);
//		temp = temp2;
//
//	}
//}
//
//void main() {
//	int nrProd;
//	nodLs* cap = NULL;
//	nodLs* coada = NULL;
//	produs* p;
//	char buffer[20];
//	FILE* f = ("fisier.txt", "r");
//	fscanf(f, "%d", &nrProd);
//	for (int i = 0; i < nrProd; i++) {
//		p = (produs*)malloc(sizeof(produs));
//		p->cod = (int*)malloc(sizeof(int));
//		fscanf(f, "%d", p->cod);
//		fscanf(f, "%s", buffer);
//		p->denumire = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
//		strcpy(p->denumire, buffer);
//		fscanf(f, "%f", &p->pret);
//		fscanf(f, "%f", &p->cantitate);
//		cap = inserareNod(cap, &coada, p);
//		free(p->denumire);
//		free(p->cod);
//		free(p);
//	}
//	traversare(cap);
//	traversareInversa(coada);
//	printf("\n-------conversie-----------");
//	produs** vect = (produs**)malloc(sizeof(produs*));
//	int nr = 0;
//	conversieListaVector(cap, vect, &nr);
//	for (int i = 0; i < nr; i++)
//		printf("\nCod=%d, Denumire=%s, Pret=%5.2f, Cantitate=%5.2f",
//			*(vect[i]->cod), vect[i]->denumire, vect[i]->pret, vect[i]->cantitate);
//	for (int i = 0; i < nr; i++)
//	{
//		free(vect[i]->denumire);
//		free(vect[i]->cod);
//		free(vect[i]);
//	}
//	free(vect);
//
//	dezalocare(cap);
//}