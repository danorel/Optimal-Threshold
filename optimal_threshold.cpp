//
// Created by Dan Orel on 2019-11-05.
//
#include "optimal_threshold.h"

void imageHistogram(
        cv::Mat Image,
        int histogram[],
        const int histogram_size){
    for (int i = 0; i < histogram_size; i++){
        // ініціалізуємо всі значення інтенсивності 0
        histogram[i] = 0;
    }
    // обчислюємо кількість пікселів для кожного значення яскравості
    for(int y = 0; y < Image.rows; y++){
        for(int x = 0; x < Image.cols; x++){
            histogram[(int)Image.at<uchar>(y, x)]++;
        }
    }
}

uchar calculateMU0(
        uchar Tk,
        int *histogram){
    int top   = 0.,
            under = 0.;
    for(int i = 0; i <= Tk; i++){
        top += i * histogram[i];
    }
    for(int i = 0; i <= Tk; i++){
        under += histogram[i];
    }
    float mu0 = top / under;
    return mu0;
}

uchar calculateMU1(
        uchar Tk,
        int *histogram,
        const int histogram_size){
    int top   = 0.,
            under = 0.;
    for(int i = Tk + 1; i < histogram_size; i++){
        top += i * histogram[i];
    }
    for(int i = 0; i < histogram_size; i++){
        under += histogram[i];
    }
    float mu1 = top / under;
    return mu1;
}

uchar findOptimalT(
        uchar mu0,
        uchar mu1){
    return (mu0 + mu1) / 2;
}

uchar AverageBrightness(
        cv::Mat Image){
    uchar average = 0;
    int   value   = 0;
    for(int row = 0; row < Image.rows; row++){
        for(int col = 0; col < Image.cols; col++){
            value += Image.at<uchar>(row, col);
        }
    }
    average = value / (Image.rows + Image.cols);
    return average;
}

cv::Mat evaluateOptimalThreshold(
        cv::Mat Image){
    cv::Mat OptimalThresholdImage = Image.clone();
    const int hist_size = 256;
    int histogram[hist_size];
    imageHistogram(Image, histogram, hist_size);
    uchar T0 = AverageBrightness(OptimalThresholdImage);
    std::cout << (int)T0 << std::endl;
    uchar Tk = T0;
    uchar Tkplus1,
            nu0 = 0,
            nu1 = 0;
    do{
        Tk = findOptimalT(nu0, nu1);
        nu0 = calculateMU0(Tk, histogram);
        nu1 = calculateMU1(Tk, histogram, hist_size);
        Tkplus1 = findOptimalT(nu0, nu1);
        std::cout << (int)Tkplus1 << std::endl;
    } while(Tk != Tkplus1);
    std::cout << "Optimal threshold: " << (int)Tk << std::endl;
    for(int row = 0; row < OptimalThresholdImage.rows; row++){
        for(int col = 0; col < OptimalThresholdImage.cols; col++){
            if(OptimalThresholdImage.at<uchar>(row, col) < Tk){
                OptimalThresholdImage.at<uchar>(row, col) = 0;
            } else {
                OptimalThresholdImage.at<uchar>(row, col) = 255;
            }
        }
    }
    return OptimalThresholdImage;
}

cv::Mat evaluateOptimalThreshold(
        cv::Mat Image,
        uchar T){
    cv::Mat OptimalThresholdImage = Image.clone();
    std::cout << "The user's input threshold: " << (int)T << std::endl;
    for(int row = 0; row < OptimalThresholdImage.rows; row++){
        for(int col = 0; col < OptimalThresholdImage.cols; col++){
            if(OptimalThresholdImage.at<uchar>(row, col) < T){
                OptimalThresholdImage.at<uchar>(row, col) = 0;
            } else {
                OptimalThresholdImage.at<uchar>(row, col) = 255;
            }
        }
    }
    return OptimalThresholdImage;
}
