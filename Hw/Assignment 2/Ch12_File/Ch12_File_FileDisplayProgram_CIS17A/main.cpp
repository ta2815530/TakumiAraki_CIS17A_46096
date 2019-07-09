#include <iostream>
#include <fstream>


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

