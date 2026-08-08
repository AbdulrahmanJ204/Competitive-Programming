#include <iostream>
using namespace std;
int main() {
     int n,a[100];
     cin>>n;
    for (int i = 0; i <n  ; ++i)
    {
        cin>>a[i];
    }
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i <n-1 ; ++i) {
            if(a[i]>a[i+1])
                swap(a[i],a[i+1]);
        }
    }
    for (int k = 0; k < n; ++k) {
        cout<<a[k]<<" ";
    }

    return 0;
}
