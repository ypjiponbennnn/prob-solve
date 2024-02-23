//key value

#include<iostream>
#include<algorithm>
#define MAX_N 100009
using namespace std;
struct iv {
    int start_time;
    int end_time;
    friend bool operator<(const iv& l, const iv& r)
    {
        return false;
    }
};
pair<int, iv> intervals[MAX_N];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].second.start_time >> intervals[i].second.end_time;
        intervals[i].first = intervals[i].second.end_time;
    }
    sort(intervals, intervals+n);
    for (int i = 0; i < n; i++) {
        cout << intervals[i].second.start_time << " " << intervals[i].second.end_time << endl;
    }
    return 0;
}