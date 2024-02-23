#include <bits/stdc++.h>
using namespace std;
const int M = 199933;

int fib[100010];

int main()
{
    int n;
    
    cin>>n;
    fib[0] = 0;
    fib[1] = 1;
    for (int i=2 ; i<=n ; i++) {
        fib[i] = fib[i-1] + fib[i-2];
        fib[i] %= M;
    }
    cout<<fib[n]<<endl;
    return 0;
}