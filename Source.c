#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

const static int MAX_PLACE = 15;

struct Place {
	int id;
	int dim;
	int prix;
	bool dispo;
};

void entree(struct Place PlaceParking[], int a, int taille, int taille2, int *recette) {
	int prix;
	while (a <= MAX_PLACE) {
		if (PlaceParking[a].dim == taille || PlaceParking[a].dim == taille2) {
			if (PlaceParking[a].dispo == true) {
				PlaceParking[a].dispo = false;
				printf("Le vehicule a ete garee a la place numero %d \n", PlaceParking[a].id);
				prix = cagnotte(PlaceParking,recette,a);
				*recette = *recette + prix;
				break;
			}
			else {
				a++;
			}
		}
		else {
			a++;
		}
	}
	if (a > MAX_PLACE) {
		printf("Il n'y a plus de place dans le parking \n");
	}
}


void sortieParking(struct Place PlaceParking[] ) {
	int randomNumber = (rand() % 6);
	int placeNumber=0;
	int prix;
	if (randomNumber > 3) {
		do {
			placeNumber = (rand() % 15);
		} while (PlaceParking[placeNumber].dispo != false);
		PlaceParking[placeNumber].dispo = true;
		printf("Un vehicule est parti de la place %d \n", PlaceParking[placeNumber].id);
	}
}

int cagnotte(struct Place PlaceParking[], int recette,int a) {
	int prix = PlaceParking[a].prix;
	recette =+ prix;
	return recette;
}



int main() {

	struct Place PlaceParking[15] = { 0 };
	srand(time(NULL));
	signed int i;
	int choix = 1;
	int recette = 0;
	int* gain = &recette;


	for (i = 0; i < MAX_PLACE; i++) {
		PlaceParking[i].id = i+1;
		PlaceParking[i].dispo = true;
		if (i <= 4) {
			PlaceParking[i].dim = 1;
			PlaceParking[i].prix = 5;
		}
		else if (i <= 9) {
			PlaceParking[i].dim = 2;
			PlaceParking[i].prix = 10;
		}
		else {
			PlaceParking[i].dim = 3;
			PlaceParking[i].prix = 15;
		}

	}
	
	for (i = 0; i < 10; i++) {
		printf("Quel est votre vehicule? \n");
		printf("1) Une moto \n2) Une voiture \n3) Un camion  \nChoix: ");
		scanf("%d", &choix);


		switch (choix) {
		case 1:
			entree(PlaceParking,0,1,2,gain);
			break;
	
		case 2:
			entree(PlaceParking,0,2,3,gain);
			break;

		case 3:
			entree(PlaceParking,0,3,3,gain);
			break;

		default:
			printf("Votre vehicule n'est pas reconnu \n");
		}

		sortieParking(PlaceParking);
		printf("\n");
	}
	printf("La recette du jour est : %d euros \n ", recette);
	return 0;
}
