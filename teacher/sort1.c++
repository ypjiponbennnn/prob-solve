//swap

#include<iostream>
#include<algorithm>
#define MAX_N 100009
using namespace std;
pair<int, int> intervals[MAX_N];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].second >> intervals[i].first;
    }
    sort(intervals, intervals+n);
    for (int i = 0; i < n; i++) {
        cout << intervals[i].second << " " << intervals[i].first << endl;
    }
    return 0;
}