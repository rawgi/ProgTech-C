#include <stdio.h>

void kreuz(int x){
	int spalte = 1;
	int zeile = 1;	
	
	while(zeile <= x){
		while(spalte <= x){
			if(spalte == zeile || spalte == x+1-zeile){
				printf("X");
			}else{
				printf(" ");
			}
		spalte++;
		}
	spalte = 1;
	printf("\n");
	zeile++;
	}
}
