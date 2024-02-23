#include <iostream>
#include <list>
using namespace std;
list<int> total;
list<int> buy;

int main() {
    int m, k, cost, money, count=0, summ=0;

    cin>> m>>k;
    for (int i=0 ; i<m ; i++) {
        cin>>cost;
        summ += cost;
        total.push_back(summ);
    }
    for (int i=0 ; i<k ; i++) {
        cin>>money;
        buy.push_back(money);
    }

    for (auto itb=buy.begin() ; itb!=buy.end() ; itb++) {
        auto first = total.begin();
        advance(first, (total.size()/2)+1);
        if (*itb < *first) {
            for (auto itt=total.begin(); itt!= first; itt++) {
                if (*itb < *itt) {
                cout<<count<<endl;
                break;
                }
                count++;
            }
        }else{
            count = (total.size()/2)+1;
            for (auto itt=first; itt!= total.end() ; itt++) {
                if (*itb < *itt) {
                cout<<count<<endl;
                break;
                }
                count++;
            }
        }
        count=0;
    }
}