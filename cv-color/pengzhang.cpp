#include<opencv2/opencv.hpp>
int main(){
    cv::Mat img=cv::imread("bubing.png");
    cv::Mat element=cv::getStructuringElement(cv::MORPH_RECT,cv::Size(5,5));
    cv::dilate(img,img,element);
    cv::imshow("",img);
    cv::waitKey(0);
    return 0;
}