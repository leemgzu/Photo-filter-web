#include "Effect.h"
#include <iostream>

using namespace std;

Effect::Effect()
{
    effect_name = "no_effect";
}
void Effect::update_pixel(string selected_file)
{
    fstream in_stream;
    string file_name = "original_photo/" + selected_file + ".bmp";
    // Open as a binary file
    in_stream.open(file_name, ios::in | ios::binary);

    fstream out_stream;
    out_stream.open("output_photo/" + selected_file + "_" + effect_name + ".bmp", ios::out | ios::binary);

    int file_size = get_int(in_stream, 2); // Get the image dimensions
    int start = get_int(in_stream, 10);
    int width = get_int(in_stream, 18);
    int height = get_int(in_stream, 22);

    // Scan lines must occupy multiples of four bytes
    int scanline_size = width * 3;
    int padding = 0;
    if (scanline_size % 4 != 0)
    {
        padding = 4 - scanline_size % 4;
    }

    if (file_size != start + (scanline_size + padding) * height)
    {
        cout << "Not a 24-bit true color image file." << endl;
        return;
    }

    in_stream.seekg(0);
    out_stream.seekp(0);
    for (int i = 0; i < start; i++)
    {
        out_stream.put(in_stream.get());
    }

    int pos = start;
    for (int i = 0; i < height; i++) // For each scan line
    {
        for (int j = 0; j < width; j++) // For each pixel
        {
            in_stream.seekg(pos); // Go to the next pixel
            int blue = in_stream.get();
            int green = in_stream.get();
            int red = in_stream.get(); // Read the pixel

            // Process the pixel
            process(red, green, blue);

            out_stream.seekp(pos); // Go back to the start of the pixel

            out_stream.put(blue); // Write the pixel
            out_stream.put(green);
            out_stream.put(red);
            pos = pos + 3;
        }

        in_stream.seekg(padding, ios::cur); // Skip the padding
        pos = pos + padding;
    }

    in_stream.close();
    out_stream.close();
}

void Effect::process(int &red, int &green, int &blue)
{
}
string Effect::get_effect_name()
{
    return effect_name;
}

int get_int(fstream &in_stream, int offset)
{
    in_stream.seekg(offset);
    int result = 0;
    int base = 1;
    for (int i = 0; i < 4; i++)
    {
        result = result + in_stream.get() * base;
        base = base * 256;
    }
    return result;
}
