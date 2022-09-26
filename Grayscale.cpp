#include "Grayscale.h"

Grayscale::Grayscale(){
    effect_name = "grayscale";
}
void Grayscale::process(int &red, int& green, int& blue)
{
    int grayness_level = 0.3*red + 0.59*green + 0.11* blue;
    red = grayness_level;
    green = grayness_level;
    blue = grayness_level;
}
