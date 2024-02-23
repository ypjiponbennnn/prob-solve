#include <iostream>
using namespace std;
long long time_per_round[100005];

int main() {
    long long n, k, count=0;
    long long min=2e9;

    cin>> n>>k;
    for (long long i=0 ; i<n ; i++) {
        cin>>time_per_round[i];
        if (time_per_round[i]<min) {
            min = time_per_round[i];
        }
    }
    long long fast3 = min*k;
    for (long long i=0 ; i<n ; i++) {
        if (time_per_round[i]*(k-1) <= fast3) {
            count++;
        }
    }
    cout<<count;
    return 0;
}