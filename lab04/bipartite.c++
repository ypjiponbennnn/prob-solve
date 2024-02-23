#include <iostream>
#include <vector>
#include <list>
#define MAXN 100005
using namespace std;

bool visited[MAXN];
int deg[MAXN];
int layer[MAXN];
int color[MAXN];
vector<int> adj[MAXN];

int k, n, m;

void init() {
    for (int i=0 ; i<n ; i++) {
        visited[i] = false;
        layer[i] = -1;
        color[i] = -1;
    }
}

bool isBipartite(int p) {
    list<int> Q;

    Q.push_back(p);
    visited[p] = true;
    layer[p] = 0;
    color[p] = 0;
    while (!Q.empty()) {
        int current = Q.front();
        Q.pop_front();
        for (int neighbor=0 ; neighbor<deg[current] ; neighbor++) {
            int v = adj[current][neighbor];
            if (!visited[v]) {
                Q.push_back(v);
                visited[v] = true;
                layer[v] = layer[current] +1;
                if (layer[v]%2 == 0) {
                    color[v] = 0; 
                } else { 
                    color[v] = 1; 
                }
            } else if (visited[v] && color[v] == color[current]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    bool ans;
    int u, v;

    cin>>k;
    for (int i=0 ; i<k ; i++) {

        cin>>n>>m;
        init();
        for (int i=0 ; i<n ; i++) {
            deg[i] = 0;
        }
        for (int j=0 ; j<m ; j++) {
            cin>>u>>v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++; deg[v]++;
        }
        ans = isBipartite(0);
        if (ans == true) cout<<"yes"<<endl;
        else cout<<"no"<<endl;

        for (int i=0 ; i<n ; i++) {
            adj[i].clear();
        }
    }

    return 0;
}