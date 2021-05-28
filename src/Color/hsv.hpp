#ifndef hsv_hpp_
#define hsv_hpp_

#include<stdint.h>
#include"rgb.hpp"

typedef struct HSV {

    public:

    uint16_t hue;
    uint16_t saturation;
    uint16_t value; //value == brightness

    HSV(uint16_t h, uint16_t s, uint16_t v);

    HSV(RGB rgb);

}HSV;

#endif