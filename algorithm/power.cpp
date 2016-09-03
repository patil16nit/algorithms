#include <iostream>
using namespace std;
int pow(int x, int y) {
  if (y == 0) {
    return 1;
  }
  int temp = pow(x, y/x);
  if (y%2) {
    return x*temp*temp;
  } else {
    return  temp*temp;
  }
}

int main() {
  int x, y;
  cin>>x>>y;
  cout << pow(x,y);  
  return 0;
}
