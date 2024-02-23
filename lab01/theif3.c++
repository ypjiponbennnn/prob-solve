#include <iostream>
using namespace std;

int main() {
    int n, k, t, count=1;

    cin>> n>>k>>t;
    int current=1;
    while (current!=t) {
        current = current+k;
        if (current>n) {
            current = (current%(n+1))+1;
        }
        if (current==1 && count!=1) {
            break;
        }
        count++;
    }
    cout<<count << endl;
    return 0;
}