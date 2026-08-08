#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n;
    cin>>n;
    int a[n];
    vector<ll> p,ne;
    for (int i = 0; i < n; i++)
    {
      cin>>a[i];
      if(a[i]<0) ne.push_back(a[i]);
      if(a[i]>=0) p.push_back(a[i]);
    }
    ll ans=0;
    if(p.size()>1){
      int size=p.size();
      sort(p.begin(),p.end());
      ans=p[size-1]*p[size-2];
    }
    if(ne.size()>1)
    {
      sort(ne.begin(),ne.end());
      ans=max(ans,ne[0]*ne[1]);
    }
    if(p.size()==1&&ne.size()==1){
      ans=p[0]*ne[0];
    }
    cout<<ans;
  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}