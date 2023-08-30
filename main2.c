#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "function.h"

int main(){
	int *v_selection = NULL, *v_insertion = NULL; //*v_merge = NULL, *v_quick = NULL, *v_heap = NULL, *v_counting = NULL;
	double *v_media = NULL;
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

	v_media = calloc(rpt, sizeof(double));

	printf("\n[[RANDOM]]\n");
	printf("   n    Selection       Insertion      Merge      Heap      Quick      Counting\n");
	printf("-------------------------------------------------------------------------------\n");


	while(inc <= fim){
		printf("%d", inc);
		cont = 0;
		v_selection = calloc(inc, sizeof(int));	
		v_insertion = calloc(inc, sizeof(int));

		while(cont < rpt){
			for(int i = 0; i<inc; i++){
				v_selection[i] = rand() % 5000;
				v_insertion[i] = v_selection[i];
			}

			begin = clock();
			selection(v_selection, inc);
			end = clock();

			v_media[cont] = (double)(end - begin)/CLOCKS_PER_SEC;
			cont++;
		}

		cont = 0;

		printf("	%f	", calculaMedia(v_media, rpt));

		while(cont < rpt){
			begin = clock();
			insertion(v_insertion, inc);
			end = clock();

			v_media[cont] = (double)(end - begin)/CLOCKS_PER_SEC;
			cont++;
		}

		printf("%f\n", calculaMedia(v_media, rpt));


		inc = inc + stp;
		free(v_selection);
		free(v_insertion);
	}

	return 0;
}