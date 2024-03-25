
#include <iostream>
#include "vector.h"

using namespace std;

int findDuplicate(Vector<int> vec);

int main() {
    Vector<int> v;
    v += 1, 2, 3, 1, 2;

    cout << "input: " << v << " first duplicate: " << findDuplicate(v) << endl;
    return 0;
}

// reference: https://leetcode.cn/problems/find-the-duplicate-number/solutions/18952/kuai-man-zhi-zhen-de-jie-shi-cong-damien_undoxie-d
// Finds a duplicate in the vector where only one duplicate number exists.
int findDuplicate(Vector<int> vec) {
    int fast = 0, slow = 0;

    // Phase 1: Detecting the cycle.
    // The 'fast' pointer moves at twice the speed of the 'slow' pointer.
    while(true) {
        fast = vec[vec[fast]]; // Moves two steps.
        slow = vec[slow]; // Moves one step.
        if(fast == slow) {
            // A cycle is detected when the fast and slow pointers meet.
            break;
        }
    }

    // Phase 2: Finding the entrance to the cycle, which is the duplicate element.
    int finder = 0;
    while(true) {
        slow = vec[slow]; // Both pointers now move at the same speed.
        finder = vec[finder];
        if(finder == slow) {
            // The point where they meet is the entrance to the cycle, i.e., the duplicate number.
            break;
        }
    }
    return finder; // Returns the duplicate number.
}

