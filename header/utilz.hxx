#ifndef _utilz__
#define _utilz__
#include "CImg.h"
#include <map>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>       /* log10 */

void detect_edges(cimg_library::CImg<> input_image) {

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

    for (int r = 0 ; r < input_image.height(); r++) {
        for (int c= 0 ; c < input_image.width(); c++) {
            value = (int) input_image(c, r, 0, channel);
        }
    }


}

#endif