#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

struct Pixel {
    int x_pos;
    int y_pos;
    double intensity;
    bool is_corner;
};

class IFeatureDetector {

        virtual void is_corner(Pixel candidate) = 0;

        virtual ~IFeatureDetector() = default; 
};
