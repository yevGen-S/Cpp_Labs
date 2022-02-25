using namespace std;

#include "FileFormatter.h"

int main(int argc, char** argv){
    FileFormatter file_object = FileFormatter(argc, argv);
    file_object.read_from_file();
    file_object.text_align_center("align_center");
    file_object.print_words();
    return 0;
}

