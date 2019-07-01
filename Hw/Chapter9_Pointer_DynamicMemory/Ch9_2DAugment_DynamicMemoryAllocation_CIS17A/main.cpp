/*
Create a 2-D array 1 row and 1 column larger than the array to copy with 0's i
 * n the 1st row and column but filled with the other rows and columns using the original array.
Create the following prototypes and implement.
int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory
 */

/* 
 * File:   main.cpp
 * Author: takumiaraki
 *
 * Created on June 30, 2019, 6:59 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int **getData(int &,int &);         //Get the Matrix Data
void printDat(const int * const *,int,int);     //Print the Matrix
int **augment(const int * const *,int,int);     //Augment the original array
void destroy(int **,int);      //Destroy the Matrix, i.e., reallocate memory

/*
 * 
 */
int main(int argc, char** argv) {
    int row, col;
    int **aptr = nullptr;
    int **augP = nullptr;
    
    aptr = getData(row, col);
    
    //cout << "before augment" << endl;
    augP = augment(aptr, row, col);
    //cout << "after augment" << endl;
    
    //cout << "printing the original" << endl;
    printDat(aptr, row, col);
    cout << endl;
    //cout << "printing the augmented" << endl;
    printDat(augP, row+1, col+1);
    
    destroy(aptr, row);
    destroy(augP, row);
    
    return 0;
}

int **getData(int &row, int &col)
{
    int **aptr = nullptr;
    
    //cout << "Enter the number of row and column: " << endl;
    cin >> row >> col;
    
    aptr = new int *[row];
    
    for(int i=0;i<row;i++)
    {
        *(aptr+i) = new int [col];
    }
    
    //cout << "Enter the contents of the array: " << endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin >> *(aptr[i]+j);
        }
    }
    

    return aptr;
}

void printDat(const int * const *array, int row, int col)
{
    //cout << "From, printDat " << endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col-1;j++)
        {
            cout << *(array[i]+j) << " ";
        }
        cout << *(array[i]+col-1);
        if(i<row-1)
            cout << endl;
    }
}

void destroy(int **array, int row)
{
    for(int i=0;i<row;i++)
    {
        delete [] *(array+i);
        *(array+i) = nullptr;
    }
}

int **augment(const int * const *array, int row, int col)
{
    int **augP = nullptr;
    
    augP = new int *[row+1];
    
    for(int i=0;i<row+1;i++)
    {
        *(augP+i) = new int [col+1];
    }
    
    //assign 0 to all rows
    for(int i=0;i<row+1;i++)
    {
        *(augP[i]+0) = 0;
    }

    //assign 0 to all columns
    for(int j=0;j<col+1;j++)
    {
        *(augP[0]+j) = 0;
    }
    
    

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            *(augP[i+1]+(j+1)) = *(array[i]+j);
        }
    }
    
    
    
    return augP;
}