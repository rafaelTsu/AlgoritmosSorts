#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "function.h"

/*Merge Sort*/
void mergesort(){

}

void merge(){

}

/*Insertion Sort*/
void insertion(int n, int *v){
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