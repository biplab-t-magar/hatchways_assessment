#include "serialization.h"

#include <sstream>

using namespace std;

string generateCourseJson(StudentCourse course) {
    stringstream ss;
    ss << "        {\n";
    ss << "          \"id\": " << course.getId() << ",\n";
    ss << "          \"name\": \"" << course.getName() << "\",\n";
    ss << "          \"teacher\": \"" << course.getTeacher() << "\",\n";
    ss << "          \"courseAverage\": " << course.getCourseAverage() << "\n";
    ss << "        }";

    return ss.str();
}

string generateStudentJson(Student student) {
    stringstream ss;
    ss << "    {\n";
    ss << "      \"id\": " << student.getId() << ",\n";
    ss << "      \"name\": \"" << student.getName() << "\",\n";
    ss << "      \"totalAverage\": " << student.calculateTotalAverage() << ",\n";
    ss << "      \"courses\": [\n";
    
    unordered_map<int, StudentCourse> courses = student.getCoursesTaken();
    unordered_map<int, StudentCourse>::iterator stepAheadIterator;
    for(unordered_map<int, StudentCourse>::iterator it = courses.begin(); it != courses.end(); it++) {
        ss << generateCourseJson(it->second);
        stepAheadIterator = it;
        if(++stepAheadIterator != courses.end()) ss << ",";
        ss << "\n";
    }

    ss << "      ]\n";
    ss << "    }";

    return ss.str();
}

string generateJson(map<int, Student> students) {
    stringstream ss;
    ss << "{\n";
    ss << "  \"students\": [\n";
    map<int, Student>::iterator stepAheadIterator;
    for(map<int, Student>::iterator it = students.begin(); it != students.end(); it++) {
        ss << generateStudentJson(it->second);
        stepAheadIterator = it;
        if(++stepAheadIterator != students.end()) ss << ",";
        ss << "\n";
    }

    ss << "  ]\n";
    ss << "}";

    return ss.str();
}