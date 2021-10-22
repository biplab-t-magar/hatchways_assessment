#pragma once
#ifndef UTILITIES_H
#define UTILITIES_H

#include <map>
#include <vector>
#include "Course.h"
#include "Test.h"
#include "Student.h"
#include "Mark.h"

float percentToWeightedMark(int, int);
bool validCourseWeights(std::map<int, Course>, std::map<int, Test>);
std::map<int, Student> populateStudentCourses(std::map<int, Student>, std::map<int, Course>, std::map<int, Test>, std::vector<Mark>);
void outputToFile(const char* outputFileName, std::string fileContent);

#endif