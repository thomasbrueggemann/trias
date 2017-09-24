//
// Created by thomas on 24.09.17.
//

#include "triangle.h"

/// CONSTRUCTOR
/// \param _p0
/// \param _p1
/// \param _p2
Triangle::Triangle(Node _p0, Node _p1, Node _p2)
{
	// add nodes to vector
	this->nodes.push_back(_p0);
	this->nodes.push_back(_p1);
	this->nodes.push_back(_p2);

	// construct edges from nodes
	Edge e0(_p0, _p1);
	this->edges.push_back(e0);

	Edge e1(_p1, _p2);
	this->edges.push_back(e1);

	Edge e2(_p2, _p0);
	this->edges.push_back(e2);

	// create a circumscribed circle of this triangle.
	// the circumcircle of a triangle is the circle which has the three vertices of the triangle lying on its circumference.
	int ax = _p1.x - _p0.x;
	int ay = _p1.y - _p0.y;
	int bx = _p2.x - _p0.x;
	int by = _p2.y - _p0.y;

	double m = _p1.x * _p1.x - _p0.x * _p0.x + _p1.y * _p1.y - _p0.y * _p0.y;
	double u = _p2.x * _p2.x - _p0.x * _p0.x + _p2.y * _p2.y - _p0.y * _p0.y;
	double s = 1.0 / (2.0 * (double)(ax * by) - (double)(ay * bx));

	this->circle.x = int((double)((_p2.y - _p0.y) * m + (_p0.y - _p1.y) * u) * s);
	this->circle.y = int((double)((_p0.x - _p2.x) * m + (_p1.x - _p0.x) * u) * s);

	// calculate the distance between the node points and the triangle circumcircle.
	int dx := _p0.x - this->circle.x;
	int dy := _p0.y - this->circle.y;

	this->circle.radius = dx * dx + dy * dy;
}
