
/*
 * File: E-16-4.cpp
 * Write the corresponding implementation using a vector to store the list of children.
 */
#include <iostream>
#include <fstream>
#include <string>
#include "familytree.h"
using namespace std;

FamilyTreeNode *readFamilyTree(const string filename);
/*
 * 方法：insertNode
 * 使用：insertNode(parent, child, root);
 * -------------------------------------
 * 在树中对应name为parent的结点下插入child这个结点，如果child已经存在，则不做任何操作。
 */
bool insertNode(const string &parent, const string &child, FamilyTreeNode *root);

void displayFamilyTree(FamilyTreeNode *tree);

// void freeTree(FamilyTreeNode *tree);
int main() {
    string filename;
    cout << "input your filename: ";
    cin >> filename;
    FamilyTreeNode *tree = readFamilyTree(filename);
    displayFamilyTree(tree);
    // freeTree(tree);
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

    root = new FamilyTreeNode(parent);

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
    if(root->getName() == parent) {
        FamilyTreeNode *pChild = new FamilyTreeNode(child);
        root->addChild(pChild);
        return true;
    }
    else {
        Vector<FamilyTreeNode *> children = root->getChildren();
        for(int i = 0; i < children.size(); ++i) {
            if(insertNode(parent, child, children[i])) {
                return true;
            }
        }
        return false;
    }
}

void displayFamilyTree(FamilyTreeNode *tree) {
    for(int i = 0; i < tree->getLevel(); ++i) {
        cout << "  ";
    }
    cout << tree->getName() << endl;

    Vector<FamilyTreeNode *> children = tree->getChildren();
    for(int i = 0; i < children.size(); ++i) {
        displayFamilyTree(children[i]);
    }
}

void freeTree(FamilyTreeNode *tree) {
    Vector<FamilyTreeNode
}

