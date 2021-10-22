#pragma once
#ifndef STUDENT_COURSE_H
#define STUDENT_COURSE_H

#include "Course.h"
#include "Test.h"

class StudentCourse {
private:
    Course course;
    float courseAverage;
    int totalMarks;
public:
    StudentCourse(){}
    StudentCourse(int id, std::string name, std::string teacher);
    StudentCourse(Course course);
    void addWeightedMarks(int marks);
    int getId();
};

#endif