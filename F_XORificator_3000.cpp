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

int findXOR(int n)
{
    int mod = n % 4;

    if (mod == 0)
        return n;

    else if (mod == 1)
        return 1;

    else if (mod == 2)
        return n + 1;

    else if (mod == 3)
        return 0;
}

int findXOR(int l, int r)
{
    return (findXOR(l - 1) ^ findXOR(r));
}

void solve()
{
    ll l , r , i , k;
    cin>>l>>r>>i>>k;
    set<int> st;
    vector<int> v;
    int x=( 1ll <<i);
    int ans;
    int z = 1;
    st.insert(k);
    while(x <= r && x >=0){
      x*=z;
      z++;
      st.insert(x-k);
      st.insert(x);
      st.insert(x+k);
    }
    for(auto x : st) v.push_back(x);
    // tryAndCry(v);
    ans = findXOR(l , r);
    x= (1ll<<i);
    for (int i = 0; i < v.size(); i++)
    {
      if(l<=v[i] && v[i]<=r){

        if(v[i]%x == k) ans ^= v[i];
      }
    }
    
    
    cout<<ans;
    
    // cendl;

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