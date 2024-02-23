#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d, r;
	int hr, mornR[100], aftR[100];

	while (true) {
        cin>>n>>d>>r;
        if (n==0 && d==0 & r==0) break;
		int pay=0;

		for (int i=0 ; i<n ; i++) {
            cin>>mornR[i];
		}
		for (int i=0 ; i<n ; i++) {
            cin>>aftR[i];
		}
        sort(mornR, mornR + n);
		sort(aftR, aftR + n, greater<int>());

		for (int i=0 ; i<n ; i++) {
			hr = mornR[i]+aftR[i];
			if (hr>d) pay+=(hr-d)*r;
		}
        cout<<pay<<endl;;
	}

	return 0;
}