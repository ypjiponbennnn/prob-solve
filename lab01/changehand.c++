#include <iostream>
using namespace std;
int give_to[100010];
bool status[100010];

int main() {
    int n, x;
    int max = 0;
    
    cin>>n;
    for (int i=0 ; i<n ; i++) {
        cin>>x;
        give_to[i] += x;
        status[i] = false;
    }
    for (int i=0 ; i<n ; i++) {
        int j=i, count=1;
        while (give_to[j]!=i+1 && status[j]==false) {
            status[j] = true;
            j = give_to[j]-1;
            count++;
        }
        if (count>max){
            max = count;
        }
    }
    cout<<max;
    return 0;
}