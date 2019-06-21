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
    
    string mostFrequentRain;
    string whichMonth;
    
    
    //this code is to get the data from the user and write a file
    
    /*
     //get data from the user
     
     char w[MONTHS][DAYS];
     
     for(int i=0;i<MONTHS;i++)
     {
     for(int j=0;j<DAYS;j++)
     {
     cout << "Day #" << j+1 << "Enter r, c, or s: ";
     cin >> w[i][j];
     }
     cout << endl;
     }
     
     
     //write a file
     
     ofstream outputFile;
     
     outputFile.open("RainOrShine.txt");
     
     //char w[MONTHS][DAYS];
     
     for(int i=0;i<MONTHS;i++)
     {
     for(int j=0;j<DAYS;j++)
     {
     outputFile << w[i][j] << " ";
     }
     cout << endl;
     }
     
     //close file
     outputFile.close();
     */
    
    

    //read in file
    
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
    
    //close file
    inputFile.close();
    
    
    for(int i=0;i<MONTHS;i++)
    {
        rainyNumber[i]=0;
        cloudyNumber[i]=0;
        sunnyNumber[i]=0;
    }
    
    
    for(int i=0;i<MONTHS;i++)
    {
        for(int j=0;j<DAYS;j++)
        {
            if(weather[i][j]=='r'||weather[i][j]=='R')
            {
                rainyNumber[i] += 1;
            }
            else if(weather[i][j]=='c'||weather[i][j]=='C')
            {
                cloudyNumber[i] += 1;
            }
            else if(weather[i][j]=='s'||weather[i][j]=='S')
            {
                sunnyNumber[i] += 1;
            }
            else
            {
                cout << "Couldn't read (the letter wasn't r,c,s)" << endl;
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

