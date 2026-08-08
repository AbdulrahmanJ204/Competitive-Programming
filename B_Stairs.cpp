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
int pow(int i ){
  return 1ll<<i;
}
int nice(int size){
  // int maxSquare =  1ll<<62;
  int i =  62;
  int squares = 0;
  cout<<"\nsize = "<<size<<endl;
  while(size > 0 && i>=0){
    if(i%2)i--;
    if(size >= pow(i)){
    cout<<size<<" "<<pow(i)<<endl;
      squares+=size/pow(i);
      size%=pow(i);
    }
    i--;
  }
  cout<<"\nsizeE = "<<size<<endl;
  return squares;
}
void solve()
{
    ll n;
    cin>>n;
    ll ans=0;
    set<int> st;
    st.insert(1);
    



    for (int i = 2; i < 100; i++)
    {
      st.insert(2*(*st.rbegin())+1);
      if(*st.rbegin() > 1e18) break;
    }
    auto it = st.begin();
    while(n>0){
      n-=*it * (*it+1) / 2;
      it++;
      if(n>=0)
      ans++;
    }
   
    cout<<ans;

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