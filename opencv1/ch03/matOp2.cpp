#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;

String folder = "/home/yhan/yhan_ROS2/data/";

int main()
{
    // matrix Operation 2 클론, 복사 clone, copyTo
    Mat img1 = imread(folder + "lena.bmp");
    Mat img2 = img1;
    Mat img3;
    img3 = img1;

    Mat img4 = img1.clone();
    Mat img5;

    img1.copyTo(img5); // 이미지5에 이미지1을 복사

    img1.setTo(Scalar(0, 255, 255)); // B G R

    imshow("img1", img1);
    imshow("img2", img2);
    imshow("img3", img3);
    imshow("img4", img4);
    imshow("img5", img5);
    // 결과 1,2,3 = 메모리 공유 (노란색img) 
    // 결과 4,5 deepCopy 결과로 레나이미지.
    waitKey(0);
    return 0;
}