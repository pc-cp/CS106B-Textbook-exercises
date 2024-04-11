
#ifndef _avl_h
#define _avl_h

#include <iostream>

struct BSTNode {
    std::string key;
    BSTNode *left, *right;
    int bf;     // balance factor
};

/*
 * Function: insertNode
 * Usage: insertNode(t, key);
 * --------------------------
 * Inserts a node with the specified key into the correct position in the
 * binary search tree. If key already exists in the tree, this call has
 * no effect.
 */
void insertNode(BSTNode * &t, std::string key);


/*
 * Function: insertAVL
 * Usage: delta = insertAVL(t, key);
 * ---------------------------------
 * Enter the key into the tree whose is passed by reference as the first
 * argument. The return value is the change in depth in the tree, which
 * is used to correct the balance factors in ancestor nodes.
 */
int insertAVL(BSTNode * &t, std::string key);

/*
 * Function: fixLeftImbalance
 * Usage: fixLeftImbalance(t);
 * ---------------------------
 * This function is called when a node has been found that is out of
 * balance with the longer subtree on the left. Depending on the balance
 * factor of the left child, the code performs a single or double rotation.
 */
void fixLeftImbalance(BSTNode * &t);

/*
 * Function: rotateLeft
 * Usage: rotateLeft(t);
 * ---------------------
 * Performs a single left rotation of the tree passed by reference as the
 * argument. The balance factors are unchanged by this function and must
 * be corrected at a higher level of the algorithm.
 */
void rotateLeft(BSTNode *&t);

/*
 * Function: fixRightImbalance
 * Usage: fixRightImbalance(t);
 * ----------------------------
 * This function is called when a node has been found that is out of
 * balance with the longer subtree on the right. Depending on the balance
 * factor of the right child, the code performs a single or double ratation.
 */
void fixRightImbalance(BSTNode * &t);

/*
 * Function: ratateRight
 * Usage: ratateRight(t);
 * ----------------------
 * Performs a single right rotation of the tree passed by reference as the
 * argument. The balance factors are unchanged by this function and must
 * be corrected at a higher level of the algorithm.
 */
void rotateRight(BSTNode * &t);




#endif //_avl_h
