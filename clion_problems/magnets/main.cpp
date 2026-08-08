#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[100000];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    int groups=1;
    for (int j = 0; j < n-1; ++j) {
        if(a[j]!=a[j+1])
            groups++;
    }
    cout<<groups<<endl;

    return 0;
}
