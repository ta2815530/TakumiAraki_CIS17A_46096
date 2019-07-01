/*
Given an array.
Create a parallel array that represents the successive sum of preceding members in the array.
Use the following prototypes
int *getData(int &);             //Return the array size and the array from the inputs
int *sumAry(const int *,int);//Return the array with successive sums
void prntAry(const int *,int);//Print the array
 */

/* 
 * File:   main.cpp
 * Author: takumiaraki
 *
 * Created on June 30, 2019, 4:36 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int *getData(int &);             //Return the array size and the array from the inputs
int *sumAry(const int *,int);   //Return the array with successive sums
void prntAry(const int *,int);  //Print the array

/*
 * 
 */
int main(int argc, char** argv) {
    int size;
    int *aptr = nullptr;
    int *sumP = nullptr;
   
    aptr = getData(size);
    
    sumP  = sumAry(aptr, size);
    
    cout << "Original: " << endl;
    prntAry(aptr, size);
    cout << endl;
    
    cout << "Sum: " << endl;
    prntAry(sumP, size);
    
    
    delete [] aptr;
    delete [] sumP;
    
    
    return 0;
}

int *getData(int &size)
{
    int *array = nullptr;

    //cout << "Enter the size of the array: " << endl;
    cin >> size;
    
    array = new int [size];
    
    //cout << "Input the contents of the array." << endl;
    for(int i=0;i<size;i++)
    {
        cin >> *(array + i);
    }
 
    
    return array;
}


int *sumAry(const int *array, int size)
{
    int *sumP = new int [size];
    int *total = new int [size];        //I need to make this guy an array (dynamically allocated)

    
    *total = *array;
    for(int i=1;i<size;i++)
    {
        *(total+i) = *(array+i) + *(total+i-1);     
        
        //cout << *(array+i) << " " << *(total+i-1) << " " << *(total+i) << endl;
    
    }
    
    for(int i=0;i<size;i++)
    {
        *(sumP+i) = *(total+i);
    } 

    return sumP;
}


void prntAry(const int *array, int size)
{
    for(int i=0;i<size-1;i++)
    {
        cout << *(array+i) << " "; 
    }
    cout << array[size-1];
    
}