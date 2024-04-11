
#include <iostream>
#include <cassert>
#include "bst.h"

using namespace std;
int main() {
    BSTNode<int> *root = nullptr;
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 2);

    assert(!isBalanced(root));
    assert(height(root) == 3);

    insertNode(root, 5);
    insertNode(root, 0);

    assert(isBalanced(root));

    insertNode(root, -1);



    assert(height(root) == 3);
    removeNode(root, 1);

    assert(height(root) == 3);
    removeNode(root, 2);
    removeNode(root, 5);

    assert(height(root) == 2);
    deleteTree(root);
    cout << "Structure BSTNode unit test succeed." << endl;
    return 0;
}
