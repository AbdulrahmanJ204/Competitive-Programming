#include<bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);


void solve() {
    ll n;
    cin >> n;
    ll ans=0;
    while(n>0){
    ll l=0,r=n,temp=0;
        while(l<=r)
        {
            ll len=(l+r)/2;
            ll x=len*2+3*(len*(len-1)/2);
            if(x<=n){
                temp=max(x,temp);
                l=len+1;
            }
            else r=len-1;
        }
        if(temp==0) break;
        ans++;
        n-=temp;

    }
    cout<<ans;
    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}