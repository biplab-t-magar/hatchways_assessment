#include "objectPrep.h"

using namespace std;

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

unordered_map<int, Student> populateStudentCourses(unordered_map<int, Student> students, unordered_map<int, Course> courses, unordered_map<int, Test> tests, vector<Mark> marks) {
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
    return round(100 * weightedMark) / 100.0;
}