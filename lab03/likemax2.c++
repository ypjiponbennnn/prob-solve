#include <bits/stdc++.h>
using namespace std;

priority_queue<tuple<int, int, int>> likemax;   //ch, no., status
map<int, int> likecount;

int main() {
    int n, status, ch;
    tuple<int, int, int> t;

    cin>>n;
    for (int i=0 ; i<n ; i++) {
        cin>>ch>>status;
        if (ch==1) {
            likecount[status] += 1;
        } else {
            likecount[status] -= 1;
        }
        likemax.push(make_tuple(likecount[status], i, status));

        while ((likecount.size()!=0) && (likecount[get<2>(likemax.top())] != get<0>(likemax.top()))) {
            likemax.pop();
        }
        cout<<get<2>(likemax.top())<<endl;
    }
}