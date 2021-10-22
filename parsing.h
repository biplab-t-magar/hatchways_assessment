#pragma once
#ifndef PARSING_H
#define PARSING_H

#include "Course.h"
#include "Student.h"
#include "Test.h"
#include "Mark.h"
#include <unordered_map>

inline std::string removeSpaces(std::string str);
std::unordered_map<int, Course> parseCourses(const char* coursesFileName);
std::unordered_map<int, Test> parseTests(const char* testsFileName);
std::unordered_map<int , Student> parseStudents(const char* studentsFileName);
std::vector<Mark> parseMarks(const char* marksFileName);

#endif