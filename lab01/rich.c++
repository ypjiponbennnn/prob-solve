#include <iostream>
using namespace std;

int main() {
    int n, m;
    int sum_val = 0;
    
    cin>>n;
    for (int i=0 ; i<n ; i++) {
        cin>>m;
        if (m>=0) {
            sum_val += m;
        }
    }
    cout<<sum_val;
    return 0;
}