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

map<int,int> primeFactors(long long n) {
  map<int,int> factorization;
  while (n % 2 == 0) {
      factorization[2]++;
      n /= 2;
  }
  for (long long d = 3; d * d <= n; d += 2) {
      while (n % d == 0) {
          factorization[d]++;
          n /= d;
      }
  }
  if (n > 1)
      factorization[n]++;
  return factorization;
}
void solve()
{
    int a,b;
    cin>>a>>b;
    if(a==b){
      cout<<0;
      return;
    }
    map<int,int> pa = primeFactors(a) , pb = primeFactors(b);
    int ans =0;
    for(auto &x : pa){
      int num = x.first;
      // cout<<num<<" "<<x.second<<" "<<pb[num]<<endl;
      if(pb[num] != x.second){
        int z=  abs(pb[num]-x.second);
        if(num==2||num==3 || num==5){
          ans+=z;
          x.second= 0;
          pb[num] = 0;
        }
        else{
          cout<<-1;
          return;
        }
      }
    }
    for(auto &x : pb){
      int num = x.first;
      if(pa[num] != x.second){
        
        int z=  abs(pa[num]-x.second);
        if(num==2||num==3 || num==5){
          ans+=z;
          x.second= 0;
          pa[num] = 0;
        }
        else{
          cout<<-1;
          return;
        }
      }
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