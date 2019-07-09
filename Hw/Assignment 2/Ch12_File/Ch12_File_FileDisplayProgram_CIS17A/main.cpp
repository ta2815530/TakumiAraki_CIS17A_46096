//use cin.get() -> instead I used getline(cin,str,'\n);

/*
//File Display Program
 * Write a program that asks the user for the name of a file. The program should 
 * display the contents of the file on the screen. If the file’s contents won’t 
 * fit on a single screen, the pro- gram should display 24 lines of output at a 
 * time, and then pause. Each time the program pauses, it should wait for the 
 * user to strike a key before the next 24 lines are displayed.
 */

#include <iostream>
#include <fstream>
//#include <ctime>

using namespace std;


int main(int argc, char** argv) {

    ifstream inputFile; 
    
    int index;
    string filename;
    string line;
    string str;
    char ch;
    bool good = true;
    
    cout << "Enter the name of the file that you want to read in: " << endl;
    cin >> filename;
    cin.ignore();
    
    
    /////
    /*
    ofstream outputFile;
    
    outputFile.open(filename);
    
    srand(0);
    
    for(int i=0;i<45;i++)
    {
        outputFile << random()%12 << endl;
    }
    
    
    outputFile.close();
    */
    
    /////
    
    
    inputFile.open(filename);
    
    if(inputFile)
    {   
        for(int i=1;!inputFile.eof();i++)
        {
            getline(inputFile,line);
            
            cout << " " << line << endl;
            
            if(i%24==0)
            {
                cout << "Program has paused.. Press Enter to continue:"; 
                //cin.get(ch);
                getline(cin,str,'\n');
            }
        }

    }
    else
    {
        cout << "Couldn't open the file." << endl;
    }
    
    inputFile.close();
    
    
    
    
    return 0;
}

