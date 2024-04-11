
#include <iostream>
#include "avl.h"

const int DEBUG = 1;

void insertNode(BSTNode *&t, std::string key) {
    insertAVL(t, key);
}

int insertAVL(BSTNode *&t, std::string key) {
    if(t == NULL) {
        t = new BSTNode;
        t->key = key;
        t->bf = 0;
        t->left = t->right = NULL;
        return +1;
    }
    if(key == t->key) return 0;
    if(key < t->key) {
        int delta = insertAVL(t->left, key);
        if(delta == 0) return 0;
        switch (t->bf) {
        case +1: t->bf = 0; return 0;
        case  0: t->bf = -1; return +1;
        case -1: fixLeftImbalance(t); return 0;
        }
    }
    else {
        int delta = insertAVL(t->right, key);
        if(delta == 0) return 0;
        switch (t->bf) {
        case -1: t->bf =  0; return 0;
        case  0: t->bf = +1; return +1;
        case +1: fixRightImbalance(t); return 0;
        }
    }
    return -1;
}

void fixLeftImbalance(BSTNode *&t) {
    BSTNode *child = t->left;
    if(child->bf != t->bf) {
        int oldBF = child->right->bf;
        rotateLeft(t->left);
        rotateRight(t);
        t->bf = 0;
        switch (oldBF) {
        case -1: t->left->bf = 0; t->right->bf = +1; break;
        case  0: t->left->bf = t->right->bf = 0; break;
        case +1: t->left->bf = -1; t->right->bf = 0; break;
        }
    }
    else {
        rotateRight(t);
        t->right->bf = t->bf = 0;
    }
}

void rotateLeft(BSTNode *&t) {
    BSTNode *child = t->right;
    if(DEBUG) {
        std::cout << "rotateLeft(" << t->key << "-" << child->key << ")" << std::endl;
    }
    t->right = child->left;
    child->left = t;
    t = child;
}

void fixRightImbalance(BSTNode *&t) {
    BSTNode *child = t->right;
    if(child->bf != t->bf) {
        int oldBF = child->left->bf;
        rotateRight(t->right);
        rotateLeft(t);
        t->bf = 0;
        switch (oldBF) {
        case -1: t->left->bf = 0; t->right->bf = +1; break;
        case  0: t->left->bf = t->right->bf = 0; break;
        case +1: t->left->bf = -1; t->right->bf = 0; break;
        }
    }
    else {
        rotateLeft(t);
        t->left->bf = t->bf = 0;
    }
}


void rotateRight(BSTNode *&t) {
    BSTNode *child = t->left;
    if(DEBUG) {
        std::cout << "rotateRight(" << t->key << "-" << child->key << ")" << std::endl;
    }
    t->left = child->right;
    child->right = t;
    t = child;

}
