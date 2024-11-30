#include<opencv2/opencv.hpp>
int main(){
    cv::Mat bgr_img = cv::imread("R-C.jpeg");
    cv::resize(bgr_img,bgr_img,{},5,1);
    cv::imshow("putin",bgr_img);
    cv::waitKey(0);
    // std::vector<cv::Mat> channels;
    // cv::split(bgr_img, channels);

    // cv::Mat bule=channels.at(0);
    // cv::Mat green=channels.at(1);
    // cv::Mat red=channels.at(2);
    
    // cv::resize(bule,bule,{},0.5,0.5);
    // cv::resize(green,green,{},0.5,0.5);
    // cv::resize(red,red,cv::Size(1000,1000));
    
    // cv::imshow("Blue",bule);
    // cv::imshow("Green",green);
    // cv::imshow("Red",red);
    // cv::waitKey(0);
    return 0;
}