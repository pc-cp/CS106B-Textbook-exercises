
#include <iostream>
#include "simpio.h"
#include "set.h"
using namespace std;

/* Function prototype */
// bool subsetSumExists(Set<int> set, int target);
bool subsetSumExists(Set<int> &set, int target);

int main(void)
{
    Set<int> s;
    s.add(-2); s.add(1); s.add(3); s.add(8);
    int target;
    while(true)
    {
        target = getInteger("Enter the target value to be searched (0 to quit): ");
        if(target == 0) break;

        if(subsetSumExists(s, target))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

// bool subsetSumExists(Set<int> set, int target)
// {
//     if(set.size() == 1)
//         return set.first() == target;
//     else
//     {
//         int first = set.first();
//         set.remove(first);
//         Set<int> removeFirstSet = set;
//         return subsetSumExists(removeFirstSet, target-first) || subsetSumExists(removeFirstSet, target);
//     }
// }


/*
 * Function: subsetSumExists
 * Usage: subsetSumExists(set, target)
 * -----------------------------------
 * You need to identify a simple case and a recursive decomposition.
 * 1. In applications that work with sets, the simple case is almost always
 * when the set is empty. If the set is empty, there is no way that you can add elements
 * to produce a target value unless the target is zero.
 * 2. The key insight you need to slove this problem is that there are two
 * ways that you might be able to produce the desired target sum after you have identified
 * a particular element.
 *      2.1. One possibility is that the subset you're looking for includes
 *           that element.
 *      2.2  The other possibility is that the subset you're looking for excludes that element.
 */
bool subsetSumExists(Set<int> &set, int target)
{
    if(set.isEmpty())
        return target == 0;
    else
    {
        int element = set.first();
        Set<int> rest = set - element;
        return subsetSumExists(rest, target)
               || subsetSumExists(rest, target - element);
    }
}
