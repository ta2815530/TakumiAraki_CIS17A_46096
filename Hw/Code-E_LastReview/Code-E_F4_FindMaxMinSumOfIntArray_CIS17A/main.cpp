/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: takumiaraki
 *
 * Created on June 24, 2019, 9:01 PM
 */

#include <cstdlib>
#include <iostream>


using namespace std;

//Function Prototypes Here
void read(int [],int);
int  stat(const int [],int,int &,int &);
void print(const int [],int,int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    sum=stat(array,sizeIn,max,min);//Output the sum, max and min
    
    //Print the results
    print(array,sizeIn,sum,max,min);//print the array, sum, max and min

    //Exit
    return 0;
}


void read(int array[], int size)
{    
    for(int i=0;i<size;i++)
    {
        cin >> array[i];
    }

}

int  stat(const int array[], int size, int &MAX,int &MIN) //get the address of min and max
{
    int total=0;
    MAX = INT_MIN;   //cannot use INT_MAX and INT_MIN for Code-E compiler
    MIN = INT_MAX;   //so instead we can set MAX=0, MIN=9999999999;
    
    for(int i=0;i<size;i++)
    {
        if(array[i]>MAX)
        {
            MAX = array[i];
        }
        
        if(array[i]<MIN)
        {
            MIN = array[i];
        }
        
        total += array[i];
    }
    
    return total;
}

void print(const int array[], int size, int sum, int MAX, int MIN)
{
    for(int i=0;i<size;i++)
    {
        cout << "a[" << i << "] = " << array[i] << endl;
    }
    
    cout << "Min  = " << MIN << endl;
    cout << "Max  = " << MAX << endl;
    cout << "Sum  = " << sum << endl;
}