//
// Created by thomas on 24.09.17.
//

#ifndef TRIAS_SOBELFILTER_H
#define TRIAS_SOBELFILTER_H

#include <vector>
#include <Magick++.h>

using namespace std;
using namespace Magick;

typedef vector<vector<int>> kernel;

class Sobel {
 private:
	kernel kernelX;
	kernel kernelY;

 public:
	Sobel();
	Image filter(Image img, double threshold);
};

#endif //TRIAS_SOBELFILTER_H
