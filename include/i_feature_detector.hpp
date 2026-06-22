#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
struct Pixel_Coordinate {
    int x;
    int y;
};

struct Pixel {
    Pixel_Coordinate coord;
    double intensity;
    bool is_corner;
};

class IFeatureDetector {

        virtual void is_corner(Pixel candidate) = 0;

        virtual ~IFeatureDetector() = default; 
};
