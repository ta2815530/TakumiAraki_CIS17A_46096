//finished a prototype, definitely need some modifications but pretty much done

/*
Speakers’ Bureau
Write a program that keeps track of a speakers’ bureau. The program should use 
 * a structure to store the following data about a speaker:
//Name
//Telephone Number 
//Speaking Topic 
//Fee Required
The program should use an array of at least 10 structures. It should let the 
 * user enter data into the array, change the contents of any element, and 
 * display all the data stored in the array. The program should have a 
 * menu-driven user interface.                  //switch
Input Validation: When the data for a new speaker is entered, be sure the user 
 * enters data for all the fields. No negative amounts should be entered for a 
 * speaker’s fee.
 */


#include <iostream>

using namespace std;


struct Bureau{
    string NAME;
    string TELEPHONE;
    string TOPIC;
    double FEE;
};

int main(int argc, char** argv) {

    Bureau information[20];
    
    int index=0;
    char choice, option, detail;
    bool good = false;
    
    do{
        cout << "================" << endl;
        cout << "1. Enter data:" << endl;
        cout << "2. Change data:" << endl;
        cout << "3. Display data:" << endl;
        cout << "4. Exit:" << endl;
        cout << "================" << endl;
        
        cout << "\nChoose a number from 1 to 4: ";
        cin >> choice;
        
        switch(choice)
        {
            case 1:
                cout << "Enter the name of the speaker: " << endl;
                cin >>  information[index].NAME;
                
                cout << "Enter a telephone number (in the form (xxx)xxx-xxx):";
                cout << endl;
                getline(cin, information[index].TELEPHONE);
                
                cout << "Enter a speech topic: " << endl;
                cin >> information[index].TOPIC;
                
                do{
                    good = false;
                    cout << "Enter the fee: " << endl;
                    cin >> information[index].FEE;
                    
                    if(!information[index].FEE||information[index]<0)
                    {
                        cout << "Invalid value..." << endl;
                        cin.clear();
                        cin.ignore(10000,'\n');
                    }
                    else
                        good = true;
                    
                }while(!good);
                
                index++;
                break;
                
            case 2: 
                cout<<"Which person's data do you want to change?"<<endl;
                cout << "----------" << endl;
                for(int i=0;i<index;i++)
                {
                    cout << "#" << i+1 << " "<< information[i].NAME << endl;   
                }
                cout << "----------" << endl;
                
                cout << "(Enter a number):" << endl;
                cin >> option;
                
                do{
                    choice = NULL;          //might need to choice choice here
                    cout << "Which data do you want to modify?" << endl;
                    cout << "---" << endl;
                    cout << "1.Name:" << endl;
                    cout << "2.Telephone Number:" << endl;
                    cout << "3.Speech Topic:" << endl;
                    cout << "4.Fee:" << endl;
                    cout << "5.Exit:" << endl;
                    cout << "---" << endl;
                    cout << "(Enter a number):" << endl;
                    cin >> detail;
                    
                    switch(detail)
                    {
                        case 1:
                            cout << "Enter a new name: " << endl;
                            cin >> information[option].NAME;
                            break;
                        case 2:
                            cout << "Enter a new telephone number" << endl;
                            cout << "((xxx)xxx-xxx): " << endl;
                            getline(cin,information[option].TELEPHONE);
                            break;
                        case 3:
                            cout << "Enter a new speech topic: " << endl; 
                            cin >> information[option].TOPIC;
                            break;
                        case 4:
                            cout << "Enter a new fee: " << endl;
                            cin >> information[option].FEE;
                            break;
                        case 5:
                            cout << "Exiting." << endl;
                            break;
                        default:
                            cout << "You didn't enter a right value." << endl;
                            break;
                    }                    

                    cout << "Do you want to keep editing? " << endl;
                    cout << "If yes, enter y." << endl;
                    cin >> choice;
                
                }while(choice=='y'||choice'Y');
                break;
                
            case 3:
                cout << "--" << endl;
                for(int i=0;i<index;i++)
                {
                    cout << information[i].NAME << endl;
                    cout << information[i].TELEPHONE << endl;
                    cout << information[i].TOPIC << endl;
                    cout << information[i].FEE << endl;
                    cout << "--" << endl;
                }
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "An error occurred." << endl;
                return 0;
        }
 
    }while(choice!=4);
    
   
    return 0;
}

