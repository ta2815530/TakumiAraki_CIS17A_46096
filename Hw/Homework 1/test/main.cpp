/*
 *An amateur meteorologist wants to keep track of weather conditions during the
 * past year's three-month summer season and has designated each day as either rainy ('R')
 *  , cloudy ('C'), or sunny ('S'). Write a program that stores this information in a
 * 3 * 30 array of characters, where the row indicates the month (0=June, 1=July, 2=August)
 * and the column indicates the day of the month. Note that data are not being collected 
 * for the 31st of any month. The program should begin by reading the weather data
 * in from a file. Then it should create a report that displays , for each month 
 * and for the whole three-month period, how many days were rainy, how many were cloudy, a
 * nd how any were sunny. It should also report which of the three months and the
 *  largest number of rainy days. Date for the program can be found in found in
 * the RainOrShine.txt file.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on June 20, 2019, 2:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    const int MONTHS=3, DAYS=30;
    
    int rainyNumber[MONTHS],
        cloudyNumber[MONTHS],
        sunnyNumber[MONTHS]; 
    
    int 
    
    
    string mostFrequentRain;
    string whichMonth;
    
    /*
    ofstream outputFile;
    
    outputFile.open("RainOrShine.txt");
    
    char w[MONTHS][DAYS];
    
    
    for(int i=0;i<MONTHS;i++)
    {
            if(i==0)
                whichMonth = "June";
            else if(i==1)
                whichMonth = "July";
            else 
                whichMonth = "August";
            
            cout << "In " << whichMonth << endl;
            
        for(int j=0;j<DAYS;j++)
        {
            cout << "Enter rain(r), cloudy(c), or sunny(s) on day #" << j+1 << endl;
            cin >> w[i][j];
            outputFile << w[i][j] << " ";
        }
         
        cout << endl;
    }
    
    outputFile.close();
    */
    
    
    
    ifstream inputFile;
   
    inputFile.open("RainOrShine.txt");
    
    char weather[MONTHS][DAYS];
    
    for(int i=0;i<MONTHS;i++)
    {
        for(int j=0;j<DAYS;j++)
        {
            inputFile >> weather[i][j];
        }
    }
    
    inputFile.close();
    
    
    for(int i=0;i<MONTHS;i++)
    {
        for(int j=0;j<DAYS;j++)
        {
            if(weather[i][j]=='r'||weather[i][j]=='R')
            {
                rainyNumber[i] += 1;
                cout << rainyNumber[i] << endl;
            }
            else if(weather[i][j]=='c'||weather[i][j]=='C')
            {
                //*(cloudptr+i)++;
            }
            else//(weather[i][j]=='s'||weather[i][j]=='S')
            {
                //*(sunptr+i)++;
            }
        }
    }
    
    
    if(rainyNumber[1]>=rainyNumber[2] && rainyNumber[1]>=rainyNumber[2])
    {
        mostFrequentRain = "June";
    }
    else if(rainyNumber[2]>=rainyNumber[1] && rainyNumber[2]>=rainyNumber[1])
    {
        mostFrequentRain = "July";
    }
    else //(rainyNumber[1]>=rainyNumber[2] && rainyNumber[1]>=rainyNumber[2])
    {
        mostFrequentRain = "August";
    }
    
    
    for(int i=0;i<MONTHS;i++)
    {
        if(i==0)
            whichMonth = "June";
        else if(i==1)
            whichMonth = "July";
        else 
            whichMonth = "August";
        
        cout << "In " << whichMonth << ", " << endl;
        cout << "The number of rainy days was " << rainyNumber[i] << endl;
        cout << "The number of cloudy days was " << cloudyNumber[i] << endl;
        cout << "The number of sunny days was " << sunnyNumber[i] << endl;
    }

    cout << "In those three months, the month that had the highest number of rainy days is " << endl;
    cout << mostFrequentRain << endl;
     
    
    return 0;
}


