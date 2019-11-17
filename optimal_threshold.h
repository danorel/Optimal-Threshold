//
// Created by Dan Orel on 2019-11-05.
//
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/opencv.hpp>
#ifndef OPTIMALTHRESHOLD_OPTIMAL_THRESHOLD_H
#define OPTIMALTHRESHOLD_OPTIMAL_THRESHOLD_H
void imageHistogram(
        cv::Mat Image,
        int histogram[],
        const int histogram_size);
uchar calculateMU0(
        uchar Tk,
        int *histogram);
uchar calculateMU1(
        uchar Tk,
        int *histogram,
        const int histogram_size);
uchar findOptimalT(
        uchar mu0,
        uchar mu1);
uchar AverageBrightness(
        cv::Mat Image);
cv::Mat evaluateOptimalThreshold(
        cv::Mat Image);
cv::Mat evaluateOptimalThreshold(
        cv::Mat Image,
        uchar T);
#endif //OPTIMALTHRESHOLD_OPTIMAL_THRESHOLD_H
