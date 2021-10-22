#include <iostream>
#include "parsing.h"

using namespace std;

bool testCourseWeights(unordered_map<int, Course> courses, unordered_map<int, Test> tests);

int main(int argc, char** argv) {
    if(argc < 6) {
        cerr << "List all csv files as command-line arguments in the following order: <courses-file> <students-file> <tests-file> <marks-file> <output-file>" << endl;
        return 1;
    }
    
    unordered_map<int, Test> tests;
    unordered_map<int, Course> courses;
    unordered_map<int, Student> students;
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
    } catch(runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    }


}

bool testCourseWeights(unordered_map<int, Course> courses, unordered_map<int, Test> tests) {
    std:unordered_map<int, int> totalCourseWeights;

    //calculate total weights for each course
    for(unordered_map<int,Test>::iterator it = tests.begin(); it != tests.end(); it++) {
        if(totalCourseWeights.count(it->second.getCourseId()) == 0) {
            totalCourseWeights[it->second.getCourseId()] = 0;
        } else {
            totalCourseWeights[it->second.getCourseId()] += it->second.getWeight();
        }
    }

    //check if total weights all add up to 100
    for(unordered_map<int, int>::iterator it = totalCourseWeights.begin(); it != totalCourseWeights.end(); it++) {
        if(it->second != 100) {
            return false;
        }
    }
    return true;
}