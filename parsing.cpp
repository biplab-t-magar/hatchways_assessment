#include <iostream>
#include <fstream>
#include <sstream>

#include "parsing.h"
#include "Course.h"
#include "Test.h"


using namespace std;

inline string removeSpaces(string str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

inline string removeOuterSpaces(string str) {
    str.erase(str.find_last_not_of(' ') + 1);        
    str.erase(0, str.find_first_not_of(' '));   
    return str;
}

unordered_map<int, Course> parseCourses(const char* coursesFileName) {
    ifstream coursesFile;

    string fileName(coursesFileName);
    cout << fileName << endl;
    coursesFile.open(fileName);
    if(!coursesFile.is_open()) {
        string msg(coursesFileName);
        throw runtime_error("Cannot open the file " + msg);
    }

    string row;
    string word;
    unordered_map<int, Course> courses;

    //remove header row
    getline(coursesFile, row);
    row = removeSpaces(row);
    if(row != "id,name,teacher") throw runtime_error("Invalid courses file");

    while(getline(coursesFile, row)) {
        stringstream ss(row);

        getline(ss, word, ',');
        word = removeOuterSpaces(word);
        int courseId = stoi(word);

        getline(ss, word, ',');
        word = removeOuterSpaces(word);
        string courseName = word;

        getline(ss, word, ',');
        word = removeOuterSpaces(word);
        string teacher = word;

        courses[courseId] = Course(courseId, courseName, teacher);
    }

    coursesFile.close();
    return courses;
}

unordered_map<int, Course> parseAndAddTests(const char* testsFileName, unordered_map<int, Course> courses) {
    ifstream testsFile;

    testsFile.open(testsFileName);
    if(!testsFile.is_open()) {
        string msg(testsFileName);
        throw runtime_error("Cannot open the file " + msg);
    }

    string row;
    string word;

    //remove header row
    getline(testsFile, row);
    row = removeSpaces(row);
    if(row != "id,course_id,weight") throw runtime_error("Invalid tests file");

    while(getline(testsFile, row)) {
        stringstream ss(row);

        getline(ss, word, ',');
        word = removeOuterSpaces(word);
        int testId = stoi(word);

        getline(ss, word, ',');
        word = removeOuterSpaces(word);
        int courseId = stoi(word);

        getline(ss, word, ',');
        word = removeOuterSpaces(word);
        int weight = stoi(word);

        courses[courseId].addTest(Test(testId, weight));
    }

    testsFile.close();
    return courses;
}
