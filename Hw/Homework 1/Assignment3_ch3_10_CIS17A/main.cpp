//Description

/*
 * Many financial experts advise that property owners should insure their homes
 * or buildings for at least 80 % of the amount it would cost to replace the structure.
 *  Write a program that asks the user to enter the replacement cost of a  building
 * and then displays the minimum amount of insurance he or she should buy for the property.
 */


#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    double insurance, replacement;
    
    bool good = false;
    
    do{
        cout << "Enter the replacement cost of a building: " << endl;
        cin >> replacement;
        
        if(!replacement || replacement <= 0)
        {
            cin.clear();
            cin.ignore(100000,'\n');
            cout << "Enter a number greater than 0." << endl;
        }
        else
            good = true;
    }while(!good);

    
    insurance = replacement * 0.8;
    
    
    cout << setprecision(2) << fixed << showpoint;
    
    cout << "The amount of insurance you may want to prepare is $" << insurance << endl;
    
    
    return 0;
}

