#include "Chain.hpp"
#include "PointChain.hpp"

#include <math.h>
#include <vector>

PointChain::PointChain(){
    headOfChain=NULL;
    pointAmount=0;
};

void PointChain::addPoint(int x, int y , int z){

    if(headOfChain==NULL){

        headOfChain = new Chain(x,y,z);
        pointAmount++;

    }else{

        Chain* temp = headOfChain;
        Chain* newChain = new Chain(x,y,z);

        pointAmount++;

        while (true)
        {
        
            if(temp->nextData==NULL){

                temp->nextData = newChain;
                
                int x1,y1,z1;
                int x2,y2,z2;

                x1 = temp->x; y1=temp->y; z1=temp->z;
                x2 = temp->nextData->x; y2 = temp->nextData->y; z2 = temp->nextData->z;

                sumOfEachDistance += sqrt(pow(x2-x1,2)+pow(y2-y1,2)+pow(z2-z1,2));
                return;
            }
            
            temp=temp->nextData;
        }
    }
};

void PointChain::printEachDistanceOfOrjin(){
    
    Chain* tempChain = headOfChain;
    
    vector<int> myList;
     
    while(tempChain!=NULL){        
            
        // cout << tempChain->distanceOfOrjin << " ";        
        myList.push_back(tempChain->distanceOfOrjin);
        
        tempChain=tempChain->nextData;
    }

    sort(myList.begin(), myList.end());
    
    for (int i = 0; i < myList.size(); i++){
        
        cout << myList.at(i) << " ";

    }
    
    cout<<endl;
}

/*
    while(true){

        int x1,y1,z1;
        int x2,y2,z2;

        x1=temp->x; y1=temp->y; z1=temp->z;
        x2=temp->nextData->x; y2=temp->nextData->y; z2=temp->nextData->z;

        sumOfEachDistance += sqrt(pow(x2-x1,2)+pow(y2-y1,2)+pow(z2-z1,2));

                    
        temp=temp->nextData;
    }
*/


/*

#include <iostream>
 
using namespace std;
 
int main(){

    int dizi[10],temp;

    for(int i=0;i<=9;i++){
        cout<<"sayigir=";
        cin>>dizi[i];
    }

    for(int a=0;a<=9;a++){

        for(int b=0;b<=9;b++){

            if(dizi[b]>dizi[b+1]){
                
                temp=dizi[b];
                dizi[b]=dizi[b+1];
                dizi[b+1]=temp;

            }
        }
    }

    for(int d=0;d<=9;d++){
        cout<<dizi[d]<<endl;
    }

    return 0;
}

*/


/*


    Chain* dizi[pointAmount];
    
    cout<<endl<<"calculation started"<<endl;

    for(int i=0;i<pointAmount-1;i++){
                
        dizi[i]=temp;

        temp = temp->nextData;
    }    

    cout<<endl<<"calculation aşama 2"<<endl;
    cout<<endl<<"PointAmount: "<<pointAmount <<endl<<endl;

    temp = NULL;

    for(int a = 1;a < pointAmount;a++){

        for(int b=0; b < pointAmount;b++){

            if(dizi[b]->distanceOfOrjin > dizi[b+1]->distanceOfOrjin){
                
                temp = dizi[b];
                dizi[b] = dizi[b+1];
                dizi[b+1] = temp;

                for (int i = 0; i < pointAmount; i++){
                    
                    cout << "Dizi elemani: " << dizi[i]->distanceOfOrjin <<endl;

                }
                

                cout<<endl;
                cout << "Point Info (B): x:" << dizi[b]->x << ", y:" <<dizi[b]->y<<", z:" << dizi[b]->z << "| \n";
                cout << "Point Info (B+1): x:" << dizi[b+1]->x << ", y:" <<dizi[b+1]->y<<", z:" << dizi[b+1]->z << "| \n";
                cout << "Ordered: " <<  dizi[b]->distanceOfOrjin << " < " << dizi[b+1]->distanceOfOrjin<<endl;
                cout<<endl;

            }

        }
    }
    
    cout<<endl<<"calculation aşama 3"<<endl;
    
    int i = 0;

    while (true)
    {
        if(i == pointAmount-1) break;

        int x1,y1,z1;
        int x2,y2,z2;

        x1=dizi[i]->x; y1=dizi[i]->y; z1=dizi[i]->z;
        x2=dizi[i+1]->x; y2=dizi[i+1]->y; z2=dizi[i+1]->z;

        sumOfEachDistance += sqrt(pow(x2-x1,2)+pow(y2-y1,2)+pow(z2-z1,2));
        
        i++;
    }
        
    temp = headOfChain;


*/


/*


void PointChain::calculateDistance(){
    
    Chain* temp = headOfChain;

    vector<Chain*> myChainVector;

    while (temp==NULL){

        myChainVector.push_back(temp);
        temp=temp->nextData;
    }

    sort(myChainVector.begin(), myChainVector.end());

    temp = headOfChain;    
    
    for(const auto &autoChain:myChainVector){
        
        int x1,y1,z1;
        int x2,y2,z2;

        x1=autoChain->x; y1=autoChain->y; z1=autoChain->z;
        x2=autoChain->nextData->x; y2=autoChain->nextData->y; z2=autoChain->nextData->z;

        sumOfEachDistance += sqrt(pow(x2-x1,2)+pow(y2-y1,2)+pow(z2-z1,2));

    }

*/