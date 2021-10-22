#pragma once
#ifndef MARK_H
#define MARK_H

class Mark {
private:
    int studentId; 
    int testId;
    int mark;
public:
    Mark(int testId, int studentId, int mark);
    int getTestId();
    int getStudentId();
    int getMark();
};

#endif
