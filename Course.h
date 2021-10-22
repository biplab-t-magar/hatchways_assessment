#pragma once
#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <unordered_map>

class Course {
private:
    int id;
    std::string name;
    std::string teacher;
    // std::unordered_map<int, Test> tests;
public:
    public:
    Course(){}
    Course(int id, std::string name, std::string teacher);
    int getId();
    std::string getTeacher();
    std::string getName();
    // void addTest(Test test);
    // int sumTestWeights();
    // std::unordered_map<int, Test> getTests();
    // void print() {
    //     std::cout << "Course " << id << ", " << name << ", " << teacher << std::endl;
    // }
};

#endif