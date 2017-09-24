//
// Created by thomas on 24.09.17.
//

#include "edge.h"

/// CONSTRUCTOR
/// \param _p0
/// \param _p1
Edge::Edge(Node _p0, Node _p1)
{
	this->nodes.clear();
	this->nodes.push_back(_p0);
	this->nodes.push_back(_p1);
}

/// EQUAL OPERATOR
/// \param _edge
/// \return
bool Edge::operator==(const Edge& _edge)
{
	vector<Node> na = this->nodes;
	vector<Node> nb = _edge.nodes;

	Node na0 = na[0];
	Node na1 = na[1];
	Node nb0 = nb[0];
	Node nb1 = nb[1];

	if (na0 == nb0 && na1 == nb1 || na0 == nb1 && na1 == nb0)
	{
		return true;
	}

	return false;
}
