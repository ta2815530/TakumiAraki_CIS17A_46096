/*
Write a program that will predict the size of a population of organisms. 
 * The program should ask the user for the starting number of organisms,
 *  their average daily population increase (as a percentage),
 *  and the number of days they will multiply. A loop should display 
 * the size of the population for each day.
Input Validation: Do not accept a number less than 2 for the starting size of
 *  the population. Do not accept a negative number for average daily population increase. 
 * Do not accept a number less than 1 for the number of days they will multiply.
 */


#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;


int main(int argc, char** argv) {

    int startNumber, days;
    double increaseRate, size;
    
    
    //input validation
    bool good = false;
    
    do{
        cout << "Enter the starting number of organisms";
        cout << "(an integer greater than or equal to 2):" << endl;
        cin >> startNumber;

        if(!startNumber || startNumber<2)
        {
            cin.clear();
            cin.ignore(10000,'\n');
        }
        else
            good = true;
    }while(!good);
    
    
    good = false;
    do{
        cout << "Enter the average daily population increase as a percentage(%):" << endl;
          cin >> increaseRate;
    

        if(!increaseRate || increaseRate<0)
        {
            cin.clear();
            cin.ignore(10000,'\n');
        }
        else
            good = true;
    }while(!good);

    good = false;
    do{
        cout << "Enter the number of days during which they will grow";
        cout << "(an integer greater than 0)" << endl;
        cin >> days;
    

        if(!days || days<=0)
        {
            cin.clear();
            cin.ignore(10000,'\n');
        }
        else
            good = true;
    }while(!good);
    
    
   
    

    
    increaseRate /= 100;
    size = startNumber;  //this is accumulator and assign it an initial value
    
    
    for(int i=0;i<days;i++)
    {
        startNumber *= increaseRate;
        size += startNumber;
        
        startNumber = size;
    }
    
    cout << fixed << setprecision(0);
    
    if(!(size<0))
    {     
        cout << "The number of organisms after " << days << " days will be " << size << endl;       
    }
    else
    {
        cout << "There was an error during calculation." << endl;
        cout << "Program terminating..." << endl;
    }
    
    return 0;
}

