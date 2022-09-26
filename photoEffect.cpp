#include <fstream>
#include <string>
#include <iostream>
#include "Effect.h"
#include "Sunset.h"
#include "Grayscale.h"
#include "Invert.h"
#include "dirent.h"

using namespace std;

//To parse the query string from html
void parse_query_string(string s, vector<string> &parsed_answers)
{
    //parse the sentence from html
    //i.e. Q1=hi&Q2=Denmark
    string delimiter1 = "&";
    string delimiter2 = "=";

    int position1 = 0;
    int position2 = 0;
    string token;
    string yourAnswer;
    //parse the sentence into token: i.e q1=hi
    int counter = 0;
    while ((position1 = s.find(delimiter1)) != string::npos)
    {
        token = s.substr(0, position1);
        //parse the token into answer: i.e hi
        position2 = s.find(delimiter2);

        yourAnswer = token.substr(position2 + 1, position1 - (position2 + 1));
        parsed_answers.push_back(yourAnswer);

        s.erase(0, position1 + delimiter1.length());
    }

    position2 = s.find(delimiter2);
    yourAnswer = s.substr(position2 + 1, position1 - (position2 + 1));
    parsed_answers.push_back(yourAnswer);
}

int main()
{
    cout << "Content-type: text/html\n\r\n\r";

    //to get answers from user input in the cgi progrm
    string s = getenv("QUERY_STRING");
    vector<string> answers;
    parse_query_string(s, answers);
    //to store address of the Effect class

    vector<Effect *> effects;
    effects.push_back(new Sunset());
    effects.push_back(new Grayscale());
    effects.push_back(new Invert());
    //answer[i] is string type and we need to convert the string to int
    //so we can use it as the index of effects
    effects[stoi(answers[1])]->update_pixel(answers[0]);
    string effectName = effects[stoi(answers[1])] -> get_effect_name();
    string fileWithEffect = answers[0] + "_" + effectName + ".bmp";

    cout << "<hl>Original Photo <br></hl>";
    cout << "<img width=\"50%\" src=\"../original_photo/" 
            + answers[0] + ".bmp\" alt=\"photo 1\" /><br>";
    cout << "<hl>Photo With " << effectName << " Effect <br></hl>";
    cout << "<img width=\"50%\" src=\"../output_photo/" 
            + fileWithEffect + "\" alt=\"photo 1\" />";

    // A button to go back to the previous page
    cout << "<div><button onclick=\"history.back()\">Back<button></div>";

    return 0;
}