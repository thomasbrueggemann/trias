//
// Created by thomas on 24.09.17.
//

#ifndef TRIAS_TRIANGLE_H
#define TRIAS_TRIANGLE_H

#include <vector>

#include "node.h"
#include "edge.h"
#include "circle.h"

using namespace std;

class Triangle {
 public:
	vector<Node> nodes;
	vector<Edge> edges;
	Circle circle;

	Triangle(Node _p0, Node _p1, Node _p2);
};

#endif //TRIAS_TRIANGLE_H
