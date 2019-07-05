//note #include <float.h> -DBL_MAX and -DBL_MIN


/*
Weather Statistics
Write a program that uses a structure to store the following weather data for 
a particular month:
 * 
Month
Total Rainfall - Inches
High Temperature - Degrees Fahrenheit
Low Temperature -Degrees Fahrenheit
Average Temperature - Degrees Fahrenheit
 * 
The program should have an array of 12 structures to hold weather data for an
entire year. When the program runs, it should ask the user to enter data for each
month. (The average temperature should be calculated.) Once the data are entered
for all the months, the program should calculate and display the average monthly
rainfall, the total rainfall for the year, the highest and lowest temperatures for the
year (and the months they occurred in), and the average of all the monthly average
temperatures.
 * 
Input Validation: Only accept temperatures within the range between –100 and +140
degrees Fahrenheit.
*/



#include <iostream>
#include <iomanip>
#include <float.h>

using namespace std;

struct Weather{
    string MONTH;
    double RAINFALL;
    double LOWTEMP;
    double HIGHTEMP;
    double AVETEMP;
};


//void displayMonth(int);


void calculate(Weather *);
//void display(double,double,double,double,string,string,double);



const int NUM_MONTHS = 12;

int main(){
	//your code here
    
    Weather weather[NUM_MONTHS];
    
    for(int i=0;i<NUM_MONTHS;i++)
    {
        cout << "Enter the month as a string: " << endl;
        cin >> weather[i].MONTH;
        
        cout << "Enter the number total rainfall: ";
        //displayMonth(i);
        cin >> weather[i].RAINFALL;
        
        cout << "Enter the lowest temperature: ";
        cin >> weather[i].LOWTEMP;
        
        cout << "Enter the highest temperature: ";
        cin >> weather[i].HIGHTEMP;

        cout << "Enter the average temperature: ";
        cin >> weather[i].AVETEMP;
    }
    
    calculate(weather);
    
    
    
    return 0;
}


void calculate(Weather *weather) 
{
    double maxTemp=-DBL_MIN,
            minTemp=-DBL_MAX;
    
    double totalRain=0,
           totalTemp=0,    
           aveRain,
           aveTemp;
    
    string highTemp_Month,
        lowTemp_Month;
    
    
    for(int i=0;i<NUM_MONTHS;i++)
    {
        totalRain += (weather+i)->RAINFALL;
        totalTemp += (weather+i)->AVETEMP;
        
        if(maxTemp<(weather+i)->HIGHTEMP)
        {
            maxTemp = (weather+i)->HIGHTEMP;
            highTemp_Month = (weather+i)->MONTH;
        }
        if(minTemp<(weather+i)->LOWTEMP)
        {
            minTemp = (weather+i)->LOWTEMP;
            lowTemp_Month = (weather+i)->MONTH;
        }
        
    }
    
    aveRain = totalRain/NUM_MONTHS;
    aveTemp = totalTemp/NUM_MONTHS;
    
    
    //display
    
    cout << "The total rainfall: " << totalRain << endl;
    cout << "The average monthly rainfall: " << aveRain << endl;
    cout << "The lowest temperature occurred in " << lowTemp_Month << ", and was ";
    cout << minTemp << endl;
    cout << "The highest temperature occurred in " << highTemp_Month << ", and was ";
    cout << maxTemp << endl;
    cout << "Average temp: " << aveTemp << endl;
     
}

/*
void display(double totalRain,double aveRain,double minTemp,double maxTemp,
        string minMon,string maxMon,double aveTemp)
{
    cout << "The total rainfall: " << totalRain << endl;
    cout << "The average monthly rainfall: " << aveRain << endl;
    cout << "The lowest temperature occurred in " << minMon << ", and was";
    cout << minTemp << endl;
    cout << "The highest temperature occurred in " << maxMon << ", and was";
    cout << maxTemp << endl;
    cout << "Average temp: " << aveTemp << endl;
    
}
*/
