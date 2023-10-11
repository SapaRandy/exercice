#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

struct Place{
	int id;
	int dim;
	int prix;
	bool dispo;
};

int sortieParking(int a) {
	int randomNumber = (rand() % 6);
	printf("%d", randomNumber);
	if (randomNumber > 3) {
		randomNumber = (rand() % 14);
		printf("Un vehicule est parti du parking \n");
	}
	return a;
}

void cagnotte(int prix, int *recette) {
	recette = recette + prix;
}


int main() {
	struct Place PlaceParking[15];
	srand(time(NULL));
	const int max_place = 10;
	signed int parking = 5;
	signed int i;
	signed int a = 0;
	signed int b = 5;
	signed int c = 10;
	int *recette = 0;
	

	for (i = 0; i <= 3; i++) {
		if (i <= 4) {
			PlaceParking[i].id = i;
			PlaceParking[i].dim = 1;
			PlaceParking[i].prix = 5;
			PlaceParking[i].dispo = true;
		}
		else if (i <= 9) {
			PlaceParking[i].id = i;
			PlaceParking[i].dim = 2;
			PlaceParking[i].prix = 10;
			PlaceParking[i].dispo = true;
		}
		else {
			PlaceParking[i].id = i;
			PlaceParking[i].dim = 3;
			PlaceParking[i].prix = 15;
			PlaceParking[i].dispo = true;
		}

	}

	int choix=1;
	
	for (i = 0; i < 20; i++) {
		printf("Quel est votre vehicule? \n");
		printf("1) Une moto \n2) Une voiture \n3) Un camion  \nChoix: ");
		scanf("%d", &choix);
		printf("\n");


		switch (choix) {
		case 1:
			while (a<=9) {
				if (PlaceParking[a].dispo == true)  {
					PlaceParking[a].dispo = false;
					printf("La moto a ete garee a la place numero %d \n", PlaceParking[a].id);
					cagnotte(PlaceParking[a].prix, recette);
					break;
				}
				a++;
			}
			if (a > 9) {
				printf("Il n'y a plus de place dans le parking \n");
			}
			break;
		case 2:
			while (b <= 14) {
				if (PlaceParking[b].dispo == true) {
					PlaceParking[b].dispo = false;
					printf("La voiture a ete garee a la place numero %d \n", PlaceParking[b].id);
					cagnotte(PlaceParking[a].prix, recette);
					break;
				}
				b++;
			}
			if (b > 14) {
				printf("Il n'y a plus de place dans le parking \n");
			}
			break;
		case 3:
			while (c <= 14) {
				if (PlaceParking[c].dispo == true) {
					PlaceParking[c].dispo = false;
					printf("La camion a ete garee a la place numero %d \n", PlaceParking[c].id);
					cagnotte(PlaceParking[a].prix, recette);
					break;
				}
				c++;
			}
			if (c > 14) {
				printf("Il n'y a plus de place dans le parking \n");
			}
			break;
		default:
			printf("Votre vehicule n'est pas reconnu \n");
		}

			parking = sortieParking(parking);
			PlaceParking[parking].dispo = true;
			
	}
	printf("La recette du jour est : %d \n ", recette);
	return 0;
}
