#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

/*Merge Sort - arrumar*/
void merge(int *v, int ini, int meio, int fim){
	int n1 = meio - ini + 1;
	int n2 = fim - meio;
	int v_esq[n1+1];
	int v_dir[n2+1];

	for(int i = 0; i<n1; i++){
		v_esq[i] = v[ini+i-1];
	}

	for(int j = 1; j<n2; j++){
		v_dir[j] = v[meio+j];
	}

	v_esq[n1+1] = 10000;
	v_dir[n2+1] = 10000;

	int i = 1, j = 1;

	for(int k = ini; k<fim; k++){
		if (v_esq[i] <= v_dir[j]){
			v[k] = v_esq[i];
			i++;
		}
		else{
			v[k] = v_dir[j];
			j++;
		}
	}
}

void mergesort(int *v, int ini, int fim){
	if(ini < fim){
		int meio = (ini+fim)/2;
		mergesort(v, ini, meio);
		mergesort(v, meio + 1, fim);
		merge(v, ini, meio, fim);
	}
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
	double media = 0;
	for(int i = 0; i<n; i++){
		media = media + v[i];
	}
	return media/n;
}