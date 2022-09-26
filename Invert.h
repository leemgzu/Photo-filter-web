#ifndef INVERT_H
#define INVERT_H
#include "Effect.h"

using namespace std;

class Invert : public Effect
{
public:
    //constructor
    Invert();
    void process(int &red, int& green, int& blue);
private:

};

   
#endif