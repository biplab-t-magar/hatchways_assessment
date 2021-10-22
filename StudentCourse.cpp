#include "StudentCourse.h"


StudentCourse::StudentCourse(int id, std::string name, std::string teacher) {
    course = Course(id, name, teacher);
}
StudentCourse::StudentCourse(Course course) {
    this->course = course;
}

void StudentCourse::addMarks(int testId, int marks) {
    // marks[testId] = marks;
}