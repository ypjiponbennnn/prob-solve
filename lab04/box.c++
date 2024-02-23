#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;
char map[40][40];
vector<char> adj[40][40];
bool visited[40][40];

int bfs(int i, int j) {
    list<char> queqe;

    visited[i][j] = true;
    queqe.push_back(map[i][j]);
    while (!queqe.empty()) {
        char curr = queqe.front();
        queqe.pop_front();
        for(auto q : adj[i][j]) {
            if (!visited && q=='.') {

            }
        }
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
            map[i][j] = *it;
            j++;
        }
    }
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<n ; j++) {
            adj[i][j].push_back(map[i-2][j]); //up
            adj[i][j].push_back(map[i][j+2]); //right
            adj[i][j].push_back(map[i+2][j]); //down
            adj[i][j].push_back(map[i][j-2]); //left
        }
    }


    bfs(0, 0);

    return 0;
}