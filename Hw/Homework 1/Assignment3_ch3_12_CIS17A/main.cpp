/*
12. Write a cout statement so the variable divSales is displayed in a field of 8 spaces, 
 * in fixed point notation, with a precision of 2 decimal places.
 *  The decimal point should always be displayed.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    double divSales = 123.45;
    
    //with a precision of 2 spaces
    cout << showpoint << setprecision(2) << fixed;
    
    //in a field of 8 spaces
    cout << setw(8) << divSales << endl;
    
    return 0;
}