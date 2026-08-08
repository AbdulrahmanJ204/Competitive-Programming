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
int ask(int a , int b){
  cout<<"? "<<a<<" "<<b<<endl;
  cout.flush();
  int x;
  cin>>x;
  return x;
}
void pr(vector<int> &v){
  cout<<"! ";
  tryAndCry(v);
  cout.flush();
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v[2];
    for (int i = 2; i < n; i++)
    {
      int x = ask(1 , i);
      if(x) v[0].push_back(i);
      else  v[1].push_back(i);
    }
    int ans[n+1];
    int i = 0 , j = 0;
    int lastInOne = 1 , lastInZero = 0;
    for(auto x : v[1]){
      ans[x] = lastInOne;
      lastInOne = x;
    }
    while(i<v[0].size() && j<v[1].size()){
      int nextLast = v[0][i];
      while(i<v[0].size()&& v[0][i]<=v[1][j] ){
        ans[v[0][i]] = lastInZero;
        
        i++;        
      } 
      lastInZero =nextLast;
      j++;
    }
    while(i<v[0].size()){
      ans[v[0][i]] = lastInZero;
      lastInZero = v[0][i];
      i++;
    }
    cout<<"! ";
    ans[1] = 0;
    for (int i = 1; i < n; i++)
    {
      cout<<ans[i]<<" ";
    }
    cout.flush();
    // 6
    // 0 0 0 1 2
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
      cout.flush();
    }
    return 0;
}