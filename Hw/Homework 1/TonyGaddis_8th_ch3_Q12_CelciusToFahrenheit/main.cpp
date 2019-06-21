/*
 Write a program that converts Celsius temperatures to Fahrenheit temperatures. The formula is
 
 F = 9C/5 +32
 
 F is the Fahrenheit temperature, and C is the Celsius temperature.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    double tempC, tempF;
    
    bool good = false;
    
    do{
        cout << "Enter the temperature in Fahrenheit: " << endl;
        cin >> tempF;
        
        if(!tempF || tempF<-459.67)       //minimum temparature in Fahrenheit is -459.67 apparently
        {
            cin.clear();
            cin.ignore(100000,'\n')
            cout << "Invalid value..." << endl;
        }
        else
            good = true;
        
    }while(!good);
    
    tempC = (9*tempF)/5 +32;
    
    cout << fixed << setprecision(1) << showpoint;
    
    cout << tempF << " degrees in Fahrenheit is " << tempC << " degrees in Celcius." << endl;
    
    return 0;
}
