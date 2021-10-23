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

map<int, Course> parseCourses(const char* coursesFileName) {
    ifstream coursesFile;

    coursesFile.open(coursesFileName);
    if(!coursesFile.is_open()) {
        string msg(coursesFileName);
        throw runtime_error("Cannot open the file " + msg);
    }

    string row;
    string word;
    map<int, Course> courses;

    //remove header row
    getline(coursesFile, row);
    row = removeSpaces(row);
    if(row != "id,name,teacher") throw runtime_error("Invalid courses file");

    while(getline(coursesFile, row)) {
        if(removeSpaces(row) == "" || removeSpaces(row) == "\n") continue;
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
    if(coursesFile.is_open()) {
        string msg(coursesFileName);
        throw runtime_error("Cannot close the file " + msg);
    }
    return courses;
}

map<int, Test> parseTests(const char* testsFileName) {
    ifstream testsFile;

    testsFile.open(testsFileName);
    if(!testsFile.is_open()) {
        string msg(testsFileName);
        throw runtime_error("Cannot open the file " + msg);
    }

    string row;
    string word;
    map<int, Test> tests;

    //remove header row
    getline(testsFile, row);
    row = removeSpaces(row);
    if(row != "id,course_id,weight") throw runtime_error("Invalid tests file");


    while(getline(testsFile, row)) {
        if(removeSpaces(row) == "" || removeSpaces(row) == "\n") continue;
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


        tests[testId] = Test(testId, courseId, weight);

    }


    testsFile.close();
    if(testsFile.is_open()) {
        string msg(testsFileName);
        throw runtime_error("Cannot close the file " + msg);
    }
    return tests;
}

map<int , Student> parseStudents(const char* studentsFileName) {

    ifstream studentsFile;

    studentsFile.open(studentsFileName);
    if(!studentsFile.is_open()) {
        string msg(studentsFileName);
        throw runtime_error("Cannot open the file " + msg);
    }

    string row;
    string word;
    map<int, Student> students;

    //remove header row
    getline(studentsFile, row);
    row = removeSpaces(row);
    if(row != "id,name") throw runtime_error("Invalid students file");

    while(getline(studentsFile, row)) {
        if(removeSpaces(row) == "" || removeSpaces(row) == "\n") continue;
        stringstream ss(row);

        getline(ss, word, ',');
        word = removeOuterSpaces(word);
        int studentId = stoi(word);

        getline(ss, word, ',');
        word = removeOuterSpaces(word);
        string studentName = word;

        students[studentId] = Student(studentId, studentName);
    }

    studentsFile.close();
    if(studentsFile.is_open()) {
        string msg(studentsFileName);
        throw runtime_error("Cannot close the file " + msg);
    }


    return students;
}

vector<Mark> parseMarks(const char* marksFileName) {
    ifstream marksFile;

    marksFile.open(marksFileName);
    if(!marksFile.is_open()) {
        string msg(marksFileName);
        throw runtime_error("Cannot open the file " + msg);
    }

    string row;
    string word;
    vector<Mark> marks;

    //remove header row
    getline(marksFile, row);
    // row = removeSpaces(row);

    // if(row != "test_id,student_id,mark") {
    //     throw runtime_error("Invalid marks file");
    // }

    while(getline(marksFile, row)) {
        if(removeSpaces(row) == "" || removeSpaces(row) == "\n") continue;
        stringstream ss(row);

        getline(ss, word, ',');
        word = removeOuterSpaces(word);
        int testId = stoi(word);

        getline(ss, word, ',');
        word = removeOuterSpaces(word);
        int studentId = stoi(word);

        getline(ss, word, ',');
        word = removeOuterSpaces(word);
        int mark = stoi(word);

        marks.push_back(Mark(testId, studentId, mark));
    }

    marksFile.close();
    if(marksFile.is_open()) {
        string msg(marksFileName);
        throw runtime_error("Cannot close the file " + msg);
    }

    return marks;

}