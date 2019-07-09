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


void calculate(Weather *);

const int NUM_MONTHS = 12;

int main(){

    bool good = false;
    
    Weather weather[NUM_MONTHS];
    
    for(int i=0;i<NUM_MONTHS;i++)
    {
        //cout << "Enter the month as a string: " << endl;
        cin >> weather[i].MONTH;
        
        //cout << "Enter the number total rainfall: ";
        cin >> weather[i].RAINFALL;
        
        do{
            good = false;
            
            //cout << "Enter the lowest temperature: ";
            cin >> weather[i].LOWTEMP;
            
            if(weather[i].LOWTEMP<-100||weather[i].LOWTEMP>140)
            {
                cin.clear();
                cin.ignore(10000,'\n');
            }
            else good = true;
            
        }while(!good);
        
        do{
            good = false;
            
            //cout << "Enter the highest temperature: ";
            cin >> weather[i].HIGHTEMP;
            
            if(weather[i].HIGHTEMP<-100||weather[i].HIGHTEMP>140)
            {
                cin.clear();
                cin.ignore(10000,'\n');
            }
            else good = true;
            
        }while(!good);
        
        
        weather[i].AVETEMP = (weather[i].HIGHTEMP+weather[i].LOWTEMP)/2;
        
    }
    
    calculate(weather);
    
    
    
    return 0;
}


void calculate(Weather *weather) 
{
    double maxTemp=-101,
            minTemp=1000000;
    
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
        if(minTemp>(weather+i)->LOWTEMP)
        {
            minTemp = (weather+i)->LOWTEMP;
            lowTemp_Month = (weather+i)->MONTH;
        }
        
    }
    
    aveRain = totalRain/NUM_MONTHS;
    aveTemp = totalTemp/NUM_MONTHS;
    
    
    //display
    cout << setprecision(1) << fixed;
    cout << "Average Rainfall " << aveRain << " inches/month"<< endl;
    
    cout << setprecision(0) << fixed;
    cout << "Lowest  Temperature " << lowTemp_Month << "  " << minTemp << " Degrees Fahrenheit" << endl;
    cout << "Highest Temperature " << highTemp_Month << "  " << maxTemp << " Degrees Fahrenheit" << endl;
    cout << "Average Temperature for the year " << aveTemp << " Degrees Fahrenheit" << endl;
     
}