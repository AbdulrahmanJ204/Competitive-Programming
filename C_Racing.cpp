#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define gcd(a ,b) __gcd(a,b)
#define lcm(a,b) a*b/gcd(a,b)
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"
#define cno cout<<"NO"
#define cin(v) for(ll i=0;i<v.size();i++)cin>>v[i];
#define cin1(v,n) for(ll i=0;i<n;i++)cin>>v[i];
#define cin2(v,n,m) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) cin>>v[i][j];
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}
#define cout1(v,n) for(ll i=0;i<n;i++)cout<<v[i]<<' '; cendl;
#define cout2(v,n,m) for(ll i=0;i<n;i++,cendl) for (int j = 0; j < m; j++) cout<<v[i][j]<<' ';
#define assign1(v,n,value) for(ll i=0;i<n;i++)v[i]=value;
#define assign2(v,n,m,value) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) v[i][j]=value;
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define oo  LLONG_MAX
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
const int z = 2e5+100;
int d[z] , l[z] , r[z];
int n;




void solve()
{
    cin>>n;
    for (int i = 0; i < n; i++)
    cin>>d[i];
    for (int i = 0; i < n; i++)
      cin>>l[i]>>r[i];
    int canM = 0 , ones = 0;

    deque<int> v; 
    for (int i = 0; i < n; i++)
    {
      if(~d[i]) ones+=d[i];
      else canM++ , v.push_back(i);
      if(ones>r[i]||ones+canM<l[i]){
        cout<<-1;
        return;
      }
      if(ones<l[i]){
      int need = l[i]-ones;
      canM -= need , ones=l[i] ;
        while(need--){
          int idx = v.back();
           v.pop_back();
          d[idx] = 1;
        }
        
      }
      if(ones+canM > r[i]){
        int dif = ones+canM -r[i];
        canM-= dif;
        while(dif--){
          v.pop_front();
        }
 
      }
    }
    if(ones<l[n-1] || ones > r[n-1]) {
      cout<<-1;
      return;
    }
    for (int i = 0; i < n; i++)
    {
      if(~d[i]) cout<<d[i];
      else 
      cout<<0;
      cout<<" ";
    }
    
    
    
    
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