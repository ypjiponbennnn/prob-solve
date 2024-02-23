#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> contract[105]; //cost_start, price_per_car, weight
vector<int> parcel;

int main() {
    int k, n, c, p, w, a;
    int minn = INT_MAX;

    cin>>k>>n;
    for (int i=0 ; i<k ; i++) {
        cin>>c>>p>>w;
        contract[i] = make_tuple(c, p, w);
    }
    for (int i=0 ; i<n ; i++) {
        cin>>a;
        parcel.push_back(a);
    }

    for (int i=0 ; i<k ; i++) {
        int count=0, summ=0;
        bool can=true;
        for (int j=0 ; j<n ; j++) {
            if (parcel[j] > get<2>(contract[i])) can=false;
            if (summ+parcel[j] > get<2>(contract[i])) {
                count++;
                summ=0;
                // cout<<"-----"<<count<<"-----"<<endl;
            }
            if (j==n-1) count++;
            // cout<<j<<" "<<summ;
            summ += parcel[j];
            // cout<<" + "<<parcel[j]<<" = "<<summ<<endl;
        }
        // cout<<"car : "<<count<<endl;
        int cost = (get<1>(contract[i])*count)+ get<0>(contract[i]);
        // cout<<"cost : "<<cost<<endl;
        if (cost<minn && can==true) {
            minn = cost;
        }
    }
    cout<<minn;

    return 0;
}