#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"
#define cno cout<<"NO"
#define cin(v) for(ll i=0;i<v.size();i++)cin>>v[i];
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    cin(a);
    ll ans=1;
    for (int i = 0; i < n; i++)
    {
      if(!(x%a[i])){
        
      }
    }
    cout<<ans;

  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}