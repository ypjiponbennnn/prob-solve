#include <bits/stdc++.h>
using namespace std;

string name, text;

int main() {
    int count=0;

    cin>>name>>text;
    auto n = name.begin();
    for (auto t=text.begin() ; t!=text.end() ; t++) {
        if (n==name.end()) {
            n = name.begin();
            count++;
        }
        if (*t==*n) n++;
    }
    cout<<count;

    return 0;
}