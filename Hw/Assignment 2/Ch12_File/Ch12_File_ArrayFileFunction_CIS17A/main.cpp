#include <iostream>
#include <fstream>

using namespace std;

//to write
void arrayToFile(string,int*,int);  
//to read
int *fileToArray(string,int*,int);

int main(int argc, char** argv) {
    
    int size=5;
    string filename="binaryFile";
    
    int array1[] = {1,2,3,4,5};
    int array2[size];
    
    int *display=nullptr;
    
    
    arrayToFile(filename,array1,size);
    
    display = fileToArray(filename,array2,size);   
    
    for(int i=0;i<size;i++)
    {
       cout << *(display+i) << " ";
    }
    
    
    return 0;
}

void arrayToFile(string name, int *aptr, int size) 
{
    fstream makeFile;
    
    makeFile.open(name, ios::out|ios::binary);
    
    if(makeFile)
    {
        for(int i=0;i<size;i++)
        {
            makeFile.write(reinterpret_cast<char *>(&aptr[i]), sizeof(aptr[i]));
            
            
        }

        makeFile.close();
    }
    else
    {
        cout << "Couldn't open the file..." << endl;
    }

}

int *fileToArray(string name, int *aptr, int size)
{
    fstream readFile;
    
    readFile.open(name, ios::in|ios::binary);
    
    if(readFile)
    {
        for(int i=0;i<size;i++)
        {
            readFile.read(reinterpret_cast<char *>(&aptr[i]), sizeof(aptr[i]));
        }
        
        readFile.close();
    }
    else
    {
        cout << "Couldn't open the file..." << endl;
    }

  
    return aptr;
}