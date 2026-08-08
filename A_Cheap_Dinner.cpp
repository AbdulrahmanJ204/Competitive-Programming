#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
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
#define rep(i , from , to) for(int i = from ; i < to ;i++)
#define repR(i , from , to) for(int i = from ; i >= to ;i--)
#define oo  LLONG_MAX;
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n[4];
    cin1(n,4);
    vector<vector<int>> a(4);
    for (int i = 0; i < 4; i++)
    for (int x,j = 0; j < n[i]; j++)
    { 
      cin>>x;
      a[i].push_back(x);
    }
    
      
    ll m[3];
    map<int,set<int>> p[3];
    int x, y;
    for (int j = 0; j < 3; j++) {
        cin >> m[j];
        for (int i = 0; i < m[j]; i++) {
            cin >> x >> y;
            x--, y--;
            p[j][x].insert(y);
        }
    }

    if(m[0]==n[0]*n[1] || m[1]== n[1]*n[2] || m[2] == n[2]*n[3]) {
      cout<<-1;
      return;
    }
    set<pair<int,int>> cur ;
    for (int level = 3; level >= 0; level--)
    {
      
      if(cur.size()) cur.clear(); 
      for (int i = 0; i < n[level]; i++)
      if(a[level][i]!=LLONG_MAX) cur.insert({a[level][i],i});
      
      if(!level) break;

      for (int i = 0; i < n[level-1]; i++)
      {
        ll upIdx=i;
        auto mn= cur.begin();
        int index=(*mn).second;
        while(mn!=cur.end()&&p[level-1][upIdx].count(index)){
          mn++;
          index=(*mn).second;
        }
        if(mn==cur.end()) a[level-1][i]=LLONG_MAX;
        else a[level-1][i]+=(*mn).first; 
      }
    }
    
    if(!cur.size()) cout<<-1;
    else cout<<(*cur.begin()).first;
  return;
}

int32_t main() {
    InTheNameOfAllah
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}