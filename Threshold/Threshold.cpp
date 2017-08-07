//
//  Threshold.cpp
//  Smooth
//
//  Created by wuminhui on 2017/8/7.
//  Copyright © 2017年 wuminhui. All rights reserved.
//

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    
    // Read image
    Mat src = imread("/Users/wuminhui/NewLife/c/Learning_OpenCV/Threshold/data/threshold.png", IMREAD_GRAYSCALE);
    Mat dst;
    
    // Basic threhold example
    threshold(src,dst,0, 255, THRESH_BINARY);
    imwrite("/Users/wuminhui/NewLife/c/Learning_OpenCV/Threshold/data/opencv-threshold-example.jpg", dst);
    
    // Thresholding with maxval set to 128
    threshold(src, dst, 0, 128, THRESH_BINARY);
    imwrite("/Users/wuminhui/NewLife/c/Learning_OpenCV/Threshold/data/opencv-thresh-binary-maxval.jpg", dst);
    
    // Thresholding with threshold value set 127
    threshold(src,dst,127,255, THRESH_BINARY);
    imwrite("/Users/wuminhui/NewLife/c/Learning_OpenCV/Threshold/data/opencv-thresh-binary.jpg", dst);
    
    // Thresholding using THRESH_BINARY_INV
    threshold(src,dst,127,255, THRESH_BINARY_INV);
    imwrite("/Users/wuminhui/NewLife/c/Learning_OpenCV/Threshold/data/opencv-thresh-binary-inv.jpg", dst);
    
    // Thresholding using THRESH_TRUNC
    threshold(src,dst,127,255, THRESH_TRUNC);
    imwrite("/Users/wuminhui/NewLife/c/Learning_OpenCV/Threshold/data/opencv-thresh-trunc.jpg", dst);
    
    // Thresholding using THRESH_TOZERO
    threshold(src,dst,127,255, THRESH_TOZERO);
    imwrite("/Users/wuminhui/NewLife/c/Learning_OpenCV/Threshold/data/opencv-thresh-tozero.jpg", dst);
    
    // Thresholding using THRESH_TOZERO_INV
    threshold(src,dst,127,255, THRESH_TOZERO_INV);
    imwrite("/Users/wuminhui/NewLife/c/Learning_OpenCV/Threshold/data/opencv-thresh-to-zero-inv.jpg", dst); 
}
