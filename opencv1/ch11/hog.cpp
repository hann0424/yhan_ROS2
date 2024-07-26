#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;
String folder = "/home/yhan/yhan_ROS2/data/";

int main()
{
    VideoCapture cap(folder + "vtest.avi");
    
    HOGDescriptor hog;
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
    Mat frame;
    while(true){
        cap >> frame;
        vector<Rect> detected;
        hog.detectMultiScale(frame, detected);

        //사각형 표시
        for (auto re : detected)
        {
            rectangle(frame, re, Scalar(0, 0, 255), 3);
        }

        imshow("frame", frame);
        if(waitKey(100) == 27)
            break;
    }
    return 0;
}