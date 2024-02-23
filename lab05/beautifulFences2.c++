#include <bits/stdc++.h>
using namespace std;

pair<int, int> house[100005];

int main() {
    int n, s, t, count=0;
    float l, fence;

    cin>>n>>l;
    for (int i=0 ; i<n ; i++) {
        cin>>s>>t;
        house[i] = make_pair(s, t);
    }
    // for (int i=0 ; i<n ; i++) {
    //     cout<<"("<<house[i].first<<", "<<house[i].second<<")";
    // }
    // cout<<endl;
    fence = house[0].first;
    int i=0;
    while (fence < house[n-1].second) {
        // cout<<house[i].first<<", "<<house[i].second<<endl;
        // cout<<"i="<<i<<" fence= "<<fence<<endl;
        if (fence <= house[i].second || fence <= house[i+1].first) {
            // cout<<"start"<<endl;
            if (i==0) {
                fence = house[0].first + l;
                count++;
            } else if (house[i].second <= fence && fence <= house[i+1].first) {
                fence = fence + l;
                count++;
                // cout<<"between"<<endl;
            } else if (house[i].first <= fence && fence <= house[i].second) {
                fence = house[i].first + l;
                count++;
                // cout<<"overlap"<<endl;
            }
        }
        i++;
        // cout<<fence<<"  count : "<<count<<endl;
        // cout<<"------------"<<endl;
        // if (i==10) break;
    }
    cout<<count;
}