#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define cin(v) for(ll i=0;i<v.size();i++)cin>>v[i];
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

map<pair<pair<int,int>,int>,int> m;
void solve()
{
    m.clear();
    ll n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin>>a[i];
    }
    // for (int i = 0; i < n-2; i++)
    // {
    //   m[make_pair(make_pair(a[i],a[i+1]),a[i+2])]++;
    //   m[make_pair(make_pair(a[i],a[i+2]),a[i+1])]++;
    //   m[make_pair(make_pair(a[i+1],a[i+2]),a[i])]++;
    // }
    // for(auto x: m){
    //   cout<<x.first.first.first<<','<<x.first.second<<','<<x.first.second<<" = "<<x.second<<endl;
    // }

  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}