#include <iostream>
#include <Magick++.h>
#include <cstdlib>

#include "flags.h"

using namespace std;
using namespace Magick;

int main(int argc, char** argv)
{
  // init command line flags
  const flags::args args(argc, argv);

  // parse command line flags
  const auto source           = args.get<string>("in");
  const auto destination      = args.get<string>("out");
  const auto blurRadius       = args.get<int>("blur", 4);
  const auto sobelThreshold   = args.get<int>("sobel", 10);
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

  // init context to draw on
  Image ctx(Geometry(width, height), Color(QuantumRange, QuantumRange, QuantumRange, 0));


  return EXIT_SUCCESS;
}