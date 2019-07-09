//I'll do this later

/*
 //Array/File Functions
Write a function named arrayToFile. The function should accept three arguments: 
 * the name of a file, a pointer to an int array, and the size of the array. 
 * The function should open the specified file in binary mode, write the 
 * contents of the array to the file, and then close the file.
Write another function named fileToArray. This function should accept three 
 * arguments: the name of a file, a pointer to an int array, and the size of the
 *  array. The function should open the specified file in binary mode, read its
 *  contents into the array, and then close the file.
Write a complete program that demonstrates these functions by using the 
 * arrayToFile function to write an array to a file, and then using the 
 * fileToArray function to read the data from the same file. //After the data are
 * read from the file into the array, display the array’s contents on the screen.
 */

//binary mode -> ios;;binary

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
    
    /*
    cout << "Enter the name of the file that you want to read and write: " << endl;
    cin >> filename;
    
    cout << "Enter the size of the array you want to make: " << endl;
    cin >> size;
    */
    
    int array1[] = {1,2,3,4,5};
    int array2[size];
    
    int *display=nullptr;
    
    /*
    cout << "Enter an integer the array: " << endl;
    for(int i=0;i<size;i++)
    {
        cout << "#" << i+1 << endl;
        cin >> array[i];
    }
    */
    
    arrayToFile(filename,array1,size);
    
    display = fileToArray(filename,array2,size);   //what do I need array for? - to read in
                                        //after reading into an array, I need to
                                        //display to the screen
    /*
    for(int i=0;i<size;i++)
    {
       cout << *(display+i) << " ";
    }
    */
    
    return 0;
}

void arrayToFile(string name, int *aptr, int size) 
{
    fstream makeFile;
    
    makeFile.open(name, ios::out|ios::binary);
    
    if(makeFile)
    {
        makeFile.write(reinterpret_cast<char *>(aptr), sizeof(aptr));

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
        readFile.read(reinterpret_cast<char *>(aptr), sizeof(aptr));
        
        readFile.close();
    }
    else
    {
        cout << "Couldn't open the file..." << endl;
    }
    
    for(int i=0;i<size;i++)
    {
        cout << *(aptr+i) << endl;
    }

  
    return aptr;
}