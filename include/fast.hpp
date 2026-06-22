#include "i_feature_detector.hpp"

using namespace cv;
using namespace std;

class Fast : public FeatureDetector {
public:
    Pixel is_corner(Pixel candidate);
    void set_image(string file_name);

private:
    bool first_check(Pixel candidate);
    bool fast_algo(Pixel candidate);
    Scalar calculate_intensity_div(Scalar center, Scalar other);
    Mat fast_image_;
    Scalar threshold_ = 50;  // [0, 255]
};
