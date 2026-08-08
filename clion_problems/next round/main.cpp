#include <iostream>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int a[100];
    for (int i = 0; i <n ; ++i) {
        cin>>a[i];
    }
    int counter=0;
    for (int j = 0; j <n ; ++j) {
        if(a[j]>=a[k-1] && a[j]>0) // k-1, not k :)
            counter++;
    }
    cout<<counter<<endl;
    return 0;
}
