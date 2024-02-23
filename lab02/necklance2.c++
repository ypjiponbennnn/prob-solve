#include <iostream>
#include <list>
#include <vector>
using namespace std;

vector<list<int>> necklance;

int main() {
    int n, follow, first;

    cin>>n;
    for (int i=1 ; i<=n ; i++) {
        necklance.at(i).push_back(i);
    }
    for (int i=1 ; i<n ; i++) {
        // cout<<endl;
        cin>>follow>>first;
        for (auto it=necklance.begin() ; it!=necklance.end() ; it++) {
            for (auto it2=it->begin() ; it2!=it->end() ; it2++) {
                if (*it2==first) {
                    it2++;
                    necklance.at(first).splice(it2, necklance.at(follow));
                }
            }
        }
        // for (int i=1 ; i<=n ; i++) {
        //     cout<<"[";
        //     for (auto it=necklance[i].begin() ; it!=necklance[i].end() ; it++) {
        //         cout<<*it<<" ";
        //     }
        //     cout<<"]";
        // }
    }
    for (auto it=necklance.begin() ; it!=necklance.end() ; it++) {
            for (auto it2=it->begin() ; it2!=it->end() ; it2++) {
                cout<<*it2<<" ";
            }
        }
    return 0;
}