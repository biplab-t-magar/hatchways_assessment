#include "StudentCourse.h"


StudentCourse::StudentCourse(int id, std::string name, std::string teacher) {
    course = Course(id, name, teacher);
}

StudentCourse::StudentCourse(Course course) {
    this->course = course;
}

void StudentCourse::addWeightedMarks(float marks) {
    totalMarks += marks;
}

int StudentCourse::getId() {
    return course.getId();
}

float StudentCourse::getCourseAverage() {
    return totalMarks;
}

std::string StudentCourse::getTeacher() {
    return course.getTeacher();
}
std::string StudentCourse::getName() {
    return course.getName();
}
