#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define cin(v) for(ll i=0;i<v.size();i++)cin>>v[i];
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    int n,x;
    cin>>n>>x;
    int a[n+1];
    a[0]=0;
    for (int i = 1; i < n+1; i++)
    {
      cin>>a[i];
    }
    int ans=a[x];
    int l=x-1,r=x+1;
    while(l>0&&r<n+1){
      a[l]==a[r]? ans+=a[l]*2: ans;
      l--;
      r++;
    }
    while(l>0) {ans+=a[l];
    l--;}
    while(r<n+1){
      ans+=a[r];
      r++;
    }
    cout<<ans;
  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}