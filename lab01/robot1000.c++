#include <iostream>
using namespace std;

int main() {
    int x=0, y=0;
    string command;

    cin>>command;
    for (int i=0 ; i<command.length() ; i++) {
        if (command[i]=='N') { 
            x += 1;
        }else if (command[i]=='S') {
            x -= 1;
        }else if (command[i]=='E') {
            y += 1;
        }else if (command[i]=='W') {
            y -= 1;
        }else if (command[i]=='Z') {
            x = 0;
            y = 0;
        }
    }
    cout<< y<<" "<<x;
    return 0;
}