#include <bits/stdc++.h>
using namespace std;

int n, i;
pair<double, double> island[1005];

int solve() {
    double r = -1e9;
    int cnt = 0;

    sort(island, island+n);
    i = 0;
    while (i<n) {
        while (i<n && island[i].first <= r) {
            if (r >= island[i].second) {
                r = island[i].second;
            }
            i++;
        }
        cnt++;
        r = island[i].second;
    }
    return cnt-1;
}

int main() {
    double x, y, d;
    int status, ans, cas=1;

    while(true) {
        cin>>n>>d;
        if (n==0 && d==0) break;
        status = true;
        for(i=0 ; i<n ; i++) {
            cin>>x>>y;

            if (y>d) {
                status = false;   
            } else {
                island[i].first = x-sqrt(d*d - y*y);
                island[i].second = x+sqrt(d*d - y*y);
            }
        }
        if (!status) ans = -1;
        else ans = solve();
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }

    return 0;
}