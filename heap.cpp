#include "heap.h"

// @brief gets the maximum value in the heap
// @return the highest value integer in the heap
int Heap::getMax() const {
    if (count == 0)
        return -1;
        return heaparray[0];
}


// @brief default constructor. Construct an empty heap with initial capacity
Heap::Heap(int size) {
    capacity = size;
    heaparray = new int[size];
    count = 0;
}

// @brief destructor
Heap::~Heap() {
    delete[] heaparray;
}

/**
 * @brief constructor to build a heap from an array of values
 * @param values array of values to be added to the heap
 * @param length the size of the array
 */
//change to resize
Heap::Heap(int *values, int length) {
    this->heaparray = new int[length]; //resize array if needed
    this->capacity = length;
    this->count = length;
    for(int i = 0; i < length; i++){//for loop to copy
        heaparray[i] = values[i];
    }
    heapify(); //call heapify after copying
}

/**
 * @brief Copy constructor to build a heap from another heap
 * @param the heap to be copied
 */
Heap::Heap(const Heap& heap) {
    capacity = heap.capacity;
    for (int i = 1; i <= heap.count; i++)
    {
        heaparray[i - 1] = heap.heaparray[i - 1];
    }
    count = heap.count;
}

/**
  * @brief assignment operator to set one heap to another
  * @param the heap that you want to set your heap to
  */
Heap& Heap::operator = (const Heap& heap)
{
    if (this != &heap)
    {
        capacity = heap.capacity;
        for (int i = 1; i <= heap.count; i++)
        {
            heaparray[i - 1] = heap.heaparray[i - 1];
        }
        count = heap.count;
    }
    return *this;
}

/**
 * @brief   organizes the values in the heap to satisfy heap property.
 */
// satisfy heap priority points to heap with values but not organized yet
void Heap::heapify() {
// TODO: Organize the heap values by percolating through the heap
    int i;
    for (i = (count / 2) - 1; i >= 0; i--)//starts at lowest parent left parent
    {
        percolateDown(i);
    }
}

/**
 * @brief  Runs percolate down on the heap for the node stored in index.
 */
void Heap::percolateDown(int index) {
    
    // TODO: check the values at index in the heap and decide whether they need to be swapped.
    // Run recursively until the current node is bigger than its children
    // int largest = index;
    int child = leftChild(index); //call leftchild to get index
    int value = heaparray[index]; // to get value of index user inputs
    
    while(child < count){
        int maxval = value; //assume largest value is index its on
        int maxindex = 0;
        int i = 0;
        while(i < 2 && i+child <count){ //loop to check if a children nodes are bigger than their parent
            if(heaparray[i + child] > maxval){
                maxval = heaparray[i+child];
                maxindex = i+child;
            }
            i++;
        }
        if(maxval == value){
            return;
        }else{
            swap(index,maxindex);
            index = maxindex;
            child = 2*index+1;
        }
    }
}

/**
 * @brief  Runs percolate up on the heap for the node stored in index.
 */
//if added node is > than root/parent switch
void Heap::percolateUp(int index) {
    while (index > 0){
        int parent = (index - 1)/2; //find parent node
        if (heaparray[index] <= heaparray[parent]){ //check if in maxheap
            return;
        }else{
            swap(index, parent); //else swap index with parent
            index = parent;
        }
    }
}

/**
 * @brief  inserts a value into the heap
 *
 */
void Heap::insert(int value) {
    if(count == capacity){
        int* newHeap = new int[capacity * 2]; //resize array if needed
        for(int i = 0; i < count; i++){
            newHeap[i] = heaparray[i];
        }
        capacity *=2;
        delete[] heaparray;
        heaparray = newHeap;
    }else{ //if count > 0
        heaparray[count] = value;
        count++; //increase count
        percolateUp(count - 1);//call percolateup
        
    }
}

/**
 * @brief  Removes the max value from the heap
 * @return the value that was removed
 */
int Heap::removeMax() {

    if(count == 0){ //if empty
        return -1; //return -1
    }else{
        int maxVal = heaparray[0]; //set max value to the root(0)
        int restoreVal = heaparray[count - 1];
        count = count - 1;
        if(count > 0){
            heaparray[0] = restoreVal;
            percolateDown(0); //call perlocate down or heapify
        }
        return maxVal; //return max value
    }
}

/**
 * @brief  Prints the values in the heap
 */
void Heap::printHeap() {
    int i;
    cout << "[ ";
    for (i = 0; i < count; i++)
        cout << heaparray[i] << " ";
    cout << "]\n";
}

/**
 * @brief  Prints the values in an array
 */
void printArray(int values[], int length) {
    int i;
    cout << "[ ";
    for (i = 0; i < length; i++) {
        cout << values[i] << " ";
    }
    cout << "]\n";
}

/**
 * @brief  Swaps the values in the heap at index1 and index2
 */
void Heap::swap(int index1, int index2) {
    int temp = heaparray[index1];
    heaparray[index1] = heaparray[index2];
    heaparray[index2] = temp;
}

/**
 * @brief  Sorts the values of an array by using the heap
 */
//in ascending order, removes max then rearranges the tree
void Heap::heapSort(int values[], int length) {
    cout << "Array Before Sorting: \n";
    printArray(values, length);
    
    // TODO Create a heap from the array and then remove them from the heap into the array in order 
        Heap myHeap(values, length);
        int k = length - 1;
        while(k != -1){
            values[k] = myHeap.removeMax();
            k--;
        }
    //call remove heap then put value in teh arrya
    cout << "Array After Sorting: \n";
    printArray(values, length);

    return;
}

/**
     * @brief Change the key of the element at position i to the new value.
     *        It maintains the heap property.
     * @param i the position of the element to be decreased
     * @param value the new value
     */
void Heap::changeKey(int i, int new_val) {
    if (i < capacity) {
        heaparray[i] = new_val;
        percolateDown(0);
    }
}
