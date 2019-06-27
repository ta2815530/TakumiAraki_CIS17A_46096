/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: takumiaraki
 *
 * Created on June 24, 2019, 4:59 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Declare all Variables Here
    char value1,value2,value3,value4;
    int index =0;
    
    
    //Input or initialize values Here
    cout << "Create a histogram chart." << endl;
    cout << "Input 4 digits as characters." << endl;
    cin >> value1 >> value2 >> value3 >> value4;
    

    //Histogram Here

 
    
    while(index<4)
    {
        index ++;
        if(index==1)
        {
            cout << value4 << " ";
            
            if(static_cast<int>(value4)<48 || static_cast<int>(value4)>57)
            {
                cout << "?" << endl;
                continue;
            }
            
            for(int j=0;j<(static_cast<int>(value4)-48);j++)
            {   
                cout << "*";
            }
            cout << endl;
        }        
        else if(index==2)
        {
            cout << value3 << " ";
            
            if(static_cast<int>(value3)<48 || static_cast<int>(value3)>57)
            {
                cout << "?" << endl;
                continue;
            }
            
            for(int j=0;j<(static_cast<int>(value3)-48);j++)
            {   
                cout << "*";
            }     
            cout << endl;
        }
        else if(index==3)
        {
            cout << value2 << " ";
            
            if(static_cast<int>(value2)<48 || static_cast<int>(value2)>57)
            {
                cout << "?" << endl;
                continue;
            }
            
            for(int j=0;j<(static_cast<int>(value2)-48);j++)
            {   
                cout << "*";
            }  
            cout << endl;
        }
        else
        {
            cout << value1 << " ";
            
            if(static_cast<int>(value1)<48 || static_cast<int>(value1)>57)
            {
                cout << "?" << endl;
                continue;
            }
            
            for(int j=0;j<(static_cast<int>(value1)-48);j++)
            {   
                cout << "*";
            }
            cout << endl;
        }
      

    }

    
    //Exit
    return 0;
}
