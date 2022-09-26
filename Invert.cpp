#include "Invert.h"

Invert::Invert()
{
    effect_name = "invert";
}
void Invert::process(int &red, int &green, int &blue)
{
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
}