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
    int option;
    char choice, detail;
    bool good = false;
    bool atLeastOnce = false;
    
    do{
        cout << "================" << endl;
        cout << "1. Enter data:" << endl;
        cout << "2. Change data:" << endl;
        cout << "3. Display data:" << endl;
        cout << "4. Exit:" << endl;
        cout << "================" << endl;
        
        cout << "\nChoose a number from 1 to 4: " << endl;
        cin >> choice;
        
        switch(choice)
        {
            case '1':
                cin.ignore(10000,'\n');
                cout << "Enter the name of the speaker: " << endl;
                cin >>  information[index].NAME;
                
                cout << "Enter a telephone number (in the form (xxx)xxx-xxx):";
                cout << endl;
                cin >> information[index].TELEPHONE;
                
                cout << "Enter a speech topic: " << endl;
                cin >> information[index].TOPIC;
                
                do{
                    good = false;
                    cout << "Enter the fee: " << endl;
                    cin >> information[index].FEE;
                    
                    if(!information[index].FEE||information[index].FEE<0)
                    {
                        cout << "Invalid value..." << endl;
                        cin.clear();
                        cin.ignore(10000,'\n');
                    }
                    else
                        good = true;
                    
                }while(!good);
                
                atLeastOnce = true;
                index++;
                break;
                
            case '2': 
                if(atLeastOnce == true)
                {                   
                    do{
                        cout<<"Which person's data do you want to change?"<<endl;
                        cout << "- - - - - -" << endl;
                        for(int i=0;i<index;i++)
                        {
                            cout << "#" << i+1 << " "<< information[i].NAME << endl;   
                        }
                        cout << "- - - - - -" << endl;

                        cout << "(Enter a number):" << endl;
                        cin >> option;

                        cout << "Option: " << option << endl;
                        
                        
                        choice = NULL;          //might need to change choice here
                        cout << "Which data do you want to modify?" << endl;
                        cout << "----------" << endl;
                        cout << "1.Name:" << endl;
                        cout << "2.Telephone Number:" << endl;
                        cout << "3.Speech Topic:" << endl;
                        cout << "4.Fee:" << endl;
                        cout << "5.Exit:" << endl;
                        cout << "----------" << endl;
                        cout << "(Enter a number):" << endl;
                        cin >> detail;

                        switch(detail)
                        {
                            case '1':
                                cout << "Enter a new name: " << endl;
                                cin >> information[option-1].NAME;
                                break;
                            case '2':
                                cout << "Enter a new telephone number" << endl;
                                cout << "((xxx)xxx-xxx): " << endl;
                                cin >> information[option-1].TELEPHONE;
                                break;
                            case '3':
                                cout << "Enter a new speech topic: " << endl; 
                                cin >> information[option-1].TOPIC;
                                break;
                            case '4':
                                cout << "Enter a new fee: " << endl;
                                cin >> information[option-1].FEE;
                                break;
                            case '5':
                                cout << "Exiting." << endl;
                                choice = 'n';
                                break;
                            default:
                                cout << "You didn't enter a right value." << endl;
                                break;
                        }                    

                        if(detail!='5')
                        {
                            cout << "Do you want to keep editing? " << endl;
                            cout << "If yes, enter y. If no, press any keys." << endl;
                            cin >> choice;
                        }
                        
                    }while(choice=='y'||choice=='Y');
                }
                else
                {
                    cout << "You have to input at least one person's data";
                    cout << " to choose this option." << endl;
                }
                break;
                
            case '3':
                if(atLeastOnce == true)
                {
                    cout << "- - -" << endl;
                    for(int i=0;i<index;i++)
                    {
                        cout << information[i].NAME << endl;
                        cout << information[i].TELEPHONE << endl;
                        cout << information[i].TOPIC << endl;
                        cout << information[i].FEE << endl;
                        cout << "- - -" << endl;
                    }
                }
                else
                {
                    cout << "You have to input at least one person's data." <<endl;
                    cout << " to choose this option." << endl;
                }
                   
                break;
            case '4':
                cout << "Exiting..." << endl;
                return 0;
                break;
            default:
                cout << "You entered an invalid value." << endl;
        }
 
        cout << endl;
    }while(choice!=4);
    
   
    return 0;
}

