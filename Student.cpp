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

bool Student::courseTaken(int courseId) {
    return courses.count(courseId) > 0;
}

void Student::addCourse(StudentCourse course) {
    if(courses.count(course.getId()) == 0) {
        courses[course.getId()] = course;
    }
}

void Student::addWeightedCourseMark(int courseId, float weightedMark) {
    if(courses.count(courseId) > 0) {
        courses[courseId].addWeightedMarks(weightedMark);
    }
}


float Student::calculateTotalAverage() {
    float totalAverage;
    for(std::unordered_map<int, StudentCourse>::iterator it = courses.begin(); it != courses.end(); it++) {
        totalAverage += it->second.getCourseAverage();
    }
    return round( 100.0 * totalAverage / this->courses.size()) / 100.0;
}

std::unordered_map<int, StudentCourse> Student::getCoursesTaken() {
    return courses;
}
