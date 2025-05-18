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

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> a(m);
    for (int i = 0; i < m; i++)
    {
      int x,y;
      cin>>x>>y;
      a[i].first=y;
      a[i].second=x;
    }
    sort(a.rbegin(),a.rend());
    ll ans=0;
    for (int i = 0; i < m; i++)
    {
      int mn=min(n,a[i].second);
      ans+=mn*a[i].first;
      n-=mn;
    }
    cout<<ans;

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