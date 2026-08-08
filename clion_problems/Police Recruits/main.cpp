#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[100000];
    int pon=0,untreated=0;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        if(a[i]>0)
            pon+=a[i];
        else if(a[i]==-1&&pon==0)
            untreated++;

        else if(a[i]==-1&&pon!=0)
           --pon;

    }
    cout<<untreated<<endl;
    return 0;
}
