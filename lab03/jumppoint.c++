#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> tree;
vector<int> adj[1005];
bool visited[1005];
int layer[1005];
int deg[1005];
int n, r, x, y, dis2;

int bfs(int p) {
    queue<int> q;
    queue<int> layer;
    q.push(p);
    layer.push(0);
    
    while (true) {
        int l = layer.front();
        if (q.front() == tree.size()-1) {
            return l;
        }
        if (!visited[q.front()]) {
            for (auto v=adj[q.front()].begin() ; v!=adj[q.front()].end() ; v++) {
                q.push(*v);
                layer.push(l+1);
            }
        }
        visited[q.front()] = true;

        q.pop();
        layer.pop();
        if (q.empty()) break;
    }
    return -1;
}

int main() {
    int ans;

    cin>>n>>r;
    r = r*r;
    tree.push_back(make_pair(0, 0));
    for (int i=0 ; i<n ; i++) {
        cin>>x>>y;
        tree.push_back(make_pair(x, y));
    }
    tree.push_back(make_pair(100, 100));

    auto t1 = tree.begin();
    for (int i=0 ; i<tree.size() ; i++) {
        auto t2 = tree.begin();
        for (int j=0 ; j<tree.size() ; j++) {
            x = t2->first - t1->first;
            y = t2->second - t1->second;
            dis2 = x*x + y*y;
            if (dis2 <= r) {
                adj[i].push_back(j);
                adj[j].push_back(i);
                deg[i]++; deg[j]++;
            }
            t2++;
        }
        t1++;
    }

    ans = bfs(0);
    cout<<ans<<endl;
    return 0;
}
