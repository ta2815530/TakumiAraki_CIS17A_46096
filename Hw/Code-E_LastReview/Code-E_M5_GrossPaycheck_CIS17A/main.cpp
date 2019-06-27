/*
 * Develop an application that will determine the gross pay for employees. 
 * The company pays "straight-time" for the first 20 hours worked, time and a 
 * half for all hours worked in excess of 20 hours but less than 40 hours, and 
 * double time for any hours worked over 40 hours. Inputs to the program would 
 * be hours worked and rate of pay.  Output would be gross pay.
 */

/* 
 * File:   main.cpp
 * Author: takumiaraki
 *
 * Created on June 24, 2019, 6:15 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Declare all Variables Here
    float payRate;
    unsigned short hrsWrkd;
    float grossPay, excess;
    
    
    //Input or initialize values Here
    cout << "Paycheck Calculation." << endl;
    cout << "Input payRate in $'s/hour and hours worked" << endl;
    //cout << "(place a space in between)" << endl;
    cin >> payRate >> hrsWrkd;
    
    //Calculate Paycheck

    grossPay = payRate * hrsWrkd;

    
    if(hrsWrkd > 20 && hrsWrkd <= 40)
    {
        grossPay += payRate * (hrsWrkd-20) * 0.5;
    }
    
    if(hrsWrkd > 40)
    {
        grossPay += payRate * 20 * 0.5;
        grossPay += payRate * (hrsWrkd-40);
    }
    
    //Output the check
    
    cout << setprecision(2) << fixed;
    
    cout << "$" << grossPay << endl;
    
    
    //Exit
    return 0;
    
}

