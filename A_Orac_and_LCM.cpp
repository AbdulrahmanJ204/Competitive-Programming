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
map<int,map<int,int>> mp;
vector<int> factors;
map<int,int> primesCnt;
void sieveFactorization(int N) {
  factors.resize(N+1 , 1);  
  for (int i = 2; i <= N; ++i) {
    if (factors[i]==1) { // If i is prime
      for (int j = i; j <= N; j += i) {
        factors[j]=i;
      }
    }
  }
  
}
void getFactorization(int x)
{
  int y = x;
  while (x != 1) {
    mp[y][factors[x]]++;
    x = x / factors[x];
  } 
}
long long fastPower(ll base, ll exponent) {
  long long result = 1;
  while (exponent > 0) {
      if (exponent % 2 == 1) {
          result *= base;
      }
      base *= base;
      exponent /= 2;
  }
  return result;
}
void solve()
{
    ll n;
    cin>>n;
    set<int> st;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin>>x;
      st.insert(x);
      v.push_back(x);
    }
    sieveFactorization(*st.rbegin());
    for(auto& x : st) getFactorization(x);
    for(auto& x : v ) if(factors[x]==x) primesCnt[x]++;
    int difPrimesCnt=0;
    for(auto& x : primesCnt) if(x.second>1) difPrimesCnt++; 
    map<int,vector<int>> powers;
    
    for(int x :v){
      // mp : map< x , map<factor , power> >    
      for(auto& p: mp[x]) {
        int factor = p.first , power = p.second;
        powers[factor].push_back(power);
      }
    }
    
    int ans=1;
    if(difPrimesCnt>1){
      cout<<1;
      return;
    }
    sort(all(v));
    if(difPrimesCnt){
     for(auto& x : primesCnt)
          if (x.second > 1) {
              ans=x.first;
          }
     if(v[1] < ans) cout<<1;
     else cout<<ans;
     return;     
    }
    
    
    for(auto& x :powers)
    {
      if(x.second.size()<n-1) continue;
      sort(all(x.second));
      int id= x.second.size()==n;
      int pw = x.second[id];       
       ans*= fastPower(x.first , pw);
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