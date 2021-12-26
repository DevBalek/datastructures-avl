#ifndef Chain_hpp
#define Chain_hpp

#include <iostream>
#include <string>
#include <sstream>

class Chain{
    public:
    int x;
    int y;
    int z;
    int distanceOfOrjin;

    Chain* nextData;

    Chain(int x,int y, int z);

};
#endif