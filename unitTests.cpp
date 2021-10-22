#include "parsing.h"
#include "objectPrep.h"
#include <assert.h>
#include <iostream>

using namespace std;

void testParseCourses();
void testParseTests();
void testParseStudents();
void testParseMarks();

int main() {
    testParseCourses();
    testParseTests();
    testParseStudents();
    testParseMarks();
}

void testParseCourses() {
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

    std::cout << "Passed testParseCourses" << std::endl;
}

void testParseTests() {

    std::unordered_map<int, Test> tests = parseTests("./testFiles/test1/tests.csv");

    assert(tests[1].getId() == 1);
    assert(tests[1].getCourseId() == 1);
    assert(tests[1].getWeight() == 10);
    
    assert(tests[2].getId() == 2);
    assert(tests[2].getCourseId() == 1);
    assert(tests[2].getWeight() == 40);
    
    assert(tests[3].getId() == 3);
    assert(tests[3].getCourseId() == 1);
    assert(tests[3].getWeight() == 50);
    
    assert(tests[4].getId() == 4);
    assert(tests[4].getCourseId() == 2);
    assert(tests[4].getWeight() == 40);
    
    assert(tests[5].getId() == 5);
    assert(tests[5].getCourseId() == 2);
    assert(tests[5].getWeight() == 60);

    std::cout << "Passed testParseAndAddTests" << std::endl;
}

void testParseStudents() {
    std::unordered_map<int, Student> courses = parseStudents("./testFiles/test1/students.csv");

    assert(courses[1].getId() == 1);
    assert(courses[1].getName() == "A");

    assert(courses[2].getId() == 2);
    assert(courses[2].getName() == "B");

    assert(courses[3].getId() == 3);
    assert(courses[3].getName() == "C");

    std::cout << "Passed testParseStudents" << std::endl;
}

void testParseMarks() { 

    std::vector<Mark> marks = parseMarks("./testFiles/test1/marks.csv");

    assert(marks[0].getTestId() == 1);
    assert(marks[0].getStudentId() == 1);
    assert(marks[0].getMark() == 78);

    assert(marks[1].getTestId() == 2);
    assert(marks[1].getStudentId() == 1);
    assert(marks[1].getMark() == 87);

    assert(marks[2].getTestId() == 3);
    assert(marks[2].getStudentId() == 1);
    assert(marks[2].getMark() == 95);


    std::cout << "Passed testParseCourses" << std::endl;
}

void testPopulateStudentCourses() {
    courses = parseCourses("./testFiles/test1/courses.csv");
    tests = parseTests("./testFiles/test1/tests.csv");
    students = parseStudents("./testFiles/test1/students.csv");
    marks = parseMarks("./testFiles/test1/marks.csv");

}