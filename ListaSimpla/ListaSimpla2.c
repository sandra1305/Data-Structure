//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//
//
//typedef struct {
//	int nrMatricol;
//	char* nume;
//	float medie;
//} student;
//
//typedef struct {
//	student inf;
//	struct nodLs* next;
//}nodLs;
//
//nodLs* inserareNod(nodLs* cap, student s) {
//	nodLs* nou = (nodLs*)malloc (sizeof(nodLs));
//	nou->inf.nrMatricol = s.nrMatricol;
//	nou->inf.nume = (char*)malloc((strlen(s.nume) + 1) * sizeof(char));
//	strcpy(nou->inf.nume, s.nume);
//	nou->inf.medie = s.medie;
//	nou->next = NULL;
//	if (cap == NULL) {
//		cap = nou;
//	}
//	else
//	{
//		nodLs* temp = cap;
//		while (temp->next != NULL)
//			temp = temp->next;
//		temp->next= nou;
//	}
//	return cap;
//
//}
//
//void traversareLista(nodLs* cap) {
//	nodLs* temp = cap;
//	while (temp != NULL) {
//		printf("\nNr.matricol = % d, Nume = %s, Medie = % 5.2f",
//			temp->inf.nrMatricol, temp->inf.nume, temp->inf.medie);
//		temp = temp->next;
//	}
//}
//
//void dezalocare(nodLs* cap) {
//	nodLs* temp = cap;
//		while (temp != NULL) {
//			nodLs* temp2 = temp->next;
//			free(temp->inf.nume);
//			free(temp);
//			temp = temp2;
//		}
//	}
//
//void salvareVector(nodLs* cap, student* vect, int* nrElem, float prag) {
//	nodLs* temp = cap;
//	while (temp != NULL) {
//		if (temp->inf.medie > prag) {
//			vect[*nrElem].nrMatricol = temp->inf.nrMatricol;
//			vect[*nrElem].nume = (char*)malloc((strlen(temp->inf.nume) + 1) * sizeof(char));
//			strcpy(vect[*nrElem].nume, temp->inf.nume);
//			vect[*nrElem].medie = temp->inf.medie;
//			(*nrElem)++;
//		}
//		temp = temp->next;
//	}
//}
//void main() {
//	int nrStudenti;
//	nodLs* cap = NULL;
//	student s;
//	char buffer[20];
//	FILE* f = fopen("fisier.txt", "r");
//	fscanf(f, "%d", &nrStudenti);
//	for (int i = 0; i < nrStudenti; i++) {
//		fscanf(f, "%d", &s.nrMatricol);
//		fscanf(f, "%s", buffer);
//		s.nume = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
//		strcpy(s.nume, buffer);
//		fscanf(f, "%f", &s.medie);
//		cap = inserareNod(cap, s);
//	}
//	fclose(f);
//	traversareLista(cap);
//
//	printf("\n------------------------------------\n");
//	int nrElem = 0;
//	student* vect = (student*)malloc(nrStudenti * sizeof(student));
//	salvareVector(cap, vect, &nrElem, 9.5f);
//	for (int i = 0; i < nrElem; i++) {
//		printf("\nNr. matricol = %d, Nume = %s, Medie = %5.2f",
//			vect[i].nrMatricol, vect[i].nume, vect[i].medie);
//	}
//	for (int i = 0; i < nrElem; i++) {
//
//		free(vect[i].nume);
//	}
//
//	free(vect);
//	dezalocare(cap);
//}