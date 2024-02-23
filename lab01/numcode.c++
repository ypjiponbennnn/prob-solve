#include <iostream>
using namespace std;
int code[55];
int decode[55];

int main() {
    int n, t;

    cin>> n>>t;
    for (int i=0 ; i<n ; i++) {
        cin>>code[i];
    }

    if (t==2) {
        for (int i=0 ; i<n ; i++) {
            if (i==0) {
                decode[i]=code[i];
            }else{
                if (decode[i-1]*2 < code[i]) {
                    decode[i] = code[i]-(decode[i-1]*2);
                }else{
                    decode[i] = code[i]-decode[i-1];
                }
            }
        }
        for (int i=0 ; i<n ; i++) {
            code[i] = decode[i];
        }
        t--;
    }
    if (t==1) {
        for (int i=0 ; i<n ; i++) {
            if (i==0) {
                if (code[i]==n-1) {
                    decode[i]=0;
                }else{
                    decode[i]=1;
                }
            }else{
                if (code[i]>code[i-1]) {
                    decode[i]=1;
                }else{
                    decode[i]=0;
                }
            }
        }
    }

    for (int i=0 ; i<n ; i++) {
        cout<<decode[i]<<endl;
    }
    return 0;
}