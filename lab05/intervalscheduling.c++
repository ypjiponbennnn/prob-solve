#include <bits/stdc++.h>
using namespace std;

pair<int, int> intervals[100005];

int main() {
    int n, count=1;

    cin>>n;
    for (int i=0 ; i<n ; i++) {
        cin>>intervals[i].second>>intervals[i].first;
    }
    sort(intervals, intervals+n);
    int curr = intervals[0].first;
    for (int i=0 ; i<n ; i++) {
        if (curr <= intervals[i+1].second) {
            curr = intervals[i+1].first;
            count++;
        }
    }
    cout<<count;
    
    return 0;
}