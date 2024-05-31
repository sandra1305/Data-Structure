//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
//typedef struct  {
//	int cod;
//	char* denumire;
//	float pret;
//	float cantitate;
//}Produs;
//typedef struct {
//	Produs inf;
//	struct NodLs* next;
//}NodLs;
//
//
//
//NodLs* insereNod(NodLs* cap, Produs p) {
//	NodLs* nou = (NodLs*)malloc(sizeof(NodLs));
//	nou->inf.cod = p.cod;
//	nou->inf.denumire = (char*)malloc((strlen(p.denumire) + 1) * sizeof(char));
//	strcpy(nou->inf.denumire, p.denumire);
//	nou->inf.pret = p.pret;
//	nou->inf.cantitate = p.cantitate;
//	nou->next = NULL;
//
//	if (cap == NULL) {
//		cap = nou;
//	}
//	else
//	{
//		NodLs* temp = cap;
//		while (temp->next != NULL) {
//			temp = temp->next;
//		}
//		temp->next = nou;
//	}
//	return cap;
//
//}
//
//void traversare(NodLs* cap) {
//	NodLs* temp = cap;
//	while (temp = NULL)
//	{
//		printf("\nCod=%d, Denumire=%s, Pret=%5.2f, Cantitate=%5.2f", temp->inf.cod, temp->inf.denumire, temp->inf.pret, temp->inf.cantitate);
//		temp = temp->next;
//	}
//}
//
//void dezalocare(NodLs* cap) {
//	NodLs* temp = cap;
//	while (temp != NULL) {
//		NodLs* temp2 = temp->next;
//		free(temp->inf.denumire);
//		free(temp);
//		temp = temp2;
//	}
//}
//
//void main() {
//	NodLs* cap = NULL;
//	Produs p;
//	char buffer[20];
//	int nrIntrari;
//	FILE* f = fopen("fisier.txt", "r");
//	fscanf(f,"%d", &nrIntrari);
//	
//	for (int i = 0; i < nrIntrari; i++) {
//		fscanf(f, "%d", &p.cod);
//		fscanf(f, "%s", buffer);
//		p.denumire = (char*)malloc((strlen(buffer) + 1)* sizeof(char));
//		strcpy(p.denumire, buffer);
//		fscanf(f, "%f", &p.pret);
//		fscanf(f, "%f", &p.cantitate);
//		cap = insereNod(cap, p);
//		free(p.denumire);
//	}
//	fclose(f);
//	traversare(cap);
//	dezalocare(cap);
//
//}