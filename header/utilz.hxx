#ifndef _utilz__
#define _utilz__
#include "CImg.h"
#include <map>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>


// helper function that adds n pixels to the border around the image
cimg_library::CImg<> add_padding_to_image(cimg_library::CImg<> image, int pixels) {
    cimg_library::CImg<> padded_image(image.width() + 2*pixels, image.height() + 2*pixels, 1, image.spectrum());
    for (int channel = 0; channel < image.spectrum(); channel++) {
        for (int r = 0 ; r < image.height(); r++) {
            for (int c = 0 ; c < image.width(); c++) {
                std::cout << image(r, c, 0, channel) << std::endl;
                padded_image(r + pixels, c + pixels, 0, channel) = (int) image(r, c, 0, channel);
            }
        }
    }
    return padded_image;
}

//applies the given filter to the image (1st param) inside the padding and produces an output image
void apply_sobel_filter(cimg_library::CImg<> image, cimg_library::CImg<> output, float filter[3][3]) {
    //loop through each pixel in the input image
    int padding = 2;

    for (int channel = 0; channel < image.spectrum(); channel++) {

        //loop through each pixel INSIDE the padding of 2px
        for (int r = padding ; r < image.height() + padding; r++) {
            for (int c = padding ; c < image.width() + padding; c++) {

                float value =
                    filter[0][0] * (float) image(r - 1, c - 1, 0, channel) +
                    filter[0][1] * (float) image(r - 1, c, 0, channel) +
                    filter[0][2] * (float) image(r - 1, c + 1, 0, channel) +
                    filter[1][0] * (float) image(r, c - 1, 0, channel) +
                    filter[1][1] * (float) image(r, c, 0, channel) +
                    filter[1][2] * (float) image(r, c + 1, 0, channel) +
                    filter[2][0] * (float) image(r + 1, c - 1, 0, channel) +
                    filter[2][1] * (float) image(r + 1, c, 0, channel) +
                    filter[2][2] * (float) image(r + 1, c + 1, 0, channel);


                //scalle the value to [0, 255];

                value = (value + 255) / 510 * 255;

                output(r, c, 0, channel) = value;
                // std::cout <<  << std::endl;
                // std::cout << value << " : " << image(r, c, 0, 0, channel) << std::endl;
                // std::cout << (filter[0][0] * (float) image(r - 1, c - 1, 0, channel)) << std::endl;
                if (value != 0.0) {
                    std::cout << value << std::endl;
                    std::cout << output(r, c, 0, channel) << std::endl;
                }
            }
        }
    }
}

void detect_edges(cimg_library::CImg<> input_image) {
    /** add padding to input image **/

    int padding = 2;
    cimg_library::CImg<> padded_image = add_padding_to_image(input_image, padding);

    padded_image.display("padded image");

    /** define sobel filters **/
    float G_x[3][3] = {
      {0.25, 0, -0.25},
      {0.50, 0, -0.50},
      {0.25, 0, -0.25}};

    float G_y[3][3] = {
      { 0.25,  0.50,  0.25},
      { 0,     0,     0},
      {-0.25, -0.50, -0.25}};

    /** Define gradient images (Ix and Iy ) **/
    cimg_library::CImg<> Ix, Iy;

    Ix.assign(padded_image.width(), padded_image.height(), 1, padded_image.spectrum());
    Ix.fill(255);

    Iy.assign(padded_image.width(), padded_image.height(), 1, padded_image.spectrum());
    Iy.fill(255);


    // /** Apply sobel filters to image **/
    // apply_sobel_filter(padded_image, Ix, G_x);
    // apply_sobel_filter(padded_image, Iy, G_y);

    // Ix.display("Ix");
    // Iy.display("Iy");

}

#endif