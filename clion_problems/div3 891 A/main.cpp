#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);


int main() {
    InTheNameOfAllah
    test {
    int n;cin>>n;
    int a[n];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        sort(a,a+n);
        ll ans=0;
        for (int i = 0; i < n/2; ++i) {

            ll x=(a[n-i-1]-a[i]);
            ans+=x;
        }
        cout<<ans<<endl;
    }
    return 0;
}