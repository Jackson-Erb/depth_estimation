## FAST


1) Select a pixel p in the image which is to be identified as an interest point or not. Let its intensity be Ip.
2) Select appropriate threshold value t.
3) Consider a circle of 16 pixels around the pixel under test.
4) Now the pixel p is a corner if there exists a set of n contiguous pixels in the circle (of 16 pixels) which are all brighter than Ip+t, 
    or all darker than Ip−t. (Shown as white dash lines in the above image). n was chosen to be 12.
5) A high-speed test was proposed to exclude a large number of non-corners. This test examines only the four pixels at 1, 9, 5 and 13 
    (First 1 and 9 are tested if they are too brighter or darker. If so, then checks 5 and 13). If p is a corner, then at least three of these must all be brighter than Ip+t or darker than Ip−t. If neither of these is the case, then p cannot be a corner. The full segment test criterion can then be applied to the passed candidates by examining all pixels in the circle. This detector in itself exhibits high performance, but there are several weaknesses:

    - It does not reject as many candidates for n < 12.
    - The choice of pixels is not optimal because its efficiency depends on ordering of the questions and distribution of corner appearances.
    - Results of high-speed tests are thrown away.
    - Multiple features are detected adjacent to one another.

i_feature_detector
    |
    '-> Interface that takes in a pixel and returns the pixel and a flag if it's a corner or not



A function fast() that takes in a Pixel Coordinate and applies the fast algorithm, and returns a bool if its a corner or not.

fast(){
        calculate_perimeter_brightness();
}

First  1, 5, 9, 13.
calculate_perimeter_brightness() {
    intensity = image(coordinates).intensity;
    p1_intensity = image(x, y-4);
    p2_intensity = image(x+4, y);
    p3_intensity = image(x, y+4);
    p4_intensity = image(x+4, y);
}