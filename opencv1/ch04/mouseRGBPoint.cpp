#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void onMouse(int event, int x, int y, int flags, void *data);
struct Mydata
{
    Point ptOld;
    Point ptNew;
    Mat img;
    Mat background;
    Scalar white = Scalar(255, 255, 255);
    Scalar yellow = Scalar(0, 255, 255);
    Scalar blue = Scalar(255, 0, 0);
    Scalar green = Scalar(0, 255, 0);
    Scalar red = Scalar(0, 0, 255);
    vector<Vec3b> mouseBGR;
    bool flag = false;
};

String folder = "/home/yhan/yhan_ROS2/data/";

int main()
{
    // 초기화 및 이미지 로드
    Mydata mydata;
    FileStorage fs;
    mydata.img = imread(folder + "lenna.bmp");
    mydata.background = mydata.img.clone();

    // 윈도우 생성 및 마우스 콜백 설정
    namedWindow("img");
    setMouseCallback("img", onMouse, (void *)&mydata);
    imshow("img", mydata.img);

    // 키보드 입력 대기 및 JSON 파일 저장
    int keycode = waitKey(0);
    if (keycode == 27)
    {
        fs.open(folder + "mouseBGRPoint.json", FileStorage::WRITE);
        fs << "mouseBGR" << mydata.mouseBGR;
        fs.release();
    }
    destroyAllWindows();
    return 0;
}

void onMouse(int event, int x, int y, int flags, void *data)
{
    Mydata *ptr = (Mydata *)data;
    switch (event)
    {
    case EVENT_LBUTTONDOWN:
        cout << "mouse left button down" << x << y << endl;
        ptr->ptOld = Point(x, y);
        ptr->mouseBGR.push_back(ptr->background.at<Vec3b>(y, x));
        ptr->flag = true;
        break;
    case EVENT_LBUTTONUP:
        cout << "mouse left button up" << x << y << endl;
        ptr->flag = false;
        break;
    case EVENT_MOUSEMOVE:
        if (EVENT_FLAG_LBUTTON)
        {
            ptr->background.copyTo(ptr->img);
            rectangle(ptr->img, Rect(Point(x - 25, y - 25), Point(x + 25, y + 25)), ptr->red, 5);
            imshow("img", ptr->img);
            ptr->ptOld = Point(x, y);
        }
    }
}

//마우스 왼쪽 버튼 클릭시 해당 부분의 BGR 값 저장
//ESC누르면 마우스 클릭시 지정된 값을 JSON 형태로 저장