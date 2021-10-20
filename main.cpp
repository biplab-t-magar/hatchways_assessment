#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    if(argc < 6) {
        std::cerr << "List all csv files as command-line arguments in the following order: <courses-file> <students-file> <tests-file> <marks-file> <output-file>" << endl;
        return 1;
    }
}