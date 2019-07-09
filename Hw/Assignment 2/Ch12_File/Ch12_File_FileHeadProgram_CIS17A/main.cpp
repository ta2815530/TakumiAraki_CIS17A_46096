#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char** argv) {

    fstream readFile;
    
    string filename;
    string line;
    
    cout << "Enter the name of the file that you want to read in: " << endl;
    cin >> filename;
    
    
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

