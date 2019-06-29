//should check how to do when parameter lists are const int


/*
 * Read in a dynamic array.
 * Output the reverse sorted dynamic array by first sorting from smallest to largest.
 * Use the following functional prototypes.
 */

/* 
 * File:   main.cpp
 * Author: takumiaraki
 *
 * Created on June 28, 2019, 2:48 PM
 */


#include <iostream>

using namespace std;

int *getData(int &);               //Fill the array
int *sort(int *,int);      //Sort smallest to largest
int *reverse(int *,int);  //Sort in reverse order
void prntDat(int *,int); //Print the array

int main(int argc, char** argv) {

    int size;
    int *aptr = nullptr;
    int *sortPtr = nullptr;
    int *revPtr = nullptr;
    
    //aptr = new int;
    
    //cout << "Enter the size of the array: " << endl;
    //cin >> size;

    aptr = getData(size);
    
    /*
    for(int i=0;i<size;i++)
    {
        cout << aptr[i] << " ";
    }
    cout << endl;
    */
      
    //sortPtr = new int [size];
    //revPtr = new int [size];
    
    sortPtr = sort(aptr, size);

    /*
    for(int i=0;i<size;i++)
    {
        cout << sortPtr[i] << " ";
    }
    cout << endl;
    */
    
    ////////////////////////////////////////
    reverse(aptr, size);

    prntDat(aptr, size);
    
    
    /*       
    delete [] aptr;    
    delete [] sortPtr;   
    delete [] revPtr;    
    aptr = nullptr;   
    sortPtr = nullptr;
    revPtr = nullptr;  
    */      
    
    return 0;
}

int *getData(int &size)
{
    int *aptr = nullptr;
    
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    
    aptr = new int [size];
    
    cout << "Input the array content." << endl;
    for(int i=0;i<size;i++)
    {
        cin >>  aptr[i];
    }
 
    return aptr;
}

int *sort(int *aptr, int size)   //so my bubble sort was wrong, needed one more for loop
{
    cout << "Hi from the inside of sort~" << endl;
    
    //int *sortedArray = nullptr;
    //ortedArray = new int [size];
    
    
    //bubble sort
    int temp;
    bool swap;
    
    do
    {
        swap = false;

        for(int i=0;i<size-1;i++)
        {
            if(aptr[i]>aptr[i+1])
            {
                temp = aptr[i+1];
                aptr[i+1] = aptr[i];
                aptr[i] = temp;
                swap = true;
            }    
        }
    }while(swap);

    
    //return sortedArray;
    
    
}

////////////////////////////////////////////////////////



int *reverse(int *aptr, int size)             //can use bubble sort as well
{
    cout << "Hi from the inside of reverse~" << endl;
    
    //let me just change this to the function of bubble sort
    
    int temp;
    bool swap;
    
    do
    {
        swap = false;

        for(int i=0;i<size-1;i++)
        {
            if(aptr[i]<aptr[i+1])
            {
                temp = aptr[i+1];
                aptr[i+1] = aptr[i];
                aptr[i] = temp;
                swap = true;
            }    
        }
    }while(swap);

    
    /*
    int *reverseArray = nullptr;
    reverseArray = new int [size];
    
    for(int i=0;i<size;i++)
    {
        reverseArray[i] = aptr[size-i-1];        
    }
    */
    
    //return reverseArray;
}

void prntDat(int *aptr, int size)
{
    cout << "Hi from the inside of prntDat~" << endl;
    
    for(int i=0;i<size;i++)
    {
        cout << aptr[i] << " ";
    }
}