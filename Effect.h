#ifndef EFFECT_H
#define EFFECT_H

#include <fstream>
#include <vector>
using namespace std;

class Effect
{
public:
    //constructor
    Effect();
    void update_pixel(string file_name);
    virtual void process(int &red, int &green, int &blue);
    //to access the protected member
    string get_effect_name();

protected:
    string effect_name;
};
/**
   Gets an integer from a binary in_stream.
   @param in_stream the in_stream
   @param offset the offset at which to read the integer
   @return the integer starting at the given offset
*/
int get_int(fstream &stream, int offset);

#endif