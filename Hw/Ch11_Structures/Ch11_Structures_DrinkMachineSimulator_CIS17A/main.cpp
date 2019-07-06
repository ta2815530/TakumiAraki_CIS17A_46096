/*
 * Write a program that simulates a soft drink machine. 
 * The program should use a structure
that stores the following data:
Drink Name
Drink Cost
Number of Drinks in Machine
The program should create an array of five structures. The elements should be initialized
with the following data:
Drink Name - Cost - Number in Machine
Cola .75 20
Root Beer .75 20
Lemon-Lime .75 20
Grape Soda .80 20
Cream Soda .80 20
Each time the program runs, it should enter a loop that performs the following
steps: A list of drinks is displayed on the screen. The user should be allowed to
either quit the program or pick a drink. If the user selects a drink, he or she will
next enter the amount of money that is to be inserted into the drink machine. The
program should display the amount of change that would be returned and subtract
one from the number of that drink left in the machine. If the user selects a drink that
has sold out, a message should be displayed. The loop then repeats. When the user
chooses to quit the program it should display the total amount of money the
machine earned.
Input Validation: When the user enters an amount of money, do not accept negative
values, or values greater than $1.00.
 */


#include <iostream>
#include <iomanip>

using namespace std;


struct Drink{
    string NAME;
    double COST;
    int NUMBER;
 
};


void calculation(double);


const int TYPE_DRINK = 5;

int main(){
	//your code here

    int count[TYPE_DRINK] = {20,20,20,20,20};
    double money;
    string input;
    bool good = true;
    
    Drink drink[TYPE_DRINK] = {{"Cola",0.75,20},
                               {"Root Beer",0.75,20},
                               {"Lemon-Lime",0.75,20},
                               {"Grape Soda",0.80,20},
                               {"Cream Soda",0.80,20},};
    
    
    do{
        cin.clear();

        cout << "Enter the name of drink, or press 'Quit' to exit: " << endl;
        getline(cin, input);


        /*Cola .75 20
    Root Beer .75 20
    Lemon-Lime .75 20
    Grape Soda .80 20
    Cream Soda .80 20*/



        if(input=="Cola")
        {
            if(drink[0].NUMBER>0)
            {
                 drink[0].NUMBER = (drink[0].NUMBER -1);                
            }
            else
            {
                cout << "This drink is sold out." << endl;
                continue;
            }

            calculation(drink[0].COST);
        }
        else if(input=="Root Beer")
        {
            if(drink[1].NUMBER>0)
            {
                 drink[1].NUMBER = (drink[1].NUMBER -1);                
            }
            else
            {
                cout << "This drink is sold out." << endl;
                continue;
            }

            calculation(drink[1].COST);
        }
        else if(input=="Lemon-Lime")
        {
            if(drink[2].NUMBER>0)
            {
                 drink[2].NUMBER = (drink[2].NUMBER- 1);                
            }
            else
            {
                cout << "This drink is sold out." << endl;
                continue;
            }        

            calculation(drink[2].COST);
        }
        else if(input=="Grape Soda")
        {
            if(drink[3].NUMBER>0)
            {
                 drink[3].NUMBER = (drink[3].NUMBER -1);                
            }
            else
            {
                cout << "This drink is sold out." << endl;
                continue;
            }

            calculation(drink[3].COST);
        }
        else if(input=="Cream Soda")
        {
            if(drink[4].NUMBER>0)
            {
                 drink[4].NUMBER = (drink[4].NUMBER -1);                
            }
            else
            {
                cout << "This drink is sold out." << endl;
                continue;
            }

            calculation(drink[4].COST);
        }
        else if(input=="Quit")
        {
            cout << "Program terminating.." << endl;
            good = false;
            break;
            return 0;
        }
        else 
        {
            cin.clear();
            cout << "Error." << endl;
            continue;
        }


        //cout << "NAME: " << drink[].NAME << endl;
        //cout << "COST: " << drink[].COST << endl;

        }while(good);


            return 0;
    }


    void calculation(double cost)
    {
        double money;
        bool good = false;


        do{
            cout << "Enter the amount of money you want to insert: " << endl;
            cin >> money;

            if(!money||money>1||money<0)
            {
                cin.clear();
                cin.ignore(10000,'\n');
                cout << "Invalid value... " << endl;
            }
            else
                good = true;

    }while(!good);
    
    
    
    if(cost<money)
    {
        money -= cost;
    }
    else
    {
        cout << "The money isn't enough." << endl;
    }
    
    cout << fixed << setprecision(2);
    cout << "Returning $" << money << " to you..." << endl;
    
    
    cin.ignore(10000,'\n');
    
}