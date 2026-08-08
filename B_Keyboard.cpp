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
    ll n,m,x;
    cin>>n>>m>>x;
    x*=x;
    string s[n];
    set<char> st;
    double d[26];
    assign1(d,26,1e8);
    set<pair<double,int>> shifts;
    cin1(s,n);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if(s[i][j]=='S') shifts.insert({i,j});
        else st.insert(s[i][j]);
      }
      
    }
    
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if(s[i][j]=='S')continue;
        for(auto p : shifts)
        d[s[i][j]-'a']= min(d[s[i][j]-'a'], (i-p.first)*(i-p.first) +(j-p.second)*(j-p.second) );
      }
    }
    
    int q;
    cin>>q;
    string t;
    cin>>t;
    ll ans=0;
    
    for (int i = 0; i < q; i++)
    {
      if(!st.count(tolower(t[i]))) {
        cout<<-1;
        return;
      }
      if(isupper(t[i])&&!shifts.size()){
        cout<<-1;
        return;
        
      }
      if(isupper(t[i]) && d[tolower(t[i])-'a']> x) ans++;
    }
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