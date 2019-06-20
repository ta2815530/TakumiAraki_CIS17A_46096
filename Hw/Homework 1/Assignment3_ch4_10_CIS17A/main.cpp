/*
Write a program that asks the user to enter the month 
 * (letting the user enter an integer in the range of 1 through 12) and the year. 
 * The program should then display the number of days in that month. 
 * Use the following criteria to identify leap years:
1. Determine whether the year is divisible by 100. If it is, then it is a leap year 
 * if and only if it is divisible by 400. For example, 2000 is a leap year but 2100 is not.
2. If the year is not divisible by 100, then it is a leap year 
 * if and if only it is divisible by 4. For example, 2008 is a leap year but 2009 is not.

 * 
 * Here is a sample run of the program:
Enter a month (1-12): 2 [Enter] Enter a year: 2008 [Enter]
29 days
 */

/* 
 * File:   main.cpp
 * Author: takumiaraki
 *
 * Created on June 19, 2019, 4:20 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int month, year, days;
    string M; 
    
    //input validation with do while

    bool good = false;
    
    do{ 
        cout << "Enter a month: " << endl;
        cin >> month;

        if(!month || month<1 || month>12)
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter an integer between 1 to 12." << endl;       
        }
        else       
            good = true;

    }while(!good);
    
    
    good = false;
    do{
        cout << "Enter a year: " << endl;
        cin >> year;

        if(!year || year<0)              
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter a positive integer." << endl; 
        }
        else 
            good = true;
    
    }while(!good);
    
    
    
    if(month!=2)
    {
        switch(month)
        {
            case 1:
                days = 31;
                M = "January";
                break;
            case 3:
                days = 31;
                M = "March";
                break;
            case 4:
                days = 30;
                M = "April";
                break;
            case 5:
                days = 31;
                M = "May";
                break;
            case 6:
                days = 30;
                M = "June";
                break;
            case 7:
                days = 31;
                M = "July";
                break;
            case 8:
                days = 31;
                M = "August";
                break;
            case 9:
                days = 30;
                M = "September";
                break;
            case 10:
                days = 31;
                M = "October";
                break;
            case 11:
                days = 30;
                M = "November";
                break;
            case 12:
                days = 31;
                M = "December";
            default:
                cout << "Unknown error." << endl;
                cout << "Program terminating..." << endl;
                return 0;
        }
                
    }
    else
    {
        M = "February";
        
        if(year%100==0){
            days = 29;
            
            if(year%400==0)
            {
                days = 28;
            }
        }
        else
        {
            if(year%4==0)
            {
                days = 29;
            }
            else 
            {
                days = 28;
            }
        }
    }
    
    
    if(year >= 2019 && month >= 6)
        cout << "In " << year << ", in " << M << ", there are " << days << " days.";
    else
        cout << "In " << year << ", in " << M << ", there were " << days << " days.";
    
    
    
    return 0;
}