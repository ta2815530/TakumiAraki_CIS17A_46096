//it works on netbeans, but why it doesn't work on Code-E


/*
Total the elements in a 2-D Array.  Create the following functions to perform this task.
int **getData(int &,int &);        //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);//Print the 2-D Array
void destroy(int **,int,int);       //Deallocate memory
int sum(const int * const *, int,int);    //Return the Sum
 */

/* 
 * File:   main.cpp
 * Author: takumiaraki
 *
 * Created on June 30, 2019, 5:23 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;


int **getData(int &,int &);          //Return the 2-D array and its size.   //pointer to pointer
void prntDat(const int* const *,int,int);   //Print the 2-D Array
void destroy(int **,int,int);               //Deallocate memory
int sum(const int * const *, int,int);       //Return the Sum

/*
 * 
 */
int main(int argc, char** argv) {
    int row, col;
    int **aptr = nullptr;
    int total;
    
    aptr = getData(row, col);
    
    prntDat(aptr, row, col);
    
    total = sum(aptr, row, col);
    
    cout << total;
    
    destroy(aptr, row, col);
   
    return 0;
}

int **getData(int &row, int &col)
{
    int **aptr = nullptr;   //pointer to a pointer
    
    
    //cout << "Enter the size of row and column of the array: " << endl;
    cin >> row >> col;
    
    
    aptr = new int* [row];
    
    for(int i=0;i<row;i++)
    {
        *(aptr+i) = new int [col];
    }
        
    
    //cout << "Enter the contents of the array. " << endl;
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin >> *(*(aptr+i)+j) ;
        }
    }
    
    
    return aptr;
}

void prntDat(const int* const *array, int row, int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col-1;j++)
        {
            cout << *(array[i] + j) << " ";
        }
        cout << *(array[i] + col-1) << endl;
    }  
}


void destroy(int **array, int row, int col)
{
    for(int i=0;i<row;i++)
    {
        delete [] *(array+i);
        *(array+i) = nullptr;
    }
    
    delete [] array;
    array = nullptr;
}

int sum(const int * const *array, int row, int col)
{
    int total=0;
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            total += *(*(array+i)+j) ;
        }
    }  
    
    return total;
}