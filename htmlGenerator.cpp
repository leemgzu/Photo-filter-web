#include <iostream>
#include <fstream>
#include "direntry.h"

using namespace std;

void find(DirectoryEntry directory, string extension, vector<DirectoryEntry> &results)
{

    vector<DirectoryEntry> entries = directory.children();
    for (int i = 0; i < entries.size(); i++)
    {
        DirectoryEntry entry = entries[i];
        if (entry.extension() == extension)
        {
            results.push_back(entry);
        }
    }
}

int main()
{
    ofstream output_file("photoEffect1.html", ofstream::out);
    string current_dir_name = "original_photo";

    output_file << "<html><head><title>Photo Effect Program</title></head>";
    output_file << "<body> \
    <h1>Photo Effect Program</h1> \
    <h3>This program has selected three signature photo effects: Sunset, Grayscale, Invert <br></h3>\
    <h1>Photo Gallery</h1>";

    DirectoryEntry current_dir(current_dir_name);

    vector<DirectoryEntry> bmp_entries;
    find(current_dir, "bmp", bmp_entries);
    vector<string> file_names;

    for (int i = 0; i < bmp_entries.size(); i++)
    {
        string entry_name = bmp_entries[i].name();
        string file_name = entry_name.substr(
            current_dir_name.length() + 1,
            entry_name.length() - current_dir_name.length() - 5);
        file_names.push_back(file_name);

        output_file << "<figure>\n";
        output_file << "<img width=\"20%\" src=\""
                    << entry_name << "\" alt=\"Photo"
                    << i << "\" />";
        output_file << "<figcaption>" << file_name << "</figcaption>"
                    << "</figure>";
    }

    output_file << "<form action=\"cgi-bin/photoEffect.cgi\">"
                << "<h2>Please select one photo in the gallery:</h2>";

    for (int i = 0; i < file_names.size(); i++)
    {
        output_file << "<div>";
        output_file
            << "<input type=\"radio\" name=\"picture\" "
            << "id=\"" << file_names[i] << "\" "
            << "value=\"" << file_names[i] << "\" >"
            << "\n"
            << "<label for=\"" << file_names[i] << "\">"
            << file_names[i] << "</label>";

        output_file << "</div>";
    }
    output_file << "<p>Please select your preferred photo effect:</p>";
    output_file << "<div>";
    output_file << "<input type=\"radio\" id=\"Sunset\" name=\"effect\" value=\"0\"> \n \
                    <label for=\"Sunset\">Sunset</label> \n"
                << "<input type=\"radio\" id=\"Grayscale\" name=\"effect\" value=\"1\"> \n \
                    <label for=\"Grayscale\">Grayscale</label>"
                << "<input type=\"radio\" id=\"Invert\" name=\"effect\" value=\"2\"> \n \
                    <label for=\"Invert\">Invert</label> \
                    </div>";
    output_file << "<div> \n \
                    <button type=\"submit\">Submit</button> \n \
                    </div>";

    output_file << "</form></body></html>";
    output_file.close();
    return 0;
}