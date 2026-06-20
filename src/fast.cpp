#include <iostream>
#include <opencv2/opencv.hpp>

#include "fast.hpp" // target_include_libraries

using namespace cv;
using namespace std;

int main() {
    Mat image = imread("assets/lemons.jpg", IMREAD_GRAYSCALE);
    
    return 0;
}

Pixel Fast::is_corner(Pixel candidate)
{
    candidate.is_corner = true;
    return candidate;
}