#include "Chain.hpp"

#include <math.h>

Chain::Chain(int x,int y,int z){        
    
    this->nextData = NULL;
    this->x = x;
    this->y = y;   
    this->z = z;

    distanceOfOrjin = sqrt(pow(x,2)+pow(y,2)+pow(z,2));

}