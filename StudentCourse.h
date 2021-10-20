#pragma once
#ifndef STUDENT_COURSE_H
#define STUDENT_COURSE_H

#include "Course.h"

class StudentCourse {
private:
    Course course;
    float courseAverage;

public:
    StudentCourse(int id, std::string name, std::string teacher);
};

#endif