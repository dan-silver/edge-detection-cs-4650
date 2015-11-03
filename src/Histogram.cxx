#include <iostream> //
#include "utilz.hxx" //contains the rgb2gray function

int main(int argc, char *argv[]) {

    cimg_library::CImg<> input_image, equalized_image, log10_image;

    //print out the usage if the user enters the wrong number of cmd inputs
    // arg count of 4 is allowed only if the command starts with the -invert flag
    if(argc != 2) {
        std::cout<<"Usage: Edge input_image"<<std::endl;
        return 1;
    }

    //lets try to load the image as specified by the user..
    //throw an exception otherwise
    try {
        input_image.load(argv[1]);
    } catch (std::exception &err) {
        std::cout<<"Error loading image.."<<std::endl;
        std::cout<<err.what()<<std::endl;
    }

    input_image.display("Input Image");

    detect_edges(input_image);

    //all programs must be written the Unix way
    //ANSI C++ standards will be applied to all assignments
    return 0;

}