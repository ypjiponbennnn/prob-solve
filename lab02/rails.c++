#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n, rail[1000];

	while (true) {
        cin >> n;
		if (n==0) break;
		while (true) {
			cin >> rail[0];
			if (rail[0]==0){
				cout<<endl;
				break;
			}
			for (int i=1 ; i<n ; i++) {
				cin>>rail[i];
			}

            stack<int> station;
            int current = 1, index = 0;
			while(current<=n){
				station.push(current);
				while((station.size()!=0) && (station.top()==rail[index])){
					station.pop();
					index++;
					if(index>=n) break;
				}
				current++;
			}
            
			if(station.size()==0) {
                cout <<"Yes"<<endl;
            } else {
                cout<<"No"<<endl;
            }
		}
	}

	return 0;
}