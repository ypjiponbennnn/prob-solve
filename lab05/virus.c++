#include <bits/stdc++.h>
using namespace std;

vector<int> dna;

int main() {
    int n, m, a, t, num;

    cin>>n>>m;
    for (int i=0 ; i<n ; i++) {
        cin>>a;
        dna.push_back(a);
    }
    auto virus = dna.begin();
    for (int i=0 ; i<m ; i++) {
        cin>>t;
        switch (t) {
        case 1: {
            virus = dna.begin();
            cout<<"1 virus "<<*virus<<endl;
            break;
        }
        case 2: {
            virus++;
            if (virus==dna.end()) virus = dna.begin();
            cout<<"2 virus "<<*virus<<endl;
            break;
        }
        case 3: {
            cin>>num;
            cout<<*virus<<endl;
            dna.insert(virus, num);
            cout<<*virus<<endl;
            virus++;
            cout<<"3 virus "<<*virus<<endl;
            break;
        }
        case 4: {
            cin>>num;
            cout<<*virus<<endl;
            // virus++;
            virus = next(virus, 1);
            cout<<*virus<<endl;
            dna.insert(virus, num);
            virus--;
            cout<<"4 virus "<<*virus<<endl;
            break;
        }
        }
        for (int i=0 ; i<=dna.size() ; i++) {
            cout<<dna[i]<<" ";
        }
        cout<<endl;
    }
    for (int i=0 ; i<dna.size() ; i++) {
        cout<<dna[i]<<endl;
    }

    return 0;
}