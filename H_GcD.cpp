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
 
 #define MAXN 1000001
vector<int> spf(MAXN + 1, 1);
const ll M = 1e6 + 10;
ll numberOfFactors[M];
void SSS()
{
    spf[0] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) { 
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j]== 1)
                    spf[j] = i;
                    numberOfFactors[j]++;
            }
        }
    }
}

vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

vector<int> divisors;
vector<pair<int,int>> v;
void fun(int index , int res = 1)
{
  if(index==v.size()){
    divisors.push_back(res);
    return;
  }
  fun(index+1 , res);
  for (int i = 1; i <= v[index].second; i++)
  {
    int temp= v[index].first * i * res;
    fun(index+1 , temp);
  }
}

ll power2(ll x) {
    return 1ll << x;
}

 void solve()
 {
     ll x;
     cin>>x;
     divisors.clear();     
     v.clear();
     vector<int> factors = getFactorization(x);
     for(auto y : factors){
      if(!v.size() || v.back().first != y) v.push_back({y , 1});
      else v.back().second++;
     }
     fun(0);
     sort(all(divisors));
     int ans = 0;
     for (int i = 0; i < divisors.size(); i++)
      ans += power2(numberOfFactors[x/divisors[i] - 1]);
     
     cout<<ans/2;
   return;
 }
 
 int32_t main() {
     InTheNameOfAllah
     //freopen("input.txt", "r", stdin);
     //freopen("output.txt", "w", stdout);
     for (ll i = 0; i < M; i++) {
        numberOfFactors[i] = 0;
    }
    SSS();
    
     ll t=1;
     cin>>t;
     while(t--){
       solve();
       cendl;
     }
     return 0;
 }