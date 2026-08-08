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
ll n, m , x ,y;
const int MXN = 1001;
string s[MXN];    
vector<int> cnt;
// . -> 0
// # -> 1
// this is test 
ll dp[MXN][2][MXN];
ll fun(int c , int last , int width){
  if(c==m) return x<= width && width <= y ? 0 : 1e8;
  int &ans = dp[c][last][width];
  if(~ans) return ans;
  ans= 1e8;
  if(width < x){
   ans =  (last ? n-cnt[c] : cnt[c]) + fun(c+1 , last , width + 1);
  } 
  else if(width == y){
    ans = (last ? cnt[c] : n-cnt[c]) + fun(c+1 , !last , 1);
  }
  else{
    int c1 = cnt[c] + fun(c+1 , 0 , last ? 1 : width + 1),
    c2 = n - cnt[c] + fun(c+1 , 1 , last ? width + 1 : 1);
    ans= min(c1 , c2);    
  }
  return ans;
}
void solve()
{
    cin>>n>>m>>x>>y;
    cin1(s , n);
    cnt.resize(m , 0);
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < 2; j++)
      {
        for (int k = 0; k < m; k++)
        {
          dp[i][j][k]=-1;
        }
        
      }
      
    }
    
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cnt[j] += (s[i][j]=='#');
      }
      
    }
    // tryAndCry(cnt); 
    cout<< min(cnt[0] + fun(1 , 0 , 1),n- cnt[0]+fun(1, 1 , 1));
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