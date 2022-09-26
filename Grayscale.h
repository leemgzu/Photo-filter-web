#ifndef GRAYSCALE_H
#define GRAYSCALE_H
#include "Effect.h"

using namespace std;

class Grayscale : public Effect
{
public:
    //constructor
    Grayscale();
    void process(int &red, int& green, int& blue);

private:

};

   
#endif