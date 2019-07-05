/* Write a program that uses a structure named MovieData to store the following 
 * information about a movie:
 * 
Title
Director
Year Released
Running Time (in minutes)
 * 
 * The program should read the number of movies, then create MovieData structure
 * variables, store values in their members, and pass each one, in turn, to 
 * a function that displays the information about the movie in a clearly
 * formatted manner.
 */


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

void display(MovieData *, int);        //pass by reference to increase efficiency a little bit


int main(){
	//your code here
    
    int number;
    
    
    cout << "This program reviews structures" << endl;
    cout << "Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)." << endl;
    
    
    
    
    
    //cout << "Enter the number of movies:" << endl;
    cin >> number;
    
    MovieData data[number];     //possibly I need to make this a dynamically allocated array
    
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