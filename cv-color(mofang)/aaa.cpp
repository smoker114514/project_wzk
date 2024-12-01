#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    
    Mat src = imread("output.png");
    if (src.empty())
    {
        cout << "Could not read the image" << endl;
        return -1;
    }

    
    Mat hsv;
    cvtColor(src, hsv, COLOR_BGR2HSV);

    
    Scalar lower_yellow = Scalar(20, 100, 100);
    Scalar upper_yellow = Scalar(30, 255, 255);
    
    Mat mask_yellow;
    inRange(hsv, lower_yellow, upper_yellow, mask_yellow);

    
    
    Scalar lower_blue = Scalar(90, 70, 70);
    Scalar upper_blue = Scalar(130, 255, 255);
    
    Mat mask_blue;
    inRange(hsv, lower_blue, upper_blue, mask_blue);

    
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    morphologyEx(mask_yellow, mask_yellow, MORPH_OPEN, kernel);
    morphologyEx(mask_blue, mask_blue, MORPH_OPEN, kernel);

    
    vector<vector<Point>> contours_yellow;
    findContours(mask_yellow, contours_yellow, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    
    for (size_t i = 0; i < contours_yellow.size(); i++)
    {
        Rect rect = boundingRect(contours_yellow[i]);
        rectangle(src, rect, Scalar(0, 255, 255), 2);
        putText(src, "Yellow", Point(rect.x, rect.y - 5), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 255), 2);
    }

    
    vector<vector<Point>> contours_blue;
    findContours(mask_blue, contours_blue, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    
    for (size_t i = 0; i < contours_blue.size(); i++)
    {
        Rect rect = boundingRect(contours_blue[i]);
        rectangle(src, rect, Scalar(255, 0, 0), 2);
        putText(src, "Blue", Point(rect.x, rect.y - 5), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 0), 2);
    }

   
    imshow("Result", src);
    waitKey(0);

    return 0;
}
