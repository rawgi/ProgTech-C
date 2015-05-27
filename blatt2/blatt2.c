#include <stdio.h>
#include <math.h>
#include "blatt2.h"

void increase(int *xp){
	*xp += 1;
}

double norm(struct Vertex v){
	return sqrt(v.x*v.x+v.y*v.y);
}

void scale(struct Vertex *this, double s){
	(*this).x *= s;
	(*this).y *= s;
}

int main(){
	int i = 1;
	increase(&i);
	printf("2: %d \n",i);
	increase(&i);
	printf("3: %d \n",i);
	increase(&i);
	printf("4: %d \n",i);

	struct Vertex a;
	a.x = 2;
	a.y = 3;
	printf("Betrag des Vertex x:%lf y:%lf : %lf \n", a.x, a.y, norm(a));
	scale(&a,2);
	printf("Um 2 skaliert: x:%lf y:%lf \n", a.x, a.y);
	return 0;
}


