#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/yhan/yhan_ROS2/data/";

int main()
{
    // matrix Operation 4 pixel change 
    Mat mat1 = Mat::zeros(3, 4, CV_8UC1); // CV_8UC1 = 0~255 사이의 숫자만 사용하겠다. 타입지정
                    //높이3, 길이4, 타입지정
    cout << "Before mat1 : " << endl << mat1 << endl;

    for (int j=0; j < mat1.rows; j++)
    {
        for (int i = 0; i < mat1.cols; i++)
        {
            mat1.at<uchar>(j,i)++;
            //mat1.at<uchar>(j,i) 의 위치에 1씩 대입한다.
        }
    }
    cout << "After mat1 : " << endl << mat1 << endl;

    cout << "Before ptr1 : " << endl << mat1 << endl;

    for (int j=0; j < mat1.rows; j++) 
    {
        uchar *p = mat1.ptr<uchar>(j);
        for (int i = 0; i < mat1.cols; i++)
        {
            p[i]++;
            //mat1.at<uchar>(j,i) 의 위치에 1씩 대입한다.
        }
    }

    cout << "After ptr1 : " << endl << mat1 << endl;
    
    cout << "Before iterator : " << endl << mat1 << endl;

    for (auto it = mat1.begin<uchar>(); it !=mat1.end<uchar>(); it++)
    {
        (*it)++;
    }

    cout << "After iterator : " << endl << mat1 << endl;
    // 장점 : 코어덤프 방지, 가능한 메모리만 접근
    // 단점 : 중간에 접근하기 힘듬
    return 0;
}