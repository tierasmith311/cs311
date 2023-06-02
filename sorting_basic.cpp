/**
 * Implemention of selected sorting algorithms
 * @file sorting.cpp
 */

#include "sorting.h"

/**
 * Implement the insertionSort algorithm correctly
 */
void insertionSort(int array[], int lowindex, int highindex, bool reversed) {
   
    //int setSize = 2;
    
    if (reversed == true){ //sort in descending order
        for(int i = lowindex + 1; i <= highindex; i++){ //going through array. assume first element is sorted(i starts at 1)
            int current = array[i]; //removing last element
            int j = i - 1; //to go back to beginning of array
            while( j >= lowindex && array[j] < current){ //while j is greater than lowindex, to go back to beg. of array
               
                    array[j + 1] = array[j]; //shift elements to the right
                    j = j - 1; //move towards beg. of array
                
              
                // setSize = setSize + 1; //now move onto next element
            }
            array[j + 1] = current;//insert j back into array
        }
    }
        if(reversed == false){ //sort in ascending order
            for(int i = lowindex + 1; i <= highindex; i++){ //
                int current = array[i];
                int j = i - 1;
                while(j >= lowindex && array[j] > current){
                        array[j + 1] = array[j];
                        j = j - 1;
                    }
                    array[j + 1] = current;
                }
        }
    
}
/**
 * @brief Implementation of the partition function used by quick sort
 * if partion is true sort array in ascending order
 */

void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    
}

int partition(int array[], int lowindex, int highindex, bool reversed) {
    
    int pivot = array[lowindex]; //have high element as pivot
    
    int low = lowindex + 1; //low point to first index
    int hi = highindex; //high point to index before pivot
    
    while(true){
        while((!reversed && array[low] < pivot) || (reversed && array[low] > pivot)){
            low++; //
        }
        while((!reversed && array[hi] > pivot) || (reversed && array[hi] < pivot)){
            hi--;
        }
        if(low >= hi){
            break;
        }
       // swap(array[hi], array[low]);
        array[low] ^= array[hi];
        array[hi] ^= array[low];
        array[low] ^= array[hi];
        
        low++;
        hi--;
            }
    if(lowindex != hi){
       // swap(array[hi],array[low]);
        array[lowindex] ^= array[hi];
        array[hi] ^= array[lowindex];
        array[lowindex] ^= array[hi];
    }
    return hi;
}
/**
 
 * Implement the quickSort algorithm correctly
 */

void quickSort(int array[], int lowindex, int highindex, bool reversed) {
    
    if(lowindex >= highindex){
        return; //base case
    }
    //if(lowindex < highindex)
    else{
        int num = partition(array,lowindex,highindex,reversed); //pivot
        
        quickSort(array,lowindex,num - 1, reversed);
        quickSort(array,num + 1, highindex, reversed);
        
    }
}


