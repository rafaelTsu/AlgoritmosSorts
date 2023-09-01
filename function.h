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

//Retorna média do tempo
double calculaMedia(double *v, int n);

#endif