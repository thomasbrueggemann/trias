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

	Delaunay(int _width, int _height);
};

#endif //TRIAS_DELAUNAY_H
