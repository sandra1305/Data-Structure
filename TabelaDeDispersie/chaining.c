#include<stdio.h>
#include<malloc.h>

typedef struct {
	int cod;
	char* nume;
	float medie;
}student;

typedef struct {
	student inf;
	struct nodls* next;
}nodls;

typedef struct {
	struct nodls** vect;
	int size;
}hashT;

int functieHash(int cheie, hashT tabela) {
	return cheie % tabela.size;
}

int inserare(hashT tabela, student s) {
	int pozitie = 0;
	if (tabela.vect != NULL) {
		pozitie = functieHash(s.cod, tabela);
	}
	nodls* nou = (nodls*)malloc(sizeof(nodls));
	nou->inf.cod = s.cod;
	nou->inf.nume = (char*)malloc(sizeof(char)*(strlen(s.nume)+1));
	strcpy(nou->inf.nume, s.nume);
	nou->inf.medie = s.medie;
	nou->next = NULL;
	if (tabela.vect[pozitie] == NULL)
		tabela.vect[pozitie] = nou;
	else
	{
		nodls* temp = tabela.vect[pozitie];
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = nou;
	}
	return pozitie;
}

void traversareLista(nodls* cap) {
	nodls* temp = cap;
		while(temp != NULL)
		{
			printf("\nCod: %d, nume: %s, medie: %5.2f",
				temp->inf.cod, temp->inf.nume, temp->inf.medie);
			temp = temp->next;
		}
			
}

void traversareTabela(hashT tabela) {
	if (tabela.vect != NULL)
	{
		for(int i=0;i<tabela.size;i++)
			if (tabela.vect[i] != NULL)
			{
				printf("\nPozitie:%d", i);
				traversareLista(tabela.vect[i]);
			}
	}
}

void dezalocareLista(nodls* cap) {
	nodls* temp = cap;
	while (temp != NULL) {
		nodls* temp2 = temp->next;
		free(temp->inf.nume);
		free(temp);
		temp = temp2;
	}
}

void dezalocareTabela(hashT tabela) {
	if (tabela.size != NULL) {
		for (int i = 0; i < tabela.size; i++) {
			if (tabela.vect[i] != NULL) {
				dezalocareLista(tabela.vect[i]);
			}
		}

		free(tabela.vect);
	}
}

void stergeNod(nodls* cap) {
	free(cap->inf.nume);
	free(cap);
}

int stergere(hashT tabela, int cod) {
	int pozitie = 0;
	if (tabela.vect != NULL)
	{
		pozitie = functieHash(cod, tabela);
		nodls* temp = tabela.vect[pozitie];
		if (temp == NULL) {
			return -1;
		}
		else {
			if (temp->inf.cod == cod) {
				if (temp->next == NULL)
				{
					stergeNod(temp);
					tabela.vect[pozitie] = NULL;
				}
				else {
					nodls* temp2 = temp;
					tabela.vect[pozitie] = temp->next;
					stergeNod(temp2);
				}
			}
			else
			{

				while (temp->next != NULL) {
					nodls* temp2 = temp->next;
					if (temp2->inf.cod != cod)
						temp = temp->next;
					else
						break;
				}
				nodls* p = temp->next;
				if (p != NULL)
				{
					if (p->next != NULL)
					{
						temp->next = p->next;
						stergeNod(p);
					}
					else {
						temp->next = NULL;
						stergeNod(p);
					}
				}
				else
					return-1;

			}
		}
	}
	return pozitie;
}
void main()
{
	hashT tabela;
	tabela.size = 101;
	tabela.vect = (nodls**)malloc(tabela.size * sizeof(nodls*));
	for (int i = 0; i < tabela.size; i++)
		tabela.vect[i] = NULL;

	int n;
	/*printf("Nr. studenti=");
	scanf("%d", &n);
	student s;
	char buffer[20];
	for (int i = 0; i < n; i++)
	{
		printf("\nCod=");
		scanf("%d", &s.cod);
		printf("\nNume=");
		scanf("%s", buffer);
		s.nume = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
		strcpy(s.nume, buffer);
		printf("\nMedie=");
		scanf("%f", &s.medie);

		inserare(tabela, s);
	}*/

	FILE* f = fopen("fisier.txt", "r");
	student s;
	char buffer[20];
	fscanf(f, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%d", &s.cod);
		fscanf(f, "%s", buffer);
		s.nume = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
		strcpy(s.nume, buffer);
		fscanf(f, "%f", &s.medie);
		inserare(tabela, s);
	}
	fclose(f);

	traversare(tabela);

	stergere(tabela, 305);

	printf("\n------dupa stergere-------");

	traversare(tabela);

	dezalocare(tabela);
}