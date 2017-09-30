#ifndef TRIAS_EDGES_H
#define TRIAS_EDGES_H

#include <vector>
#include <Magick++.h>
#include <random>

#include "point.h"

#define POINT_RATE 0.875

using namespace std;
using namespace Magick;

class Edges {
 public:
	vector<Point> getEdgePoints(Image img, double threshold, int maxpoints);
};

#endif //TRIAS_EDGES_H
