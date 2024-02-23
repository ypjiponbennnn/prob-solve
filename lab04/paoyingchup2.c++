#include <iostream>
#include <vector>
#include <list>
#define MAXN 1005
using namespace std;

list<pair<int, int>> history;
bool visited[MAXN];
int deg[MAXN];
int layer[MAXN];
int color[MAXN];
vector<int> adj[MAXN];

int n, m;

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

    cin>>n>>m;
    for (int i=0 ; i<n ; i++) {
        deg[i] = 0;
    }
    for (int i=0 ; i<m ; i++) {
        cin>>u>>v;
        u--; v--;
        history.push_back(make_pair(u, v));
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    for (auto it=history.begin() ; it!=history.end() ; it++) {
        init();
        for (auto itr=adj[it->first].begin() ; itr!=adj[it->first].end() ; itr++) {
            if (*itr==it->second) {
                adj[it->first].erase(itr);
                deg[it->first]--;
                break;
            }
        }
        for (auto itr=adj[it->second].begin() ; itr!=adj[it->second].end() ; itr++) {
            if (*itr==it->first) {
                adj[it->second].erase(itr);
                deg[it->second]--;
                break;
            }
        }
        ans = isBipartite(0);
        if (ans == true) {
            cout<<it->first+1<<" "<<it->second+1;
            break;
        }
        adj[it->first].push_back(it->second);
        adj[it->second].push_back(it->first);
        deg[it->first]++; deg[it->second]++;
    }
    return 0;
}