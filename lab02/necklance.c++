#include<bits/stdc++.h>
using namespace std;

list<int> necklance[300005];
vector<list<int>::iterator> pos(300005);

int main() {
    int n, follow, first;

    cin>>n;
    for (int i=1 ; i<=n ; i++) {
        necklance[i].push_back(i);
        pos[i] = necklance[i].begin();
    }
    for (int i=1 ; i<n ; i++) {
        // cout<<endl;
        cin>>follow>>first;
        list<int>::iterator it = pos[first];
        necklance[first].splice(++it, necklance[follow]);
    }
    for (int i=1 ; i<=300000 ; i++) {
        for (auto it=necklance[i].begin() ; it!=necklance[i].end() ; it++) {
            cout<<*it<<" ";
        }
    }
    return 0;
}