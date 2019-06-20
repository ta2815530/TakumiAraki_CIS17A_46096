/*
 * The formula for converting a temperature from FAhrenheit to Celsius is
 * C=5/9*(F-32)
 * where F is the Fahrenheit temperature and C is the Celsius temperature. 
 * Write a function named celsius that accepts a FAhrenheit temperature as an argument.
 * THe function should return the temperature, converted to Celsius. 
 * Demonstrate the function by calling it in a loop that displays a table of the Fahrenheit temperatures ) through 2-
 * and their Celsius equivalents.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on June 20, 2019, 2:32 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

double celsius(double);

/*
 * 
 */
int main(int argc, char** argv) {
    
    const int TIME = 21;
    
    double temp=0;
    
    
    cout << fixed << setprecision(1);
    
    cout << "Fahrenheit  Celsius" << endl;
    
    for(int i=0;i<TIME;i++)
    {
        if(i<10)
        {
            cout << temp << "F" << setw(14) << celsius(temp) << "C" << endl;            
        }
        else
        {
            cout << temp << "F" << setw(13) << celsius(temp) << "C" << endl;                
        }
        
        temp += 1;
    }
   

    return 0;
}

double celsius(double tempF)
{
    double tempC;
    
    tempC = (tempF-32)*5/9; 
    
    return tempC;
}

