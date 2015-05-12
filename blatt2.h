#ifndef __BLATT2_H__
#define __BLATT2_H__

struct Vertex{
	double x;
	double y;
};
void increase(int *xp);
double norm(struct Vertex v);
void scale(struct Vertex* this, double s);

#endif
