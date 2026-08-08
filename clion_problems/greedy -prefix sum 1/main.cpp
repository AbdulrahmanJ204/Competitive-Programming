#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {/*
    ll q, n;
    cin>>q>>n;
    ll arr[n + 10];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    ll pre[n + 10] = {0, 0};
    while (q--)
    {
        ll l,r,v;
        cin>>l>>r>>v;
        pre[l]+=v;
        pre[r+1]-=v;
    }
    for (int j = 1; j < n; ++j) {
        pre[j]+= pre[j-1];
    }
    for (int k = 0; k < n; ++k) {
        cout<<arr[k]+pre[k]<<endl;
    }
*/

//first problem f(k)
    ll n;
    cin>>n;
    ll a[n+10];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    ll premin[n+10],sufmax[n+10];
    premin[0]=a[0];
    sufmax[n-1]=a[n-1];
    for (int i = 1  ; i < n; ++i) {
        premin[i]=min(premin[i-1],a[i]);
      }
    ll ans=0;
    for (int i = n-2; i >=0 ; --i) {
        sufmax[i]=max(a[i],sufmax[i+1]);
      }
    for (int i = 1; i < n-2; ++i) {
        ll temp;
        temp=abs(premin[i-1]-sufmax[i+1]);
        ans=max(ans,temp);
    }

    ans=max(sufmax[0],max(ans,premin[n-1]));
    cout<<ans<<endl;
    return 0;
}
