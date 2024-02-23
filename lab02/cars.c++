#include <iostream>
#include <list>
using namespace std;
list<int> cars;

int main() {
    int n, cost, eff, miss=0, hit=0, count=0;
    
    cin>>n;
    for (int i=0 ; i<n ; i++) {
        cin>>cost>>eff;
        if (cars.size()==0) {
            cars.push_front(eff);
            continue;
        }
        while (cars.size()!=0 && (cars.front() <= eff)) {
            cars.pop_front();
            count++;
        }
        cars.push_front(eff);
    }
    cout<<count;
    return 0;
}