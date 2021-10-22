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

// void Course::addTest(Test test) {
//     this->tests[test.getId()] = test;
// }

// int Course::sumTestWeights() {
//     int sum = 0;
//     for(std::unordered_map<int, Test>::iterator it = tests.begin() ; it != tests.end(); it++) {
//         sum += it->second.getWeight();
//     } 
//     return sum;
// }

// std::unordered_map<int, Test> Course::getTests() {
//     return this->tests;
// }