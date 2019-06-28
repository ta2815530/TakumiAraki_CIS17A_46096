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
    cout<<"Create a numbered shape that can be sized."<<endl;
    cout<<"Input an integer number [1,50] and a character [x,b,f]."<<endl;
    cin>>x>>shape;
    
    //Draw the shape
    
    if(shape == 'b')
    {
        for(int i=0;i<x;i++)
        {   
            if(x>=10)
            {
                cout << setw(i+2) << x-i;
                for(int j=i;j<x-1;j++)
                {
                     cout <<  " ";   
                }
                cout << endl;
            }
            else
            {
                cout << setw(i+1) << x-i;
                for(int j=i;j<x-1;j++)
                {
                     cout <<  " ";   
                }
                cout << endl;
            }
        }
    }
    else if (shape == 'f')
    {
        int i;
        if(x>=10)
        {
            for(;i<x-9;i++)
            {
                cout << setw(x-i+1) << x-i;
                for(int j=0;j<i;j++)
                {
                     cout <<  " ";   
                }
                cout << endl;
            }
        }
        for(;i<x;i++)
        {   
            cout << setw(x-i) << x-i;
            for(int j=0;j<i;j++)
            {
                 cout <<  " ";   
            }
            cout << endl;
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
                cout << setw(i+1) << x-i << setw(x-i*2-1) << i+1;
                
                for(int s=0;s<i;s++)
                {
                    cout << " ";
                }
                cout << endl;
            }
            else if((x-i)==(i+1))
            {
                cout << setw(i+1) << x-i;
                
                for(int s=0;s<i;s++)
                {
                    cout << " ";
                }
                cout << endl;
            }
            else
            {
                if(x%2==0)
                {
                    cout << setw(x-i) << i+1 << setw((j*2)+1) << x-i;
                    
                    for(int s=0;s<x-i-1;s++)
                    {
                        cout << " ";
                    }
                    cout << endl;
                }

                if(x%2!=0)
                {
                    cout << setw(x-i) << i+1 << setw(j*2) << x-i;
                       
                    for(int s=0;s<x-i-1;s++)
                    {
                        cout << " ";
                    }
                    cout << endl;
                }
                
                j++;
            }
            
        }
    }

    
    //Exit
    return 0;
}
