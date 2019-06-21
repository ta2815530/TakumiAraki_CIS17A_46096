/*
 * Modify the binarySearch function presented in this chapter so it searches 
 * an array of strings instead of an array of ints. Test the function with 
 * a driver program. Use Program 8-8 as a skeleton to complete. (The array must
 *  be sorted before the binary search will work.)
 */

/* 
 * File:   main.cpp
 * Author: takumiaraki
 *
 * Created on June 20, 2019, 7:36 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>


using namespace std;

void selectionSort(string[], int);
int binarySearch(string[], string, int);

/*
 * 
 */


int main() {
    
    const int NUM_NAMES = 20;
    
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim","Griffin, Jim", "Stamey, Marty", 
                                "Rose, Geri", "Taylor, Terri", "Johnson, Jill", "Allison, Jeff", "Looney, Joe",
                                "Wolfe, Bill", "James, Jean", "Weaver, Jim", "Pore, Bob", "Rutherford, Greg", 
                                "Javens, Renee", "Harrison, Rose", "Setzer, Cathy","Pike, Gordon", "Holland, Beth"}; 
    string findingName;
    int index;
    

    cout << "Enter the name you are looking for: " << endl;
    getline(cin, findingName);

    selectionSort(names, NUM_NAMES);

    cout << "========================" << endl;


    for(int i=0;i<NUM_NAMES;i++)
    {
        cout << names[i] << endl;
    }

    cout << "========================" << endl;


    index = binarySearch(names, findingName, NUM_NAMES);

    if(index == -1)
    {
        cout << "Sorry we couldn't find the name you entered." << endl;
    }
    else
    {
        cout << "The name you entered was found at index #" << index+1 << "." << endl;
    }


    return 0; 
}


void selectionSort(string sortArray[], int size)
{
    //cout << "Selection Sorting..." << endl;
    
    
    string minName;
    int minIndex;
    
    for(int i=0;i<(size-1);i++)
    {
        minIndex = i;
        minName = sortArray[i];
        
        for(int j=i+1;j<size;j++)
        {
            if(sortArray[j]<minName)
            {
                minName = sortArray[j];
                minIndex = j;
            }
        }
        
        sortArray[minIndex] = sortArray[i];
        sortArray[i] = minName;
    }
    
}



int binarySearch(string searchArray[], string searchName, int size)
{
    int position = -1;
    int first = 0,
        last = size-1,   //why size - 1?
        middle;
    bool found = false;
    
    while(!found && first <= last)
    {
        middle = (first + last)/2;
        
        if(searchArray[middle]==searchName)
        {
            found = true;
            position = middle;
        }
        else if(searchArray[middle]>searchName)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
        
    }
    
    return position;
}
