
// 整体思想是将remainPeople当成一组集合，包含/去除一部分后更新remainPeople对应的MaxWeight
Set<Pair> maximumWeightMatchingRec(const Map<string, Map<string, int>>& possibleLinks,
                                   Map<Set<string>, Set<Pair>> &memorizations,
                                   Set<string> &remainPeople) {
    // 对于同一组人，无需重复计算
    // 启发自： https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1224/section/section3/
    // 3) Change We Can Believe In
    if(memorizations.containsKey(remainPeople)) {
        return memorizations[remainPeople];
    }
    else {
        Set<Pair> MaxWeight;
        Set<Pair> watched;

        // string currentPeople = remainPeople.first();
        for(string currentPeople: remainPeople) {
            Map<string, int> currentLinks = possibleLinks[currentPeople];

            for(string currentLink: currentLinks) {

                if(remainPeople.contains(currentLink)) {
                    Pair possiblePair(currentPeople, currentLink);
                    if(!watched.contains(possiblePair)) {
                        watched += possiblePair;
                    }
                    else {
                        continue;
                    }

                    Set<string> remainPeopleCp = remainPeople;
                    remainPeopleCp -= {currentPeople, currentLink};
                    Set<Pair> currentSubMaxWeight = maximumWeightMatchingRec(possibleLinks,
                                                                             memorizations,
                                                                             remainPeopleCp);
                    // 处理的目标是remainPeople，而currentSubMaxWeight处理的是remainPeople-{currentPeople, currentLink}
                    // 对应的maxWeight，所以需要下面这个操作
                    currentSubMaxWeight += possiblePair;

                    if(sum(possibleLinks, MaxWeight) < sum(possibleLinks, currentSubMaxWeight)) {
                        MaxWeight = currentSubMaxWeight;
                    }
                }
            }
        }

        memorizations[remainPeople] = MaxWeight;
        return MaxWeight;
    }

}

Set<Pair> maximumWeightMatching(const Map<string, Map<string, int>>& possibleLinks) {
    Map<Set<string>, Set<Pair>> memorizations;
    Set<string> remainPeople;
    for(string people : possibleLinks) {
        remainPeople += people;
    }
    return maximumWeightMatchingRec(possibleLinks, memorizations, remainPeople);
}
