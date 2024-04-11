
#ifndef _bst_h
#define _bst_h

template <typename ValueType>
struct BSTNode {
    ValueType key;

    BSTNode<ValueType> *left;
    BSTNode<ValueType> *right;
};

/*
 * 因为map的底层用BST实现，所以此处BST的操作大多来自于mymap.h中对map的操作
 */

template <typename ValueType>
void insertNode(BSTNode<ValueType> *&root, const ValueType &key){
    BSTNode<ValueType> *&cp = findTreeNode(root, key);
    if(cp == nullptr) {
        cp = new BSTNode<ValueType>;
        cp->key = key;
        cp->left = cp->right = nullptr;
    }
}

template <typename ValueType>
void removeNode(BSTNode<ValueType> *&root, const ValueType &key) {
    BSTNode<ValueType> *&cp = findTreeNode(root, key);
    if(cp != nullptr) {
        // 1. 该结点没有孩子
        if(cp->left == nullptr && cp->right == nullptr) {
            delete cp;
            cp = nullptr;
        }

        else {
            // 该结点有左孩子（只有左孩子或者是有两个孩子）
            if(cp->left) {
                BSTNode<ValueType> *rightMostNode = rightMostNodeInLeftSubTree(cp->left);
                ValueType rightMostNodeKey = rightMostNode->key;
                removeNode(cp->left, rightMostNodeKey);
                cp->key = rightMostNodeKey;
            }
            // 该结点仅有右孩子
            else {
                BSTNode<ValueType> *leftMostNode = leftMostNodeInRightSubTree(cp->right);
                ValueType leftMostNodeKey = leftMostNode->key;
                removeNode(cp->right, leftMostNodeKey);
                cp->key = leftMostNodeKey;
            }
        }
    }
}

template <typename ValueType>
BSTNode<ValueType>* rightMostNodeInLeftSubTree(BSTNode<ValueType> *root) {
    if(root->right) {
        return rightMostNodeInLeftSubTree(root->right);
    }
    else {
        return root;
    }
}

template <typename ValueType>
BSTNode<ValueType>* leftMostNodeInRightSubTree(BSTNode<ValueType> *root) {
    if(root->left) {
        return leftMostNodeInRightSubTree(root->left);
    }
    else {
        return root;
    }
}

template <typename ValueType>
void deleteTree(BSTNode<ValueType> *root) {
    if(root == nullptr) {
        return ;
    }
    else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

template <typename ValueType>
BSTNode<ValueType> *& findTreeNode(BSTNode<ValueType> *&root, const ValueType &key) {
    if(root == nullptr) {
        return root;
    }

    else {
        if(key == root->key) {
            return root;
        }
        else if(key < root->key) {
            return findTreeNode(root->left, key);
        }
        else {
            return findTreeNode(root->right, key);
        }
    }
}

template <typename ValueType>
void inOrder(const BSTNode<ValueType> *root) {
    if(root == nullptr) {
        return ;
    }
    else {
        inOrder(root->left);
        std::cout << root->key << std::endl;
        inOrder(root->right);
    }
}

/*
 * 实现笔记：height
 * --------------
 * 一个以非空结点为根的树的高度 = 左子树的高度与右子树的高度的最大值 + 1
 */
template <typename ValueType>
int height(BSTNode<ValueType> *tree) {
    if(tree == nullptr) {
        return 0;
    }
    int leftTreeHeight = height(tree->left);
    int rightTreeHeight = height(tree->right);
    return std::max(leftTreeHeight, rightTreeHeight) + 1;
}


#endif // _bst_h
