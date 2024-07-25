#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;
String folder = "/home/yhan/yhan_ROS2/data/";

int main()
{
    Mat src1 = imread(folder + "lenna256.bmp", IMREAD_GRAYSCALE);
    Mat src2 = imread(folder + "square.bmp", IMREAD_GRAYSCALE);

    Mat dst1, dst2, dst3, dst4;

    bitwise_and(src1, src2, dst1);
    bitwise_or(src1, src2, dst2);
    bitwise_xor(src1, src2, dst3);
    bitwise_not(src1, dst4);

    imshow("src1", src1);
    imshow("src2", src2);
    imshow("and", dst1);
    imshow("or", dst2);
    imshow("xor", dst3);
    imshow("not", dst4);
    waitKey(0);

    return 0;
}