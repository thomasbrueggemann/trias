//
// Created by thomas on 24.09.17.
//

#include "sobel.h"

/// Constructor
Sobel::Sobel()
{
	this->kernelX = {
		{-1, 0, 1},
		{-2, 0, 2},
		{-1, 0, 1}
	};

	this->kernelY = {
		{-1, -2, -1},
		{0, 0, 0},
		{1, 2, 1}
	};
}

/// Detect image edges, see https://en.wikipedia.org/wiki/Sobel_operator
/// \param img
/// \param threshold
/// \return
Image Sobel::filter(Image img, double threshold)
{
	int sumX, sumY;


}