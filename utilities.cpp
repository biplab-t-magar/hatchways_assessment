#include "utilities.h"
#include <fstream>
#include <math.h>

using namespace std;

bool validCourseWeights(map<int, Course> courses, map<int, Test> tests) {
    std:map<int, int> totalCourseWeights;

    //calculate total weights for each course
    for(map<int,Test>::iterator it = tests.begin(); it != tests.end(); it++) {
        if(totalCourseWeights.count(it->second.getCourseId()) == 0) {
            totalCourseWeights[it->second.getCourseId()] = it->second.getWeight();
        } else {
            totalCourseWeights[it->second.getCourseId()] = totalCourseWeights[it->second.getCourseId()] + it->second.getWeight();
        }
    }

    //check if total weights all add up to 100
    for(map<int, int>::iterator it = totalCourseWeights.begin(); it != totalCourseWeights.end(); it++) {
        if(it->second != 100) {
            return false;
        }
    }
    return true;
}

map<int, Student> populateStudentCourses(map<int, Student> students, map<int, Course> courses, map<int, Test> tests, vector<Mark> marks) {
    for(vector<Mark>::iterator it = marks.begin(); it != marks.end(); it++) {
        int studentId = it->getStudentId();
        int testId = it->getTestId();
        int courseId = tests[testId].getCourseId();
        if(!students[studentId].courseTaken(courseId)) {
            students[studentId].addCourse(StudentCourse(courses[courseId]));
        }
        students[studentId].addWeightedCourseMark(courseId, percentToWeightedMark(it->getMark(), tests[testId].getWeight()));
    }
    return students;
}

float percentToWeightedMark(int percent, int weight) {
    float weightedMark =  percent / 100.00 * weight; 
    return roundf(100 * weightedMark) / 100.0;
}

void outputToFile(const char* outputFileName, string fileContent) {
    ofstream outputFile;

    outputFile.open(outputFileName);
    if(!outputFile.is_open()) {
        string msg(outputFileName);
        throw runtime_error("Cannot open the file " + msg);
    }

    outputFile << fileContent;

    outputFile.close();
    if(outputFile.is_open()) {
        string msg(outputFileName);
        throw runtime_error("Cannot close the file " + msg);
    }
}
