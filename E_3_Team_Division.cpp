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

ll n;
vector<pair<int,int>> v;
int Tsum = 0;
const int z = 510 , zz= 110;
int dp[zz][z][z];
int fun(int i ,int s1 , int s2 ,int s3)
{
  
  if(i==n) return s1 == s2 && s2 == s3 ? 0 : 1e18;
  
  if(~dp[i][s1][s2]) return dp[i][s1][s2];
  
  int team= v[i].first , str = v[i].second;
  
  int c1 = 1e18, c2 =1e18, c3 =1e18;
    
  if(s1 + str <= 500) 
  c1 = fun(i+1 , s1 +str , s2 , s3) + (team!=0);
  if(s2 + str <= 500) 
  c2 =  fun(i + 1, s1, s2 + str, s3)+(team!=1);
  if(s3 + str <= 500) 
  c3 = fun(i + 1, s1 , s2 , s3 + str)+(team!=2);
    
  return dp[i][s1][s2]= min({c1 , c2 , c3});    
}
void solve()
{
    cin>>n;
    for (int i = 0; i < n+1; i++)
      for (int j = 0; j < z; j++)
        for (int k = 0; k < z; k++)
          dp[i][j][k]=-1;
        
      
      
    
    
    for (int i = 0; i < n; i++)
    {
      int x, y;
      cin>>x>>y;
      v.push_back({x-1 ,y});
    }
    
    int ans= fun(0,0,0,0);
    cout<< (ans==1e18 ? -1 : ans);
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