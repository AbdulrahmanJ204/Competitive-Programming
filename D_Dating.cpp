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
    ll n,m;
    cin>>n>>m;
    map<set<int> , int> mp;
    map<int,int> cnt;
    for (int i = 1; i <= n; i++)
    {
      int k;
      cin>>k;
      set<int> st;
      for (int j = 0; j < k; j++)
      {
        int x;cin>>x;
        st.insert(x);
      }
      if(st.size()<=1) continue;
      mp[st]=i;
    }
    if(mp.size()<=1){
      cno;
      return;
    }
    
    vector<set<int>> v;
    for(auto &x : mp)  v.push_back(x.first);
      reverse(all(v));
    // for (int i = 0; i < v.size(); i++)
    //   for(auto x: v[i]) cout<<x<<' ';cendl;
    
    for (int i = 0; i < v.size(); i++)
    {
      for (int j = i+1; j < v.size(); j++)
      {
        
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
      cendl;
    }
    return 0;
}