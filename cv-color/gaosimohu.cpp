#include<opencv2/opencv.hpp>

int main(){
    cv::Mat img=cv::imread("wuwa.jpg");
    int knSize=7;
    double sigma=10.0;
    cv::Mat BLR_img;
    cv::GaussianBlur(img,BLR_img,cv::Size(knSize,knSize),sigma);
    cv::imshow("result",BLR_img);
    cv::imshow("原来",img);
    cv::waitKey(0);
    return 0;
}