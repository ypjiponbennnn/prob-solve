#include <iostream>
#include <vector>
using namespace std;

bool visited[100005];
vector<int> adj[100005];

void dfs(int p) {
    visited[p] = true;
    for (int q : adj[p]) {
        if (!visited[q]) dfs(q);
    }
}

int main() {
    int n, m, a, b, count=0;

    cin>>n>>m;
    for (int i=0 ; i<m ; i++) {
        cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=0 ; i<n ; i++) {
        if (!visited[i]) {
            count++;
            dfs(i);
        }
    }
    cout<<count;
    return 0;
}