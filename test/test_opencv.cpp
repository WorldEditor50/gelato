#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

void test_01()
{
    cv::Mat img1(200, 200, CV_8UC3, cv::Scalar(255, 0, 0));
    cv::Mat img2(200, 200, CV_8UC3, cv::Scalar(0, 255, 0));
    cv::Mat img3(200, 200, CV_8UC3, cv::Scalar(0, 0, 255));
    cv::Mat img4(200, 200, CV_8UC3, cv::Scalar(255, 0, 255));
    cv::Mat img12;
    cv::hconcat(img1, img2, img12);
    cv::Mat img34;
    cv::hconcat(img3, img4, img34);
    cv::Mat img;
    cv::vconcat(img12, img34, img);
    cv::imshow("test01", img);
    cv::waitKey(0);
    return;
}

int main()
{
    test_01();
    return 0;
}
