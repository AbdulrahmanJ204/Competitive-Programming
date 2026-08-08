#include <iostream>
#include <cstring>
using namespace std;
int main() {
   int n;
   cin>>n;
   string balls;
   cin>>balls;
   int counter=0;
    for (int i = 0; i < n; ++i) {
        if(balls[i]==balls[i+1])
            counter++;
    }
    cout<<counter<<endl;
    return 0;
}
