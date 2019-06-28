//this is 1D

/*
Calculate the Median by creating a dynamic float array 2 larger in size than
the dynamic integer array.
 * 
If you don't know how to calculate the median, google it.
Output the results with 2 decimal places.
 * 
Create the following functions and use them, here are the prototypes
int *getData(int &);         //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float *median(int *,int);  
          //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *);     //Print the median Array
 */


#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int *getData(int &);         
void prntDat(int *,int);    
float *median(int *,int); 
void prntMed(float *, int);     
/*
 * 
 */
int main(int argc, char** argv) {

    int size;
    int *aptr = nullptr; 
    float *med = nullptr;
    
    aptr = getData(size);
        
    prntDat(aptr, size);
    
    med = median(aptr, size); //new sorted pointer with size and its median value
    
    prntMed(med, size);
    
    
    delete [] aptr;
    delete [] med;
    aptr = nullptr;
    med = nullptr;
    
    return 0;
}

int *getData(int &size)
{
    //cout << "Enter the size of the array: " << endl;
    cin >> size;
   
    int *aptr = nullptr;
    aptr = new int [size];
   
    
    //cout << "Create an array." << endl;
    for(int i=0;i<size;i++)
    {
        cin >> aptr[i];
    }
    
    return aptr;
}

void prntDat(int *aptr, int size)
{
    for(int i=0;i<size;i++)
    {
        cout << *(aptr + i) << " "; 
    }
    
    cout << endl;

}

float *median(int *aptr, int size)            //maybe i can change aptr to an array declaration - no, i didn't need to 
{
    //before assigning aptr to med (ptr) i need to sort the array
    
    bool good = false;

    int temp;
    int index = size/2;

    float median;
    float *med = nullptr;
    
    med = new float [size+2];
    
    for(int i=2, j=0;i<size+2;i++,j++)
    {
        *(med + i) = *(aptr + j);
    }
    
    //bubble sort
    // now do i need to sort to get the median ? - yes i do.
    // do i need to put it into the original order (before it was sorted)
    // - i don't know, maybe i don't have that would be easier. let me try.
    

    do{
        good = false;
        
        for(int i=0;i<size;i++)
        {
            if(aptr[i]>aptr[i+1])
            {
                temp = aptr[i+1];
                aptr[i+1] = aptr[i];
                aptr[i] = temp;
                good = true;
            }
        }
    }while(good);
    
    //get the median
    if(size%2!=0)
    {
        cout << "odd!" << endl;
        median = aptr[index+1];
        
        cout << "Median(odd): " << median << endl;
    }
    else
    {
        cout << "even!" << endl;
        median = (static_cast<float>(aptr[index])+static_cast<float>(aptr[index+1]))/2;    //how can i make i a float value
                                                    // I can't simply add 0.5, when the sum is even
        
        cout << "Median(even): " << median << endl;
    }
    

    
    //fill the median array(ptr) with size of the array, the median, the rest of sorted integer array
    *med = size+2;
    *(med+1) = median;
    
    /*
    for(int i=2, j=1;i<size+2;i++,j++)
    {
        *(med + i) = *(aptr + j);
    }
    */
    
    return med;
}

void prntMed(float *med, int size)
{
    cout << "Size: " << *med << " ";
    
    cout << setprecision(2) << fixed;
    cout << "Med: " << *(med+1) << " ";
    
    for(int i=2;i<size+2;i++)
    {
        cout << med[i] << " ";
    }
    
}
