#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct {
	int cod;
	char* titlu;
	float pret;
}carte;

typedef struct {
	carte inf;
	struct nodStiva* next;
}nodStiva;


typedef struct {
	carte inf;
	struct nodLista* next;
}nodLista;
void push(nodStiva** varf, carte c){

	nodStiva* nou = (nodStiva*)malloc(sizeof(nodStiva));
	nou->inf.cod = c.cod;
	nou->inf.titlu = (char*)malloc((strlen(c.titlu) + 1) * sizeof(char));
	strcpy(nou->inf.titlu, c.titlu);
	nou->inf.pret = c.pret;
	nou->next = NULL;
	if (*varf = NULL)
		*varf = nou;
	else {
		nou->next = *varf;
		*varf= nou;
	}
}

int pop(nodStiva**varf, carte* val) {
	if (*varf == NULL)
		return -1;
	else {
		(*val).cod = (*varf)->inf.cod;
		(*val).titlu = (char*)malloc((strlen((*varf)->inf.titlu) + 1) * sizeof(char));
		strcpy((*val).titlu, (*varf)->inf.titlu);
		(*val).pret = (*varf)->inf.pret;
		nodStiva* temp = *varf;
		*varf = (*varf)->next;
		free(temp->inf.titlu);
		free(temp);
		return 0;
	}

}

void traversare(nodStiva* varf) {
	nodStiva* temp = varf;
	while (temp) {
		printf("\nCod = %d, Titlu = %s, Pret = %5.2f", temp->inf.cod, temp->inf.titlu, temp->inf.pret);
		temp = temp->next;
	}
}

void conversieStivaVector(nodStiva** varf, carte* vect, int* nr) {
	carte val;
	while (pop(varf, &val) == 0)
	{
		vect[*nr] = val;
		(*nr)++;
	}
}

void inserareLista(nodLista** cap, carte c) {
	nodLista* nou = (nodLista*)malloc(sizeof(nodLista));
	nou->inf.cod = c.cod;
	nou->inf.titlu = (char*)malloc((strlen(c.titlu) + 1) * sizeof(char));
	strcpy(nou->inf.titlu, c.titlu);
	nou->inf.pret = c.pret;
	nou->next = NULL;
	if (*cap == NULL) {
		*cap = nou;
	}
	else {
		nodLista* temp = *cap;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = nou;
	}
}

void traversareLista(nodLista* cap) {
	nodLista* temp = cap;
	while (temp != NULL) {
		printf("\nCod = %d, Titlu = %s, Pret = %5.2f", temp->inf.cod, temp->inf.titlu, temp->inf.pret);
		temp = temp->next;
	}
}

void dezalocareLista(nodLista* cap)
{
	nodLista* temp = cap;
	while (temp)
	{
		nodLista* temp2 = temp->next;
		free(temp->inf.titlu);
		free(temp);
		temp = temp2;
	}
}

void conversieStivaListaSimpla(nodStiva** varf, nodLista** cap) {
	carte val;
	while (pop(varf, &val) == 0) {
		inserare(cap, val);
	}
}

void main() {
	nodStiva* varf = NULL;
	int n;
	carte c;
	printf("Nr. carti=");
	scanf("%d", &n);
	char buffer[30];
	for (int i = 0; i < n; i++)
	{
		printf("\nCod=");
		scanf("%d", &c.cod);
		printf("\nTitlu=");
		scanf(" %[^\n]s", buffer);
		c.titlu = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
		strcpy(c.titlu, buffer);
		printf("\nPret=");
		scanf("%f", &c.pret);

		push(&varf, c);
	}
	traversare(varf);

	carte val;
	pop(&varf, &val);
	printf("\nCartea extrasa are codul %d si titlul %s", val.cod, val.titlu);
	free(val.titlu);

	printf("\n--------Conversie stiva vector--------\n");
	carte* vect = (carte*)malloc(n * sizeof(carte));
	int nr = 0;
	conversieStivaVector(&varf, vect, &nr);
	for (int i = 0; i < nr; i++)
		printf("\nCod = %d, Titlu = %s, Pret = %5.2f", vect[i].cod, vect[i].titlu, vect[i].pret);
	for (int i = 0; i < nr; i++)
		free(vect[i].titlu);
	free(vect);
}

