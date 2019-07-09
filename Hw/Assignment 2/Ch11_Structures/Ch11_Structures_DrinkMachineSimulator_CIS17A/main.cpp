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

    int count[TYPE_DRINK] = {20,20,20,20,20};
    double totalSpent=0;
    string input;
    bool good = true;
    
    Drink drink[TYPE_DRINK] = {{"Cola",75,20},
                               {"Root Beer",75,20},
                               {"Lemon-Lime",75,20},
                               {"Grape Soda",80,20},
                               {"Cream Soda",80,20},};
    
    
    do{
            cin.clear();
            
            
            cout << "Cola       75  " << drink[0].NUMBER << endl;
            cout << "Root Beer  75  " << drink[1].NUMBER << endl;
            cout << "Lemon-Lime 75  " << drink[2].NUMBER << endl;
            cout << "Grape Soda 80  " << drink[3].NUMBER << endl;
            cout << "Cream Soda 80  " << drink[4].NUMBER << endl;
            cout << "Quit" << endl;
            
    
            //cout << "Enter the name of drink, or press 'Quit' to exit: " << endl;
            getline(cin, input);

    
            if(input=="Cola")
            {
                if(drink[0].NUMBER>0)
                {
                     drink[0].NUMBER = (drink[0].NUMBER -1);                
                }
                else
                {
                    //cout << "This drink is sold out." << endl;
                    continue;
                }
    
                calculation(drink[0].COST);
                totalSpent += drink[1].COST;
            }
            else if(input=="Root Beer")
            {
                if(drink[1].NUMBER>0)
                {
                     drink[1].NUMBER = (drink[1].NUMBER -1);                
                }
                else
                {
                    //cout << "This drink is sold out." << endl;
                    continue;
                }
    
                calculation(drink[1].COST);
                totalSpent += drink[1].COST;
            }
            else if(input=="Lemon-Lime")
            {
                if(drink[2].NUMBER>0)
                {
                     drink[2].NUMBER = (drink[2].NUMBER- 1);                
                }
                else
                {
                    //cout << "This drink is sold out." << endl;
                    continue;
                }        
    
                calculation(drink[2].COST);
                totalSpent += drink[2].COST;
            }
            else if(input=="Grape Soda")
            {
                if(drink[3].NUMBER>0)
                {
                     drink[3].NUMBER = (drink[3].NUMBER -1);                
                }
                else
                {
                    //cout << "This drink is sold out." << endl;
                    continue;
                }
    
                calculation(drink[3].COST);
                totalSpent += drink[3].COST;
            }
            else if(input=="Cream Soda")
            {
                if(drink[4].NUMBER>0)
                {
                     drink[4].NUMBER = (drink[4].NUMBER -1);                
                }
                else
                {
                    //cout << "This drink is sold out." << endl;
                    continue;
                }
    
                calculation(drink[4].COST);
                totalSpent += drink[4].COST;
            }
            else if(input=="Quit")
            {
                cout << totalSpent << endl;
                //cout << "Program terminating.." << endl;
                good = false;
                break;
                return 0;
            }
            else 
            {
                cin.clear();
                //cout << "Error." << endl;
                continue;
            }


        }while(good);


            return 0;
    }


    void calculation(double cost)
    {
        double money;
        bool good = false;


        do{
            //cout << "Enter the amount of money you want to insert: " << endl;
            cin >> money;

            if(!money||money>100||money<0)
            {
                cin.clear();
                cin.ignore(10000,'\n');
                //cout << "Invalid value... " << endl;
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
        //cout << "The money isn't enough." << endl;
    }
    
    //cout << fixed << setprecision(2);
    cout << money << endl;
    
    
    cin.ignore(10000,'\n');
    
}