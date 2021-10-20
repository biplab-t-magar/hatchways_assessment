#include "parsing.h"
#include <assert.h>
#include <iostream>

using namespace std;

void testParseCourses();
void testParseAndAddTests();

int main() {
    testParseCourses();
    testParseAndAddTests();
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

void testParseAndAddTests() {

    //populate courses unordered map
    //make sure parseCourse is well tested
    testParseCourses();

    std::unordered_map<int, Course> courses = parseCourses("./testFiles/test1/courses.csv");

    //parse tests and add to courses objects
    courses = parseAndAddTests("./testFiles/test1/tests.csv", courses);

    int results[7][3] = {{1, 1, 10}, {2, 1, 40}, {3, 1, 50}, {4, 2, 40}, {5, 2, 60}, {6, 3, 90}, {7, 3, 10}};

    assert(courses.size() == 3);

    //test first course
    std::vector<Test> tests = courses[1].getTests();
    assert(tests[0].getWeight() == 10);
    assert(tests[1].getWeight() == 40);
    assert(tests[2].getWeight() == 50);
    
    //test second course
    tests = courses[2].getTests();
    assert(tests[0].getWeight() == 40);
    assert(tests[1].getWeight() == 60);

    //test third course
    tests = courses[3].getTests();
    assert(tests[0].getWeight() == 90);
    assert(tests[1].getWeight() == 10);

    std::cout << "Passed testParseAndAddTests" << std::endl;

    
}