#include "hsv.hpp"
#include<algorithm>

    HSV::HSV(uint16_t h, uint16_t s, uint16_t v) {
        this->hue = h;
        this->saturation = s;
        this->value = v;
    }

    HSV::HSV(RGB rgb) {

        double r = (double)rgb.red   / 255;
        double g = (double)rgb.green / 255;
        double b = (double)rgb.blue  / 255;

        double cmax = std::max(r, std::max(g,b));
        double cmin = std::min(r, std::min(g,b));

        double diff = cmax - cmin;

        if (cmax == cmin) {
            this->hue = 0;
 
        }else if (cmax == r) {
            this->hue = (uint16_t)((uint16_t)(60 * ((g - b) / diff) + 360) % 360);
 
        } else if (cmax == g) {
            this->hue = (uint16_t)((uint16_t)(60 * ((b - r) / diff) + 120) % 360);
 
        } else if (cmax == b) {
            this->hue = (uint16_t)((uint16_t)(60 * ((r - g) / diff) + 240) % 360);
        }
        
        if (cmax == 0)
            this->saturation = 0;
        else
            this->saturation = (diff / cmax) * 100;
 

        this->value = cmax * 100;
    }