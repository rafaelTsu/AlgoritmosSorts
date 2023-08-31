#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "function.h"

int main(){
	int *v_selection = NULL, *v_insertion = NULL; //,*v_merge = NULL, *v_quick = NULL, *v_heap = NULL, *v_counting = NULL;
	double *media_selection = NULL, *media_insertion = NULL; //,*media_merge = NULL, *media_heap = NULL, *media_quick = NULL, *media_counting = NULL;
	int random, nearly_random, sorted, reverse;
	clock_t begin, end;
	int inc, fim, stp, rpt, cont;

	srand(time(NULL));

	printf("Digite o inicio do vetor: ");
	scanf("%d", &inc);

	printf("Digite o fim do vetor: ");
	scanf("%d", &fim);

	printf("Digite o intervalo entre dois vetores: ");
	scanf("%d", &stp);

	printf("Digite quantas vezes o vetor deve repetir: ");
	scanf("%d", &rpt);

	media_selection = calloc(rpt, sizeof(double));
	media_insertion = calloc(rpt, sizeof(double));

	printf("\n[[RANDOM]]\n");
	printf("   n    Selection       Insertion      Merge      Heap      Quick      Counting\n");
	printf("-------------------------------------------------------------------------------\n");
	random = inc;

	while(random <= fim){
		printf("%d", random);
		cont = 0;
		v_selection = calloc(random, sizeof(int));	
		v_insertion = calloc(random, sizeof(int));

		while(cont < rpt){
			for(int i = 0; i<random; i++){
				v_selection[i] = rand() % 7000;
				v_insertion[i] = v_selection[i];
			}

			begin = clock();
			selection(v_selection, random);
			end = clock();

			media_selection[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			begin = clock();
			insertion(v_insertion, random);
			end = clock();

			media_insertion[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			cont++;
		}

		printf("	%f	", calculaMedia(media_selection, rpt));
		printf("%f\n", calculaMedia(media_insertion, rpt));


		random = random + stp;
		free(v_selection);
		free(v_insertion);
	}

	printf("\n[[REVERSE]]\n");
	printf("   n    Selection       Insertion      Merge      Heap      Quick      Counting\n");
	printf("-------------------------------------------------------------------------------\n");
	reverse = inc;

	
	return 0;
}