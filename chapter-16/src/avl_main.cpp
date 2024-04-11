
#include <iostream>
#include "avl.h"
using namespace std;

void inOrder(BSTNode *root);

int main() {
    BSTNode *root = nullptr;
    insertNode(root, "H");
    // inOrder(root);
    insertNode(root, "He");
    // inOrder(root);
    insertNode(root, "Li");
    // inOrder(root);
    insertNode(root, "Be");
    // inOrder(root);
    insertNode(root, "B");
    insertNode(root, "C");
    inOrder(root);
    return 0;
}

void inOrder(BSTNode *root) {
    if(root == nullptr) {
        return ;
    }
    inOrder(root->left);
    cout << root->key << "(" << root->bf << ")" << endl;
    inOrder(root->right);

}
