#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "function.h"

int main(){
	int v[] = {1, 5, 2, 6, 8, 4, 3, 2, 0, 22, 44, 21};

	counting(v, 12);
	//embaralhar(v, 12);

	for(int i = 0; i< 12; i++){
		printf("%d ", v[i]);
	}

}