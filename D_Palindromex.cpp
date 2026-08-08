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
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define cout1(v,n) for(ll i=0;i<n;i++)cout<<v[i]<<' '; cendl;
#define cout2(v,n,m) for(ll i=0;i<n;i++,cendl) for (int j = 0; j < m; j++) cout<<v[i][j]<<' ';
#define assign1(v,n,value) for(ll i=0;i<n;i++)v[i]=value;
#define assign2(v,n,m,value) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) v[i][j]=value;
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define oo  LLONG_MAX
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(L,R) uniform_int_distribution<int>(L, R)(rng);

void solve()
{
    ll n;
    cin>>n;
    int n2 = n*2;
    int a[n*2];
    cin1(a,n2);
    
    vector<pair<int,int>> v(n, {-1,-1});
    for (int i = 0; i < n2; i++)
    {
      if(v[a[i]].first == -1){
        v[a[i]].first = i;
      }
      else v[a[i]].second = i;
    }
    vector<int> starts;
    for(int i = 0; i < v.size(); i++)
    { auto x = v[i];
    if(x.second - x.first <=2) starts.push_back(i);
}
    // tryAndCry(starts);
    int mex = 1;
    for (int i = 0; i < starts.size(); i++)
    {
      auto p = v[starts[i]];
      int l = p.first;
      int r = p.second;
      set<int> st;
      if(r-l == 2) st.insert(a[l+1]);
      while(l>= 0 && r < n2 && a[l] == a[r]){
        // cout<<"L = " <<l<<" R = "<<r<<endl;
        // cout<<"aL = " <<a[l]<<" aR = "<<a[r]<<endl;
        
        st.insert(a[l]);
        l--; r++;
      }
      int cnt = 0;
      for(int z : st) {
        if(z!=cnt) break;
        cnt++;
      }
       mex = max(cnt , mex);

    }
    
    cout<<mex;
     
    

  return;
}

int32_t main() {
    InTheNameOfAllah;
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