#pragma once
#ifndef ASSESSMENT_H
#define ASSESSMENT_H

#include "Course.h"
#include <unordered_map>


inline std::string removeSpaces(std::string str);
std::unordered_map<int, Course> parseCourses(const char* coursesFileName);
std::unordered_map<int, Course> parseAndAddTests(const char* testsFileName, std::unordered_map<int, Course> courses);

#endif