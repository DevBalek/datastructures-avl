#ifndef PointChain_hpp
#define PointChain_hpp

#include "Chain.hpp"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class PointChain{
    public:
    //int rowNumber;
    int sumOfEachDistance;
    int pointAmount;
    Chain* headOfChain;

    PointChain();

    void printEachDistanceOfOrjin();
    void addPoint(int x, int y, int z);
    void calculateDistance();
    
};
#endif