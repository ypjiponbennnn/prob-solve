#include <bits/stdc++.h>
using namespace std;

int seq[1005];
int L[1005];
int from[1005];
vector<int> ans;

int main() {
    int n, a, maxx=0, idx=1;

    cin>>n;
    for (int i=1 ; i<=n ; i++) {
        cin>>seq[i];
    }
    for (int i=1 ; i<=n ; i++) {
        for (int j=1 ; j<i ; j++) {
            if (seq[j] < seq[i]) {
                L[i] = max(L[j]+1, L[i]);
                // cout<<i<<" "<<L[i]<<"L "<<endl;
                if (L[i] == L[j]+1) {
                    from[i] = j;
                }
                // cout<<from[i]<<"f "<<endl;
            }
        }
        if (maxx < L[i]) {
            maxx=L[i];
            idx=i;
        }
    }
    cout<<maxx+1<<endl;
    while (idx!=0) {
        ans.push_back(seq[idx]);
        idx = from[idx];
    }
    for (int i=ans.size()-1 ; i>=0 ; i--) {
        cout<<ans[i]<<" ";
    }

    return 0;
}