#include <iostream>
using namespace std;
int main() {
  int n,x=0;
  cin>>n;
  int steps=0;
    for (int i = 5; i >0; --i) {
        while(n>0 && n-i>=0) {

            steps++;
            n-=i;
        }
    }
    cout<<steps<<endl;
    return 0;
}
