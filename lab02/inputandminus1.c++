#include <iostream>
#include <list>
using namespace std;

int main() {
    long long M, x;
    char menu;
    list<long long> num;

    cin>>M;
    for (int i=0 ; i<M ; i++) {
        cin>> menu>>x;
        if (menu=='I') {
            num.push_front(x);
        }else if (menu=='D') {
            if (x<=num.size()) {
                auto it = num.begin();
                if (x ==1) {
                    num.pop_front();
                }else{
                    advance(it,x-1);
                    num.erase(it);
                }
            }
        }
    }
    for (auto i=num.begin() ; i!=num.end() ; i++) {
        cout<<*i<<endl;
    }
    return 0;
}