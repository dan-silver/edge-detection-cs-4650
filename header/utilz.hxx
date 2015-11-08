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
        int G_X[3][3] = {
          {-1, 0, 1},
          {-2, 0, 2},
          {-1, 0, 1}};
}

#endif