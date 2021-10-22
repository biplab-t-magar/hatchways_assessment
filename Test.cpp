#include "Test.h"

Test::Test(int id,int courseId, int weight) {
    this->id = id;
    this->courseId = courseId;
    this->weight = weight;
}
    
int Test::getWeight() {
    return weight;
}

int Test::getId() {
    return id;
}

int Test::getCourseId() {
    return courseId;
}