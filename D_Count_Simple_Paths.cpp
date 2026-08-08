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
ll n, m ,k;
const int z = 15;
string s[z];
bool valid(int i , int j ){
  if(i<0 || j<0 || i>=n || j>=m) return false;
  return s[i][j]=='.';
}
set<pair<int,int>> st;
int fun(int i , int j  , int cnt){
  if(!valid(i, j)) return 0;

  if(st.count({i,j}) || cnt > k) return  0;
  if(cnt==k) return 1;
  int ans = 0;
  st.insert({i,j});
  ans+=fun(i+1 ,j , cnt+1);
  ans+=fun(i-1 ,j , cnt+1);
  ans+=fun(i ,j+1 , cnt+1);
  ans+=fun(i ,j-1 , cnt+1);
  st.erase({i,j});
  return ans;
}
void solve()
{
    
    
cin>>n>>m>>k;
cin1(s,n);
int ans =0;
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        if (!valid(i, j))
            continue;
        st.clear();
        ans += fun(i, j, 0);
    }

    cout<<ans;

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