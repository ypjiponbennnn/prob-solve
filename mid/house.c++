#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> house;

int main() {
    int n, k, l, x;
    int maxx = 0;

    cin>>n>>k>>l;
    for (int i=0 ; i<n ; i++) {
        cin>>x;
        house.push_back(x);
    }
    sort(house.begin(), house.end());

    int end = house.size()-(k+l);
    auto it = house.begin();
    advance(it, end);

    for (auto itr=house.begin() ; itr!=it ; itr++) {
        auto itr2 = itr;
        advance(itr2, k+l);
        int d = *itr2 - *itr;
        //cout<<*itr2<<" - "<<*itr<<" = "<<d<<endl;
        if (d>maxx) {
            maxx = d;
        }
    }
    cout<<maxx;
}
