#pragma once
#ifndef STUDENT_COURSE_H
#define STUDENT_COURSE_H

#include "Course.h"
#include "Test.h"

class StudentCourse {
private:
    Course course;
    float totalMarks = 0;
public:
    StudentCourse(){}
    StudentCourse(int id, std::string name, std::string teacher);
    StudentCourse(Course course);
    void addWeightedMarks(float marks);
    int getId();
    std::string getTeacher();
    std::string getName();
    float getCourseAverage();
};

#endif