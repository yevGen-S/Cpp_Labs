
#include "FileFormatter.h"
using namespace std;


string operator * (string a, unsigned int b) {
    string output = "";
    while (b--) {
        output += a;
    }
    return output;
}

FileFormatter::FileFormatter(int argc, char** argv){
    filename = argv[1];
    width = atoi(argv[2]);
}



void FileFormatter::read_from_file(){
    ifstream file;
    file.open(this->filename);
    if(!file.is_open()){
    cout<<"File wasn't opened. Check if the name of file correct."<<endl;
    }

    string buff;
    while(!file.eof()){
    getline(file, buff);
    istringstream iss(buff);
    copy(istream_iterator<string>(iss),
            istream_iterator<string>(),
            back_inserter <vector <string>>(this->words));
    }
    file.close();
}

void FileFormatter::print_words(){
    for(auto &x: words){
        cout << x<< endl;
    }
}

void FileFormatter::spacer(string& buff, int current_length, ofstream& output){
    int diff;
    diff = (width - current_length) / 2;
    string space = " ";
    output << (space * diff) + buff + (space * diff) + '\n';
    buff.clear();
}


int FileFormatter::text_align_center(string output_filename){
    ofstream output;
    output.open( output_filename = R"(D:\Coding\C++\4sem\Lab1\files\output\)" + output_filename + ".txt");
    int counter = 0;
    string buff;
    int current_length = 0;
    if(output.is_open()){

        for(auto &word: words) {
            if (current_length + word.length() + 1 <= width) {
                current_length += (int) word.length() + 1;
                buff += word + " ";
                continue;
            }

            if (current_length) {
                spacer(buff, current_length, output);
            }

            if (word.length() > width) {
                for (auto &letter: word) {
                    counter++;
                    buff += letter;
                    if (counter == width) {
                        counter = 0;
                        output << buff + '\n';
                        buff.clear();
                    }
                }
                buff += " ";
                current_length = (int)buff.length();
                counter =0;
                continue;
            }

            if (word.length() <= width){
                buff += word + " ";
                current_length = (int)buff.length();
            }
        }
        spacer(buff,current_length, output);
    }
    else
        return ERROR_OPENING_FILE;

    output.close();
    return EXIT_SUCCESS;
}