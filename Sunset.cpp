#include "Sunset.h"
using namespace std;

Sunset::Sunset(){
    effect_name = "sunset";
}
void Sunset::process(int &red, int& green, int& blue)
{
    red = red;
    green = 0.7*green;
    blue = 0.7*blue;
}
