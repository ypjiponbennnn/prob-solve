#include <iostream>
using namespace std;
int time_per_round[400];
bool status[400];

int main() {
    int n, k, x=0, count=0;
    int min = 1000;
    
    cin>> n>>k;
    for (int i=0 ; i<n ; i++) {
        cin>>time_per_round[i];
        status[i] = true;
        if (time_per_round[i]<min) {
            min = time_per_round[i];
        }
    }
    for (int i=0 ; i<k*min ; i++) {
        if (i%6 == 0) {
            count++;
        }
        for (int j=0 ; j<n ; j++) {
            if (i%time_per_round[j]!=0 && i<(min*(count+1)) && status[j]==true) {
                status[j] = false;
            }else if (i%time_per_round[j]==0 && i<(min*(count+1))) {
                status[j] = true;
            }
        }
    }
    for (int i=0 ; i<n ; i++) {
        if (status[i]==true) {
            x++;
        }
    }
    cout<< x;
    return 0;
}


