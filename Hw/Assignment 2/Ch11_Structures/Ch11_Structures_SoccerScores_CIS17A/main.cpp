#include <iostream>
#include <iomanip>

using namespace std;

struct Player {
    string NAME;
    int NUMBER;
    int SCORE;
};


int main(int argc, char** argv) {

    const int NUM_OF_PLAYERS = 12;    
    
    int totalScore=0, index=0;
    int maxScore=0;
    bool good = false;
    
    Player playerInfo[NUM_OF_PLAYERS];
    
    //get the data
    for(int i=0;i<3;i++)
    {
        cout << "Enter the player's name #" << i+1 << ": " << endl;
        getline(cin, playerInfo[i].NAME);

        
        do{
            good = false;
            cout << "Enter the number of the player: " << endl;
            cin >> playerInfo[i].NUMBER;
            
            if(playerInfo[i].NUMBER<0)
            {
                cout << "Invalid value..." << endl;
                cin.clear();
                cin.ignore(10000,'\n');
            }
            else
                good = true;
            
        }while(!good);        
        
        do{
            good = false;
            cout << "Enter the score marked by this player: " << endl;
            cin >> playerInfo[i].SCORE;
            
            if(playerInfo[i].SCORE<0)
            {
                cout << "Invalid value..." << endl;
                cin.clear();
                cin.ignore(10000,'\n');
            }
            else
                good = true;
            
            if(maxScore<playerInfo[i].SCORE)
            {
                maxScore = playerInfo[i].SCORE;
                index = i;
            }
            
            
        }while(!good);

        totalScore += playerInfo[i].SCORE;
        
        cin.clear();
        cin.ignore(10,'\n');
    }
    
    
    //display the result
    cout << "=========================|" << endl;

    
    for(int i=0;i<1;i++)
    {

        cout << "Name:  ";
        cout << setw(16) << playerInfo[i].NAME << "  |" << endl;
        
        cout << "Number:";
        cout << setw(16) << playerInfo[i].NUMBER << "  |" << endl;

        cout << "Score: ";
        cout << setw(16) << playerInfo[i].SCORE << "  |" << endl;    
        
        cout << "-------------------------|" << endl;

        cout << "Total Score: " << setw(10) << totalScore << "  |" << endl;
        cout << "The highest score:" << setw(5) << playerInfo[index].SCORE << "  |"<< endl;
        cout << "By: " << setw(20) <<  playerInfo[index].NAME << "  |" << endl;
    }
    
    cout << "=========================|" << endl;
    

    
    
    
    return 0;
}

