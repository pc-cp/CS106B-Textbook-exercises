
/*
 * File: E-16-4.cpp
 * Write the corresponding implementation using a vector to store the list of children.
 */
#include <iostream>
#include <fstream>
#include <string>
#include "familytree.h"
using namespace std;

FamilyTreeNode *readFamilyTree(const string filename, FamilyTreeNode * &p, FamilyTreeNode * &q);
/*
 * 方法：insertNode
 * 使用：insertNode(parent, child, root);
 * -------------------------------------
 * 在树中对应name为parent的结点下插入child这个结点，如果child已经存在，则不做任何操作。
 */
bool insertNode(const string &parent, const string &child, FamilyTreeNode *root, FamilyTreeNode * &p, FamilyTreeNode * &q);

void displayFamilyTree(FamilyTreeNode *tree);

FamilyTreeNode *commonAncestor(FamilyTreeNode *p1, FamilyTreeNode *p2);

int main() {
    string filename;
    cout << "input your filename: ";
    cin >> filename;

    FamilyTreeNode *p = nullptr;
    FamilyTreeNode *q = nullptr;
    FamilyTreeNode *tree = readFamilyTree(filename, p, q);
    displayFamilyTree(tree);
    // freeTree(tree);
    FamilyTreeNode *ancestor = commonAncestor(p, q);
    cout << ancestor->getName() << endl;

    return 0;
}




FamilyTreeNode *readFamilyTree(const string filename, FamilyTreeNode * &p, FamilyTreeNode * &q) {
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
            insertNode(parent, child, root, p, q);
        }
        else {
            cout << "format error in file." << endl;
            break;
        }
    }
    infile.close();
    return root;

}


bool insertNode(const string &parent, const string &child, FamilyTreeNode *root, FamilyTreeNode * &p, FamilyTreeNode * &q) {
    if(root->getName() == parent) {
        FamilyTreeNode *pChild = new FamilyTreeNode(child);
        if(!child.compare("Adela")) {
            p = pChild;
        }
        else if(!child.compare("Henry II")) {
            q = pChild;
        }
        root->addChild(pChild);
        return true;
    }
    else {
        Vector<FamilyTreeNode *> children = root->getChildren();
        for(int i = 0; i < children.size(); ++i) {
            if(insertNode(parent, child, children[i], p, q)) {
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

FamilyTreeNode *commonAncestor(FamilyTreeNode *p1, FamilyTreeNode *p2) {
    if(p1->getLevel() == p2->getLevel()) {
        if(p1->getName() == p2->getName()) {
            return p1;
        }
        else {
            return commonAncestor(p1->getParent(), p2->getParent());
        }
    }
    else if (p1->getLevel() > p2->getLevel()) {
        return commonAncestor(p1->getParent(), p2);
    }
    else {
        return commonAncestor(p1, p2->getParent());
    }
}
