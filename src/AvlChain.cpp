#include "AvlChain.hpp"



AvlChain* AvlChain::addChainToTree(AvlChain* chain, PointChain* data){  
    
    if (chain == NULL){
        return newChain(data);  
    }

    if (data->sumOfEachDistance < chain->data->sumOfEachDistance){
        chain->left = addChainToTree(chain->left, data);  

    } else if (data->sumOfEachDistance > chain->data->sumOfEachDistance){
        chain->right = addChainToTree(chain->right, data);  
    }else return chain;  
    
    chain->heightAvlTree = 1 + max(calculateHeight(chain->left), calculateHeight(chain->right));  
   
    int chainBalance = getBalance(chain);
             
    if ((chainBalance > 1) && (data->sumOfEachDistance) < (chain->left->data->sumOfEachDistance)){
        return rightB(chain);  
    }
      
    if ((chainBalance < -1) && (data->sumOfEachDistance) > (chain->right->data->sumOfEachDistance)){
        return leftB(chain);  
    }
  
    if ((chainBalance > 1) && (data->sumOfEachDistance) > (chain->left->data->sumOfEachDistance)){  
        chain->left = leftB(chain->left);  
        return rightB(chain);  
    }  
    
    if ((chainBalance < -1) && (data->sumOfEachDistance) < (chain->right->data->sumOfEachDistance)){  
        chain->right = rightB(chain->right);  
        return leftB(chain);  
    }  
    
    return chain;

};



int AvlChain::getBalance(AvlChain *inputChain){  

    if (inputChain == NULL) return 0;  

    return calculateHeight(inputChain->left) - calculateHeight(inputChain->right);  
}    

int AvlChain::calculateHeight(AvlChain *inputChain){  
 
    if (inputChain == NULL)  
        return 0;  
    return inputChain->heightAvlTree;  

}

AvlChain* AvlChain::newChain(PointChain* data){  

    AvlChain* newChain = new AvlChain(); 
    
    newChain->data = data;  
    newChain->left = NULL;  
    newChain->right = NULL;  
    newChain->heightAvlTree = 1;
    
    return(newChain);

}  

AvlChain* AvlChain::rightB(AvlChain *inputChain){  
    
    AvlChain *p1 = inputChain->left;  
    AvlChain *p2 = p1->right;  
       
    p1->right = inputChain;  
    inputChain->left = p2;  
   
    inputChain->heightAvlTree = max(calculateHeight(inputChain->left),calculateHeight(inputChain->right)) + 1;  
    p1->heightAvlTree = max(calculateHeight(p1->left),calculateHeight(p1->right)) + 1;  
       
    return p1;  

}  

AvlChain* AvlChain::leftB(AvlChain* inputChain){

    AvlChain *p1 = inputChain->right;  
    AvlChain *p2 = p1->left;  
   
    p1->left = inputChain;  
    inputChain->right = p2;  
   
    inputChain->heightAvlTree = max(calculateHeight(inputChain->left),calculateHeight(inputChain->right)) + 1;  
    p1->heightAvlTree = max(calculateHeight(p1->left),calculateHeight(p1->right)) + 1;  
   
    return p1;  

}  

void AvlChain::postOrderSearch(AvlChain* root){

    if(root){        
        postOrderSearch(root->left);
        postOrderSearch(root->right);
        root->data->printEachDistanceOfOrjin();        
        //  cout << root->data->sumOfEachDistance << " ";
    }
}
