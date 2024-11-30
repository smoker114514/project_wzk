#include <opencv2/opencv.hpp>
int main()
{
    cv::Mat img;
    img = cv::imread("bubing.png");
    cv::Mat G_img;
    cv::cvtColor(img, G_img, cv::COLOR_BGR2GRAY);
    cv::Mat B_img;
    cv::threshold(G_img, B_img, 128, 255, cv::THRESH_BINARY);
    // std::vector<std::vector<cv::Point>> contours;
    // cv::findContours(B_img, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    // cv::Mat s=img.clone();
    // cv::drawContours(s, contours, -1, cv::Scalar(0, 0, 255), 2);
    // cv::imshow("",img);
    // cv::waitKey(0);
    // std::vector<cv::RotatedRect> rotated_rects;
    // for (const auto &c : contours)
    // {
    //     cv::RotatedRect rect=cv::minAreaRect(c);
    //     cv::Point2f v[4];
    //     rect.points(v);
    //     for(int i=0;i<4;i++)
    //     {
    //         cv::line(img,v[i],v[(i+1)%4],cv::Scalar(0,0,255),2);
    //     }
    // }
    cv::imshow("",B_img);
    //cv::imshow("",s);
    cv::waitKey(0);
    // cv::Mat drawrect = img.clone();
    // for (const auto &r : rotated_rects)
    // {
    //     std::vector<cv::Point2f>points(4);
    //     r.points(&points[0]);
    //     tools::draw_point
    // }

}