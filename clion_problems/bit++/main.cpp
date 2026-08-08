#include <iostream>
#include <string>
using namespace std;
int main() {
    int n,x=0;
    cin>>n;
    string a;
    for (int i = 0; i < n; ++i) {
        cin>>a;
        if (a=="++X"||a=="X++")
        x++;
        if (a=="--X"||a=="X--")
            x--;
    }
    cout<<x<<endl;
    return 0;
}
