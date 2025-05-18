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
ll fun(int x){
  return 1ll << x;
}
int lowBit(int i){
  
 return i & (-i);
}
void solve()
{
    ll n , sum;
    cin>>sum>>n;

    vector<int> v;
    int ones = (n+1)/2;
    int ans =0;
    for (int i = n-n%2; i >=2; i-=2)
    {

      if(sum-lowBit(i)>=0){
        sum-=lowBit(i);
        v.push_back(i);
      }
      if(sum - ones <= 0 ) break;
    }
   
    int i = 1;
    if(sum-ones<=0){
    while(sum--){
      v.push_back(i);
      i+=2;
    }
  }
    if(sum>0){
      cout<<-1;
      return;
    }
    cout<<v.size()<<endl;
    tryAndCry(v);
    
    
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