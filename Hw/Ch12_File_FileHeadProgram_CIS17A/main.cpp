/*
//File Head Program
Write a program that asks the user for the name of a file. The program should 
 * display the first 10 lines of the file on the screen (the “head” of the file). 
 * If the file has fewer
than 10 lines, the entire file should be displayed, with a message indicating 
 * the entire
file has been displayed.
 */

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;


int main(int argc, char** argv) {

    fstream readFile;
    
    string filename;
    string line;
    
    cout << "Enter the name of the file that you want to read in: " << endl;
    cin >> filename;
    
    
    //////
    
    readFile.open(filename, ios::out);
    
    srand(0);
    /*
    for(int i=0;i<9;i++)
    {
        if(i!=8)
            readFile << rand()%10 +5 << endl;
        else
            readFile << "endoffile";
    }
    
    readFile.close();
    */
    
    //////
    
    
    readFile.open(filename, ios::in);
    
    if(readFile)
    {
        for(int i=0;i<10;i++)
        {
            getline(readFile, line);
            
            cout << line << endl;
            
            if(readFile.eof()&&i!=9)
            {
                cout << "/nThe number of lines were fewer than 10." << endl;
                break;
            }
        }
        
        readFile.close();
    }
    else
    {
        cout << "Couldn't read the file." << endl;
    }
    
    
    return 0;
}

