//
// Created by thomas on 30.09.17.
//

#include "edges.h"

/// Get the edge points after the Sobel filter has been applied
/// \param img
/// \param threshold
/// \param maxpoints
/// \return
vector<Point> Edges::getEdgePoints(Image img, double threshold, int maxPoints)
{
	random_device rd;
	mt19937 e2(rd());
	std::uniform_real_distribution<double> dist(0.0, 1.0);

	int width = img.columns();
	int height = img.rows();

	MagickCore::PixelPacket *pixels = img.getPixels(0, 0, width, height);

	int total = 0;
	double sum;
	vector<Point> points;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			sum = 0.0;
			total = 0;

			Color color = pixels[x + y];
			sum += color.alpha();

			total++;

			if (total > 0)
			{
				sum /= total;
			}

			if (sum > threshold)
			{
				Point p;
				p.x = x;
				p.y = y;

				points.push_back(p);
			}
		}
	}

	int ilen = points.size();
	int tlen = ilen;
	int limit = (int) ((double) ilen * POINT_RATE);

	vector<Point> dpoints;

	if (limit > maxPoints)
	{
		limit = maxPoints;
	}

	for (int i = 0; i < limit && i < ilen; i++)
	{
		int j = (int) ((double) tlen * dist(e2));
		dpoints.push_back(points[j]);

		// remove points
		points.erase(points.begin() + j);
		tlen--;
	}

	return dpoints;
}
