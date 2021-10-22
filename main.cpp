#include <iostream>
#include "parsing.h"
#include "objectPrep.h"

using namespace std;

int main(int argc, char** argv) {
    if(argc < 6) {
        cerr << "List all csv files as command-line arguments in the following order: <courses-file> <students-file> <tests-file> <marks-file> <output-file>" << endl;
        return 1;
    }
    
    unordered_map<int, Test> tests;
    unordered_map<int, Course> courses;
    unordered_map<int, Student> students;
    vector<Mark> marks;
    try {
        courses = parseCourses(argv[1]);
        tests = parseTests(argv[3]);
        students = parseStudents(argv[2]);
    } catch(runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    }
    
    if(testCourseWeights(courses, tests)) {
        cerr << "Bad weights" << endl;
    }

    try {
        students = parseStudents(argv[2]);
        marks = parseMarks(argv[4]);
    } catch(runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    }

    students = populateStudentCourses(students, courses, tests, marks);

}

