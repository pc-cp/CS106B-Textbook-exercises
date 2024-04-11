
#include <iostream>
#include "bst.h"

using namespace std;
int main() {
    BSTNode<int> *root = nullptr;
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 2);
    cout << "----------------" << endl;
    inOrder(root);
    cout << "----------------" << endl;
    cout << height(root) << endl;
    insertNode(root, 5);
    insertNode(root, 0);
    insertNode(root, -1);
    cout << "----------------" << endl;
    inOrder(root);
    cout << "----------------" << endl;
    cout << height(root) << endl;
    removeNode(root, 1);
    cout << "----------------" << endl;
    inOrder(root);
    cout << "----------------" << endl;
    cout << height(root) << endl;
    removeNode(root, 2);
    removeNode(root, 5);
    cout << "----------------" << endl;
    inOrder(root);
    cout << "----------------" << endl;
    cout << height(root) << endl;
    deleteTree(root);
    return 0;
}
