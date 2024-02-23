#include <iostream>
#include <string>
#include <list>
using namespace std;
list<string> out;

int main() {
    string  text;
    bool status=false;
    int i=0;

    while (cin>>text) {
        for (auto it=text.begin() ; it!=text.end() ; it++) {
            if (*it=='[') {
                status=true; 
                continue;
            }else if (*it==']') {
                status=false;
                continue;
            }
            if (status==true) {
                auto itr = out.begin();
                advance(itr, i);
                out.insert(itr, string(1, *it));
                i++;
            }else{
                out.push_back(string(1, *it));
            }
        }
        for (auto it=out.begin() ; it!=out.end() ; it++) {
            cout<<*it;
        }
        cout<<endl;
        out.clear();
    }
    return 0;
}