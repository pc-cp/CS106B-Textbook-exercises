
/*
 * File: E-16-3.cpp
 * Using the linked design illustrated in this diagram, write new definitions of FamilyTreeNode,
 * readFamilyTree, and displayFamilyTree.
 */
#include <iostream>
#include <fstream>
#include <string>
#include "vector.h"
using namespace std;

/*
 * 树中结点的定义
 */
struct FamilyTreeNode{
    string name;
    int level;      // 确定空格的数量
    FamilyTreeNode *eldestChild, *nextSibling;
};

FamilyTreeNode *readFamilyTree(const string filename);
/*
 * 方法：insertNode
 * 使用：insertNode(parent, child, root);
 * -------------------------------------
 * 在树中对应name为parent的结点下插入child这个结点，如果child已经存在，则不做任何操作。
 */
bool insertNode(const string &parent, const string &child, FamilyTreeNode *root);

void displayFamilyTree(FamilyTreeNode *tree);

int main() {
    string filename;
    cout << "input your filename: ";
    cin >> filename;
    FamilyTreeNode *tree = readFamilyTree(filename);
    displayFamilyTree(tree);
    return 0;
}

FamilyTreeNode *readFamilyTree(const string filename) {
    ifstream infile;

    infile.open(filename.c_str());

    FamilyTreeNode *root = nullptr;

    if(infile.fail()) {
        cout << "open failed." << endl;
        return root;
    }

    string childAndParent;
    string child, parent;
    getline(infile, parent);

    root = new FamilyTreeNode;
    root->name = parent;
    root->level = 0;
    root->eldestChild = root->nextSibling = nullptr;

    while(getline(infile, childAndParent)) {
        int posSemicolon = -1;
        for(int i = 0; i < childAndParent.size(); ++i) {
            if(childAndParent[i] == ':') {
                posSemicolon = i;
                break;
            }
        }
        if(posSemicolon != -1) {
            child = childAndParent.substr(0, posSemicolon);
            parent = childAndParent.substr(posSemicolon+1);
            insertNode(parent, child, root);
        }
        else {
            cout << "format error in file." << endl;
            break;
        }
    }
    infile.close();
    return root;

}


bool insertNode(const string &parent, const string &child, FamilyTreeNode *root) {
    if(root->name == parent) {
        bool existChild = false;
        FamilyTreeNode *p = root->eldestChild, *r = nullptr;
        while(p && p->name != child) {
            r = p;
            p = p->nextSibling;
        }
        if(p) {
            existChild = true;
        }

        if(!existChild) {
            FamilyTreeNode *tmp = new FamilyTreeNode;
            tmp->name = child;
            tmp->level = root->level + 1;
            tmp->eldestChild = tmp->nextSibling = nullptr;
            if(r == nullptr) {
                root->eldestChild = tmp;
            }
            else {
                r->nextSibling = tmp;
            }
        }
        return true;
    }
    else {

        if(root->nextSibling) {
            if(insertNode(parent, child, root->nextSibling)) {
                return true;
            }
        }
        if(root->eldestChild) {
            if(insertNode(parent, child, root->eldestChild)) {
                return true;
            }
        }

        return false;
    }
}


void displayFamilyTree(FamilyTreeNode *tree) {

    for(int i = 0; i < tree->level; ++i) {
        cout << "  ";
    }
    cout << tree->name << endl;

    if(tree->eldestChild != nullptr) {
        displayFamilyTree(tree->eldestChild);
    }
    if(tree->nextSibling != nullptr) {
        displayFamilyTree(tree->nextSibling);
    }
}




