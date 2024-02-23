#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    long long M, x;
    string menu;
    list<long long> num;

    cin>>M;
    for (int i=0 ; i<M ; i++) {
        cin>>menu;
        if (menu=="li" || menu=="ri") cin>>x;
        if (menu=="li") {
            num.push_front(x);
        }else if (menu=="ri") {
            num.push_back(x);
        }else if (menu=="lr") {
            auto it=num.begin();
            num.push_back(*it);
            num.pop_front();
        }else if (menu=="rr") {
            auto it=num.end();
            it--;
            num.push_front(*it);
            num.pop_back();
        }
    }
    for (auto i=num.begin() ; i!=num.end() ; i++) {
        cout<<*i<<endl;
    }
    return 0;
}