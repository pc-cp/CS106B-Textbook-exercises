
/*
 * File: set.h
 * -----------
 * This interface exports the Set class, a collection for storing a set
 * of distince elements.
 */
#ifndef _myset_h
#define _myset_h

#include <fstream>
#include <ostream>
#include "mymap.h"
#include "myvector.h"


/*
 * Class: MySet<ValueType>
 * -----------------------
 * This template class stores a collection of distinct element.
 * 集合内部使用二叉搜索树（BST）结构。由于选择了这种内部表示法，存储在集合中的元素类型的 ValueType
 * 必须通过 less 函数和/或 < 操作符定义自然排序，以便对元素进行比较和排序。
 * 基于范围的 for 循环将按排序顺序遍历元素。添加/查找/删除元素的 Set 操作只需运行 O(logN) 时间。
 * O(logN)的时间复杂度基于BST是平衡的情况下，目前没有保证树的平衡性。
 *
 * 参考：https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set
 * 时间：
 *      1. 2024.4.13: 第一版
 */

template <typename ValueType>
class MySet{
public:
    /*
     * Constructor: MySet
     * Usage: Set<ValueType> Set;
     * --------------------------
     * Initializes an empty set of the specified value type.
     */

    MySet();

    /*
     * Destructor: ~Set
     * ----------------
     * Frees any heap storage associated with set.
     */
    ~MySet();

    /*
     * Method: size
     * Usage: int count = set.size();
     * ------------------------------
     * Returns the number of elements in this set.
     */
    int size() const;

    /*
     * Method: isEmpty
     * Usage: if(set.isEmpty()) . . .
     * ------------------------------
     * Returns true if this set contains no elements.
     */
    bool isEmpty() const;

    /*
     * Method: add
     * Usage: set.add(value);
     * ----------------------
     * Adds an element to this set if it is not already there.
     */
    void add(const ValueType &value);

    /*
     * Method: remove
     * Usage: set.remove(value);
     * -------------------------
     * Removes an element from this set. If the value was not contained in the
     * set, the set remains unchanged.
     */

    void remove(const ValueType &value);

    /*
     * Method: contains
     * Usage: if(set.contains(value)) . . .
     * ------------------------------------
     * Returns true if the specified value is in this set.
     */
    bool contains(const ValueType &value) const;

    /*
     * Method: clear
     * Usage: set.clear();
     * -------------------
     * Removes all elements from this set.
     */
    void clear();

    /*
     * Method: isSubsetOf
     * Usage: if(set.isSubsetOf(set2)) . . .
     * -------------------------------------
     * Implements the subset relation on sets. It returns true if every
     * element of this set is contained in set2.
     */
    bool isSubsetOf(const MySet<ValueType> &set2) const;

    /*
     * Operator: ==
     * Usage: set1 == set2
     * -------------------
     * Returns true if set1 and set2 contain the same elements.
     */
    bool operator==(const MySet<ValueType> &set2) const;

    /*
     * Operator: !=
     * Usage: set1 != set2
     * -------------------
     * Returns true if set1 and set2 are different.
     */
    bool operator!=(const MySet<ValueType> &set2) const;

    /*
     * Operator: +
     * Usage: set1 + set2
     *        set1 + value
     * -------------------
     * Returns the union of sets set1 and set2, which is the set of elements
     * that appear in at least one of the two sets. The second form returns
     * the set formed by adding a single element.
     */

    MySet<ValueType> operator+(const MySet<ValueType> &set2) const;
    MySet<ValueType> operator+(const ValueType &value) const;

    /*
     * Operator: *
     * Usage: set1 * set2
     * ------------------
     * Returns the intersection of sets set1 and set2, which is the set of all
     * elements that appear in both.
     */

    MySet<ValueType> operator*(const MySet<ValueType> &set2) const;

    /*
     * Operator: -
     * Usage: set1 - set2
     *        set1 - value
     * -------------------
     * Returns the difference of sets set1 and set2, which is all of the
     * elements that appear in set1 but not set2. The second form returns
     * the set formed by removing a single element.
     */

    MySet<ValueType> operator-(const MySet<ValueType> &set2) const;
    MySet<ValueType> operator-(const ValueType &value) const;

    /*
     * Operator: +=
     * Usage: set1 += set2
     *        set1 += value;
     * ---------------------
     * Adds all elements from set2 (or the single specified value) to set1.
     */
    MySet<ValueType> & operator +=(const MySet<ValueType> &set2);
    MySet<ValueType> & operator+=(const ValueType &value);

    /*
     * Operator: *=
     * Usage: set1 *= set2;
     * --------------------
     * Removes any elements from set1 that are not present in set2.
     */
    MySet<ValueType>& operator *= (const MySet<ValueType> &set2);

    /*
     * Operator: -=
     * Usage: set1 -= set2;
     *        set1 -= value;
     * ---------------------
     * Removes all elements from set2 (or a single value) from set1.
     */
    MySet<ValueType>& operator-=(const MySet<ValueType> &set2);
    MySet<ValueType>& operator-=(const ValueType &value);

    std::string toString() const;
    /*
     *  deepCopy
     *  copyConstructor and assignment operator
     *  default version is fine, because we have MyMap ~.
     */
    MySet(const MySet<ValueType> &src) = default;
    MySet<ValueType>& operator=(const MySet<ValueType> &src) = default;

    // The private section of the class goes here.

private:
    MyMap<ValueType, bool> map;

};

// The implementation of the class goes here.

template <typename ValueType>
MySet<ValueType>::MySet() {
    //
}

template <typename ValueType>
MySet<ValueType>::~MySet() {
    //
}

template <typename ValueType>
int MySet<ValueType>::size() const {
    return map.size();
}

template <typename ValueType>
bool MySet<ValueType>::isEmpty() const {
    return map.isEmpty();
}

template <typename ValueType>
void MySet<ValueType>::add(const ValueType &value) {
    map.put(value, true);
}

template <typename ValueType>
void MySet<ValueType>::remove(const ValueType &value) {
    map.remove(value);
}

template <typename ValueType>
bool MySet<ValueType>::contains(const ValueType &value) const {
    return map.containsKey(value);
}


template <typename ValueType>
void MySet<ValueType>::clear() {
    map.clear();
}

template <typename ValueType>
bool MySet<ValueType>::isSubsetOf(const MySet<ValueType> &set2) const {
    MyVector<ValueType> values = (this->map).keys();
    for(int i = 0; i < values.size(); ++i) {
        if(!set2.contains(values[i])) {
            return false;
        }
    }
    return true;
}

template <typename ValueType>
bool MySet<ValueType>::operator == (const MySet<ValueType> &set2) const {
    return this->isSubsetOf(set2) && ((this->map).size() == set2.map.size());
}

template <typename ValueType>
bool MySet<ValueType>::operator != (const MySet<ValueType> &set2) const {
    return !((*this) == set2);
}

template <typename ValueType>
MySet<ValueType> MySet<ValueType>::operator+ (const MySet<ValueType> &set2) const {
    if(*this == set2) return *this;
    else {
        MySet<ValueType> unionSet = *this;
        MySet<ValueType> difference = set2 - (*this);
        MyVector<ValueType> values = difference.map.keys();
        for(int i = 0; i < values.size(); ++i) {
            unionSet.add(values[i]);
        }
        return unionSet;
    }
}


template <typename ValueType>
MySet<ValueType> MySet<ValueType>::operator+ (const ValueType &value) const {

    MySet<ValueType> unionSet = (*this);
    unionSet.add(value);
    return unionSet;
}


template <typename ValueType>
MySet<ValueType> MySet<ValueType>::operator* (const MySet<ValueType> &set2) const {
    if(*this == set2) return *this;
    else {
        MySet<ValueType> intersectionSet;
        MyVector<ValueType> values = (*this).map.keys();
        for(int i = 0; i < values.size(); ++i) {
            if(set2.contains(values[i])) {
                intersectionSet.add(values[i]);
            }
        }
        return intersectionSet;
    }
}

template <typename ValueType>
MySet<ValueType> MySet<ValueType>::operator- (const MySet<ValueType> &set2) const {

    MySet<ValueType> differenceSet;
    MyVector<ValueType> values = (*this).map.keys();
    for(int i = 0; i < values.size(); ++i) {
        if(!set2.contains(values[i])) {
            differenceSet.add(values[i]);
        }
    }
    return differenceSet;

}

template <typename ValueType>
MySet<ValueType> MySet<ValueType>::operator- (const ValueType &value) const {
    MySet<ValueType> differenceSet = *this;
    differenceSet.remove(value);
    return differenceSet;
}


template <typename ValueType>
MySet<ValueType>& MySet<ValueType>::operator+= (const MySet<ValueType> &set2) {
    *this = *this + set2;
    return *this;
}


template <typename ValueType>
MySet<ValueType>& MySet<ValueType>::operator+= (const ValueType &value) {
    *this = *this + value;
    return *this;
}

template <typename ValueType>
MySet<ValueType> & MySet<ValueType>::operator*= (const MySet<ValueType> &set2) {
    *this  = *this * set2;
    return *this;
}

template <typename ValueType>
MySet<ValueType> & MySet<ValueType>::operator-= (const MySet<ValueType> &set2) {
    *this = *this - set2;
    return *this;

}

template <typename ValueType>
MySet<ValueType> & MySet<ValueType>::operator-= (const ValueType &value) {
    *this = *this - value;
    return *this;
}

template <typename ValueType>
std::string MySet<ValueType>::toString() const {
    MyVector<ValueType> keys = this->map.keys();
    return keys.toString();
}


template <typename ValueType>
std::ostream & operator <<(std::ostream & os, const MySet<ValueType> &set) {
    return os << set.toString();
}





#endif //_myset_h
