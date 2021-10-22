#pragma once
#ifndef UTILITIES_H
#define UTILITIES_H

#include <unordered_map>
#include <map>
#include <vector>
#include "Course.h"
#include "Test.h"
#include "Student.h"
#include "Mark.h"

float percentToWeightedMark(int, int);
bool validCourseWeights(std::unordered_map<int, Course>, std::unordered_map<int, Test>);
std::map<int, Student> populateStudentCourses(std::map<int, Student>, std::unordered_map<int, Course>, std::unordered_map<int, Test>, std::vector<Mark>);

#endif