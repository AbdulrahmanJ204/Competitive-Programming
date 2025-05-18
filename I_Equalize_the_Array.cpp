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
    ll a[n];
    cin1(a,n);
    sort(a,a+n);
    map<ll,ll> mp;
    for(auto x: a) mp[x];
    int z=1;
    for(auto &x: mp) x.second=z++;
    ll cnt[z];
    assign1(cnt,z,0);
    for(auto &x: a) cnt[mp[x]]++;
    sort(cnt,cnt+z);
    ll pre[z];
    pre[0]=0;
    for (int i = 1; i < z; i++)
      pre[i]=cnt[i]+pre[i-1];
    ll ans=1e18;
    // cout1(a,n);
    // cout1(cnt,z);
    // cout1(pre,z);
    
    for (int i = 1; i < z; i++)
    {
      if(cnt[i]==cnt[i-1]|| !cnt[i]) continue;
      int last=lower_bound(cnt,cnt+z,cnt[i]+1)-cnt;
      ll cur=pre[i-1]-pre[0];
     if(z!=last) cur+=(pre[z-1]-pre[last-1])-(z-last)*cnt[i];
      // cout<<"I = "<<i<<"  cnt[i] = "<<cnt[i]<<" Last = "<<last<<"  Cur =  "<<cur<<endl;

      ans=min(ans,cur);
    }
    if(ans==1e18 || ans<0) ans=0;
    cout<<ans;
    


    // cout<<n-ans;
  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}