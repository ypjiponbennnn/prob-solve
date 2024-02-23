#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> likecount;

int main() {
    int n, status, maxx=0, maxs=0;

    cin>>n;
    for (int i=0 ; i<n ; i++) {
        cin>>status;
        likecount[status] += 1;
        if (likecount[status]>=maxx) {
            maxx = likecount[status];
            maxs = status;
            cout<<maxs<<endl;
        } else {
            cout<<maxs<<endl;
        }
    }
    return 0;
}

