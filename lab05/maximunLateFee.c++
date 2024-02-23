#include <bits/stdc++.h>
using namespace std;

pair<int, int> finish[100005];

int main() {
    int n, dur=0;
    int maxx=0;

    cin>>n;
    for (int i=0 ; i<n ; i++) {
        cin>>finish[i].first>>finish[i].second;
    }
    sort(finish, finish+n);
    for (int i=0 ; i<n ; i++) {
        dur += finish[i].second;
        if (dur-finish[i].first > 10) {
            int fee = (dur-finish[i].first-10)*1000;
            if (fee>maxx) {
                maxx = fee;
            }
        }
    }
    cout<<maxx;

    return 0;
}