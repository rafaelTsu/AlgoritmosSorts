#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

/*Merge Sort - arrumar*/
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
int filho_esq(int pai){
	return pai*2 + 1;
}

int filho_dir(int pai){
	return pai*2 + 2;
}

int heap_pai(int filho){
	return(filho-0.5)/2;
}

void max_heapify(int *v, int pai, int n){
	
}




/*Quick Sort*/





/*Counting Sort*/





/*Retorna média*/
double calculaMedia(double *v, int n){
	double media = 0.0;
	for(int i = 0; i<n; i++){
		media = media + v[i];
	}
	return media/n;
}