#include <iostream>
#include <vector>
using namespace std;
vector<int> total;
vector<int> buy;

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
        auto ans = lower_bound(total.begin(), total.end(), *itb);
        if (*ans == *itb) {
            cout<<(ans-total.begin()+1)<<endl;
        }else{
            cout<<(ans-total.begin())<<endl;
        } 
    }
    return 0;
}