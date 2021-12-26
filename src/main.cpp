#include "PointChain.hpp"
#include "AvlChain.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std; 

int main(){

    AvlChain* headOfAvlChain = 0;
    
    ifstream file("Noktalar.txt");
    string data;
    string stringNumber;
    

    if(file.is_open()){

        cout << "RESPONSE| File Opened \n";
        
        int line=0;

        cout << "Distances Adding list:\n";
        while(getline(file,data)){

            PointChain* myPointChain = new PointChain();

            // cout<<"my Line: " << line << endl;
            line++;
            int xyzCounter=0;
            int addingValue[3];

            for(int i=0; i < data.length();i++){
                
                if(data[i]==' '){
                    
                    int tempInt = stoi(stringNumber);
                    addingValue[xyzCounter] = tempInt;

                    stringNumber="";
                    xyzCounter++;

                    // cout <<"value: |" <<tempInt <<"| \n";

                    if(xyzCounter==3){
                        xyzCounter=0;
                        myPointChain->addPoint(addingValue[0],addingValue[1],addingValue[2]);                                                
                    }
                                    
                }else stringNumber += data[i];
                                
            }

            //myPointChain->calculateDistance();
            cout<< myPointChain->sumOfEachDistance << endl;
            headOfAvlChain = headOfAvlChain->addChainToTree(headOfAvlChain, myPointChain);

        }
    }
          

    cout << "\n------------------\n";
    cout << "\nPost Order Search: \n\n";
    headOfAvlChain->postOrderSearch(headOfAvlChain);
    
    cout<< "\nRESPONSE| END\n";
   
}