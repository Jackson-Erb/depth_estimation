#include "../include/fast.hpp"

using namespace cv;
using namespace std;

int main() {

    Fast test_image;

    test_image.set_image("assets/church.jpg");
    int counter = 0;
    for (int i = 10; i < 1000; ++i) {
        for (int j = 10; j < 1000; ++j) {
            Pixel candidate_iter;
            Pixel_Coordinate coord;
            coord.x = j;
            coord.y = i;
            candidate_iter.coord = coord;
            counter++;

            test_image.is_corner(candidate_iter);
        }
    }
    cout << "Pixels Counted:  " << counter << endl;
    cout << "Number of Potential Candidates:  " << test_image.fast_candidates_.size() << endl;

    return 0;
}

void Fast::set_image(string file_name)
{   
    fast_image_ = imread(file_name, IMREAD_GRAYSCALE);
    rows_ = fast_image_.rows;
    columns_ = fast_image_.cols;
}

Pixel Fast::is_corner(Pixel candidate)
{
    candidate.is_corner = fast_algo(candidate);
    return candidate;
}

bool Fast::fast_algo(Pixel candidate)
{   
    bool initial_verdict = first_check(candidate);

    if (!initial_verdict) {  // If Fails the first check, return. 
        return 0;
    }

    fast_candidates_.push_back(initial_verdict);

    return 0;
}

bool Fast::first_check(Pixel candidate)
{
    Pixel_Coordinate top_pix = candidate.coord;
    Pixel_Coordinate bottom_pix = candidate.coord;
    Pixel_Coordinate left_pix = candidate.coord;
    Pixel_Coordinate right_pix = candidate.coord;

    top_pix.y += 4;
    bottom_pix.y -= 4;
    left_pix.x += 4;
    right_pix.x -= 4;

    Scalar candidate_pixel_intensity = fast_image_.at<uchar>(candidate.coord.y, candidate.coord.x);
    Scalar top_pixel_intensity = fast_image_.at<uchar>(top_pix.y, top_pix.x);
    Scalar bottom_pixel_intensity = fast_image_.at<uchar>(bottom_pix.y, bottom_pix.x);
    Scalar left_pixel_intensity = fast_image_.at<uchar>(left_pix.y, right_pix.x);
    Scalar right_pixel_intensity = fast_image_.at<uchar>(right_pix.y, right_pix.x);

    vector<Scalar> differences = {calculate_intensity_div(candidate_pixel_intensity, top_pixel_intensity),
                                  calculate_intensity_div(candidate_pixel_intensity, bottom_pixel_intensity),
                                  calculate_intensity_div(candidate_pixel_intensity, left_pixel_intensity),
                                  calculate_intensity_div(candidate_pixel_intensity, right_pixel_intensity)};

    // If at least 2 points are within the threshold, then it is not a corner
    int mid_counter = 0;
    int bright_counter = 0;
    int dim_counter = 0;
    for (Scalar pixel_diff : differences){
        if (pixel_diff[0] < threshold_[0] || pixel_diff[0] > -threshold_[0]){  // Center is Dimmer | Brighter than Periphery (Within Threshold)
            mid_counter++;
        } else if (pixel_diff[0] > threshold_[0]) { // Center is Brighter than Periphery (Beyond Threshold)
            bright_counter++;
        } else if (pixel_diff[0] < -threshold_[0]) {// Center is Dimmer than Periphery (Beyond Threshold)
            dim_counter++;
        };
        if (mid_counter == 2){
            // If 2 or more pixels are within the threshold ,
            return false;
        }
    };

    if (bright_counter == 3 || dim_counter == 3){  // Only a corner if 3 points are >threshold
        return true;
    } else {  // 2 Bright and 2 Dim, or 4 Dim, or 4 Bright are not corners
        return false;
    }
}

Scalar Fast::calculate_intensity_div(Scalar center, Scalar other){
    return (center - other);
}


