#pragma once
#ifndef TEST_H
#define TEST_H

class Test {    
private:
    int id;
    int weight;
public:
    // Test() {}
    Test(int id, int weight);
    int getWeight();
};

#endif