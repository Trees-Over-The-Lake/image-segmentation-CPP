#include<stdint.h>
#include<algorithm>
#include"rgb.cpp"

typedef struct HSV {

    public:

    uint16_t hue;
    uint16_t saturation;
    uint16_t value; //value == brightness

    HSV(uint16_t h, uint16_t s, uint16_t v) {
        this->hue = h;
        this->saturation = s;
        this->value = v;
    }

    HSV(RGB rgb) {
        double r = rgb.red   / 255;
        double g = rgb.green / 255;
        double b = rgb.blue  / 255;

        double cmax = std::max(r, std::max(g,b));
        double cmin = std::min(r, std::min(g,b));

        double diff = cmax - cmin;

        if (cmax == cmin) {
            this->hue = 0;
 
        }else if (cmax == r) {
            uint16_t tmp1 = (g - b) / diff;
            uint16_t tmp2 = 60 * tmp1 + 360;
            this->hue = tmp2 % 360;
 
        } else if (cmax == g) {
            uint16_t tmp1 = (b - r) / diff;
            uint16_t tmp2 = 60 * tmp1 + 120;
            this->hue = tmp2 % 360;
 
        } else if (cmax == b) {
            uint16_t tmp1 = (r - g) / diff;
            uint16_t tmp2 = 60 * tmp1 + 240;
            this->hue = tmp2 % 360;
        }
        
        if (cmax == 0)
            this->saturation = 0;
        else
            this->saturation = (diff / cmax) * 100;
 

        this->value = cmax * 100;
    }

};