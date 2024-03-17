
int countSubsetSumWays(Set<int> &set, int target) {
    if(set.isEmpty()) {
        if(target == 0)
            return 1;
        else
            return 0;
    }
    else {
        int element = set.first();
        Set<int> rest = set - element;
        int includeThisElement = countSubsetSumWays(rest, target-element);
        int excludeThisElement = countSubsetSumWays(rest, target);
        return includeThisElement + excludeThisElement;
    }
}
