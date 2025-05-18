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
    ll n,m,k,q;
    cin>>n>>m>>k>>q;
    char r[3]={'c','k','g'};
    map<char , string > mp;
    mp['c'] ="Carrots";
    mp['k'] ="Kiwis";
    mp['g'] ="Grapes";
    mp['.'] ="Waste";
    
    vector<pair<int,int>> p;
    for (int i = 0; i < k; i++)
    {
      int x,y;
      cin>>x>>y;
      p.push_back({x,y});
    }
    

    while(q--){
      int x,y;
      cin>>x>>y;
      ll cnt= 0;
      char  c='?';
      for (int i = 0; i < k; i++)
      {
        if(p[i].first<x || (p[i].first<=x && p[i].second<y)) cnt++;
        if(p[i].first==x && p[i].second==y) {c='.'; break;} 
      }
      if(c!='?') cout<<mp[c]<<endl;
      else {
        ll z = (x-1) * m + y - cnt -1;
        z%=3;
        cout<<mp[r[z]]<<endl;
      }
    }

  return;
}

int32_t main() {
    InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
    }
    return 0;
}