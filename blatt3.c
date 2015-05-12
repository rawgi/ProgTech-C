#include <stdio.h>
#include "blatt3.h"

double durchschnittQuersumme(int i){
	if(0 == i) return 0;
	int array[i];
	int x;
	for(x = 0; x<i; x++){
		array[x] = (x+1)*(x+1);
	}
	
	double result;
	for(x = 0; x<i; x++){
		result = result+array[x];
	}
	return result/i;
}

int main(){
	int x;
	do{
		printf("bitte zahl eingeben:\n");
		scanf("%d",&x);
		printf("durchschnitt: %f \n",durchschnittQuersumme(x));
	}while(x > 0);
	return 0;
}
