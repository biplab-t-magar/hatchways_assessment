#pragma once
#ifndef STUDENT_COURSE_H
#define STUDENT_COURSE_H

#include "Course.h"
#include "Test.h"

class StudentCourse {
private:
    Course course;
    float courseAverage;
    std::unordered_map<int, Test> marks;
public:
    StudentCourse(int id, std::string name, std::string teacher);
    StudentCourse(Course course);
    void addMarks(int testId, int marks);
    
};

#endif