#include "Mark.h"

Mark::Mark(int testId, int studentId, int mark) {
    this->testId = testId;
    this->studentId = studentId;
    this->mark = mark;
}

int Mark::getStudentId() {
    return this->studentId;
}

int Mark::getTestId() {
    return this->testId;
}

int Mark::getMark() {
    return this->mark;
}

