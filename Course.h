#pragma once
#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include "Test.h"

class Course {
private:
    int id;
    std::string name;
    std::string teacher;
    std::vector<Test> tests;
public:
    public:
    Course(){}
    Course(int id, std::string name, std::string teacher);
    int getId();
    std::string getTeacher();

    void addTest(Test test);
    int sumTestWeights();
};

#endif