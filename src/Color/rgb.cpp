#include<stdint.h>

typedef struct RGB {

    public:

    uint16_t red;
    uint16_t green;
    uint16_t blue;

    RGB(uint16_t r, uint16_t g, uint16_t b) {
        this->red = r;
        this->green = g;
        this->blue = b;
    }

};