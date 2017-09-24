//
// Created by thomas on 24.09.17.
//

#ifndef TRIAS_NODE_H
#define TRIAS_NODE_H

class Node {
 public:
	int x;
	int y;

	Node(int _x, int _y);
	bool operator==(const Node& _p);
};

#endif //TRIAS_NODE_H
