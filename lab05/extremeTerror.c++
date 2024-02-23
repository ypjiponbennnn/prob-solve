#include <bits/stdc++.h>
using namespace std;

long long money[100005];

int main() {
	int t, Case=1;
	int n, k;
	long long x;

	cin>>t;
	while (t--) {
        cin>>n>>k;
		for (int i=0 ; i<n ; i++) {
            cin>>money[i];
            money[i] = -money[i];
        }
		for (int i=0 ; i<n ; i++) {
            cin>>x;
            money[i] += x;
        }
		sort(money, money+n, greater<long long>());
		long long p=0;
		for (int i=0, j=n-1 ; i<k ; i++, j--) {
			if (money[j] < 0) n--;
        }
		for (int i=0 ; i<n ; i++) {
			p += money[i];
        }
        cout<<"Case "<<Case++<<": ";
		if (p <= 0)	cout<<"No Profit"<<endl;
		else cout<<p<<endl;
	}

	return 0;
}