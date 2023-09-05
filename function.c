#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

#define MAX 500001

/*Merge Sort*/
void merge(int *v, int ini, int meio, int fim){
	int *temp_left, *temp_right;
	int left = meio - ini + 1;
	int right = fim - meio;

	temp_left = calloc(left, sizeof(int));
	temp_right = calloc(right, sizeof(int));

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


/*Insertion Sort*/
void insertion(int *v, int n){
	int key,i,j;
	for(j = 2; j<n; j++){
		key = v[j];
		i = j-1;
		while(i>0 && v[i]>key){
			v[i+1] = v[i];
			i = i-1;
		}
		v[i+1] = key;
	}
}

/*Selection Sort*/
void troca(int *num1, int *num2){
	int aux = *num1;
	*num1 = *num2;
	*num2 = aux;
}

void selection(int *v, int n){
	int min;
	for(int i = 0; i<n-1; i++){
		min = i;
		for(int j = i+1; j<n; j++){
			if(v[min]>v[j]){
				min = j;
			}
		}
		if(min != i){
			troca(&v[i],&v[min]);
		}
	}
}

/*Heap Sort*/
int heap_left(int pai){
	return 2*pai + 1;
}

int heap_right(int pai){
	return 2*pai + 2;
}

void max_heapify(int *v, int n, int i){
	int maior = i;
	int left = heap_left(i);
	int right = heap_right(i);

	if(left < n && v[left] > v[maior]){
		maior = left;
	}
	if(right < n && v[right] > v[maior]){
		maior = right;
	}
	if(maior!=i){
		troca(&v[i],&v[maior]);
		max_heapify(v, n, maior);
	}
}

void build_max_heap(int *v, int n){
	for(int i = n/2; i>=0; i--){
		max_heapify(v, n, i);
	}
}

void heapsort(int *v, int n){
	build_max_heap(v, n);

	for(int i = n-1; i>0; i--){
		troca(&v[0], &v[i]);
		max_heapify(v, i, 0);
	}
}

/*Quick Sort*/
int partition(int *v, int ini, int fim) {
	int meio = (ini+fim)/2;
    int pivot = v[meio];
    int i = ini - 1;
    int j = fim + 1;

    while (1) {
        do{
            i++;
        }while (v[i] < pivot);

        do{
            j--;
        }while (v[j] > pivot);

        if (i >= j)
            return j;

        troca(&v[i], &v[j]);
    }
}

void quick(int *v, int ini, int fim) {
    if (ini < fim) {
        int p = partition(v, ini, fim);
        quick(v, ini, p);
        quick(v, p + 1, fim);
    }
}

void quicksort(int *v, int n){
	quick(v, 0, n-1);
}

/*Counting Sort*/
void counting(int *v, int n){
	int *count, index = 0;
	count = malloc(MAX * sizeof(int));
	for(int i = 0; i<MAX; i++){
		count[i] = 0;
	}

	for(int i = 0; i<n; i++){
		count[v[i]]++;
	}

	for(int i = 0; i < MAX; i++){
		while(count[i] > 0){
			v[index++] = i;
			count[i]--;
		}
	}
}

/*Retorna média*/
double calculaMedia(double *v, int n){
	double media = 0.0;
	for(int i = 0; i<n; i++){
		media = media + v[i];
	}
	return media/n;
}

/*Inverte vetor*/
void inverter_lista(int *v, int n){
	if(n>0){
		int *aux = calloc(n, sizeof(int));
		int cont = 0;

		for(int i = 0; i<n; i++){
			aux[i] = v[i];
		}

		for(int j = n-1; j >= 0; j--){
			v[cont++] = aux[j];
		}
	}
}

/*Embaralha vetor*/
void embaralhar(int *v, int n){
	srand(time(NULL));
	int index1, index2;
	int qtde = n * 0.1;
	for(int i = 0; i<qtde; i++){
		index1 = rand() % n;
		index2 = rand() % n;
		troca(&v[index1], &v[index2]);
	}
}