#include <iostream>
using namespace std;
int penguin[305]; 

int main() {
    int n, count=0;
    
    cin>>n;
    for (int i=0 ; i<n ; i++) {
        cin>>penguin[i];
    }
    for (int i=0 ; i<n ; i++) {
        for (int j=i ; j<n ; j++) {
            if (penguin[j]>penguin[i]) {
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}