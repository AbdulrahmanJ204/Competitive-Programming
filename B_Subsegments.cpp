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
    ll n,k;
    cin>>n>>k;
    ll a[n];
    cin1(a,n);
    map<ll,ll> cnt;
    set<ll> st;
    for (int i = 0; i < k; i++)
    {
      cnt[a[i]]++;
      if(cnt[a[i]]==1) st.insert(a[i]);
      else if(st.find(a[i])!=st.end()) st.erase(st.find(a[i]));
    }
      if(!st.size()) cout<<"Nothing"<<endl;
      else cout<<*st.rbegin()<<endl;
    ll l=0,r=k;
    while(r<n){
      cnt[a[r]]++;
      if(cnt[a[r]]==1) st.insert(a[r]);
      else if(st.find(a[r])!=st.end()) st.erase(st.find(a[r]));
      cnt[a[l]]--;
      if(cnt[a[l]]==1) st.insert(a[l]);
      else if(st.find(a[l])!=st.end()) st.erase(st.find(a[l]));

      if(!st.size()) cout<<"Nothing"<<endl;
      else cout<<*st.rbegin()<<endl;
      l++;
      r++;
    }
    
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