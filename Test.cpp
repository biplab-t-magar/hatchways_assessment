#include "Test.h"

Test::Test(int id, int weight) {
    this->id = id;
    this->weight = weight;
}
    
int Test::getWeight() {
    return weight;
}