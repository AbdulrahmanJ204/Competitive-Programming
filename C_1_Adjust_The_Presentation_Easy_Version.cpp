#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"
#define cno cout<<"NO"
#define cin(v) for(ll i=0;i<v.size();i++)cin>>v[i];
#define cin1(v,n) for(ll i=0;i<n;i++)cin>>v[i];
#define cin2(v,n,m) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) cin>>v[i][j];
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define cout1(v,n) for(ll i=0;i<n;i++)cout<<v[i]<<' '; cendl;
#define cout2(v,n,m) for(ll i=0;i<n;i++,cendl) for (int j = 0; j < m; j++) cout<<v[i][j]<<' ';
#define assign1(v,n,value) for(ll i=0;i<n;i++)v[i]=value;
#define assign2(v,n,m,value) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) v[i][j]=value;
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define oo  LLONG_MAX;
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n,m,q;
    cin>>n>>m>>q;
    ll a[n], b[m];
    cin1(a,n);
    cin1(b,m);
    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
      mp[a[i]] = i;
    }
    
    if(a[0]!=b[0]){
      cout<<"TIDAK";
      return;
    }
    bool vis[n+1];
    assign1(vis,n+1,false);
    vis[mp[a[0]]] = true;
    for (int i = 1; i < m; i++)
    { 
      if(vis[mp[b[i]]])continue;
      if(!vis[mp[b[i]]-1]) {
        // cout<<"b = "<<b[i]<<"  mp[b[i]-1] = "<<mp[b[i]]-1<<endl;
        cout<<"TIDAK";
        return;
      }
      else vis[mp[b[i]]] =true;
    }
    cout<<"YA";
  return;
}

int32_t main() {
    InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}