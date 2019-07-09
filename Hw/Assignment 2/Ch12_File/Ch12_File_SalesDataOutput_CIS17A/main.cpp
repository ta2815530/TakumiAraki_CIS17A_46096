//one error: when you input 0 to one of the sales, it displays "invalid value"
//although it's not


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int FOUR=4;

struct Company{
    
    string NAME;
    int QUARTER[FOUR];
    double SALES[FOUR];
};

int main(int argc, char** argv) {

    string filename;
    
    bool good = false;
    
    Company division[FOUR];
    
    for(int i=0;i<FOUR;i++)
    {
        cout << "Enter the division name of your company: " << endl;    //can be initialized
        cin >> division[i].NAME;
        
        for(int j=0;j<FOUR;j++)
        {
            division[i].QUARTER[j] = 0;
            division[i].QUARTER[j] = static_cast<int>(division[i].QUARTER[j]+j+1);

            do
            {
                good = false;
                cout << "Enter the sales for division " << division[i].NAME;
                cout << " in the quarter #" << j+1 << endl;
                cin >> division[i].SALES[j];

                if(!division[i].SALES[j]||division[i].SALES[j]<0)     
                {   
                    cout << "Invalid value." << endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                }
                else
                    good = true;

            }while(!good);
        }
    }

    ofstream writeFile;
    
    cout << "Enter the name of the file that you want to write: " << endl;
    cin >> filename;
    
    
    writeFile.open(filename);
    
    if(writeFile)
    {
        cout << "Writing file..." << endl;
        for(int i=0;i<FOUR;i++)
        {
            writeFile << division[i].NAME << endl;
            
            for(int j=0;j<FOUR;j++)
            {
                writeFile << division[i].QUARTER[j] << " "; 
                writeFile << division[i].SALES[j] << endl;                
            }
        }

        writeFile.close(); 
    }
    else
    {
        cout << "Couldn't open a file." << endl;
    }

    
    
    
    return 0;
}
