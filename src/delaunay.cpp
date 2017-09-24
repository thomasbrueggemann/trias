//
// Created by thomas on 24.09.17.
//

#include "delaunay.h"

/// CONSTRUCTOR
/// \param _width
/// \param _height
Delaunay::Delaunay(int _width, int _height)
	: width(_width), height(_height)
{
	this->triangles.clear();
}
