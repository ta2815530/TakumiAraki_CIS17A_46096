#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype> //for put(toupper()), and put(tolower())

using namespace std;

int main(int argc, char** argv) {
    
    fstream createFile;
    
    ifstream inputFile;
    ofstream outputFile;
    
    string filename1;
    string filename2;
    string writingFile;
    

    char letter;
    
    bool ifPeriod=false;
    
        
    cout << "Enter the name of the first file to read in data: " << endl;
    getline(cin, filename1, '\n');
    

    createFile.open(filename1, ios::out);
    getline(cin, writingFile);
    createFile << writingFile;    
    createFile.close();

    
    cout << "Enter the name of the second file to write out data: " << endl;
    cin.clear();
    getline(cin, filename2);
    
    inputFile.open(filename1);
    outputFile.open(filename2);
    
    if(inputFile&&outputFile)
    {
        inputFile.get(letter);
                        
        outputFile.put(toupper(letter));
        
        while(!inputFile.eof())
        {
            inputFile.get(letter);
            if(!ifPeriod)
                outputFile.put(tolower(letter));
            else
                outputFile.put(toupper(letter));
            
            if(letter == '.')
                ifPeriod = true;
            else
                ifPeriod = false;
        }
        
        inputFile.close();
        outputFile.close();
    }
    else
    {
        cout << "Failed to open the file." << endl;
    }
    
    return 0;
}

