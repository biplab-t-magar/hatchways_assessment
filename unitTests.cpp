#include "parsing.h"
#include <assert.h>
#include <iostream>

using namespace std;

void testParseCoursesFunction();

int main() {
    testParseCoursesFunction();
}

void testParseCoursesFunction() {
    std::unordered_map<int, Course> courses = parseCourses("./testFiles/test1/courses.csv");

    assert(courses[1].getId() == 1);
    assert(courses[1].getName() == "Biology");
    assert(courses[1].getTeacher() == "Mr. D");

    assert(courses[2].getId() == 2);
    assert(courses[2].getName() == "History");
    assert(courses[2].getTeacher() == "Mrs. P");

    assert(courses[3].getId() == 3);
    assert(courses[3].getName() == "Math");
    assert(courses[3].getTeacher() == "Mrs. C");

    std::cout << "Passed testParseCoursesFunction" << std::endl;
}

void testParseAndAddTestsFunction() {

    //populate courses unordered map
    //make sure parseCourse is well tested
    testParseCoursesFunction();

    std::unordered_map<int, Course> courses = parseCourses("./testFiles/test1/courses.csv");

    //parse tests and add to courses objects
    courses = parseAndAddTests("./testFiles/test1/tests.csv", courses);
}