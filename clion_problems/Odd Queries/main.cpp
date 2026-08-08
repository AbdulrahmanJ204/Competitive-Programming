#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t;
    cin>>t;

    while(t--)
    {
        ll n,q,l,r,k;

        cin>>n>>q;
        ll a[n]={0},pre[n+10]={0};
        for (int i = 1; i <= n; ++i) {

            cin>>a[i];

        }
        for (int i = 1; i < n+1; ++i) {
            pre[i]+=pre[i-1]+a[i];
        }
        ll sum=pre[n];
        for (int i = 0; i < q; ++i) {
            cin>>l>>r>>k;
            ll x=sum-pre[r]+pre[l]-a[l];
            ll y=k*(r-l+1);
            if((x+y)%2==1)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
            }
    }

   return 0;
}
