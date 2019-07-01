//succeeded in counting maxCount (maximum frequency

//left are 2 more steps
//1, count modeCount (number of modes)
//2, getting those modes

/*
 * The maximum count identifies the mode.
 *  All those with the maximum count must be one of the modes.  
 * So now that you know the max frequency, go back and count how many had the max frequency. 
 *  Once you know this, then you can size the mode array and cycle back to fill it.
 * Literally requires you to traverse the sorted array 3 times.
 */

/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr edited by Takumi Araki
 * Created on March 6th, 2019, 7:45 PM
 */

//Libraries
#include <cstdlib>//Random number seed
#include <iostream>//I/O Library
#include <cmath>   //Math Library
using namespace std;

//No Global Constants

//Function Prototypes
int *fillAry(int,int);      //Fill the Array
void prntAry(int *,int,int);//Print the Array
void prntMod(int *);        //Print the mode set
void swap(int *,int *);     //Swap
void minPos(int *,int,int); //Find min Position
void mrkSort(int *,int);    //Mark Sort
int *copy(const int *,int); //Copy the Array
void shuffle(int *,int,int);//Shuffle the Array
unsigned int GRB();         //Generate Random Bit
void GR(unsigned int&);     //Generate Random Number
int *mode(const int *,int); //Find the mode set

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize,//The array/set size
         modNum,//Unique numbers in the array
           *ary;//Pointer to the array
    
    //Input the number of unique numbers
    //and size of the array
    cout<<"The program finds the mode of a set"<<endl;
    cout<<"Input the size of the array and ";
    cout<<"quantity of unique numbers"<<endl;
    cin>>arySize>>modNum;
    ary=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"The Array before shuffling"<<endl;
    prntAry(ary,arySize,modNum);
    
    //Shuffle the Array 7 times
    shuffle(ary,arySize,7);
    
    //Calculate the mode array
    int *modeAry=mode(ary,arySize);
    
    //Print the initial array
    cout<<"The Array after shuffling"<<endl;
    prntAry(ary,arySize,modNum);
    
    //Print the modal information of the array
    cout<<"The Modal Information"<<endl;
    prntMod(modeAry);
    
    //Delete allocated memory
    delete []ary;
    delete []modeAry;
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    int *b=new int[n];
    //Fill with passed array
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

////////////////////////////////////////////////////////////////////////////////

void prntMod(int *ary){
    cout<<"The number of modes = "<<
            ary[0]<<endl;
    cout<<"The max Frequency = "<<
            ary[1]<<endl;
    if(ary[0]==0){
        cout<<"The mode set = {null}"<<endl;
        return;
    }
    cout<<"The mode set = {";       //don't need else, because it's returning
    for(int i=2;i<ary[0]+1;i++){
        cout<<ary[i]<<",";
    }
    cout<<ary[ary[0]+1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        minPos(array,n,i);
    }
}

void minPos(int *array,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(*(array+pos)>*(array+i))
            swap(array+pos,array+i);
    }
}

void swap(int *a,int *b){
    //Swap in place
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

void prntAry(int *array,int n,int perLine){
    //Output the array
    for(int i=0;i<n;i++){
        cout<<*(array+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n, int modNum){
    //Allocate memory
    int *array=new int[n];
    
    //Fill the array with 2 digit numbers
    for(int i=0;i<n;i++){
        *(array+i)=i%modNum;
        //*(array+i)=rand()%modNum;
    }
    
    //Exit function
    return array;
}

void shuffle(int *a,int n,int nShuf){
    unsigned int temp;
    for(int shuf=1;shuf<=nShuf;shuf++){
        for(int i=0;i<n;i++){
            GR(temp);
            temp%=n;
            if(i!=temp)swap(a[i],a[temp]);
        }
    }
}

unsigned int GRB(){
    static unsigned int seed=0;
    seed += (seed * seed) | 5;
    return seed & 0x80000000;
}
 
void GR(unsigned int& value){
    value=0;
    const unsigned int numBits = sizeof(int) * 8;
    unsigned int* dataPointer = (unsigned int *)&value;
    for (unsigned int index = 0; index < numBits; ++index)
    {
        if(GRB()) {
            unsigned int pointerIndex = index / 32;
            unsigned int mask = 1 << index % 32;
            dataPointer[pointerIndex] |= mask;
        }
    }
}

//This just a stub.  You are to fill in the correct solution
int *mode(const int *array,int arySize){
    //Copy the array
    int *ary=copy(array,arySize); 
    //Sort the copy
    mrkSort(ary,arySize);       //small to the large, ary is now a sorted array (maybe, what if not?)
    //Find the max Frequency
    
    //it's gonna be slightly easier because it's already sorted, (I'm assuming)
    int index=0,
        maxIndex=1,
        modeCount=0; //=1
    int count=1,
        maxCount=0,
        currMode=*ary;
    
    int *modesArray = nullptr; //instead dynamically allocate!!              //endpoint
    
    //modesArray = 

    /*
    for(int i=0;i<arySize-1;i++)
    {
        if(ary[i]==ary[i+1])
        {
            index++;      
        }
        else
        {
            
            if(index==1&&maxIndex==1)
                modeCount=1;
            else if(maxIndex == index)
                modeCount++;
                        
            maxIndex = index;
            index=0;
        }
    }
    */
    
    //feel like if I make currMode a dynamically allocated pointer I can do all the process at once.
    //same size as the array size.
    
    //count maxCount
    
    for(int i = 1; i < arySize; i++)
    {
        if(*(ary+i) == *(ary+ i - 1))
            count++;
        else
        {
            if(count > maxCount)
            {
                maxCount = count;
                //currMode = *(ary+ i - 1);
                count = 1;
//                modeCount++;
//                cout << "modeCount++ #1" << endl;
            }
//            if(count==maxCount)
//            {
//                modeCount++;
//                cout << "modeCount++ #2" << endl;
//            } 
        }
        
    }
    if(count > maxCount)
    {
        maxCount = count;
        //currMode = *(ary+ arySize - 1);
    }
    
    
    //count modeCount   
    //how many have maxCount
    
    int countMax = 0;
    int max = 0;
    //int modeCount=0;
    
    for(int i=0;i<arySize;i++)      //test 9 and 3
    {
        if(*(ary+i) == *(ary+ i - 1))
            countMax++;
        else
        {
            if(countMax>max)
            {
                max=countMax;
                countMax=1;
                cout << "*" << endl;
                modeCount=1;
            }
            
            if(max==maxCount)   //I should once keep away from this idea, maybe
            {
                if(i<arySize-1)
                {
                    modeCount++;
                    cout << "modeCount++ " << endl;
                }
            } 

        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    cout << "maxCount: " << maxCount << endl;
    cout << "modeCount: " << modeCount << endl; 
    
    
    //if(maxCount != 1)
    //return currMode;
    
    
    //you should have maxCount after this for loop
    
    //need to count the number of modes
    //count the number of modes which has the same index as maxCount
    
    
    
    
    
//    for(int i=0;i<arySize;i++)
//    {
//        if(i==maxCount)
//        {
//            modeCount++;
//        }
//        
//        
//    }
    
//    10      
//    3
//    
//    0 1 2 3     
//    0 1 2 3
//    0 1 
//    
//    
//    need to check the number of elements in the very last row
//    
//
//    0 0 0 1 1 1 2 2 3 3 
//  
//
//  
//  
    
    
    
    //modesArray = new int [];    //don't know size yet
    
    
    
    
    
    
    //Find the number of modes
    
    //again, this is not too hard because you just need to compare the size of index
    //oh probably I need to make it a 1d array. I'm not sure. let me see.
    
    //it's just modeCount
    
    //cout << "modeCount: " << modeCount << endl;
    //cout << "maxIndex: " << maxIndex << endl;
    
    
    //Allocate the mode array
    //Again this is just a stub.
    //int modeCount;
    int *modeAry=new int[modeCount+2];
    modeAry[0]=modeCount;//Stub returns no modes
    modeAry[1]=maxIndex;//Stub returns Frequency 1
    //modeAry[2]=
    
    //Fill the mode array
    for(int i=2;i<modeCount;i++)
    {
        *(modeAry+i)=modesArray[i];
    }

    //Delete the allocated copy and return
    delete []ary;
    delete []modesArray;
    
    return modeAry;
}

