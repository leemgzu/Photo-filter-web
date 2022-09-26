#ifndef SUNSET_H
#define SUNSET_H
#include "Effect.h"

using namespace std;

class Sunset : public Effect
{
public:
    //constructor
    Sunset();
    void process(int &red, int& green, int& blue);
private:

};

   
#endif