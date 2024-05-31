#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct {
	char* dataConsultatie;
	char* numeMedic;
	char* specialitate;
	char* diagnostic;
	int pretConsultatie;
}Consultatie;

typedef struct {
	Consultatie inf;
	struct NodLS* next;
}NodLS;

typedef struct {
	struct NodLS* inf;
	struct NodLp* next;
}NodLp;

void inserareNod(NodLS** cap, Consultatie c) {
	NodLS* nou = (NodLS*)malloc(sizeof(NodLS));
	nou->inf.dataConsultatie = (char*)malloc(sizeof(char) * (strlen(c.dataConsultatie) + 1));
	strcpy(nou->inf.dataConsultatie, c.dataConsultatie);

	nou->inf.numeMedic = (char*)malloc(sizeof(char) * (strlen(c.numeMedic) + 1));
	strcpy(nou->inf.numeMedic, c.numeMedic);

	nou->inf.specialitate = (char*)malloc(sizeof(char) * (strlen(c.specialitate) + 1));
	strcpy(nou->inf.specialitate, c.specialitate);

	nou->inf.diagnostic = (char*)malloc(sizeof(char) * (strlen(c.diagnostic) + 1));
	strcpy(nou->inf.diagnostic, c.diagnostic);

	nou->inf.pretConsultatie = c.pretConsultatie;
	nou->next = NULL;
	if (*cap == NULL) {
		*cap = nou;
	}
	else
	{
		NodLS* temp = *cap;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = nou;
	}
}
void inserareLP(NodLp** capLP, NodLS* capLS) {
	NodLp* nou = (NodLp*)malloc(sizeof(NodLp));
	nou->inf = capLS;
	nou->next = NULL;
	if (*capLP == NULL) {
		*capLP = nou;
	}
	else
	{
		NodLp* temp = *capLP;
		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = nou;
	}
}

int valoareTotalaConsultatie(NodLp* capLP, char *specializare) {
	int total = 0;
	if (!capLP)
	{
		return total;
	}
	while (capLP!=NULL) {
		NodLS* temp = capLP->inf;
			while (temp) {
				if (strcmp(temp->inf.specialitate, specializare) == 0) {
				total += temp->inf.pretConsultatie;
			}
				temp = temp->next;
		}
		capLP = capLP->next;
	}
	return total;
}

void modificaPretConsultatie(NodLp* capNodLP, char *dataConsultatie, int noulPret) {
	while (capNodLP != NULL) {
		NodLS* temp = capNodLP->inf;
		while (temp != NULL) {
			if (strcmp(temp->inf.dataConsultatie, dataConsultatie) == 0)
			{
				temp->inf.pretConsultatie = noulPret;
			}
			temp = temp->next;
		}
		capNodLP = capNodLP->next;
	}

}

NodLp* stergereConsultatie(NodLp* capNodLP, char* diagnostic) {
	NodLp* currentLP = capNodLP;
	while (currentLP != NULL) {
		NodLS* currentLS = currentLP->inf;
		NodLS* prevLS = NULL;
		while (currentLS != NULL) {
			if (currentLS->inf.diagnostic==diagnostic) {
				NodLS* temp = currentLS;
				if (prevLS == NULL) {
					currentLP->inf = currentLS->next;
				}
				else {
					prevLS->next = currentLS->next;
				}
				free(currentLS->inf.dataConsultatie);
				free(currentLS->inf.numeMedic);
				free(currentLS->inf.specialitate);
				free(currentLS->inf.diagnostic);
				free(currentLS);
				currentLS = temp->next;
			}
			else
			{
				prevLS = currentLS;
				currentLS = currentLS->next;

			}
		}
		currentLP = currentLP->next;
	}
	return capNodLP;

}

void obtineConsultatiiDupaPrag(NodLp* capLP, Consultatie*arr, int pragPret, int* sizeArr) {
	while (capLP!=NULL) {
		NodLS* temp = capLP->inf;
		while (temp != NULL) {
			if (temp->inf.pretConsultatie > pragPret)
			{
				arr[*sizeArr].dataConsultatie = (char*)malloc(sizeof(char) * (strlen(temp->inf.dataConsultatie)));
				strcpy(arr[*sizeArr].dataConsultatie, temp->inf.dataConsultatie);
				arr[*sizeArr].numeMedic = (char*)malloc(sizeof(char) * (strlen(temp->inf.numeMedic)));
				strcpy(arr[*sizeArr].numeMedic, temp->inf.numeMedic);
				arr[*sizeArr].specialitate = (char*)malloc(sizeof(char) * (strlen(temp->inf.specialitate)));
				strcpy(arr[*sizeArr].specialitate, temp->inf.specialitate);
				arr[*sizeArr].diagnostic = (char*)malloc(sizeof(char) * (strlen(temp->inf.diagnostic)));
				strcpy(arr[*sizeArr].diagnostic, temp->inf.diagnostic);
				
				arr[*sizeArr].pretConsultatie = temp->inf.pretConsultatie;
				(*sizeArr)++;
			}
			temp = temp->next;
		}
		capLP = capLP->next;
	}
}

void traversareLS(NodLS* capLs) {
	NodLS* temp = capLs;
	while (temp != NULL) {
		printf("Data consultatie: %s \n", temp->inf.dataConsultatie);
		printf("Medic: %s \n", temp->inf.numeMedic);
		printf("Specialitate: %s \n", temp->inf.specialitate);
		printf("Diagnostic: %s \n", temp->inf.diagnostic);
		printf("Pret: %d \n", temp->inf.pretConsultatie);
		printf("\n");
		temp = temp->next;
	}
}

void traversareLP(NodLp* capLP) {
	while (capLP != NULL) {
		NodLp* temp = capLP->inf;
		traversareLS(temp);
		capLP = capLP->next;
	}
}

void dezalocareNodLS(NodLS* capLs) {
	NodLS* temp = capLs;
	while (temp != NULL) {
		NodLS* temp2 = temp->next;
		free(temp->inf.dataConsultatie);
		free(temp->inf.numeMedic);
		free(temp->inf.specialitate);
		free(temp->inf.diagnostic);
		free(temp);
		temp = temp2;
	}

}
void dezalocareNodLP(NodLp* capLP) {
	NodLp* temp = capLP;
	while (temp != NULL) {
		NodLp* temp2 = temp->next;
		dezalocareNodLS(temp->inf);
		free(temp);
		temp = temp2;
	}
	
}
void main() {
	int nr;
	NodLp* capLp = NULL;
	NodLS* capLS = NULL;
	Consultatie c;
	char buffer[30];
	FILE* f = fopen("consultatii.txt", "r");
	fscanf(f, "%d", &nr);
	for (int i = 0; i < nr; i++) {
		fscanf(f, "%s", buffer);
		c.dataConsultatie = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
		strcpy(c.dataConsultatie, buffer);

		fscanf(f, "%s", buffer);
		c.numeMedic = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
		strcpy(c.numeMedic, buffer);

		fscanf(f, "%s", buffer);
		c.specialitate = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
		strcpy(c.specialitate, buffer);

		fscanf(f, "%s", buffer);
		c.diagnostic = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
		strcpy(c.diagnostic, buffer);
		fscanf(f, "%d", &c.pretConsultatie);
		inserareNod(&capLS, c);
		free(c.dataConsultatie);
		free(c.numeMedic);
		free(c.diagnostic);
		free(c.specialitate);
		
	}
	fclose(f);
	inserareLP(&capLp, capLS);

	traversareLP(capLp);
	printf("\n----------------------------\n");
	int valoare = valoareTotalaConsultatie(capLp, "Urologie");
	printf("Valoare totala=%d", valoare);

	printf("\n----------------------------\n");
	modificaPretConsultatie(capLp, "2023-06-30", 50);
	traversareLP(capLp);

	printf("\n----------------------------\n");

	capLp=stergereConsultatie(capLp, "DiabetTip2");
	traversareLP(capLp);
	printf("\n----------------------------\n");
	
	Consultatie* vect = (Consultatie*)malloc(sizeof(Consultatie) * nr);
	int nrElem = 0;
	 obtineConsultatiiDupaPrag(capLp, vect,100, &nrElem);
	for (int i = 0; i < nrElem; i++) {
		printf("Data consultatie: %s \n", vect[i].dataConsultatie);
		printf("Medic: %s \n", vect[i].numeMedic);
		printf("Specialitate: %s \n", vect[i].specialitate);
		printf("Diagnostic: %s \n", vect[i].diagnostic);
		printf("Pret: %d \n", vect[i].pretConsultatie);
		printf("\n");
	}
	for (int i = 0; i < nrElem; i++) {
		free(vect[i].dataConsultatie);
		free(vect[i].numeMedic);
		free(vect[i].specialitate);
		free(vect[i].diagnostic);

	}
	free(vect);
	
	dezalocareNodLP(capLp);
}