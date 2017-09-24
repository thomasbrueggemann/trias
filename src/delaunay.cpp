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

/// Clear the delaunay triangles slice
void Delaunay::clear()
{
	Node p0(0, 0);
	Node p1(this->width, 0);
	Node p2(this->width, this->height);
	Node p3(0, this->height);

	Triangle t0(p0, p1, p2);
	this->triangles.push_back(t0);

	Triangle t1(p0, p2, p3);
	this->triangles.push_back(t1);
}

/// Insert new triangles into the delaunay triangles slice
/// \param points
void Delaunay::insert(vector<Point> points)
{
	vector<Edge> polygon;
	vector<Edge> edges;
	vector<Triangle> temps;

	for (auto point : points)
	{
		int x = point.x;
		int y = point.y;

		edges.clear();
		temps.clear();

		for (auto t : this->triangles)
		{
			// check whether the points are inside the triangle circumcircle.
			int dx = t.circle.x - x;
			int dy = t.circle.y - y;
			int distSq = dx * dx + dy * dy;

			if (distSq < t.circle.radius)
			{
				// save triangle edges in case they are included.
				edges.push_back(t.edges[0]);
				edges.push_back(t.edges[1]);
				edges.push_back(t.edges[2]);
			}
			else
			{
				// if not included carry over.
				temps.push_back(t);
			}
		}

		polygon.clear();

		// check duplication of edges, delete if duplicates.
		for(auto edge : edges)
		{
			int j = 0;
			for(auto poly : polygon)
			{
				// remove identical edges
				if(edge == poly)
				{
					// remove polygon from the polygon slice
					polygon.erase(polygon.begin() + j);
					goto cnt;
				}

				j++;
			}

			cnt:;
			polygon.push_back(edge);
		}

		for(auto edge : polygon)
		{
			Node newNode(x, y);
			Triangle t(edge.nodes[0], edge.nodes[1], newNode);
			temps.push_back(t);
		}

		this->triangles = temps;
	}
}

/// Get the generated triangles
/// \return
vector<Triangle> Delaunay::getTriangles()
{
	return this->triangles;
}
