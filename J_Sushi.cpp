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
const int z =310;
ll a[z];
ll n;
double dp[z][z][z];
double fun(int i , int j, int k ){
  if(i < 0 || j < 0 || k < 0 ) return 0;
  if(!i && !j && ! k ) return 0;
  if(dp[i][j][k]!=-1) return dp[i][j][k];
  double temp=0;
  temp= 1.0 * i / n * (1 + fun(i-1 , j , k));
  temp+= 1.0 * j / n * (1 + fun(i+1 , j-1 , k));
  temp+= 1.0 * k / n * (1 + fun(i , j+1 , k-1));
  double waste = n- i -j -k ;
  waste /= n;
  temp+= waste;
  temp/=(1-waste);
  return dp[i][j][k]= temp;

}
void solve()
{
    cin>>n;
    cin1(a,n);
    for (int i = 0; i < n+1; i++)
    {
      for (int j = 0; j < n+1; j++)
      {
        for (int k = 0; k < n+1; k++)
        {
          dp[i][j][k]=-1;
        }
        
      }
      
    }
    int cnt[4];
    assign1(cnt , 4 , 0);
    for (int i = 0; i < n; i++)
      cnt[a[i]]++;
    
    cout<<fixed<<setprecision(10)<<fun(cnt[1], cnt[2] , cnt[3]);
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