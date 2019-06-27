/* 
 * File:   main.cpp
 * Author: Takumi Araki
 * Created on June 24th
 * Purpose:  Cross one-side or the other
 */

//System Libraries Here
#include <iostream>
#include <iomanip>


using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    unsigned short x;
    char shape;       //f-> forward b->backward x->cross
    
    //Input or initialize values Here
    cout << "Create a numbered shape that can be sized." << endl;
    cout << "Input an integer number [1,50] and a character [x,b,f]." << endl;
    cin >> x >> shape;
    
    //Draw the shape
    

    
    if(shape == 'b')
    {
        for(int i=0;i<x;i++)
        {
            cout << setw(i+1) << x-i << endl;
        }
    }
    else if (shape == 'f')
    {
        for(int i=0;i<x;i++)
        {
            cout << setw(x-i) << x-i << endl;
        }
    }
    else
    {
        int j = 0;
     
        if(x%2!=0)
        {
            j = 1;
        }
        
        for(int i=0;i<x;i++)
        {
            if((x-i)>(i+1))
            {
                cout << setw(i+1) << x-i << setw(x-i*2-1) << i+1 << endl;
            }
            else if((x-i)==(i+1))
            {
                cout << setw(i+1) << x-i << endl;
            }
            else
            {
                if(x%2==0)
                {
                    cout << setw(x-i) << i+1 << setw((j*2)+1) << x-i << endl;
                }

                if(x%2!=0)
                {
                    cout << setw(x-i) << i+1 << setw(j*2) << x-i << endl;
                }
                
                j++;
            }
            
        }
    }
    
    
    //Exit
    return 0;
}
