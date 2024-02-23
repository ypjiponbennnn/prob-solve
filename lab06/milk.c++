#include <bits/stdc++.h>
using namespace std;

int n, q, u, v;
int parent[100005];
int set_rank[100005];

void init_set() {
    for (int i=0 ; i<n ; i++) {
        parent[i] = i;
        set_rank[i] = 1;
    }
}

int set_find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return set_find(parent[x]);
}

void set_union(int u, int v)
{
    u = set_find(u);
    v = set_find(v);
    if (u == v) return;
    if (set_rank[v] > set_rank[u]) {
        parent[u] = v;
    } else if (set_rank[u] > set_rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        set_rank[u]++;
    }
}

int main() {
    char ch;

    cin>>n>>q;
    init_set();
    for (int i=0 ; i<q ; i++) {
        cin>>ch>>u>>v;
        u--; v--;
        switch (ch) {
        case 'c': {
            set_union(u, v);
            break;
        }
        case 'q': {
            int pu = set_find(u);
            int pv = set_find(v);
            if (pu == pv) {
                cout<<"yes"<<endl;
            } else {
                cout<<"no"<<endl;
            }
            break;
        }
        }
    }

    return 0;
}