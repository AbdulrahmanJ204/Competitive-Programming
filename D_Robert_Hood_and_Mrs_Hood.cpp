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
    ll n,d,k;
    cin>>n>>d>>k;
    vector<int> l , r;
    for (int i = 0; i < k; i++)
    {
      int x, y;
      cin>>x>>y;
      l.push_back(x);
      r.push_back(y);
    }
    sort(all(l));
    sort(all(r));
    ll sum=0, mn= 0 , mx= 0 , lsmn=1e8, lsmx=0;
    d=min(n,d);
    for (int i = 1; i <= n-d +1; i++)
    {
      ll pre= lower_bound(all(r),i) -r.begin() -1, suf= upper_bound(all(l), i+d-1)-l.begin();
      ll cur = k;
      
      if(pre>=0&&r[pre] < i) cur-=pre + 1;
      if(suf<l.size() && l[suf] > i+d-1) cur-=l.size() - suf ;
      if(cur<lsmn)
        mn=i,lsmn=cur;

      if(cur>lsmx)
        mx=i,lsmx=cur;
      

    }
    cout<<mx<<' '<<mn;
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