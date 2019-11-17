#include <iostream>
#include "optimal_threshold.h"


int main() {
    std::string pathToImage = "/Users/danorel/Workspace/World of C/C++/KMA/MMPI/OptimalThreshold/";
    std::string image = "image2.jpg";
    std::string RegularImageLabel = "Regular Image";
    std::string OptimalThresholdLabel = "Optimal Threshold Image";
    std::string InputThresholdImageLabel = "Manual Threshold First Image";
    std::string InputThresholdImageLabel2 = "Manual Threshold Second Image";

    cv::Mat Image,
            OptimalThresholdImage,
            InputThresholdImage,
            InputThresholdImage2;

    Image = imread(
            pathToImage + image,
            cv::IMREAD_GRAYSCALE);
    OptimalThresholdImage = evaluateOptimalThreshold(Image);
    InputThresholdImage = evaluateOptimalThreshold(Image, 100);
    InputThresholdImage2 = evaluateOptimalThreshold(Image, 150);


    imshow(RegularImageLabel, Image);
    imshow(OptimalThresholdLabel, OptimalThresholdImage);
    imshow(InputThresholdImageLabel, InputThresholdImage);
    imshow(InputThresholdImageLabel2, InputThresholdImage2);

    cv::waitKey(0);
    return 0;
}
