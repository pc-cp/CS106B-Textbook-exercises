
/*
 * File: familytree.h
 * ------------------
 * This file is an interface to a simple class that represents and individual
 * person in a family tree.
 */
#ifndef _familytree_h
#define _familytree_h

#include <string>
#include "vector.h"

/*
 * Class: FamilyTreeNode
 * ---------------------
 * This class defines the structure of an individual in the family
 * tree, which consists of a name and a vector of children.
 */

class FamilyTreeNode {
public:
    /*
     * Constructor: FamilyTreeNode
     * Usage: FamilyTreeNode *person = new FamilyTreeNode(name);
     * ---------------------------------------------------------
     * This function constructors a new FamilyTreeNode with the specified
     * name. The newly constructed entry has no children, but clients
     * can add children by calling the addChild method.
     */
    FamilyTreeNode(const std::string &name);

    /*
     * Method: getName
     * Usage: string name = person->getName();
     * ---------------------------------------
     * Returns the name of the person.
     */

    std::string getName() const;

    /*
     * Method: addChild
     * Usage: person->addChild(child);
     * -------------------------------
     * Adds child to the end of the list of children for person, and
     * makes person the parent of child.
     */
    void addChild(FamilyTreeNode *child);

    /*
     * Method: getParent
     * Usage: FamilyTreeNode *parent = person->getParent();
     * ----------------------------------------------------
     * Returns the parent of the specified person.
     */

    FamilyTreeNode *getParent() const;

    /*
     * Method: getChildren
     * Usage: Vector<FamilyTreeNode *> children = person->getChildren();
     * -----------------------------------------------------------------
     * Returns a vector of the children of the specified person.
     * Note that this vector is a copy of the one in the node, so
     * that the client cannot change the tree by adding or removing
     * children from this vector.
     */

    Vector<FamilyTreeNode *> getChildren() const;

    /*
     * Method: getLevel
     * Usage: int level = getLevel();
     * ------------------------------
     * 返回当前结点所在的层次
     */
    int getLevel() const;
    /* The private section of the class goes here. */

private:
    std::string name;
    FamilyTreeNode *parent;
    int level;
    Vector<FamilyTreeNode*> children;
};

#endif //_familytree_h
