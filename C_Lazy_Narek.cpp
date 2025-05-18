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
const int z=1010;
ll n,m;
string c="narek"; 
set<char> st={'n','a','r','e','k'};
string s[z];
ll dp[z][5];
ll fun(int i , int cur){
  if(i==n) return 0;
  if(~dp[i][cur]) return dp[i][cur];
  int temp=cur, curN=0 , curM=0;
  for (int j = 0; j < s[i].size(); j++)
  {
    if(s[i][j]==c[temp]){
      temp++;
      if(temp==5) temp=0 ,curN+=5; 
    }
    if(st.count(s[i][j])) curM++;
  }
  curM-=curN;
  ll take , leave;
  take=curN-curM + fun(i+1 , temp);
  leave=fun(i+1,cur);
  return dp[i][cur]= max(take,leave);
}
void solve()
{
    cin>>n>>m;
    cin1(s,n);
    assign2(dp,n,5,-1);
    cout<<fun(0,0);
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