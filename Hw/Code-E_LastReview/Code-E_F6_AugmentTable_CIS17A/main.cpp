/* 
 * File:   main.cpp
 * Author: Takumi Araki
 * Created on June 25th 
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

const int COLMAX=80;  //Max Columns much larger than needed.


void read(int [][COLMAX],int &,int &);  //Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);  //Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);  //Either table can be printed



int main(int argc, char** argv) {
    const int ROW=80;           
    int array[ROW][COLMAX]={}; 
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    //Input the original table
    read(array,row,col);
   
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

void read(int array[][COLMAX], int &row, int &column)
{
    cout << "Enter the number of row you want: " << endl;
    cin >> row;
    cout << "Enter the number of column you want: " << endl;
    cin >> column;
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cin >> array[i][j];            
        }
    }
    
    
}

void sum(const int array[][COLMAX], int row, int column, int augArray[][COLMAX])
{
    int sumArrayRow[COLMAX], sumArrayColumn[COLMAX];
    int totalRow=0, totalColumn=0;
    
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            augArray[i][j] = array[i][j];
        }
    }
   
    
    for(int i=0;i<row;i++)
    {
        sumArrayRow[i] = 0;
        for(int j=0;j<column;j++)
        {
            sumArrayRow[i] += array[i][j];
        }
    }
    
    
    for(int j=0;j<column;j++)
    {
        sumArrayColumn[j] = 0;
        for(int i=0;i<row;i++)
        {
            sumArrayColumn[j] += array[i][j];
        }

    }
    
    
    for(int i=0;i<row;i++)
    {
        augArray[i][column] = sumArrayRow[i];
        totalRow += sumArrayRow[i];

    }
    
    for(int j=0;j<column;j++)
    {
        augArray[row][j] = sumArrayColumn[j];
        totalColumn += sumArrayColumn[j];

    }
    

    augArray[row][column] = totalRow + totalColumn;
    
}


void print(const int array[][COLMAX], int row, int column, int width)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout << setw(width) << array[i][j];
        }
        cout << endl;
    }
}