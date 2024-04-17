
#include <iostream>
#include <set>
#include <cstring>

using namespace std;
const int N = 1e2 + 10;

set<int> s, neighbors;

int h[N], e[N], ne[N], idx;
struct node {
    int index;
    int indegree;
};

node inDegree[N];

int n, m;

bool cmp(node a, node b) {
    return a.indegree > b.indegree;
}

void findDominatingSet() {
    sort(inDegree + 1, inDegree + n + 1, cmp);
    for(int i = 1; i <= n; ++i) {
        bool valid = false;
        for(int j = h[inDegree[i].index]; j != -1; j = ne[j]) {
            if(!neighbors.count(e[j]) && !s.count(e[j])) {
                valid = true;
                break;
            }
        }
        if(valid && s.count(inDegree[i].index)) {
            valid = false;
        }

        if(valid) {
            s.insert(inDegree[i].index);
            for(int j = h[inDegree[i].index]; j != -1; j = ne[j]) {
                if(!s.count(e[j])) {
                    neighbors.insert(e[j]);
                    // cout << "+++++" << e[j] << "++++" << endl;
                }
            }
            // cout << inDegree[i].index << endl;
        }
    }
}

void insert(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

int main() {
    cin >> n >> m;
    memset(h, 0xFF, sizeof h);

    for(int i = 1; i <= n; ++i) {
        inDegree[i].index = i;
    }
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        insert(a, b);
        insert(b, a);
        inDegree[a].indegree++;
        inDegree[b].indegree++;
    }

    findDominatingSet();

    for(auto e : s) {
        cout << e << ' ';
    }

    return 0;

}
