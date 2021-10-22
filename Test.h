#pragma once
#ifndef TEST_H
#define TEST_H

class Test {    
private:
    int id;
    int courseId;
    int weight;
public:
    Test() {}
    Test(int id, int courseId, int weight);
    int getWeight();
    int getCourseId();
    int getId();
};

#endif