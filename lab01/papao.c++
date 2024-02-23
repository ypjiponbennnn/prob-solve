#include <iostream>
using namespace std;

int main() {
  int n;
  int score = 0;

  cin>>n;
  for (int i=0 ; i<n ; i++) {
      int x, y;
      cin >> x >> y;
      int dis2 = x*x + y*y;
      if (dis2 <= 4) {
          score += 5;
      }else if (dis2 <= 16) {
          score += 4;
      }else if (dis2 <= 36) {
          score += 3;
      }else if (dis2 <= 64) {
          score += 2;
      }else if (dis2 <= 100) {
          score += 1;
      }else{
          score += 0;
      }
  }
  cout<< score;
  return 0;
}