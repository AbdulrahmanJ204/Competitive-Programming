#include <bits/stdc++.h>
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

/* void solve() {
    ll n;
    cin >> n;
    ll a[31];
    a[0] = 1;
    for (int i = 1; i < 31; i++)
        a[i] = a[i - 1] * 2;
    ll ans=0;
    for (int i = 30; i >= 0; i--)
    {
        if(a[i]<=n) {
            n-=a[i];
            ans++;
        }
    }
            cout<<ans;
    return;
}
 */
/* void solve(){
    ll n;
    cin>>n;
    ll ans=0;
    while(n>0){
        ans+=n%2;
        n/=2;
    }
    cout<<ans;
    return;
} */
void solve(){
    ll n;
    cin>>n;
    ll ans=0;
    while(n>0){
        ans+=n&1;
        n>>=1; 
    }
    cout<<ans;
    return;
}
int main() {
    InTheNameOfAllah
        ll t = 1;
    // cin>>t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}