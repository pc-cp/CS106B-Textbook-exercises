
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string courses[] = {"XX", "CS1", "CS2", "CS3", "CS4", "CS5", "CS6", "CS7", "CS8"};

bool g[9][9];
bool visited[9];
vector<string> ans;


void dfs(int u) {
    stack<int> s;
    s.push(u);

    while(!s.empty()) {
        int t = s.top(); s.pop();
        ans.push_back(courses[t]);
        visited[t] = true;
        for(int i = 1; i <= 8; ++i) {
            if(!visited[i] && g[t][i]) {
                s.push(i);
            }
        }
    }

}

int main () {
    g[1][2] = 1;
    g[2][3] = g[2][4] = g[2][5] = 1;
    g[3][7] = g[3][8] = 1;
    g[4][6] = 1;
    g[5][6] = g[5][7] = g[5][8] = 1;

    dfs(1);

    for(auto course : ans) {
        cout << course << ' ';
    }

    return 0;
}
