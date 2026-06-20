#include <i_feature_detector.hpp>

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class Fast : public FeatureDetector {

    Pixel is_corner(Pixel candidate);
};
