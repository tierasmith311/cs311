/**
 * @brief Implementation of unionLinkedList and mergeLinkedList functions
 */
//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.

#include "linkedlist.h"
#include <iostream>

using namespace std;

 
/**
    * @brief Assume two linked lists that represent Set A and Set B respectively.
    * Compute the union A U B and return the result as a new linked list.
    *   friend function
    * @param LA Input linkedlist A as a set (no duplicated element)
    * @param LB Input linkedlist B as a set (no duplicated element)
    * @return LinkedList return the unioned linkedlist 
    */
LinkedList unionLinkedList(const LinkedList& LA, const LinkedList& LB) {
    LinkedList newList;
    newList = LA; //copy LA(l1, first ll) into result
    Node *temp = LB.front; //put 1st node of 2nd LL in temp
    while(temp != nullptr){ //run while loop until temp is nullptr
        int test = LA.search(temp->val); //storing search in test
        if(!test){ //if value of temp isnt in LB(2nd list)
           
            newList.addRear(temp->val); //add temp value to rear of newList
        }
        temp = temp->next; //move temp to next node
    }
        
     return newList;
}

/**
     * @brief Assume two input linked lists, LA and LB, whose elements are both in the non-descending order.
     * This function merges LA and LB into a new linked list (as the return value).
     * The elements in the new list should still be in the non-descending order.
     *
     * @param LA
     * @param LB
     * @return LinkedList
     */
LinkedList mergeLinkedList(const LinkedList& LA, const LinkedList& LB) {
    LinkedList newList;//make third list
    Node *temp = LA.front; //temp gets front of LA
    Node *temp2 = LB.front; //temp2 gets front of LB
    
    //first check if either list is empty
    if(temp == nullptr){
        return LB;  //just output 2nd list if 1st is empty
    }else if(temp2 == nullptr){
        return LA;//output first list if 2nd is empty
    }
 //   cout << "starting while" << endl;
    while(temp != nullptr || temp2 != nullptr) //run loop until either one is nullptr
    {
        if(temp == NULL){ //if we reach the end of temp(1st list)
          //  cout << "first list empty" << endl;
            while(temp2!= nullptr){
              //  cout << "adding" << temp2->val << endl;
                newList.addRear(temp2->val); //add the rest of LB in newList
                temp2 = temp2->next;
            }
            return newList; //now return newList
            // break;
        }else if(temp2 == NULL){ //if we reach end of temp2
            while(temp!=nullptr){ //while loop to go through temp
                newList.addRear(temp->val); //add temp(1st list) to newList
                temp = temp->next; //move temp
            }
            return newList; //return merged list
        }else if(temp->val <= temp2->val){ //if 1st list's node val is less than/equal to 2nd list's node
           // cout << "adding temp val" << temp->val << endl;
            newList.addRear(temp->val); //add 1st list's node to 3rd list we made first
            temp = temp->next; //move temp(1st)
        }else{ //if(temp->val >temp2->val){ //if 1st list's node val is greater than/equal to 2nd list's node
          //  cout << "adding temp2 val" << temp2->val << endl;
            newList.addRear(temp2->val); //add 2nd list's node to 3rd list we made
            temp2 = temp2->next; //move temp2(2nd)
        }
    }
    return newList;
}
   

