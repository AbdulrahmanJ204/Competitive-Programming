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
    
    int mp[m];
    assign1(mp, m ,0);
    for (int i = 0; i < n; i++)
    {
      int x;
      cin>>x;
      int mod = x%m;
      mp[mod]++;
    }
    ll ans=(mp[0] > 0);

    for (int i = 1; i <= m/2; i++)
    {
      // cout<<"Ans = "<<ans<<endl;  
      // cout<<"i = "<<i<<' ';
      // cout<<mp[i]<<" "<<mp[m-i]<<endl;
      if(!mp[i] && !mp[m-i]) continue;
      else if(i==m-i) ans++;
      else if(!mp[i]) ans+=mp[m-i];
      else if(!mp[m-i]) ans+=mp[i];
      else ans+= (abs(mp[i]-mp[m-i]) > 1 ? abs(mp[i]-mp[m-i]) : 1   );
    }
    if(!ans) ans++;
    cout<<ans;
    
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