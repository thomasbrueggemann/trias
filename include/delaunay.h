#ifndef TRIAS_DELAUNAY_H
#define TRIAS_DELAUNAY_H

#include <vector>
#include "point.h"
#include "node.h"
#include "edge.h"
#include "triangle.h"

using namespace std;

class Delaunay
{
 private:
	int width;
	int height;
	vector<Triangle> triangles;

 public:
	Delaunay(int _width, int _height);
	void clear();
	void insert(vector<Point> points);
	vector<Triangle> getTriangles();
};

#endif //TRIAS_DELAUNAY_H
