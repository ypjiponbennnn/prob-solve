#include <iostream>
#include <string>
using namespace std;
char chess[510][510];
bool cross=false;

int dfs(int i, int j) {
    int count=0;
    if (chess[i+1][j]=='.') {
        count++;
        dfs(i+1, j);
    }else if (chess[i][j+1]=='.') {
        count++;
        dfs(i, j+1);
    }else if (chess[i][j-1]=='.') {
        count++;
        dfs(i, j-1);
    }else if (chess[i-1][j]=='.') {
        count++;
        dfs(i-1, j);
    }else {
        if (!cross) {
            cross = true;
            if (chess[i+1][j+2]=='.') {
                dfs(i+1, j+2);
            }else if (chess[i+2][j+1]=='.') {
                dfs(i+2, j+2);
            }
        }
        count++;
    }
    if (i==100 && j==100) {
        return count;
    }
}

int main() {
    int n;
    string x;

    cin>>n;
    for (int i=0 ; i<n ; i++) {
        cin>>x;
        int j=0;
        for (auto it=x.begin() ; it!=x.end() ; it++) {
            chess[i][j] = *it;
            j++;
        }
    }

    dfs(0, 0);

    // for (int i=0 ; i<n ; i++) {
    //     for (int j=0 ; j<n ; j++) {
    //         cout<<chess[i][j];
    //     }
    //     cout<<endl;
    // }

}