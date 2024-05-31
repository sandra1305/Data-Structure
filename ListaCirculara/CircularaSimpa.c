//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct {
//	unsigned int codRezervare;
//	char* destinatie;
//	char* orasPlecare;
//	char* dataPlecare;
//	unsigned int numarTuristi;
//}rezervare;
//
//typedef struct {
//	rezervare inf;
//	struct nodCirculara* next;
//}nodCirculara;
//
//nodCirculara* inserareNod(nodCirculara* cap, rezervare r) {
//	nodCirculara* nou = (nodCirculara*)malloc(sizeof(nodCirculara));
//	nou->inf.codRezervare = r.codRezervare;
//	nou->inf.destinatie = (char*)malloc((strlen(r.destinatie) + 1) * sizeof(char));
//	strcpy(nou->inf.destinatie,r.destinatie);
//	nou->inf.orasPlecare = (char*)malloc((strlen(r.orasPlecare) + 1) * sizeof(char));
//	strcpy(nou->inf.orasPlecare, r.orasPlecare);
//	nou->inf.dataPlecare = (char*)malloc((strlen(r.dataPlecare) + 1) * sizeof(char));
//	strcpy(nou->inf.dataPlecare, r.dataPlecare);
//	nou->inf.numarTuristi = r.numarTuristi;
//	nou->next = NULL;
//	if (cap == NULL) {
//		cap = nou;
//		nou->next = cap;
//	}
//	else {
//		nodCirculara* temp = cap;
//		while (temp->next != cap)
//			temp = temp->next;
//		temp->next = nou;
//		nou->next = cap;
//	}
//	return cap;
//}
//void afisareRezervare(rezervare r) {
//	printf("Cod rezervare: %u\n", r.codRezervare);
//	printf("Destinatie: %s\n", r.destinatie);
//	printf("Oras plecare: %s\n", r.orasPlecare);
//	printf("Data plecare: %s\n", r.dataPlecare);
//	printf("Nr turisti: %u\n", r.numarTuristi);
//	printf("\n");
//}
//
//void traversareLista(nodCirculara* cap) {
//	afisareRezervare(cap->inf);
//	nodCirculara* temp = cap->next;
//	while (temp != cap) {
//		afisareRezervare(temp->inf);
//		temp = temp->next;
//	}
//}
//
//rezervare returnareRezervare(nodCirculara* cap) {
//	rezervare maxim = cap->inf;
//	nodCirculara* temp = cap->next;
//	while (temp != cap) {
//		if (temp->inf.numarTuristi > maxim.numarTuristi){
//			maxim = temp->inf;
//		}
//	temp = temp->next;
//	}
//	return maxim;
//}
//
//void actualizareDataPlecare(nodCirculara* cap, int codNou, char nouaData) {
//	nodCirculara* temp = cap->next;
//	while (temp != cap) {
//		if (temp->inf.codRezervare == codNou) {
//			free(temp->inf.dataPlecare);
//			temp->inf.dataPlecare = (char*)malloc(sizeof(char) * (strlen(nouaData) + 1));
//			strcpy(temp->inf.dataPlecare, nouaData);
//		}
//		temp = temp->next;
//	}
//}
//
//
//char* getDestinatieMaxima(nodCirculara* cap) {
//	rezervare maxim = cap->inf;
//	nodCirculara* temp = cap->next;
//	while (temp != cap)
//	{
//		if (temp->inf.numarTuristi > maxim.numarTuristi) {
//			maxim = temp->inf;
//		}
//		temp = temp->next;
//	}
//	char* newDestinatie = (char*)malloc(sizeof(char) * (1 + strlen(maxim.destinatie)));
//	strcpy(newDestinatie, maxim.destinatie);
//	return newDestinatie;
//}
//
//void salveazaVector(nodCirculara* cap, rezervare* vect, int* nrElem, char destinatieNoua) {
//	if (cap->inf.destinatie == destinatieNoua)
//	{
//		vect[*nrElem].codRezervare = cap->inf.codRezervare;
//		vect[*nrElem].destinatie = (char*)malloc((strlen(cap->inf.destinatie) + 1) * sizeof(char));
//		strcpy(vect[*nrElem].destinatie, cap->inf.destinatie);
//		vect[*nrElem].orasPlecare = (char*)malloc((strlen(cap->inf.orasPlecare) + 1) * sizeof(char));
//		strcpy(vect[*nrElem].orasPlecare, cap->inf.orasPlecare);
//		vect[*nrElem].dataPlecare = (char*)malloc((strlen(cap->inf.dataPlecare) + 1) * sizeof(char));
//		strcpy(vect[*nrElem].dataPlecare, cap->inf.dataPlecare);
//		vect[*nrElem].numarTuristi = cap->inf.numarTuristi;
//		(*nrElem)++;
//	}
//	nodCirculara* temp = cap->next;
//	
//	while (temp != cap) {
//		if (temp->inf.destinatie==destinatieNoua)
//		{
//			vect[*nrElem].codRezervare = temp->inf.codRezervare;
//			vect[*nrElem].destinatie = (char*)malloc((strlen(temp->inf.destinatie) + 1) * sizeof(char));
//			strcpy(vect[*nrElem].destinatie, temp->inf.destinatie);
//			vect[*nrElem].orasPlecare = (char*)malloc((strlen(temp->inf.orasPlecare) + 1) * sizeof(char));
//			strcpy(vect[*nrElem].orasPlecare, temp->inf.orasPlecare);
//			vect[*nrElem].dataPlecare = (char*)malloc((strlen(temp->inf.dataPlecare) + 1) * sizeof(char));
//			strcpy(vect[*nrElem].dataPlecare, temp->inf.dataPlecare);
//			vect[*nrElem].numarTuristi = temp->inf.numarTuristi;
//			(*nrElem)++;
//		}
//		temp = temp->next;
//	}
//	
//}
//
//void dezalocare(nodCirculara* cap) {
//	nodCirculara* temp = cap->next;
//	while (temp != cap) {
//		nodCirculara* temp2 = temp->next;
//		free(temp->inf.dataPlecare);
//		free(temp->inf.orasPlecare);
//		free(temp->inf.destinatie);
//		free(temp);
//		temp = temp2;
//	}
//	free(temp->inf.dataPlecare);
//	free(temp->inf.orasPlecare);
//	free(temp->inf.destinatie);
//	free(temp);
//}
//void main() {
//	unsigned int nrDestinatii;
//	nodCirculara* cap = NULL;
//	rezervare r;
//	char buffer[20];
//	FILE* f = fopen("fisier.txt", "r");
//	fscanf(f, "%u", &nrDestinatii);
//	for (int i = 0; i < nrDestinatii; i++) {
//		fscanf(f, "%u", &r.codRezervare);
//		fscanf(f, "%s", buffer);
//		r.destinatie= (char*)malloc((strlen(buffer) + 1) * sizeof(char));
//		strcpy(r.destinatie, buffer);
//		fscanf(f, "%s", buffer);
//		r.orasPlecare= (char*)malloc((strlen(buffer) + 1) * sizeof(char));
//		strcpy(r.orasPlecare, buffer);
//		fscanf(f, "%s", buffer);
//		r.dataPlecare = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
//		strcpy(r.dataPlecare, buffer);
//		fscanf(f, "%u", &r.numarTuristi);
//		cap = inserareNod(cap, r);
//		free(r.dataPlecare);
//		free(r.orasPlecare);
//		free(r.destinatie);
//	}
//
//	traversareLista(cap);
//	
//
//	rezervare rezMaxima = returnareRezervare(cap);
//	afisareRezervare(rezMaxima);
//
//	actualizareDataPlecare(cap, "2025-09-15", 4567);
//	traversareLista(cap);
//
//	char* destinatieMaxima = getDestinatieMaxima(cap);
//	printf("%s", destinatieMaxima);
//	printf("\n-----------------------------------------------\n");
//	rezervare* vect=(rezervare*)malloc(nrDestinatii*sizeof(rezervare));
//	int nrElem = 0;
//	salveazaVector(cap, vect, &nrElem,"Cairo");
//	for (int i = 0; i < nrElem; i++) {
//		printf("%u,%s,%s,%s,%u", vect[i].codRezervare, vect[i].destinatie, vect[i].orasPlecare, vect[i].dataPlecare,vect[i].numarTuristi);
//	}
//	for (int i = 0; i < nrElem; i++) {
//		free(vect[i].dataPlecare);
//		free(vect[i].orasPlecare);
//		free(vect[i].destinatie);
//	}
//
//	free(vect);
//	dezalocare(cap);
//
//}