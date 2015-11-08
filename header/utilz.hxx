#ifndef _utilz__
#define _utilz__
#include "CImg.h"
#include <map>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>


cimg_library::CImg<> addPaddingToImage(cimg_library::CImg<> image, int pixels) {
    cimg_library::CImg<> padded_image(image.width() + pixels, image.height() + pixels, 1, image.spectrum());


    for (int channel = 0; channel < image.spectrum(); channel++) {
        for (int r = pixels ; r < image.height() + pixels; r++) {
            for (int c= pixels ; c < image.width() + pixels; c++) {
                padded_image(r, c, 0, channel) = (int) image(r, c, 0, channel);
            }
        }
    }

    return padded_image;
}

void detect_edges(cimg_library::CImg<> input_image) {
    /** add padding to input image **/

    cimg_library::CImg<> paddedImage = addPaddingToImage(input_image, 2);
    paddedImage.display("padded image");

    /** define sobel filters **/
    int G_x[3][3] = {
      {0.25, 0, -0.25},
      {0.50, 0, -0.50},
      {0.25, 0, -0.25}};

    int G_y[3][3] = {
      { 0.25,  0.50,  0.25},
      { 0,     0,     0},
      {-0.25, -0.50, -0.25}};

    /** Define gradient images (Ix and Iy ) **/
    cimg_library::CImg<> Ix(input_image.width(),input_image.height(), 1, 3);
    cimg_library::CImg<> Iy(input_image.width(),input_image.height(), 1, 3);

    /** Apply sobel filters to image **/

    //loop through each pixel in the input image
    int channel = 0;
    int value;

    for (int channel = 0; channel < input_image.spectrum(); channel++) {
        for (int r = 0 ; r < input_image.height(); r++) {
            for (int c= 0 ; c < input_image.width(); c++) {
                value = (int) input_image(r, c, 0, channel);
            }
        }
    }


}

#endif