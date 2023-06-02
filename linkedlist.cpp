/**
 * @brief The implementation of the Linked List data structure
 */

//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.

//- Make sure description and PARAMETER comments are given in detail
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//  Add sufficient comments to your code body to describe what it does.
//      - Make sure all if-then-else are commented describing which case it is
//      - Make sure all local variables are described fully with their purposes

// ====================================================
//Your name: Tiera Smith
//Complier:  g++
//File type: linkedList.cpp implementation file
//=====================================================

#include<iostream>
#include"linkedlist.h"

using namespace std;

/**
 * @brief Destructor to destroy all nodes and release memory
 */
LinkedList::~LinkedList() {
    Node *temp1 = new Node(); //create a temp1
        while(front != nullptr) //while loop to go through link list
        {
            temp1 = front; //temp1 is front to start from beg.
            front = front->next; //move front
            delete temp1; //now delete temp1
        }
}

/**
 * @brief Purpose: Checks if the list is empty
 * @return true if the list is empty, false otherwise
 */
bool LinkedList::isEmpty() const {
    if(front == 0 && count == 0) //if empty
    {
        return true; //true
    }else{
        return false;//if not empty return false
    }
    return count == 0;
}

/**
 * @brief  Get the number of nodes in the list
 * @return int The number of nodes in the list
 */
int LinkedList::length() const{
    int count = 0;
    Node *counter = front;
    while(counter != nullptr)
    {
        count++;
        counter = counter->next;
    
    }
    return count;
}

/**
 * @brief Convert the list to a string
 *
 */
string LinkedList::toString() {
    string str = "[";
    Node *ptr = front;
    if (ptr != nullptr) {
        // Head node is not preceded by separator
        str += to_string(ptr->val);
        ptr = ptr->next;
    }
    while (ptr != nullptr) {
        str += ", " + to_string(ptr->val);
        ptr = ptr->next;
    }
    str  += "]";
    return str;
}

/**
 * @brief Displays the contents of the list
 */
void LinkedList::displayAll() {
    cout << toString() << endl;
}


void LinkedList::addRear(T val) {
    if(isEmpty())
    {
        front = new Node(val); //make new node and assign to front
        rear = front; //have rear point to front
        count++; //increase count
    }else{
        rear->next = new Node(val); //make a new node and assign to rear's next
        rear = rear->next; //move rear to rear's next
        count++; //increase counter
    }
    // consider the two cases of whether the list was empty
}


void LinkedList::addFront(T val) {
    if(isEmpty())
    {
        front = new Node(val); //make a new node and have front point to it
        rear = front; //have rear point to front
        count++; //update counter
    }else{
        Node *temp = front; //assigning front to temp node
        front = new Node(val); //make a new node  and have front point to it
        front->next = temp; //temp's next is front's next
        count++; //increment count
    }
    // consider the two cases of whether the list was empty
} 


bool LinkedList::deleteFront(T &OldNum) {
   if(isEmpty()) //if empty
   {
       return false;
   }else if(count == 1){
       OldNum = front->val; // old num gets the front's value
       delete front; //delete front
       //set front,rear, and count to 0
       front = nullptr;
       rear = nullptr;
       count = 0;
   }else{
       Node *temp = front;
       front = front->next;
       OldNum = temp->val;
       delete temp;
       count--;
   }
    return true;
    
    // consider if the list was empty and return false if the list is empty
    // consider the special case of deleting the only node in the list
} 

//TODO: Add comments
bool LinkedList::deleteRear(T &OldNum) {
   if(isEmpty())
   {
       return false;
   }else if(count == 1){
       OldNum = front->val;
       delete front;
      //set rear,front and count to 0
       front = nullptr;
       rear = nullptr;
       count = 0;
   }else{
       Node *temp = front;
       while(temp->next != rear)
       {
           temp = temp->next;
       }
       OldNum = rear->val;
       delete rear;
       rear = temp;
       rear->next = nullptr;
       count--;
   }
    return true;
    // consider if the list was empty and return false if the list is empty
    // consider the special case of deleting the only node in the list
} 

/* --- harder ones for test 2 and 3 -- */

    /**
    * Implement the deleteAt function to delete a node at a given position.
    */
bool LinkedList::deleteAt(int pos, T &val) {
    // check if the pos is valid first, then move the ptr to the rigth positon
    if(pos < 0 || pos > count - 1){ //if position user wants doesnt exist
           return false; //return false if position invalid
    }else if(pos == 0){ // pos at 0(first) // consider the special case of deleting the first node and the last node
        deleteFront(val);
    }else if(pos == count - 1){ //when at last node
        deleteRear(val);
    }else{
        Node *temp1 = front; //assign front into temp1
        for(int i = 0; i < pos - 1; i++){ //for loop to move temp1 to the before position you want to insert at
            temp1 = temp1->next;
        }
        val = temp1->next->val;
        Node *temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2; //delete temp 2
        count--;
    }
       // check if the pos is valid first, then move the ptr to the rigth positon
    return true;
       // Do not forget to set value.
    
}

    /**
     * Implement the insertAt function here.
     */
bool LinkedList::insertAt(int pos, T val) {
    if(pos < 0 || pos > count) //if less than position or larger than count(size)
    {
        return false;
    }else if (pos == 0){ //if first
        addFront(val); //add front
    }else if(pos == count){ //if at the length of list
        addRear(val); //add to the rear
    }else{
        Node *temp = front; //set front the the temp node
        for(int i = 0; i < pos - 1; i++) //moving temp
        {
            temp = temp->next;
        }
            Node *newNode = new Node(val); //making a new node and assigning it to val
            newNode->next = temp->next; //temp's->next is newNode's next
            temp->next = newNode; //new node gets temp's nect
            count++; //increment count
         // return val;
    }
      // consider the special case of inserting the first node and the last node
    return true;
}
/**
 * @brief Copy Constructor to allow pass by value and return by value of a LinkedList
 * @param other LinkedList to be copied
 */
LinkedList::LinkedList(const LinkedList &other) {
    // Start with an empty list
    front = nullptr;
    rear = nullptr;
    count = 0;
    
    // for each node in the other list. The new node should have the same value as the other node.
    Node *ptr = other.front;
    while(ptr != nullptr){
        addRear(ptr->val);
        ptr = ptr->next;
    }
}

/**
 * @brief Overloading of = (returns a reference to a LinkedList)
 * @param other LinkedList to be copied
 * @return reference to a LinkedList
 */
LinkedList& LinkedList::operator=(const LinkedList &other) {
    if(this != &other) { // check if the same object
        // Delete all nodes in this list
        Node *temp = front;
        while(temp != nullptr){
            Node *temp2 = temp->next;
            delete temp;
            temp = temp2;
        }
        front = nullptr;
        rear = nullptr;
        count = 0;
        // Interate through the other list and add a new node to this list
        // Be sure to set the front and rear pointers to the correct values
        // Be sure to set the count to the correct value
        Node *ptr = other.front;
        while(ptr != nullptr){
            addRear(ptr->val);
            ptr = ptr->next;
        }
    }
    return *this;
}

/**
 * Implement the search function.
 * 
 * @return int: the position of the value in the list. If the value is not in the list, return -1.
 */
 int LinkedList::search(const T& val) const {
     Node *temp = front;
     while(temp != nullptr)
     {
        if(temp->val == val)
        {
            return true; //value was found in link list
        }
        temp = temp->next;
    }
     return false;
     
    return -1;
}

