/**
 * Implementation of BST class.
 */
//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.
//You should always comments to each function to describe its PURPOSE and PARAMETERS

// =======================================================
// Your name: ??? (TODO: Add your name)
// Compiler:  g++
// File type: cpp file BST.cpp
// @brief This class implements a BST search tree
//=======================================================

#include "BST.h"
#include <vector>
#include <iostream>

using namespace std;
/**
 * Implement the BST constructor
 */
BST::BST() {
    root = NULL;
    numElements = 0;
}

/**
 * Implement the BST destructor
 */
BST::~BST() {
    clear();
    // Must release memory correctly to avoid memory leaks
}

/**
 * Implement size() correctly
 */
unsigned int BST::size() const {
    return sizeHelper(root);
}

/**
 * Implement clear() correctly without memory leaks
 */
void BST::clear() {
   return clearHelper(root);
}

/**
 * Implement insert() correctly
 */
bool BST::insert(T element) {
    return insertHelper(root,element);
}

/**
 * Implement find() correctly
 */
bool BST::find(const T &query) const {
    return searchHelper(root,query);
}


/**
 * Implement the height() function correctly
 */
int BST::height() const {
    return getHeight(root) - 1; //call getHeight and - 1
}

/**
 * Implement the getRoot() function correctly
 */
BST::Node* BST::getRoot() {
    return root; //return root
}

/**
 * @brief Print the subtree at node using inorder traversal
 * @param node a pointer to node in BST
 */
//print in order, root in middle
void BST::printInorder(Node* node) {
    if(node != NULL){
        printInorder(node->leftChild);
        cout << node->data << " ";
        printInorder(node->rightChild);
        
    }
}

/**
* @brief Print the subtree at node using preorder traversal
* @param node a pointer to node in BST
*/
//print pre order, root is first
void BST::printPreorder(Node* node) {
    if(node != NULL){
        cout << node->data << " ";
        printPreorder(node->leftChild);
        printPreorder(node->rightChild);
        
    }
}

/**
* @brief Print the subtree at node using postorder traversal
* @param node a pointer to node in BST
*/
//print post order root is last
void BST::printPostorder(Node* node) {
    if(node != NULL){
        return;
        printPostorder(node->leftChild);
        printPostorder(node->rightChild);
        cout << node->data << " ";
    }
}
//return left most pointer in tree
BST::Node *BST:: getLeftMostNode(Node* node){
    while(node != nullptr && node->leftChild != nullptr){
        node = node->leftChild;
    }
    return node;
}
/**
 * Implement the getLeftMostNode() function correctly
 */
BST::Node* BST::getLeftMostNode() {
    Node* curr = root; //have a pointer point to root
    while(curr != nullptr && curr->leftChild != nullptr){
        curr = curr->leftChild; //go down the left subtree
    }
    return curr;

}

/**
 * Implement the BST successor function correctly
 */
BST::Node *BST::successor(Node *node) {
    /* TODO: YOUR CODE HERE */
    if(node == nullptr){ //if we hit nullptr(0)
        return nullptr; //return 0
    }
    if(node->rightChild != nullptr){ //if right side isnt empty, go through it to find successor
        Node* curr = node->rightChild; //assign current to nodes right child
        while(curr->leftChild != nullptr){ //while loop to find successor
            curr = curr->leftChild;
        }
        return curr; //return it now
    }
    Node* parent = node->parent; 
    while(parent != nullptr && node == parent->rightChild){
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

