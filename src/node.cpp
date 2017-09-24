//
// Created by thomas on 24.09.17.
//

#include "node.h"

/// CONSTRUCTOR
/// \param _x
/// \param _y
Node::Node(int _x, int _y)
	: x(_x), y(_y)
{

}

/// EQUAL OPERATOR
/// \param _p
/// \return
bool Node::operator==(const Node& _p)
{
	double dx = this->x - _p.x;
	double dy = this->y - _p.y;

	if (dx < 0)
	{
		dx = -dx;
	}

	if (dy < 0)
	{
		dy = -dy;
	}

	if(double(dx) < 0.0001 && double(dy) < 0.0001)
	{
		return true;
	}

	return false;
}