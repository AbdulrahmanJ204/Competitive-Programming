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
#define cin1(v,n) for(ll i=0;i<n;i++)cin>>v[i];
#define cin2(v,n,m) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) cin>>v[i][j];
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define cout1(v,n) for(ll i=0;i<n;i++)cout<<v[i]<<' '; cendl;
#define cout2(v,n,m) for(ll i=0;i<n;i++,cendl) for (int j = 0; j < m; j++) cout<<v[i][j]<<' ';
#define assign1(v,n,value) for(ll i=0;i<n;i++)v[i]=value;
#define assign2(v,n,m,value) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) v[i][j]=value;
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n;
    cin>>n;
    int a[n];
    cin1(a,n);
    int m;
    cin>>m;
    string s;
    while(m--){
      cin>>s;
      if(s.size()!=n){
        cno;
        cendl;
        continue;
      }  
      bool can=true;
      set<int> st[26];
      for (int i = 0; i < n; i++)
      {
        st[s[i]-'a'].insert(a[i]);
      }
      for(auto x: st)
      if(x.size()>1) can=false;
      map<int,set<int>> mp;
      for (int i = 0; i < n; i++)
      mp[a[i]].insert(s[i]);

      for(auto x:mp)
      if(x.second.size()>1) can=false;

        can? cyes: cno;
        cendl;
      

    }

  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      // cendl;
    }
    return 0;
}