#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
    if(argc < 6) {
        cerr << "List all csv files as command-line arguments in the following order: <courses-file> <students-file> <tests-file> <marks-file> <output-file>" << endl;
        return 1;
    }
}


inline string removeSpaces(string str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}


unordered_map<int, Course> parseCourses(const char* coursesFileName) {
    ifstream coursesFile;

    coursesFile.open(coursesFileName);
    if(!coursesFile.is_open()) {
        string msg(coursesFileName);
        msg = "Cannot open the file " + msg;
        throw runtime_error("Cannot open the file " + msg);
    }

    string row;
    string word;
    unordered_map<int, Course> courses;

    //remove header row
    getline(coursesFile, row);
    row = removeSpaces(row);
    if(row != "id,course_id,weight") throw runtime_error("Invalid courses file");

    while(getline(coursesFile, row)) {
        row = removeSpaces(row);
        stringstream ss(row);

        getline(ss, word, ',');
        int courseId = stoi(word);

        getline(ss, word, ',');
        string courseName = word;

        getline(ss, word, ',');
        string teacher = word;

        courses[courseId] = Course(courseId, courseName, teacher);
    }

    coursesFile.close();
    return courses;
}

unordered_map<int, Course> parseAndAddTests(const char* testsFileName, unordered_map<int, Course> courses) {
    ifstream testsFile;

    testsFile.open(testsFileName);
    if(!testsFile.is_open()) {
        string msg(testsFileName);
        msg = "Cannot open the file " + msg;
        throw runtime_error("Cannot open the file " + msg);
    }

    testsFile.close();
    return courses;
}



class Test {    
private:
    int id;
    int weight;
public:
    // Test() {}
    Test(int id, int weight) {
        this->id = id;
        this->weight = weight;
    }
    int getWeight() {
        return weight;
    }
};



class Course {
private:
    int id;
    string name;
    string teacher;
    vector<Test> tests;
public:
    Course(){}

    Course(int id, string name, string teacher) {
        this->id = id;
        this->name = name;
        this->teacher = teacher;
    }

    int getId() {
        return id;
    }

    string getTeacher() {
        return teacher;
    }

    void addTest(Test test) {
        this->tests.push_back(test);
    }

    int sumTestWeights() {
        int sum = 0;
        for(vector<Test>::iterator it = tests.begin() ; it < tests.end(); it++) {
            sum += it->getWeight();
        } 
        return sum;
    }
};

class StudentCourse {
private:
    Course course;
    float courseAverage;

public:
    StudentCourse(int id, string name, string teacher) {
        course = Course(id, name, teacher);
    }
};

class Student {
private:
    int id;
    string name;
    vector<StudentCourse> courses;
public:
    Student(int id, string name) {
        this->id = id;
        this->name = name;
    }
    
};

