#pragma once
#ifndef OBJECT_PREP_H
#define OBJECT_PREP_H

#include <unordered_map>
#include <vector>
#include "Course.h"
#include "Test.h"
#include "Student.h"
#include "Mark.h"

float percentToWeightedMark(int, int);
bool testCourseWeights(std::unordered_map<int, Course>, std::unordered_map<int, Test>);
std::unordered_map<int, Student> populateStudentCourses(std::unordered_map<int, Student>, std::unordered_map<int, Course>, std::unordered_map<int, Test>, std::vector<Mark>);

#endif