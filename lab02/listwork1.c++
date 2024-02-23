#include <iostream>
#include <list>
using namespace std;

int main() {
    int M, x, count=0;
    char menu;
    list<int> num;

    cin>>M;
    for (int i=0 ; i<M ; i++) {
        cin>> menu>>x;
        if (menu=='I') {
            num.push_front(x);
        }else if (menu=='D') {
            if (x<=num.size()) {
                auto it = num.begin();
                advance(it,x-1);
                cout<<*it<<endl;
                num.erase(it);
            }
        }
    }
    for (auto i=num.begin() ; i!=num.end() ; i++) {
        cout<<*i<<" ";
    }
    return 0;
}
