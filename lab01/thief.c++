#include <iostream>
using namespace std;
int N[200005];

int main() {
    int n, k, t, count=1;

    cin>> n>>k>>t;
    for (int i=1 ; i<=n ; i++) {
        N[i] = i;
    }
    int current=1;
    while (current!=t) {
        if (current+k!=n) {
            current = (current+k)%n;
        }else{
            current = current+k;
        }
        cout<<current;
        if (current==N[1] && count!=1) {
            break;
        }
        for (int i=current ; i<=n ; i+=k) {
            current = N[i];
            count++;
            cout<<count<<endl;
        }
    }
    cout<<count;
    return 0;
}