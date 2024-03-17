
/* E-8-4.cpp
 * Determines whether it is possible to measure out
 * the desired target amount with a given set of weights,
 * which is stored in the vector weights.
 */

#include <iostream>
#include "vector.h"

using namespace std;

bool isMeasurable(int target, Vector<int> & weights);

int main(void) {
    Vector<int> sampleWeights;
    sampleWeights += 1, 3;

    if(isMeasurable(2, sampleWeights)) {
        cout << "it is possible to measure out " << 2 << " ounces using the sample weight set" << endl;
    }
    if(isMeasurable(5, sampleWeights)) {
        cout << "it is possible to measure out " << 5 << " ounces using the sample weight set" << endl;
    }
    return 0;
}

/*
 * Function: isMeasurable
 * Usage: if(isMeasurable(target, weights)) {
 *             ...
 *          }
 * Description: Determines if a target weight can be measured using a given set of weights.
 * Each weight can be used in three ways:
 *      1. Placed on the opposite side of the scale from the target.
 *      2. Placed on the same side as the target.
 *      3. Not used at all.
 * The base case occurs when there are no weights left to consider (i.e., when the weights vector is empty).
 * In this case, the target is measurable if it has been reduced to 0.
 */

bool isMeasurable(int target, Vector<int> &weights) {
    // Base case: if there are no weights left to consider
    if(weights.isEmpty()) {
        // The target is measurable if it is exactly 0
        return target == 0;
    }
    else {
        // Take the first weight from the list
        int firstWeight = weights.get(0);
        // Create a new list of weights without the first weight
        Vector<int> removeFirstWeights = weights;
        removeFirstWeights.remove(0);
        // Recursively check if the target can be measured by:
        // 1. Adding the weight to the opposite side of the scale
        // 2. Adding the weight to the same side as the target
        // 3. Not using the weight at all
        return isMeasurable(target - firstWeight, removeFirstWeights)
               || isMeasurable(target + firstWeight, removeFirstWeights)
               || isMeasurable(target, removeFirstWeights);
    }
}
