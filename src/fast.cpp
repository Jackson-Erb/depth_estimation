#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    Mat image = imread("assets/lemons.jpg", IMREAD_GRAYSCALE);
    cout << "Success! " << endl;
    return 0;
}