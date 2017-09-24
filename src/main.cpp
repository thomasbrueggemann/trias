#include <iostream>
#include "flags.h"

int main(int argc, char** argv)
{
  // parse command line flags
  const flags::args args(argc, argv);

  const auto source = args.get<std::string>("in");
  const auto destination = args.get<std::string>("out");
  const auto blurRadius = args.get<int>("blur", 4);
  const auto sobelThreshold	= args.get<int>("sobel", 10);
  const auto pointsThreshold	= args.get<int>("points", 20);
  const auto maxPoints	= args.get<int>("max", 2500);
  const auto wireframe	= args.get<int>("wireframe", 0);
  const auto lineWidth = args.get<float>("width", 1.0);
  const auto isSolid = args.get<bool>("solid", false);

  // validate command line input
  if (!source || !destination)
  {
	  std::cerr << "Usage: ./trias -in file.jpg -out output.jpg" << std::endl;
	  return 1;
  }

  // open source file
  std::cout << "TRIAS" << std::endl;

  return 0;
}