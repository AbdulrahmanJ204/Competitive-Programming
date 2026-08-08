#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
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
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
vector<ll> primes;
const int N=1e5;
ll prime[N];
void sieve(){
  assign1(prime,N,0);
    for(int i=2;i<N;i++){
        if(prime[i])continue;
        primes.push_back(i);
        for(int j=i;j<N;j+=i){
            prime[j]=i;
        }
    }
}

 
void solve()
{
    ll n;
    cin>>n;
    ll a[n];
    cin1(a,n);
    set<ll> st;
    for (int i = 0; i < n; i++)
    {
      for(auto &x: primes){
        if(x*x>a[i]) break;
        if(a[i]%x!=0) continue;
        if(st.find(x)!=st.end()){ cyes; return;}
        while(a[i]%x==0) a[i]/= x;
        st.insert(x);
      }
      if(a[i]>1){
        if(st.find(a[i])!=st.end()) {cyes; return;}
        st.insert(a[i]);
      }
    }
    cno;
  return;
}

int main() {
    InTheNameOfAllah
    sieve();
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}