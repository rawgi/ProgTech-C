#include <stdio.h>
#include "qsit.h"
#include "qsrek.h"
#include "kreuz.h"

int main(int argt, char **argv){
	printf("iterativ: \n");
	printf("quersumme von 4356: %d \n",quersummeIt(4356));

	printf("rekursiv: \n");
	printf("quersumme von 4356: %d \n",quersummeRek(4356));

	printf("kreuz mit 5 x: \n");
	kreuz(5);

	return 0;
}
