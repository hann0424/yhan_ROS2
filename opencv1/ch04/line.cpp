#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;
String folder = "/home/yhan/yhan_ROS2/data/";

int main()
{
    Mat img(400, 600, CV_8UC3, Scalar(255, 255, 255)); // 하얀 배경화면 생성
    Point pt1(30, 30), pt2(200, 200); // 선을 그을 포인터 지정
    int a = 1;
    while(true)
    {
        img = Scalar(255, 255, 255); // 하얀배경으로 초기화
        pt1.x += a;
        pt2.x += a;
        line(img, pt1, pt2, Scalar(255, 0, 0), 3, LINE_AA);
        imshow("img", img);
        if (waitKey(30) == 27)
            break;
    }

    return 0;
}