#include <bits/stdc++.h>
using namespace std;

int main() {  
    int t, Case=1;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<char> field(n + 2, '#');
        for (int i=0 ; i<n ; i++) {
            cin >> field[i];
        }

        int scarecrows = 0;
        for (int i=0 ; i<n ; i++) {
            if (field[i]=='.') {
                field[i] = field[i + 1] = field[i + 2] = '#';
                scarecrows++;
            }
        }
        cout<<"Case "<<Case++<<": "<<scarecrows<<endl;
    }
    
    return 0;
}