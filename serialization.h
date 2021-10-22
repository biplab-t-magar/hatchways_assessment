#pragma once
#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include "Student.h"
#include <map>

std::string generateCourseJson(StudentCourse course);
std::string generateStudentJson(Student student);
std::string generateJson(std::map<int, Student> students);
std::string generateErrorJson(std::string errorMessage);

#endif