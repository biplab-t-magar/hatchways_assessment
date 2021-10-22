#pragma once
#ifndef PARSING_H
#define PARSING_H

#include "Course.h"
#include "Student.h"
#include "Test.h"
#include "Mark.h"
#include <map>
#include <vector>

inline std::string removeSpaces(std::string str);
std::map<int, Course> parseCourses(const char* coursesFileName);
std::map<int, Test> parseTests(const char* testsFileName);
std::map<int , Student> parseStudents(const char* studentsFileName);
std::vector<Mark> parseMarks(const char* marksFileName);

#endif