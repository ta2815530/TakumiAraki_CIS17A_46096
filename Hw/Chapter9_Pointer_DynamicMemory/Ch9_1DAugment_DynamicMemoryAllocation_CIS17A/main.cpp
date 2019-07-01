/*
Augment a 1-D array by 1 Element, place 0 in the first element and copy the rest 
from the original shifted by 1 index.
int *getData(int &);//Read the array
int *augment(const int *,int);//Augment and copy the original array
void prntAry(const int *,int);//Print the array
 */

/* 
 * File:   main.cpp
 * Author: takumiaraki
 *
 * Created on June 30, 2019, 6:28 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;


int *getData(int &);            //Read the array
int *augment(const int *,int);      //Augment and copy the original array
void prntAry(const int *,int);      //Print the array

/*
 * 
 */
int main(int argc, char** argv) {
    int size;
    int *aptr = nullptr;
    int *augP = nullptr;
    
    aptr = getData(size);
    
    augP = augment(aptr, size);
    
    prntAry(augP, size+1);
    
    
    delete [] aptr;
    aptr = nullptr;
    
    return 0;
}



int *getData(int &size)
{
    int *aptr = nullptr;
    
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    
    aptr = new int [size];
    
    cout << "Enter the contents of the array: " << endl;
    for(int i=0;i<size;i++)
    {
        cin >> *(aptr+i);
    }
    
    return aptr;
    
}

int *augment(const int *array, int size)
{
    int *aptr = new int [size+1];
    
    *aptr = 0;
    for(int i=0;i<size;i++)
    {
        *(aptr+i+1) = *(array+i);
        cout << "* ";
    }

    return aptr;
}

void prntAry(const int *array, int size)
{
    for(int i=0;i<size-1;i++)
    {
        cout << *(array+i) << " ";
    }
    cout << array[size-1];
    
}
