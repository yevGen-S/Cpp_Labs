#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <sstream>
#include <ostream>

#include "FileFormatter.h"

using namespace std;

#define ERROR_OPENING_FILE 1
#define EXIT_SUCCESS 0



string operator * (string a, unsigned int b) {
    string output = "";
    while (b--) {
        output += a;
    }
    return output;
}

vector<string> read_from_file(string& input_filename){
    ifstream file;
    file.open(input_filename);
    if(!file.is_open()){
        cout<<"File wasn't opened. Check if the name of file correct."<<endl;
    }

    string buff;
    vector<string>words;

    while(!file.eof()){
        getline(file, buff);
        istringstream iss(buff);
        copy(istream_iterator<string>(iss),
             istream_iterator<string>(),
             back_inserter <vector <string>>(words));
    }
    file.close();
    return words;
}


void print_words(vector <string>& words){
    for(auto &x: words){
        cout << x<< endl;
    }
}


int text_align_center(string& output_filename, vector<string>& words, int width){
    ofstream output;
    output.open(output_filename + ".txt");
    int counter = 0;
    string buff;
    int current_length = 0;
    if(output.is_open()){
        for(auto &word: words){
            int width_copy = width;

            if(current_length + word.length() + 1 < width_copy){
                current_length += (int)word.length() + 1;
                buff += (word + " ");
                continue;
            }
            else if (word.length() < width_copy){
                    int diff;
                    diff = (width - current_length)/2;
                    string spacer = " ";
                    output << spacer * diff;
                    output << buff;
                    output << spacer * diff;
                    output << '\n';
                    buff.clear();
                    current_length = 0;
            }

            if (word.length() > width){
                for (auto &letter: word){
                    output << letter;
                    counter++;
                    if(counter == width){
                        counter = 0;
                        output << '\n';
                    }
                }
                output << " ";
                width_copy -= counter;
            }

            if(word.length() == width){
                output << word;
                output << '\n';
            }


            if(!width_copy)
                output << '\n';

        }

    }
    else
        return ERROR_OPENING_FILE;

    output.close();
    return EXIT_SUCCESS;
}



int main(int argc, char** argv) {
    string filename = argv[1];
    int width = atoi(argv[2]);

    vector<string> text = read_from_file(filename);
    string output_filename = {"align_center"};
//    cin >> output_filename;

    output_filename = "D:\\Coding\\C++\\4sem\\Lab1\\files\\output\\" + output_filename;
    text_align_center(output_filename, text, width);
    return 0;
}