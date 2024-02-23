#include <iostream>
#include <list>
#include <set>
using namespace std;

int main() {
    set<int> price;
    list<int> store;
    int n, tmp, summ=0;

    cin>>n;
    for (int i=0 ; i<n ; i++) {
        cin>>tmp;
        store.push_back(tmp);
    }
    for (auto it=store.begin() ; it!=store.end() ; it++) {
        for (auto it2=it ; it2!=store.end() ; it2++ ) {
            summ += *it2;
            price.insert(summ);
        }
        summ = 0;
    }
    cout<<price.size();
    return 0;
}