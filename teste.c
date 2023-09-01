#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(){
	int v[10] = {5,6,2,4,1,8,5,3,2,1};

	mergesort(v,10);

	for(int i = 0; i<10; i++){
		printf("%d ", v[i]);
	}
}