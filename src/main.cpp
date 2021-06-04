#include "color/rgb.cpp"
#include "color/hsv.cpp"

#include <iostream>

int main(int argc, char ** argv)
{

    auto rgb = RGB(129,88,47);

    auto hsv = HSV(rgb);

    std::cout << hsv.hue << "\n" << hsv.saturation << "\n" << hsv.value << std::endl;
    
    return 0;
}