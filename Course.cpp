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

void Course::addTest(Test test) {
    this->tests.push_back(test);
}

int Course::sumTestWeights() {
    int sum = 0;
    for(std::vector<Test>::iterator it = tests.begin() ; it < tests.end(); it++) {
        sum += it->getWeight();
    } 
    return sum;
}

std::vector<Test> Course::getTests() {
    return this->tests;
}