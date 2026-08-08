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
const int z=0;

void solve()
{
    ll n,k;
    cin>>n>>k;
    map<string,ll> mp;
    for (int i = 0; i < k; i++)
    {
      for (int j = 0; j < k; j++)
      {
        char first=(char)(i+'a');
        char second=(char)(j+'a');
        string s="";
        s+=first;
        s+=second;
        mp[s]=0;
      }
    }
    if(n==1){
      cout<<"a";
      return;
    }
    string ans="aa";
    ll cnt[k];
    assign1(cnt,k,0);
    cnt[0]+=2;
    ll temp=n-2;
    while(temp>0){
    ll x=1e8;
    int cur=0;
    for (int i = 0; i < k; i++)
      if(cnt[i]<=x) x=cnt[i], cur=i; 
    ans+=char(cur+'a');
    cnt[cur]++;
    temp--;
    }
    // cout1(cnt,k);
    cout<<ans;

  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}