#include <iostream> 
#include <vector>
using namespace std;
vector<int> boat;
vector<int> use = {10, 20, 5, 7, 3};
vector<int> arr = {8, 2, 4, 6, 10, 11};

int main() {

    auto b = lower_bound(use.begin(), use.end(), 4);
    cout<<*b;
    auto it3 = lower_bound(arr.begin(), arr.end(), 7);
    cout<<*it3;
    // for (auto itr=use.begin() ; itr!=use.end() ; itr++) {
    //     auto b = lower_bound(boat.begin(), boat.end(), *itr);
    //     cout<<*itr<<" lw : "<<*b<<endl;
    //     // if (b == boat.end()) {
    //     //     break;
    //     // } else {
    //     //     count++;
    //     //     boat.erase(b);
    //     // }
    // }
}