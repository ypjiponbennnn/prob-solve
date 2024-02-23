#include<iostream>
#include<vector>
#define MAX_NODE 100000
using namespace std;

bool visited[MAX_NODE];
vector<int> adj[MAX_NODE];

void dfs(int p) {
    visited[p] = true;
    cout << p+1 << endl;
    for(int q: adj[p]) {
        if (!visited[q]) {
            dfs(q);
        }
    }
}

int main() {
    int n, m;
    int a, b;
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}