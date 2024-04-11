
/*
 * File: E-16-1.cpp
 * 实现FamilyTreeNode *readFamilyTree(string filename);
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
    Vector<FamilyTreeNode *> children;
};

FamilyTreeNode *readFamilyTree(const string filename);
/*
 * 方法：insertNode
 * 使用：insertNode(parent, child, root);
 * -------------------------------------
 * 在树中对应name为parent的结点下插入child这个结点，如果child已经存在，则不做任何操作。
 */
void insertNode(const string &parent, const string &child, FamilyTreeNode *&tree);

int main() {
    string filename;
    cout << "input your filename: ";
    cin >> filename;
    FamilyTreeNode *tree = readFamilyTree(filename);
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


void insertNode(const string &parent, const string &child, FamilyTreeNode *&root) {
    if(root->name == parent) {
        bool existChild = false;
        for(int i = 0; i < root->children.size(); ++i) {
            if(root->children[i]->name == child) {
                existChild = true;
                break;
            }
        }
        if(!existChild) {
            FamilyTreeNode *tmp = new FamilyTreeNode;
            tmp->name = child;
            root->children.add(tmp);
        }
    }
    else {
        for(int i = 0; i < root->children.size(); ++i) {
            insertNode(parent, child, root->children[i]);
        }
    }
}


