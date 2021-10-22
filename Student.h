#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include "StudentCourse.h"

class Student {
private:
    int id;
    std::string name;
    std::vector<StudentCourse> courses;
public:
    Student(){}
    Student(int id, std::string name);
    int getId();
    std::string getName();
    void addCourse(StudentCourse course);
    
};

#endif