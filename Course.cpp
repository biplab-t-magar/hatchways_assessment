#include "Course.h" 
// Course::Course(){}

Course::Course(int id, std::string name, std::string teacher) {
    this->id = id;
    this->name = name;
    this->teacher = teacher;
}

int Course::getId() {
    return id;
}

std::string Course::getName() {
    return name;
}

std::string Course::getTeacher() {
    return teacher;
}