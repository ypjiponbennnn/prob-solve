#include <iostream>
using namespace std;
int bowls[300];

int main() {
    int n, b;
    int max = 0;
    
    cin>>n;
    for (int i=0 ; i<n ; i++) {
        cin>>b;
        bowls[b] += 1;
    }
    
    for (int j=0 ; j<=300 ; j++) {
        if (bowls[j]>max) {
            max = bowls[j];
        }
    }
    cout<<max;
    return 0;
}