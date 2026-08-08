#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
ll n,k;
bool check(ll v){
  ll ans=0;
  ll temp=1;
  while(v/temp!=0){
    ans+=v/temp;
    temp*=k;
  }
  return ans>=n;
}
void solve()
{
    cin>>n>>k;
    ll l=1,r=n,ans=1e10;
    while(l<=r)
    {
      ll mid=(l+r)/2;
      if(check(mid))
      {
        r=mid-1;
        ans=min(ans,mid);
      }
      else l=mid+1;
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