#include <bits/stdc++.h>
using namespace std;

pair<int, int> house[100005];

int main() {
    int n, s, t, count;
    float l, fence;

    cin>>n>>l;
    for (int i=0 ; i<n ; i++) {
        cin>>s>>t;
        house[i] = make_pair(s, t);
    }
    fence = house[0].first + l;
    for (int i=0 ; i<n ; i++) {
        if (fence < house[i].second) {
            fence -= fence-house[i].first;
        }
        if (i==n-1) {
            if (fence < house[i].second) fence += l;
        } else {
            if (fence < house[i+1].first) fence += l;
        }
    }
    // cout<<fence-house[0].first<<endl;
    // cout<<(fence-house[0].first)/l<<endl;
    count = ceil((fence-house[0].first)/l);
    cout<<count<<endl;

    return 0;
}