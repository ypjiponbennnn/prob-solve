#include <bits/stdc++.h>
using namespace std;

int tmp[2000005];
long long inversion;

void merge(int begin, int mid, int end);
void merge_sort(int begin, int end);

void merge_sort(int begin, int end) {
    if (begin < end) {
        int mid = (end + begin)/2;
        merge_sort(begin, mid);
        merge_sort(mid+1, end);
        merge(begin, mid, end);
    }
}

void merge(int begin, int mid, int end) {
    int left[(mid-begin)+1];
    int right[end-mid];

    for (int i=0 ; i<(mid-begin)+1 ; i++) {
        left[i] = tmp[begin + i];
    }
    for (int i=0 ; i<end-mid ; i++) {
        right[i] = tmp[mid+1 + i];
    }

    int i=0, j=0, k=begin;
    while (i<(mid-begin)+1 && j<end-mid) {
        if (left[i] <= right[j]) {
            tmp[k] = left[i];
            i++;
        } else {
            tmp[k] = right[j];
            j++;
            inversion += (mid-begin)+1 - i;
        }
        k++;
    }
    while (i<(mid-begin)+1) {
        tmp[k] = left[i];
        k++; i++;
    }
    while (j<end-mid) {
        tmp[k] = right[j];
        k++; j++;   
    }

}

int main() {
    int n, a;

    cin>>n;
    for (int i=0 ; i<n ; i++) {
        cin>>a;
        tmp[i] = a;
    }
    inversion = 0;
    merge_sort(0, n-1);
    cout<<inversion<<endl;
    
    return 0;
}