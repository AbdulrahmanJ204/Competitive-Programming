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
string s[110];
    ll n,m;
bool can(int i , int j){
  if(i<0 || i>= n || j<0 || j>=m) return false;
  return true;
}
bool valid(int i , int j){
  return (!can(i , j) || s[i][j] =='#');
}
bool set1(int x ,int y){
  for (int i = -1; i < 2; i++)
  {
  for (int j = -1; j < 2; j++)
    {
      if(!i && !j) continue;
      int newX = x+i , newY = y+j;
      if(!valid(newX , newY)) return false;
    }
  }
  for (int i = -1; i < 2; i++)
  {
  for (int j = -1; j < 2; j++)
    {
      if(!i && !j) continue;
int newX = x+i , newY = y+j;
      if(can(newX ,newY)){
      s[newX][newY]= '.';
      }
    }
  }
  return true;
}
void solve()
{
    cin>>n>>m;
    cin1(s,n);
    bool p = false;
    
    for (int i = 1; i < n-1; i++)
    {
      for (int j = 1; j < m-1; j++)
      {
        if(s[i][j]=='#'){
           p|=set1(i,j);
           if(p) break;
        }
      }
    }
    for (int i = 0; i < n; i++)
    {
      if(p) break;
      for (int j = 0; j < m; j++)
      {
        if(s[i][j]=='#'){
           p|=set1(i,j);
           if(p) break;
          
        }
      }
    }
    if(!p){
      cout<<"Impossible";
      return;
    }
    cout<<"Possible"<<endl;
    for (int i = 0; i < n; i++)
    {
      cout<<s[i]<<endl;
    }
    
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