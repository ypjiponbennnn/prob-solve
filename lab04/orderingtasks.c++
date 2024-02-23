#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100005];
vector<int> output;
queue<int> start;
int indeg[100005];

int main() {
    int n, m, u, v;

    while (true) {

        cin>>n>>m;
        if (n==0 && m==0) break;
        for (int i=0 ; i<m ; i++) {
            cin>>u>>v;
            u--; v--;
            adj[u].push_back(v);
            indeg[v]++;
        }
        for (int i=0 ; i<n ; i++) {
            if (indeg[i]==0) start.push(i);
        }
        while (!start.empty()) {
            int s = start.front();
            output.push_back(s);
            start.pop();
            for (int q : adj[s]) {
                indeg[q]--;
                if (indeg[q]==0) start.push(q);
            }
            // for (auto it=output.begin() ; it!=output.end() ; it++) {
            //     cout<<*it+1<<" ";
            // }
            // cout<<endl;
        }
        if (output.size()==n) {
            for (auto it=output.begin() ; it!=output.end() ; it++) {
                cout<<*it+1<<" ";
            }
            cout<<endl;
        }
        output.clear();
        for (int i=0 ; i<n ; i++) {
            adj[i].clear();
        }

    }

    return 0;
}