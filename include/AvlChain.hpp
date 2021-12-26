#ifndef AvlChain_hpp
#define AvlChain_hpp

#include "PointChain.hpp"

class AvlChain{
    public: 
    int heightAvlTree;
    AvlChain *left;  
    AvlChain *right;      
    PointChain* data;
    
    AvlChain* newChain(PointChain* data);
    
    int calculateHeight(AvlChain* inputNode);
    int getBalance(AvlChain* inputNode);
    
    AvlChain* addChainToTree(AvlChain* inputNode, PointChain* data);
    
    AvlChain *rightB(AvlChain* inputNode);
    AvlChain *leftB(AvlChain* inputNode);
    
    void postOrderSearch(AvlChain* root);

};

#endif