#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
vector<int> boat;
vector<int> use;

int main() {
    int n, m, x, y, count=0;

    cin>>n>>m;
    for (int i=0 ; i<n ; i++) {
        cin>>x;
        boat.push_back(x);
    }
    for (int i=0 ; i<m ; i++) {
        cin>>y;
        use.push_back(y);
    }
    sort(boat.begin(), boat.end());
    for (auto itr=use.begin() ; itr!=use.end() ; itr++) {
        auto b = lower_bound(boat.begin(), boat.end(), *itr);
        if (b == boat.end()) {
            break;
        } else {
            count++;
            boat.erase(b);
        }
    }
    cout<<count;
}

