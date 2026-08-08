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
vector<int> decToBinary(int n)
{
    int i = 0;
    vector<int> v;
    while (n > 0) {
        v.push_back( n % 2);
        n = n / 2;
        i++;
    }
    // reverse
    while(v.size()<63) v.push_back(0);
    return v;
}
ll fastPower_base2(ll x) {
    return (ll)1 << x;
}
ll binaryToDecimal(vector<int> &v){
  ll ans=0;
  for (int i = 0; i < v.size(); i++)
  {
    if(v[i])
    ans+= fastPower_base2(i);
  }
   return ans;
}
void solve()
{
    ll b ,c ,d;
    cin>>b>>c>>d;
    vector<int> on , off , res ;
    on=decToBinary(b);
    off=decToBinary(c);
    res=decToBinary(d);
    vector<int> ans(on.size());
    for (int i = 0; i < 61; i++) {
        if (res[i]) {

            if (on[i]) {
                ans[i] = 0;
            } else if (!on[i] && !off[i]) {
                ans[i] = 1;
            } else {
                cout << -1;
                return;
            }
        } else {
            if (off[i]) {
                ans[i] = 1;
            } else if (!on[i] && !off[i]) {
                ans[i] = 0;
            } else {
                cout << -1;
                return;
            }
        }
    }

    cout<<binaryToDecimal(ans);
    

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