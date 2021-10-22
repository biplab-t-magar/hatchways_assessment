#include "parsing.h"
#include "utilities.h"
#include "serialization.h"
#include <assert.h>
#include <iostream>

using namespace std;

void testParseCourses();
void testParseTests();
void testParseStudents();
void testParseMarks();
void testValidCourseWeights();
void testPopulateStudentCourses();
void testGenerateJson();


int main() {
    testParseCourses();
    testParseTests();
    testParseStudents();
    testParseMarks();
    testValidCourseWeights();
    testPopulateStudentCourses();
    testGenerateJson();
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
    std::map<int, Student> students = parseStudents("./testFiles/test1/students.csv");

    assert(students[1].getId() == 1);
    assert(students[1].getName() == "A");

    assert(students[2].getId() == 2);
    assert(students[2].getName() == "B");

    assert(students[3].getId() == 3);
    assert(students[3].getName() == "C");

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

void testValidCourseWeights() {
    std::unordered_map<int, Course> courses = parseCourses("./testFiles/test1/courses.csv");
    std::unordered_map<int, Test> tests = parseTests("./testFiles/test1/tests.csv");
    
    assert(validCourseWeights(courses, tests));

    tests[1] = Test(1, 1, 90);

    assert(!validCourseWeights(courses, tests));

    std::cout << "Passed testValidCourseWeights" << std::endl;

}

void testPopulateStudentCourses() {
    std::unordered_map<int, Course> courses = parseCourses("./testFiles/test1/courses.csv");
    std::unordered_map<int, Test> tests = parseTests("./testFiles/test1/tests.csv");
    std::map<int, Student> students = parseStudents("./testFiles/test1/students.csv");
    std::vector<Mark> marks = parseMarks("./testFiles/test1/marks.csv");

    students = populateStudentCourses(students, courses, tests, marks);

    assert(students[1].calculateTotalAverage() * 100 == 7203);
    assert(students[2].calculateTotalAverage() * 100 == 6215);
    assert(students[3].calculateTotalAverage() * 100 == 7203);

    std::cout << "Passed testPopulateStudentCourses" << std::endl;
}

void testGenerateJson() {
    std::unordered_map<int, Course> courses = parseCourses("./testFiles/test1/courses.csv");
    std::unordered_map<int, Test> tests = parseTests("./testFiles/test1/tests.csv");
    std::map<int, Student> students = parseStudents("./testFiles/test1/students.csv");
    std::vector<Mark> marks = parseMarks("./testFiles/test1/marks.csv");
    students = populateStudentCourses(students, courses, tests, marks);

    std::cout << generateJson(students) << std::endl;

}