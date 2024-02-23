#include <bits/stdc++.h>
using namespace std;

int height[100005], status[100005];

int main() {
	int c, testcase=1;
    cin>>c;
	while (c--) {
		int n, h, ta, tb;
        cin>>n>>h>>ta>>tb;
		for (int i=0 ; i<n ; i++) {
            cin>>height[i];
        }
		sort(height, height+n);
		
		long long mintime = 0;
		memset(status, false, sizeof(status));
		int r = n-1;
		for (int i=0 ; i<n ; i++) {
			if (status[i]==true) continue;
			while (r>i && (height[i]+height[r] >= h || status[r]==true)) {
                r--;
            }
			if (r>i && height[i]+height[r]<h && status[r]==false && ta+ta>tb) {
				mintime += tb;
				status[r] = status[i] = true;
			} else {
				mintime += ta;
				status[i] = true;
			}
		}
        cout<<"Case "<<testcase++<<": "<<mintime<<endl;
	}
	return 0;
}