#include <iostream>
#include <list>
using namespace std;

int main() {
    int n;
    
    cin>>n;
    while (n!=0) {
        list<int> remaining;
        for (int i=1 ; i<=n ; i++) {
            remaining.push_back(i);
        }
        cout<<"Discarded cards:";
        while (remaining.size()!=1) {
            auto it=remaining.begin();
            if (remaining.size()==n) {
                cout<<" "<<*it;
            }else{
                cout<<", "<<*it;
            }
            remaining.pop_front();
            auto it2=remaining.begin();
            remaining.push_back(*it2);
            remaining.pop_front();
        }
        cout<<endl<<"Remaining card: "<<*remaining.begin()<<endl;
        cin>>n;
    }
}