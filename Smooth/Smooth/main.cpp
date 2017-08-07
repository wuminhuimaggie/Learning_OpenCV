//
//  main.cpp
//  Smooth
//
//  Created by wuminhui on 2017/8/7.
//  Copyright © 2017年 wuminhui. All rights reserved.
//


//////

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;

/// 全局变量
int DELAY_CAPTION = 1500;  //提示图片生存时间
int DELAY_BLUR = 600;    // 效果图片生存时间
int MAX_KERNEL_LENGTH = 15;  //最大内核长度

Mat src; Mat dst;
char window_name[] = "Filter Demo 1";

int display_dst( int delay )
{
    imshow( window_name, dst );
    int c = waitKey ( delay );
    //if( c >= 0 ) { return -1; }
    return 0;
}

int display_caption( const std::string& caption )
{
    dst = Mat::zeros( src.size(), src.type() );
    putText( dst, caption,
            Point( src.cols/4, src.rows/2),
            CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255) );
    imshow( window_name, dst );
    int c = waitKey( DELAY_CAPTION );
    //if( c >= 0 ) { return -1; }
    return 0;
}

int main( int argc, char** argv )
{
    namedWindow( window_name, CV_WINDOW_AUTOSIZE );
    
    /// 载入原图像
    src = imread("/Users/wuminhui/NewLife/c/Learning_OpenCV/Smooth/data/2-lucy.jpg"); //读入图像，下方给出图像获取方法，
    
    if( display_caption( "Original Image" ) != 0 ) { return 0; } // 先输出一副黑地白字的图片用于提示。
    
    dst = src.clone();   //将src的内容克隆到dst
    if( display_dst( DELAY_CAPTION ) != 0 ) { return 0; } //将原图进行输出。
    
    /// 使用 均值平滑
    if( display_caption( "Homogeneous Blur" ) != 0 ) { return 0; }//声明下面开始Homogeneous Blur算法
    
    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        blur( src, dst, Size( i, i ), Point(-1,-1) );     //输入src图像，和内核大小，指定锚点位置（计算出的像素值覆盖的地方），如果为负值则中心为锚点。
        if( display_dst( DELAY_BLUR ) != 0 ) { return 0; }
    }  //对图片进行输出
    
    /// 使用高斯平滑
    if( display_caption( "Gaussian Blur" ) != 0 ) { return 0; } //声明使用高斯平滑
    
    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        GaussianBlur( src, dst, Size( i, i ), 0, 0 ); // 输入的src原图像，和size内核大小和x，y的方差如果是0 则用内核自行计算。
        if( display_dst( DELAY_BLUR ) != 0 ) { return 0; }
    }
    
    /// 使用中值平滑
    if( display_caption( "Median Blur" ) != 0 ) { return 0; }
    
    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        medianBlur ( src, dst, i );
        if( display_dst( DELAY_BLUR ) != 0 ) { return 0; }
    }
    
    /// 使用双边平滑
    if( display_caption( "Bilateral Blur" ) != 0 ) { return 0; }
    
    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        bilateralFilter ( src, dst, i, i * 2, i / 2 );
        if( display_dst( DELAY_BLUR ) != 0 ) { return 0; }
    }
    
    /// 等待用户输入
    display_caption( "End: Press a key!" );
    
    waitKey(0);
    return 0;
}
