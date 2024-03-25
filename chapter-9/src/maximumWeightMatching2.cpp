
// 整体思想是将remainPeople当成一组集合，包含/去除一部分后更新remainPeople对应的MaxWeight
Set<Pair> maximumWeightMatchingRec(const Map<string, Map<string, int>>& possibleLinks,
                                   Set<string> &remainPeople,
                                   Map<Set<string>, Set<Pair>> memorizations) {

    if(memorizations.containsKey(remainPeople)) {
        return memorizations[remainPeople];
    }
    if(remainPeople.isEmpty()) {
        return {};
    }

    else {
        Set<Pair> includeRes, excludeRes;

        string leftPeople = remainPeople.first();
        for(string rightPeople: possibleLinks[leftPeople]) {
            if(remainPeople.contains(rightPeople)) {
                Pair possibleMatch (leftPeople, rightPeople);
                remainPeople -= {leftPeople, rightPeople};

                Set<Pair> subres = maximumWeightMatchingRec(possibleLinks, remainPeople, memorizations);
                subres += possibleMatch;
                if(sum(possibleLinks, includeRes) < sum(possibleLinks, subres)) {
                    includeRes = subres;
                }
                remainPeople += {leftPeople, rightPeople};
            }
        }

        remainPeople -= leftPeople;
        excludeRes = maximumWeightMatchingRec(possibleLinks, remainPeople, memorizations);
        remainPeople += leftPeople;

        memorizations[remainPeople] = ((sum(possibleLinks, includeRes) > sum(possibleLinks, excludeRes)) ? includeRes : excludeRes);
        return memorizations[remainPeople];
    }
}

Set<Pair> maximumWeightMatching(const Map<string, Map<string, int>>& possibleLinks) {
    Map<Set<string>, Set<Pair>> memorizations;
    Set<string> remainPeople;
    for(string people : possibleLinks) {
        remainPeople += people;
    }
    return maximumWeightMatchingRec(possibleLinks, remainPeople, memorizations);
}
