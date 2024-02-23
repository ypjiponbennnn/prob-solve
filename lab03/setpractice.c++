#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<int> X;
// vector<int> Y;

int main() {
    int n, m, x, y;

    cin>>n>>m;
    for (int i=0 ; i<n ; i++) {
        cin>>x;
        X.insert(x);
    }
    for (int i=0 ; i<m ; i++) {
        cin>>y; //{15,17,19,20} //19 //16
        auto itr1 = X.lower_bound(y); //19 //17
        if (X.lower_bound(y) == X.end()) {
            itr1--;
            cout<<*itr1<<endl;
            continue;
        } else if (X.lower_bound(y) == X.begin()){
            cout<<*itr1<<endl;
        } else {
            auto itr2 = itr1--;
            if (y-*itr2 > *itr1-y) {
                cout<<*itr2<<endl;
            } else {
                cout<<*itr1<<endl;
            }
        }
        // if (y-*itr2 > *itr1-y) {
        //     cout<<*itr1<<endl;
        // } else {
        //     cout<<*itr2<<endl;
        // }
        // cout<<*it<<" "<<*itr1<<endl;
    }

    
    return 0;
}