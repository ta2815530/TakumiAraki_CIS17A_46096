/*
 * Wtite a program that will convert U.S dollar amounts to Japanese yen and to euros, 
 * storing the conversion factors in the constants YEN_PER_DOLLAR and 
 * EUROS_PER_DOLLAR. To get the most up-to-date exchange rates, search the Internet using the
 * term :currency exchange tate". If you cannot find the most recent exchange rates, use the
 * following: 
 *  1 Dollar = 98.93 Yen
 *  1 Dollar = 0.74 Euros
 */


#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    const double yenConversion = 98.93,
              eurosConversion = 0.74;  
    
    double dollar, yen, euros;
    
    
    bool good = false;
    do{
        cout << "Enter the amount of dollar that you want to convert:" << endl;
        cin >> dollar;
        
        if(!dollar || dollar < 0)
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Invalid value... " << endl;
        }
        else
            good = true;
        
    }while(!good);
    
    yen = dollar * yenConversion;
    euros = dollar * eurosConversion;
    
    cout << fixed << setprecision(2) << showpoint;
     
    cout << "$" << dollar << " is " << yen << " yen." << endl;
    cout << "and " << euros << " euros." << endl;
    
    
    
    
    
    return 0;
}

