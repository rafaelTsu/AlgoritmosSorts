#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "function.h"

int main(){
	int *v_selection = NULL, *v_insertion = NULL ,*v_merge = NULL, *v_quick = NULL, *v_heap = NULL; //, *v_counting = NULL;
	double *media_selection = NULL, *media_insertion = NULL, *media_merge = NULL, *media_quick = NULL, *media_heap = NULL; //, *media_counting = NULL;
	int random, nearly_sorted, sorted, reverse;
	clock_t begin, end;
	int inc, fim, stp, rpt, cont;
	FILE *output;

	srand(time(NULL));

	output = fopen("output.txt", "w");

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
	media_merge = calloc(rpt, sizeof(double));
	media_quick = calloc(rpt, sizeof(double));
	media_heap	= calloc(rpt, sizeof(double));

	printf("\n[[RANDOM]]\n");
	printf("   n    Selection       Insertion       Merge           Quick           Heap             Counting\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	fprintf(output, "\n[[RANDOM]]\n");
	fprintf(output, "   n    Selection       Insertion       Merge           Quick           Heap             Counting\n");
	fprintf(output, "-------------------------------------------------------------------------------------------------\n");
	random = inc;

	while(random <= fim){
		printf("%d", random);
		fprintf(output, "%d", random);
		cont = 0;
		v_selection = calloc(random, sizeof(int));	
		v_insertion = calloc(random, sizeof(int));
		v_merge = malloc(random * sizeof(int));
		v_quick = malloc(random * sizeof(int));
		v_heap = malloc(random * sizeof(int));

		while(cont < rpt){
			for(int i = 0; i<random; i++){
				v_selection[i] = rand();
				v_insertion[i] = v_selection[i];
				v_merge[i] = v_selection[i];
				v_quick[i] = v_selection[i];
				v_heap[i] = v_selection[i];
			}

			begin = clock();
			selection(v_selection, random);
			end = clock();

			media_selection[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			begin = clock();
			insertion(v_insertion, random);
			end = clock();

			media_insertion[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			begin = clock();
			mergesort(v_merge, random);
			end = clock();

			media_merge[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			begin = clock();
			quicksort(v_quick, random);
			end = clock();

			media_quick[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			begin = clock();
			heapsort(v_heap, random);
			end = clock();

			media_heap[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			cont++;
		}

		printf("	%f	", calculaMedia(media_selection, rpt));
		printf("%f", calculaMedia(media_insertion, rpt));
		printf("	%f", calculaMedia(media_merge, rpt));
		printf("	%f", calculaMedia(media_quick, rpt));
		printf("	%f\n", calculaMedia(media_heap, rpt));
		fprintf(output, "	%f	", calculaMedia(media_selection, rpt));
		fprintf(output, "%f", calculaMedia(media_insertion, rpt));
		fprintf(output, "	%f", calculaMedia(media_merge, rpt));
		fprintf(output, "	%f", calculaMedia(media_quick, rpt));
		fprintf(output, "	%f\n", calculaMedia(media_heap, rpt));

		random = random + stp;

		free(v_selection);
		free(v_insertion);
		free(v_merge);
		free(v_quick);
		free(v_heap);
	}

	printf("\n[[REVERSE]]\n");
	printf("   n    Selection       Insertion       Merge           Quick           Heap             Counting\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	fprintf(output, "\n[[REVERSE]]\n");
	fprintf(output, "   n    Selection       Insertion       Merge           Quick           Heap             Counting\n");
	fprintf(output, "-------------------------------------------------------------------------------------------------\n");
	reverse = inc;

	while(reverse <= fim){
		printf("%d", reverse);
		fprintf(output, "%d", reverse);
		cont = 0;
		v_selection = calloc(reverse, sizeof(int));	
		v_insertion = calloc(reverse, sizeof(int));
		v_merge = malloc(reverse * sizeof(int));
		v_quick = malloc(reverse * sizeof(int));
		v_heap = malloc(reverse * sizeof(int));

		while(cont < rpt){
			for(int i = 0; i<reverse; i++){
				v_selection[i] = rand();
			}
			mergesort(v_selection, reverse);
			inverter_lista(v_selection, reverse);

			for(int i = 0; i<reverse; i++){
				v_insertion[i] = v_selection[i];
				v_merge[i] = v_selection[i];
				v_quick[i] = v_selection[i];
				v_heap[i] = v_selection[i];
			}

			begin = clock();
			selection(v_selection, reverse);
			end = clock();

			media_selection[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			begin = clock();
			insertion(v_insertion, reverse);
			end = clock();

			media_insertion[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			begin = clock();
			mergesort(v_merge, reverse);
			end = clock();

			media_merge[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			begin = clock();
			quicksort(v_quick, reverse);
			end = clock();

			media_quick[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			begin = clock();
			heapsort(v_heap, reverse);
			end = clock();

			media_heap[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			cont++;
		}

		printf("	%f	", calculaMedia(media_selection, rpt));
		printf("%f", calculaMedia(media_insertion, rpt));
		printf("	%f", calculaMedia(media_merge, rpt));
		printf("	%f", calculaMedia(media_quick, rpt));
		printf("	%f\n", calculaMedia(media_heap, rpt));
		fprintf(output, "	%f	", calculaMedia(media_selection, rpt));
		fprintf(output, "%f", calculaMedia(media_insertion, rpt));
		fprintf(output, "	%f", calculaMedia(media_merge, rpt));
		fprintf(output, "	%f", calculaMedia(media_quick, rpt));
		fprintf(output, "	%f\n", calculaMedia(media_heap, rpt));

		reverse = reverse + stp;

		free(v_selection);
		free(v_insertion);
		free(v_merge);
		free(v_quick);
		free(v_heap);
	}

	printf("\n[[SORTED]]\n");
	printf("   n    Selection       Insertion       Merge           Quick           Heap             Counting\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	fprintf(output, "\n[[SORTED]]\n");
	fprintf(output, "   n    Selection       Insertion       Merge           Quick           Heap             Counting\n");
	fprintf(output, "-------------------------------------------------------------------------------------------------\n");
	sorted = inc;

	while(sorted <= fim){
		printf("%d", sorted);
		fprintf(output, "%d", sorted);
		cont = 0;
		v_selection = calloc(sorted, sizeof(int));	
		v_insertion = calloc(sorted, sizeof(int));
		v_merge = malloc(sorted * sizeof(int));
		v_quick = malloc(sorted * sizeof(int));
		v_heap = malloc(sorted * sizeof(int));

		while(cont < rpt){
			for(int i = 0; i<sorted; i++){
				v_selection[i] = rand();
			}
			mergesort(v_selection, sorted);

			for(int i = 0; i<sorted; i++){
				v_insertion[i] = v_selection[i];
				v_merge[i] = v_selection[i];
				v_quick[i] = v_selection[i];
				v_heap[i] = v_selection[i];
			}

			begin = clock();
			selection(v_selection, sorted);
			end = clock();

			media_selection[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			begin = clock();
			insertion(v_insertion, sorted);
			end = clock();

			media_insertion[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			begin = clock();
			mergesort(v_merge, sorted);
			end = clock();

			media_merge[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			begin = clock();
			quicksort(v_quick, sorted);
			end = clock();

			media_quick[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			begin = clock();
			heapsort(v_heap, sorted);
			end = clock();

			media_heap[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			cont++;
		}

		printf("	%f	", calculaMedia(media_selection, rpt));
		printf("%f", calculaMedia(media_insertion, rpt));
		printf("	%f", calculaMedia(media_merge, rpt));
		printf("	%f", calculaMedia(media_quick, rpt));
		printf("	%f\n", calculaMedia(media_heap, rpt));
		fprintf(output, "	%f	", calculaMedia(media_selection, rpt));
		fprintf(output, "%f", calculaMedia(media_insertion, rpt));
		fprintf(output, "	%f", calculaMedia(media_merge, rpt));
		fprintf(output, "	%f", calculaMedia(media_quick, rpt));
		fprintf(output, "	%f\n", calculaMedia(media_heap, rpt));

		sorted = sorted + stp;

		free(v_selection);
		free(v_insertion);
		free(v_merge);
		free(v_quick);
		free(v_heap);
	}

	printf("\n[[NEARLY SORTED]]\n");
	printf("   n    Selection       Insertion       Merge           Quick           Heap             Counting\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	fprintf(output, "\n[[NEARLY SORTED]]\n");
	fprintf(output, "   n    Selection       Insertion       Merge           Quick           Heap             Counting\n");
	fprintf(output, "-------------------------------------------------------------------------------------------------\n");
	nearly_sorted = inc;

	while(nearly_sorted <= fim){
		printf("%d", nearly_sorted);
		fprintf(output, "%d", nearly_sorted);
		cont = 0;
		v_selection = calloc(nearly_sorted, sizeof(int));	
		v_insertion = calloc(nearly_sorted, sizeof(int));
		v_merge = malloc(nearly_sorted * sizeof(int));
		v_quick = malloc(nearly_sorted * sizeof(int));
		v_heap = malloc(nearly_sorted * sizeof(int));

		while(cont < rpt){
			for(int i = 0; i<nearly_sorted; i++){
				v_selection[i] = rand();
			}
			mergesort(v_selection, nearly_sorted);
			embaralhar(v_selection, nearly_sorted);

			for(int i = 0; i<nearly_sorted; i++){
				v_insertion[i] = v_selection[i];
				v_merge[i] = v_selection[i];
				v_quick[i] = v_selection[i];
				v_heap[i] = v_selection[i];
			}

			begin = clock();
			selection(v_selection, nearly_sorted);
			end = clock();

			media_selection[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			begin = clock();
			insertion(v_insertion, nearly_sorted);
			end = clock();

			media_insertion[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			begin = clock();
			mergesort(v_merge, nearly_sorted);
			end = clock();

			media_merge[cont] = ((double)(end - begin))/CLOCKS_PER_SEC;

			begin = clock();
			quicksort(v_quick, nearly_sorted);
			end = clock();

			media_quick[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			begin = clock();
			heapsort(v_heap, nearly_sorted);
			end = clock();

			media_heap[cont] = (double)(end - begin)/CLOCKS_PER_SEC;

			cont++;
		}

		printf("	%f	", calculaMedia(media_selection, rpt));
		printf("%f", calculaMedia(media_insertion, rpt));
		printf("	%f", calculaMedia(media_merge, rpt));
		printf("	%f", calculaMedia(media_quick, rpt));
		printf("	%f\n", calculaMedia(media_heap, rpt));
		fprintf(output, "	%f	", calculaMedia(media_selection, rpt));
		fprintf(output, "%f", calculaMedia(media_insertion, rpt));
		fprintf(output, "	%f", calculaMedia(media_merge, rpt));
		fprintf(output, "	%f", calculaMedia(media_quick, rpt));
		fprintf(output, "	%f\n", calculaMedia(media_heap, rpt));

		nearly_sorted = nearly_sorted + stp;

		free(v_selection);
		free(v_insertion);
		free(v_merge);
		free(v_quick);
		free(v_heap);
	}
	fclose(output);

	return 0;
}