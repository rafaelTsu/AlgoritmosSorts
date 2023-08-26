#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "function.h"

int main(){
	int v[10] = {1,5,8,3,2,33,6,9,18,4};

	clock_t begin, end;

	begin = clock();
	insertion(10,v);
	end = clock();

	for(int i = 0; i<10; i++){
		printf("%d ", v[i]);
	}

	double total = (double)(end - begin)/CLOCK_PER_SEC;

	printf("Tempo de execução insertion: %fs", total);
}