#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> product;

int main() {
    int m, ch, type, amount, summ=0;

    cin>>m;
    for (int i=0 ; i<m ; i++) {
        cin>>ch;
        switch (ch) {
        case 1 : {
            cin>>type>>amount;
            if (product.find(type) != product.end()) {
                product[type] += amount;
            } else {
                product[type] = amount;
            }
            // for (auto it=product.begin() ; it!=product.end() ; it++) {
            //     cout<< it->first << " " << it->second <<endl;
            // }
            break; }
        case 2 : {
            cin>>type;
            auto it = product.find(type);
            if (product.find(type) != product.end()) {
                cout<< it->second << endl;
            } else {
                cout<< "0" << endl;
            }
            break; }
        case 3 : {
            cin>>type>>amount;
            auto it2 = product.find(type);
            if (product.find(type) == product.end()) {
                cout<< "0" <<endl;
                break;
            }
            if (it2->second <= amount) {
                cout<< it2->second << endl;
                product[type] = 0;
            } else {
                cout<< amount <<endl;
                product[type] -= amount;
            }
            break; }
        }
    }
    return 0;
}