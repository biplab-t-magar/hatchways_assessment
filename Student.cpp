#include "Student.h"

Student::Student(int id, std::string name) {
    this->id = id;
    this->name = name;
}    

int Student::getId() {
    return id;
}

std::string Student::getName() {
    return name;
}
