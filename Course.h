#pragma once
#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
private:
    int id;
    std::string name;
    std::string teacher;
public:
    public:
    Course(){}
    Course(int id, std::string name, std::string teacher);
    int getId();
    std::string getTeacher();
    std::string getName();
};

#endif