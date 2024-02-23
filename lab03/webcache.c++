#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
list<int> cache;
unordered_map<int, bool> status;

int main() {
    int n, m, page, miss=0, hit=0;
    
    cin>>n>>m;
    for (int i=0 ; i<m ; i++) {
        cin>>page;
        if (status[page] == false) { //not found
            miss++;
            if (cache.size() < n) {
                cache.push_back(page);
                status[page] = true;
            } else {
                auto it=cache.begin();
                status[*it] = false;
                cache.pop_front();
                cache.push_back(page);
                status[page] = true;
            }
        } else {
            hit++;
        }
        
    }
    cout<<miss;
    return 0;
}