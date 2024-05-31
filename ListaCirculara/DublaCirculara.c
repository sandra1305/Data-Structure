#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct
{
	int* cod;
	char* denumire;
	float pret;
	float cantitate;
} produs;

typedef struct
{
	produs* inf;
	struct nodls* next, * prev;
} nodls;

nodls* inserare(nodls* cap, nodls** coada, produs* p) {
	nodls* nou = (nodls*)malloc(sizeof(nodls));
	nou->inf = (produs*)malloc(sizeof(produs));
	nou->inf->cod = (int*)malloc(sizeof(int));
	*(nou->inf->cod) = *(p->cod);
	nou->inf->denumire = (char*)malloc((strlen(p->denumire) + 1) * sizeof(char));
	strcpy(nou->inf->denumire, p->denumire);
	nou->inf->pret = p->pret;
	nou->inf->cantitate = p->cantitate;
	if (cap == NULL) {
		nou->next = cap;
		nou->prev = cap;
		cap = nou;
		*coada = nou;
	}
	else
	{
		(*coada)->next = nou;
		nou->prev = *coada;
		nou->next = cap;
		cap->prev = nou;
		*coada = nou;
	}
}