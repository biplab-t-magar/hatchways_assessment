#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include "StudentCourse.h"

class Student {
private:
    int id;
    std::string name;
    std::unordered_map<int, StudentCourse> courses;
public:
    Student(){}
    Student(int id, std::string name);
    int getId();
    std::string getName();
    bool courseTaken(int courseId);
    void addCourse(StudentCourse course);
    void addWeightedCourseMark(int courseId, float weightedMark);
    float calculateTotalAverage();
    std::unordered_map<int, StudentCourse> getCoursesTaken();
};

#endif