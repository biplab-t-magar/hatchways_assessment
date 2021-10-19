#include "StudentCourse.h"

StudentCourse::StudentCourse(int id, std::string name, std::string teacher) {
    course = Course(id, name, teacher);
}

