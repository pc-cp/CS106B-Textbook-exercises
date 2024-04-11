#include <string>
#include "familytree.h"
#include "vector.h"

FamilyTreeNode::FamilyTreeNode(const std::string &name) {
    this->name = name;
    this->level = 0;
}

std::string FamilyTreeNode::getName() const {
    return this->name;
}

void FamilyTreeNode::addChild(FamilyTreeNode *child) {
    bool isExist = false;

    for(int i = 0; i < children.size(); ++i) {
        if(children[i]->getName() == child->getName()) {
            isExist = true;
            break;
        }
    }
    if(!isExist) {
        children.add(child);
        child->parent = this;
        child->level = this->level+1;
    }
}

FamilyTreeNode* FamilyTreeNode::getParent() const {
    return this->parent;
}

Vector<FamilyTreeNode *> FamilyTreeNode::getChildren() const {
    return this->children;
}


int FamilyTreeNode::getLevel() const {
    return this->level;
}
