#include <iostream>
#include <Magick++.h>

#include "flags.h"
#include "edges.h"
#include "delaunay.h"

using namespace std;
using namespace Magick;

int main(int argc, char** argv)
{
    // init command line flags
    const flags::args args(argc, argv);

    // parse command line flags
    const auto source           = args.get<string>("in");
    const auto destination      = args.get<string>("out");
    const auto blurRadius       = args.get<double>("blur", 4.0);
    const auto pointsThreshold  = args.get<int>("points", 20);
    const auto maxPoints        = args.get<int>("max", 2500);
    const auto wireframe        = args.get<int>("wireframe", 0);
    const auto lineWidth        = args.get<float>("width", 1.0);
    const auto isSolid          = args.get<bool>("solid", false);

    // validate command line input
    if (!source || !destination)
    {
        cerr << "Usage: ./trias -in file.jpg -out output.jpg" << endl;
        return 1;
    }

    // open source file
    Image src(*source);
	unsigned int width = src.columns();
	unsigned int height = src.rows();

	// histogram equalization
	src.equalize();

	// blur image
	src.blur(blurRadius);

	// convert to greyscale
	src.modulate(100.0, 0, 100.0);

    // detect edges
	const double kernel[3][3] = {
		{1.0, 0.0, -1.0},
		{2.0, 0.0, -2.0},
		{1.0, 0.0, -1.0}
	};

    src.convolve(3, *kernel);

	// get edge points
	Edges edges;
	vector<Point> points = edges.getEdgePoints(src, pointsThreshold, maxPoints);

	// perform delaunay triangulation
	Delaunay delaunay(width, height);
	delaunay.insert(points);
	int numPoints = points.size();

	vector<Triangle> triangles = delaunay.getTriangles();
	int numTriangles = triangles.size();

	// init context to draw on
	Image ctx(Geometry(width, height), Color(1, 1, 1, 1));

	for (auto triangle : triangles)
	{

	}

	// write to destination
	src.write(*destination);

	return EXIT_SUCCESS;
}