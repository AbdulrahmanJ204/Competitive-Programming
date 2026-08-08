#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a[10]={5,10,15,20,25,30,35,40,45,50};
    int n,k,p=0,time=240;
    cin>>n>>k;
    time=240-k;
    for (int i = 0; i < n; ++i) {
        time-=a[i];
        if(time<0)
            break;
        p++;
    }
    cout<<p<<endl;

    return 0;
}
