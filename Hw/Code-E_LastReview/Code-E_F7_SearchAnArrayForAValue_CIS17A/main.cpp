//Honestly I have no idea how to solve this question

#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
#include <cstdlib>

using namespace std;


//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found


int main(int argc, char** argv) {
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    //int firstPos=-1;
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //int match[LINE];
    //firstPos = srch1(sntnce, pattern, firstPos); //I think this memset for the code I'm looking at
                                                //no that was in srchAll function
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //srchAll(sntnce,pattern,match);
    
    //Exit
    return 0;
}

int  srch1(const char sntnce[], const char pattern[], int startPosition)
{
    int sLen = strlen(sntnce);
    int pLen = strlen(pattern);
    
    int j;
    
    for(int i=startPosition;i<(sLen-pLen+1);i++)
    {
        for(j=0;j<pLen;j++)
        {
            if(sntnce[i+j]!=pattern[j])
                break;
        }
        
        if(j >= pLen)
            return i;
    }
    
    return -1;
    
    
    
    
    /*
    for(int i=0;sntnce[i]!='\0';i++)
    {
        int j=0;
        if(sntnce[i]==pattern[j])
        {
            firstPosition = i;
            while(sntnce[i]==pattern[j])
            {
                i++;
                j++;
            }
            if(pattern[j]=='\0')
            {
                cout << "First Occurrence of the pattern occurred in the position";
                cout << firstPosition << endl;
                break;
            }
            else
            {
                i = firstPosition;
                firstPosition = 0;
            }
        }
     }
    
    if(firstPosition ==-1)
    {
        cout << "The pattern is not occurred in the given string" << endl;
    }*/
    
    //return firstPosition;
    
    
}

void srchAll(const char sntnce[], const char pattern[], int match[]) 
{
    int i=0;
    int pattern_index = 0;
    
    while((pattern_index = srch1(sntnce,pattern,pattern_index)) != -1)
    {
        match[i++] = pattern_index;
        pattern_index += 1;
    }
    
    match[i] = -1;
    
    
    /*
    int count =0;
    int K = strlen(pattern);
    int L = strlen(sntnce);
    
    for(int i=0;i<=(L-K);i++)
    {
        for(int j=0;j<K;j++)
        {
            if(sntnce[i+j]!=pattern[j])
                break;
            if(j==K)
            {
                cout << i << endl;
            }
        }
    }
    */

}

void print(const char str[])
{
    for(int i=0;str[i]!='\0';i++)
    {
        cout << str[i];
    }   
    cout << endl;
}    

void print(const int match[])
{
    bool good = false;
    
    for(int i=0;match[i]!= -1;i++)
    {
        cout << match[i] << endl;
        if(match[i]!=-1)
        good = true;
    }
    
    if(!good)
        cout << "None" << endl;
    
}