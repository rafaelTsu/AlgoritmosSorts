#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *v, int ini, int meio, int fim){
	int left = meio - ini + 1;
	int right = fim - meio;

	int temp_left[left];
	int temp_right[right];

	int i, j, k;

	for(int i = 0; i < left; i++){
		temp_left[i] = v[ini + i];
	}

	for(int j = 0; j < right; j++){
		temp_right[j] = v[meio + j + 1];
	}

	for(i = 0, j = 0, k = ini; k<=fim; k++){
		if((i<left) && (j>=right || temp_left[i]<=temp_right[j])){
			v[k] = temp_left[i];
			i++;
		}
		else{
			v[k] = temp_right[j];
			j++;
		}
	}
}

void mergesort_recursao(int *v, int ini, int fim){
	if(ini < fim){
		int meio = ini + (fim-ini)/2;

		mergesort_recursao(v, ini, meio);
		mergesort_recursao(v, meio + 1, fim);
		
		merge(v, ini, meio, fim);
	}
}

void mergesort(int *v, int n){
	mergesort_recursao(v, 0, n-1);
}

int main(){
	int *v_merge = NULL;
	double *media_merge = NULL;
	int random;
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

	media_merge = calloc(rpt, sizeof(double));

	printf("\n[[RANDOM]]\n");
	printf("   n    Merge\n");
	printf("-------------\n");
	random = inc;

	while(random <= fim){
		printf("%d", random);
		cont = 0;
		v_merge = calloc(random, sizeof(int));

		while(cont < rpt){
			for(int i = 0; i<random; i++){
				v_merge[i] = rand();
			}

			begin = clock();
			mergesort(v_merge, random);
			end = clock();

			media_merge[cont] = ((double)(end - begin))/CLOCKS_PER_SEC;

			cont++;
		}

		printf("	%f\n", calculaMedia(media_merge, rpt));

		random = random + stp;

		free(v_merge);
	}