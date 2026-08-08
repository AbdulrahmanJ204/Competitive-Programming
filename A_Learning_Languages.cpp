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

int sz[101], p[101];

ll find(int a){
  return p[a]= (p[a]==a ? a  : find(p[a]));
}
void merge(int a, int b){
  a=find(a);
  b=find(b);
  if(a==b) return;
  if(sz[a]>sz[b]) swap(a,b);
  sz[a]=0;
  p[a]=b;
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    
    ll ans=0;
    
    
    for (int i = 0; i <= m; i++)
    {
      p[i]=i;
      sz[i] = 0;
    }
   
    
    set<int> v[n+1];

    for (int i = 1; i <= n; i++)
    {
      int z;
      cin>>z;
      int last = 0;
      if(!z) ans++;

      while(z--) {
        int lang;
        cin>>lang;
        sz[lang]=true;
        v[i].insert(lang);
      }
    }

    for (int i = 1; i <= n; i++)
    { 
      int last= 0;
      for(int x: v[i]) if(!last) last= x; else merge(x,last);
    }
    bool x = false;
    for (int i = 1; i <= m; i++)  
      if(sz[i]) ans++ , x=true;
    if(x)
    ans--;
    cout<<ans;

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
      cendl;
    }
    return 0;
}