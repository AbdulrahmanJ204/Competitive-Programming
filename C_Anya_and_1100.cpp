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
#define oo  LLONG_MAX
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    string s;
    cin>>s;
    int n = s.size();
    int q;
    cin>>q;
    set<int> st;
    for (int i = 0; i <= n-4; i++)
      if(s.substr(i , 4)=="1100") st.insert(i);
    
    
    while(q--){
      int i ; char v;
      cin>>i>>v;
      i--;

      if(s.size()<4){
        cno;
        cendl;
        continue;
      }

      if(s[i]==v){
        st.size() ? cyes : cno;
        cendl;
        continue;
      }

      for (int j = max(0ll , i-3); j <= i; j++)
        if(st.count(j)){
          st.erase(st.find(j));
        }
      

      s[i]= v;
      for (int j = max(0ll , i-3); j <= min(n-4 , i+1); j++)
        if(s.substr(j,4)=="1100") st.insert(j);
      
     st.size() ? cyes : cno;
        cendl;
    }

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
      // cendl;
    }
    return 0;
}