//
// Created by thomas on 24.09.17.
//

#ifndef TRIAS_EDGE_H
#define TRIAS_EDGE_H

#include <vector>
#include "node.h"

using namespace std;

class Edge {
 public:
	vector<Node> nodes;

	Edge(Node _p0, Node _p1);
	bool operator==(const Edge& _edge);
};

#endif //TRIAS_EDGE_H
