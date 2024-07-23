#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>

std::string folder = "/home/yhan/yhan_ROS2/opencv1/first/";
int main()
{
    std::cout << "hello world" << std::endl; 
    cv::Mat img;
    img = cv::imread(folder + "lena.bmp");

    cv::imshow("image", img);
    cv::waitKey(0);
    
    return 0;
}