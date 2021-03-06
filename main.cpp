#include <iostream>
#include "parsing.h"
#include "utilities.h"
#include "serialization.h"

using namespace std;


int main(int argc, char** argv) {
    if(argc < 6) {
        cerr << "List all csv files as command-line arguments in the following order: <courses-file> <students-file> <tests-file> <marks-file> <output-file>" << endl;
        return 1;
    }
    
    map<int, Test> tests;
    map<int, Course> courses;
    map<int, Student> students;
    vector<Mark> marks;
    try {
        courses = parseCourses(argv[1]);
    } catch(runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    } catch(exception& e) {
        cerr << "Error when parsing Courses file: " << e.what() << endl;
        return 1;
    }
    
    try {
        tests = parseTests(argv[3]);
    } catch(runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    } catch(exception& e) {
        cerr << "Error when parsing Tests file: " << e.what() << endl;
        return 1;
    } 

    if(!validCourseWeights(courses, tests)) {
        outputToFile(argv[5], generateErrorJson("Invalid course weights"));
        return 1;
    }

    try {
        students = parseStudents(argv[2]);
    } catch(runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    } catch(exception& e) {
        cerr << "Error when parsing Students file: " << e.what() << endl;
        return 1;
    }

    try {
        marks = parseMarks(argv[4]);
    } catch(runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    } catch(exception& e) {
        cerr << "Error when parsing Marks file: " << e.what() << endl;
        return 1;
    }

    students = populateStudentCourses(students, courses, tests, marks);
    outputToFile(argv[5], generateJson(students));
}



