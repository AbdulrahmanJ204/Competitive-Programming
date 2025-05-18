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

int sum_1_to_n(int n) {
    return (n * (n + 1) / 2);
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<int,int>> a(m);
    for (int i = 0; i < m; i++)
    {
      cin>>a[i].first;
    }
    for (int i = 0; i < m; i++)
    {
      cin>>a[i].second;
    }
    sort(all(a));
    if(a.back().first != n){
      a.push_back({n,0});
      m++;
    }
    
    if(a[0].first!=1){
      cout<<-1;
      return;
    }

    int carry = 0 , ans = 0;
    for (int i = 0; i < m -1; i++)
    {
      carry= a[i].second - 1;
      a[i].second = 1;
      
      if(a[i].first+carry < a[i+1].first-1){
        cout<<-1;
        return;
      }
      ans+=sum_1_to_n(a[i+1].first - a[i].first -1);
      carry -= a[i+1].first-a[i].first-1;
      ans+=carry * (a[i+1].first- a[i].first);
      a[i+1].second +=carry;
    }
    carry = a[m-1].second -1;
    if(carry) cout<<-1;
    else cout<<ans;

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