#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "StudentCourse.h"

class Student {
private:
    int id;
    std::string name;
    std::vector<StudentCourse> courses;
public:
    Student(int id, std::string name);
};

#endif