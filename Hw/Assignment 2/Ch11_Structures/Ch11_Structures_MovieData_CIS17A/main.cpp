#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct MovieData{
    string Title;
    string Director;
    int ReleasedYear;
    double RunningTime;
};

void display(MovieData *, int); 


int main(){
    
    int number;
    
    
    cout << "This program reviews structures" << endl;
    cout << "Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)." << endl;
    
    
    
    
    
    //cout << "Enter the number of movies:" << endl;
    cin >> number;
    
    MovieData data[number];  
    
    for(int i=0;i<number;i++)
    {
        //cout << "Enter the title of the movie #" << i+1 << ": " << endl;
        cin.ignore();
        getline(cin, data[i].Title);
        //cout << "Enter the name of the director: " << endl;
        cin.clear();
        getline(cin, data[i].Director);
        //cout << "Enter the year when the movie was released: " << endl;
        cin >> data[i].ReleasedYear;
        //cout << "Enter the running time (in minutes): " << endl;
        cin >> data[i].RunningTime;       
    }
    
    display(data, number);
    
    return 0;
}

void display(MovieData *data, int number)
{
    cout << endl;
    
    for(int i=0;i<number;i++)
    {

        cout << "Title:" << "     " << data[i].Title << endl;
        cout << "Director:" << "  " << data[i].Director << endl;
        cout << "Year:" << "      " << data[i].ReleasedYear << endl;
        cout << "Length:" << "    " << data[i].RunningTime << endl;
        if(i!=number-1)   cout << endl;
    }
    
    
    
}