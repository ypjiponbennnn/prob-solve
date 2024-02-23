#include <bits/stdc++.h>
using namespace std;
int point[100005], summ[100005];
int main() {
    int n, p;
    cin>>n;
    for (int i=1 ; i<=n ; i++) cin>>point[i];
    for (int i=3 ; i<=n ; i++) {
        int jump = summ[i-3] + point[i];
        int notjump = summ[i-1];
        int m = max(jump, notjump);
        summ[i] = m;
    }
    cout<<summ[n];
}