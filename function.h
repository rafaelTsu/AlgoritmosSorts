#ifndef _TIMER_
#define _TIMER_

//Insertion Sort
void insertion(int *v, int n);

//Merge Sort
void merge(int *v, int ini, int meio, int fim);

void mergesort_recursao(int *v, int ini, int fim);

void mergesort(int *v, int n);

//Selection Sort
void troca(int *num1, int *num2);

void selection(int *v, int n);

//Heap Sort
int heap_left(int pai);

int heap_right(int pai);

void max_heapify(int *v, int n, int i);

void build_max_heap(int *v, int n);

void heapsort(int *v, int n);

//Quick Sort
void quicksort(int *v, int n);

void quick(int *v, int ini, int fim);

int partition(int *v, int ini, int fim);

//Counting Sort
void counting(int *v, int n);

//Retorna média do tempo
double calculaMedia(double *v, int n);

//Inverte vetor
void inverter_lista(int *v, int n);

//Embaralha vetpr
void embaralhar(int *v, int n);

#endif